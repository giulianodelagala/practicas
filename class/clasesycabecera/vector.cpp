#include "vector.h"
#include <iostream>
#include <math.h>

using namespace std;

double Vector::distance()
{
	return sqrt(pow ((start.getx() - end.getx() ),2) + pow ((start.gety() - end.gety() ),2) );
}

void Vector::print()
{
	cout << "Coor. x inicial" << start.getx() << endl;
	cout << "Coor. y inicial" << start.gety() << endl;
	cout << "Coor. x final" << end.getx() << endl;
	cout << "Coor. y final" << end.gety() << endl;

}

Vector::Vector()
{
	start.setx(0);
	start.sety(0);
	
	end.setx(0);
	end.sety(0);
}
	
Vector::Vector(double startx, double starty, double endx, double endy)
{
	start.setx(startx);
	start.sety(starty);
	
	end.setx(endx);
	end.sety(endy);
}
