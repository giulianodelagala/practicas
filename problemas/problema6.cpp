#include <iostream>

using namespace std;

int main()
{
	long suma = 0;
	for (int i = 3; i<1000; i++)
	{
		if (i % 3 ==0 or i % 5 == 0)
		{
			//cout << i;
			suma += i;
		}
	
	}
	
	
	
	cout << suma;
	
	return 0;
}
