#include "vehicle.h"
#include "stringify.h"

const string Vehicle::getDesc() const
{
	return license + "from" + stringify (year);
}

const string Vehicle::&getLicense () const
{
	return license;
}

const int Vehicle::getYear()
const
{
	return year;
}



		
		
