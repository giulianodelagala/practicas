#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
	int op = 0, num = 1;
	do
	{
		
		cout << "Ingrese numero: ";
		cin >> num;
		cout << "Ingrese 1. Cuadrado - 2. Cubo - 3. Fibonacci 0. Salir : ";
		cin >> op;
			
		
		if (op == 1)
		{
			int res = square (num);
			cout << res << endl;
		}
		if (op == 2)
		{
			int res = cube(num);
			cout << res << endl;
		}
		
		if (op == 3)
		{
			int res = fibo(num);
			cout << res << endl;
		}
		
		else 
		{
			cout << "Ingrese opcion valida"<< endl ;
		}
		
	} while 	(op != 0);
return 0;
}
		
		
	 

int cube (int x)
{
	return x * square (x);
}

int square (int x)
{
	return x * x;
}

int fibo (int x)
{
	if (x==0 || x ==1)
	{
		return 1;
	}
	else {
		return fibo (x-2) + fibo (x-1);
	}
}
		 
