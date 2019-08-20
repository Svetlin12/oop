#pragma once
#include "Point2D.h"

class Point3D : public Point2D
{
private:

	double z;

public:

	Point3D();
	Point3D(const double x, const double y, const double z);
	Point3D(const Point3D& p);
	Point3D operator=(const Point3D& p);
	virtual ~Point3D();

	void setZ(const double z);
	const double getZ() const;

	virtual Point3D* clone() const override;

	virtual const std::string getType() const override;

	virtual void print() const override;

	virtual const double getDistanceTo(Point2D* p) const override;

};