#include <iostream>
using namespace std;

int main()
{
	int arr[4];
	cout << "Ingrese 4 enteros: " << endl;
	
	for (int i=0; i< 4; i++)
	{
		cin >> arr[i];
	}
	
	cout << "Los valores en array son: ";
	
	for (int i =0; i < 4; i++)
	{
		cout << " " << arr[i];
	}
	
	cout << endl;
	
	return 0;
}
		
