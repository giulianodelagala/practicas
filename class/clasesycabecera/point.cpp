#include "point.h"

double Point::getx()
{
	return _x;
}
		
double Point::gety()
{
	return _y;
}
		
void Point::setx(double x)
{
	_x = x;
}

void Point::sety (double y)
{
	_y = y;
}

Point::Point()
{
	_x =0; _y = 0;
}

Point::Point (double x, double y)
{
	_x = x; _y = y;
}
