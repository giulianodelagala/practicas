#include <iostream>

using namespace std;

long factorial(int num)
{
	long facto = 1;
	for (int i = num; i > 1; i--)
	{
		facto *= i;
	}
	return facto;
}
	


int main()
{
	int num;
	long facto;
	cout << "num?"; cin >> num;
	facto = factorial(num);
	cout << facto;
}
