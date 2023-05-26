#include "Point.hpp"

Point::Point(void) 
{}

Point::Point(const float x, const float y) : _x(x), _y(y) 
{}

Point::Point(const Point& obj) : _x(obj._x), _y(obj._y) 
{}

Point::~Point(void) 
{}

Fixed Point::GetPointX(void)  const 
{
	return (_x);
}

Fixed Point::GetPointY(void) const  
{
	return (_y);
}

Point& Point::operator=(const Point& obj) 
{
	_x = obj._x;
	_y = obj._y;

	return *this;
}
