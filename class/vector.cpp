#include <iostream>
#include <math.h>

using namespace std;

class vector
{
	public:
	int xinit;
	int yinit;
	int xfin;
	int yfin;
	
};

float distancia (int xi, int yi, int xf, int yf)
{
	float d;
	d = pow((pow((xf - xi),2) + pow((yf-yi),2)),0.5);
	return d;
}

int main ()
{
	vector vec1;
	vec1.xinit = 0;
	vec1.yinit = 0;
	vec1.xfin = 4;
	vec1.yfin = 4;
	
	cout << distancia(vec1.xinit, vec1.yinit, vec1.xfin, vec1.yfin);
	
	return 0;
	
}
