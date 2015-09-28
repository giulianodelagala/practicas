#include <iostream>

using namespace std;

int main()
{
	int arr[8];
	for (int i=0; i<8; i++)
	{
		cout << "num" << i+1 << "= "; cin >> arr[i];
	}
	for (int i=7; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
