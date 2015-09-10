#include <iostream>

using namespace std;

int main()
{
   int vec[10] = {2,5,6,7,10,13,16,18,20,21};
   int num;
   cout << "Ingrese un numero" << endl;
   cin >> num;
   for (int i=0; i<10; i++)
      { if (vec[i] == num)
		  { cout << "numero en lista" << endl;
			return 0;
		  }
		  
	   }
   cout << "No esta en lista" << endl;
   return 0;
 }

