#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{
	Vector vec1;
	vec1.start.x = 0;
	vec1.start.y = 0;
	
	vec1.end.x = 4;
	vec1.end.y = 3;
	
	double distancia = vec1.distance();
	cout << distancia << endl;
	
}
 
