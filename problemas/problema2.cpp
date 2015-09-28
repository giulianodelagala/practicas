#include <iostream>

using namespace std;

int main()
{
	unsigned long long a = 1;
	unsigned long long b = 2;
	unsigned long long suma = 0;
	
	unsigned long long fibo;
	
	for (int i=0; i<4000000; i++)
	{
		if (i == 0)
		{fibo = 1;}
		else if (i==1)
		{fibo = 2;}
		else
		{
			fibo = a+b;
			a = b;
			b = fibo;
		}
		
		if (fibo % 2 == 0)
		{
			suma += fibo; 
		}
		//cout << fibo << " ";
	}
	cout << suma;
	return 0;
	
}
		
