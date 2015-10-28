// Point Header file

class Point
{
	private:
		double _x, _y;
		
	public:
		
		//constructor
		Point();
		Point(double x, double y);
			
		
		//getter
		double getx();		
		double gety();
		
		//setter
		void setx(double x);	
		void sety (double y);
		
};
