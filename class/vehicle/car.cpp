#include "car.h"
#include "stringify.h"

const string Car::getDesc() //Overriding
{
	return stringify(year) + ' ' + style + ": " + license;
} 
	 

const string Car::&getStyle()
{
	return style;
}
 
