#include "Vector.h"
#include <iostream>
#include <math.h>

using namespace std;

double Vector::distance()
{
	return sqrt(pow ((start.x - end.x),2) + pow ((start.y - end.y),2) );
}

void Vector::print()
{
	cout << "Coor. x inicial" << start.x << endl;
	cout << "Coor. y inicial" << start.y << endl;
	cout << "Coor. x final" << end.x << endl;
	cout << "Coor. y final" << end.y << endl;

}
