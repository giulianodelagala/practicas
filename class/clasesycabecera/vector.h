//Vector h header file
#include "point.h"

class Vector
{
	public:
	
		Point start, end;
		
		double distance();
		void print();
		
		//constructor
		
		Vector ();
		Vector ( double startx, double starty, double endx, double endy);
	
};
	
