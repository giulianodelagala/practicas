#include <iostream>

using namespace std;

int main()
{
 char cadena101[10], cadena102[10], cadena20[20];
 for (int j=0; j<2; j++)
	{ cout << "Cadena" << j << endl;
		
	 for (int i=0;i<10;i++)
		{ cout << "letra" << i << endl;
			if (j==0) { 
			   cin >> cadena101[i];
		    }
		    else {
				cin >> cadena102[i];
			}
		}
	
	for (int i=0;i<20;i++)
		{		
	       cadena20[i] = cadena101[i];
	       cadena20[i] = cadena102[i+10];
	     }      
	
 }
cout << cadena20;
return 0;
} 
