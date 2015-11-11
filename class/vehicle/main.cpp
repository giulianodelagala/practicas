#include "car.h"
#include <iostream>
using namespace std;

int main()
{
	Car Nuevo ("V2G-254", 2010, "HiLux");
	cout << Nuevo.getDesc() << endl;
	cout << Nuevo.getStyle() << endl;
	return 0;
}
