#include "Point3D.h"

Point3D::Point3D() : Point2D()
{
	setZ(0);
}

Point3D::Point3D(const double x, const double y, const double z) : Point2D(x, y)
{
	setZ(z);
}

Point3D::Point3D(const Point3D & p) : Point2D(p)
{
	setZ(p.getZ());
}

Point3D Point3D::operator=(const Point3D & p)
{
	if (this != &p)
	{
		Point2D::operator=(p);
		setZ(p.getZ());
	}
	return *this;
}

Point3D::~Point3D()
{
}

void Point3D::setZ(const double z)
{
	this->z = z;
}

const double Point3D::getZ() const
{
	return this->z;
}

Point3D * Point3D::clone() const
{
	return new Point3D(*this);
}

const std::string Point3D::getType() const
{
	return "Point3D";
}

void Point3D::print() const
{
	Point2D::print();
	std::cout << "z: " << getZ() << std::endl;
}

//we create a Point3D* and set it to the dynamic cast of the clone of p (we clone p because we don't want p1 to
//share memory with p):
//if p1 is NULL meaning that p is a pointer to Point2D then we create a double to store the distance and then return it
//the way we calculate the distance in this case is we basically treat p's Z coordinate as 0
//before we return solution we destroy the newly created pointer p1
//if p1 is not NULL then calculate the distance the traditional way and then return solution
const double Point3D::getDistanceTo(Point2D * p) const
{
	Point3D* p1 = dynamic_cast<Point3D*>(p->clone());
	if (p1 == NULL)
	{
		double solution = sqrt(pow(getX() - p->getX(), 2) + pow(getY() - p->getY(), 2) + pow(getZ(), 2));
		delete p1;
		return solution;
	}
	double solution = sqrt(pow(getX() - p1->getX(), 2) + pow(getY() - p1->getY(), 2) + pow(getZ() - p1->getZ(), 2));
	delete p1;
	return solution;
}
