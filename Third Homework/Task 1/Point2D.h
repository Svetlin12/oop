#pragma once
#include <iostream>
#include <string>

class Point2D
{
private:

	double x;
	double y;

public:

	Point2D();
	Point2D(const double x, const double y);
	Point2D(const Point2D& p);
	Point2D& operator=(const Point2D& p);
	virtual ~Point2D();

	const double getX() const;
	const double getY() const;

	void setX(const double x);
	void setY(const double y);

	//function to prevent the sharing of memory when either Point2D or Poin3D has been copied
	virtual Point2D* clone() const;

	//this is where we determine which type is the Poin2D* used in the Entity.cpp
	//it is a virtual because depending on which class Point2D* points to, it will call either this function
	//or the function that is inherited in Point3D(getType())
	//this returns a string - "Point2D" and in Point3D - "Point3D" to be easily distinguished and readable
	virtual const std::string getType() const;

	virtual void print() const;

	virtual const double getDistanceTo(Point2D* p) const;
};