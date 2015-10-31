#include <string>

class Vehicle
{
	protected:
		std::string license;
		int year;
	
	public:
		Vehicle (const std::string &myLicense, const int myYear)
		: license (myLicense), year (myYear)
		{}
		
		const std::string getDesc() const;
		const std::string getLicense () const;
		const int getYear() const;
		
};
