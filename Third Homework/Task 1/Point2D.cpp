#include "Point2D.h"

Point2D::Point2D()
{
	setX(0);
	setY(0);
}

Point2D::Point2D(const double x, const double y)
{
	setX(x);
	setY(y);
}

Point2D::Point2D(const Point2D & p)
{
	setX(p.getX());
	setY(p.getY());
}

Point2D & Point2D::operator=(const Point2D & p)
{
	if (this != &p)
	{
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

Point2D::~Point2D()
{
}

const double Point2D::getX() const
{
	return this->x;
}

const double Point2D::getY() const
{
	return this->y;
}

void Point2D::setX(const double x)
{
	this->x = x;
}

void Point2D::setY(const double y)
{
	this->y = y;
}

Point2D * Point2D::clone() const
{
	return new Point2D(*this);
}

const std::string Point2D::getType() const
{
	return "Point2D";
}

void Point2D::print() const
{
	std::cout << "x: " << getX() << std::endl;
	std::cout << "y: " << getY() << std::endl;
}

const double Point2D::getDistanceTo(Point2D * p) const
{
	return sqrt(pow((getX() - p->getX()),2) + pow((getY() - p->getY()),2));
}
