#include <iostream>

using namespace std;

void incremento (int a)
{
	a++;
	cout << "a dentro de funcion " << a <<endl;
}

int main ()
{
	int q = 5;
	incremento (q);
	cout << "q dentro de main " << q;
}
