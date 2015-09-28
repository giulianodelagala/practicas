#include <iostream>
#include <cstdlib> 
using namespace std;
int n=100;

void buscar (int **pm,int w )
{
	 for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
			if(*(*(pm + i) + j) == w )
			{
				cout << "fila: "<< i<<" col:  "<< j<<endl;
			}
		}
	}
}
 
int main()
{
    int **pm;
 
    pm = new int* [n];
    for (int i = 0; i < n; i++) {
        pm[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <n; j++) {
           
            *(*(pm + i) + j) = rand() % 100; //i + j;
            //cout << *(*(pm + i) + j) << " " ;
        }
        //cout << endl;
    }
    int a ;
    cout << "buscar: " << endl;
    cin >> a;
    cout << "num " << a << " en: " << endl; 
    buscar (pm,a);
}
