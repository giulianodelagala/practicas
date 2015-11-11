//#include <string>
#include "vehicle.h"
#include "stringify.h"

const std::string Vehicle::getDesc()
const
{
	return license + " del " + stringify (year);
}

const std::string Vehicle:: getLicense ()
const
{
	return license;
}

const int Vehicle::getYear()
const
{
	return year;
}



		
		
