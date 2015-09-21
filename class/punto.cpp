#include <iostream>
#include <math.h>

using namespace std;

class Punto
{
	public:
	double x,y;
	
};

class Vector
{
	public:
	Punto init, fin;
};

float distancia (int xi, int yi, int xf, int yf)
{
	float d;
	d = pow((pow((xf - xi),2) + pow((yf-yi),2)),0.5);
	return d;
}

int main ()
{
	Vector vec1;
	vec1.init.x = 0;
	vec1.init.y = 0;
	vec1.fin.x = 4;
	vec1.fin.y = 4;
	
	cout << distancia(vec1.init.x, vec1.init.y, vec1.fin.x, vec1.fin.y);
	
	return 0;
	
}	
