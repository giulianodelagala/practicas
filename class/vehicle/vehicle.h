
class Vehicle
{
	protected:
		string license;
		int year;
	
	public:
		Vehicle (const string &myLicense, const int myYear)
		: license (myLicense), year (myYear)
		{}
		
		const string getDesc();
		const string &getLicense ();
		const int getYear();
		
};
