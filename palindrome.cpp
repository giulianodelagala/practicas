#include <iostream>

using namespace std;

char ingreso (char cadena[20])
{
	
	cout << "Ingrese palabra" ;
	cin >> cadena;
	return cadena[20];
}

void palindrome (char cadena[])
{
	//cout << "enpalin" << cadena[2];
	//cout << sizeof cadena[0];
	int i = 0;
	while (cadena[i] != 0)
	{
		cout << cadena[i];
		i++;
	}
	
}

int main()
{
	char cadena[] = "jasdasdasdasdasd";
	
	//cadena[20] = ingreso(cadena);
	//cout << sizeof (cadena);
	
	//cout << "en main" << cadena[2];
	palindrome(cadena);
	
	
	return 0;
	
}
	
