#include <iostream>

using namespace std;

void iniLista (int lista[19])
{
	for (int i = 2; i<21; i++)
	{
		lista[i-2] = i;
	}
}

void impLista (int lista[19])
{
	for (int i = 2; i<21; i++)
	{
		cout << lista[i-2];
	}
}

void hallamcm (int lista[19], int div, int &mcm)
{
	bool cambio = false;
	for (int i = 0; i <19; i++)
	{
		if (lista[i] % div == 0)
		{
			cambio = true;
			lista[i] /= div;
			//cout << endl << "div" << div;
						
		}
			
	}
	if (cambio)
	{
		mcm *= div;	
		hallamcm (lista, div, mcm);
	}
	else if (not cambio && div < 19)
	{
		hallamcm (lista, div+1, mcm);
		
	}
	
}

int main ()
{
	int mcm = 1;
	int div = 2;
	int lista[19];
	iniLista (lista);
	//impLista (lista);
	hallamcm (lista, div, mcm);
	//impLista (lista);
	cout << endl;
	cout << mcm;
	
	return 0;
}
