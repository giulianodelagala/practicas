#include <iostream>

using namespace std;

int main ()

{
	float num, max, min;
	
	for (int i = 0; i<7; i++)
	{
		if (i == 0)
		{
			cout << "num" << i+ 1 << " "; cin >> num;
			max = num;
			min = num;
		}
		
		else
		{
			cout << "num" << i+ 1 << " "; cin >> num;
			if (num > max)
			{
				max = num;
			}
			else if (num < min)
			{
				min = num;
			}
		}
	}
	
	cout << "max = " << max << " min=" << min; 
	
	return 0;


}
