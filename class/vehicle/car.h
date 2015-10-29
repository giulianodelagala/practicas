class Car : public Vehicle
{
	string style;
	
	public:
		Car (const string &myLicense, const int myYear,
		 const string &myStyle) : Vehicle(myLicense, myYear), 
		 style(myStyle)
		 {}
		
		const string getDesc(); //Overriding
		
		const string &getStyle();
		
}; 
