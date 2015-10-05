#include <iostream>

using namespace std;



int main()
{
	int matr[][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	
	cout << **matr  << endl;   //**matr es igual a 1 

	cout << *(*(matr+1)+2) << endl; // *(*(matr+1)+2) es igual a 7  

	cout << *(matr[2]+3) << endl;//*(matr[2]+3) es igual a 12 

	cout << (*(matr+2))[2] << endl;// (*(matr+2))[2] es igual a 11 

	cout << *((*matr)+1) << endl;// *((*matr)+1) es igual a 5 FALSA
}
