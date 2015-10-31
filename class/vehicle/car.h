#include "vehicle.h"
#include <string>

class Car : public Vehicle
{
	std::string style;
	
	public:
		Car (const std::string &myLicense, const int myYear,
		 const std::string &myStyle) : Vehicle(myLicense, myYear), 
		 style(myStyle)
		 {}
		
		//const std::string getDesc(); //Overriding
		
		const std::string getStyle();
		
}; 
