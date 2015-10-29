#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
	
	Vector vec1 (2, 4, 6, 4);
	//vec1.start.setx (0);
	//vec1.start.sety (0);
	
	//vec1.end.setx (4);
	//vec1.end.sety (3);
	

	vec1.print();
	
	double distancia = vec1.distance();
	cout << distancia << endl;
	
}
 
