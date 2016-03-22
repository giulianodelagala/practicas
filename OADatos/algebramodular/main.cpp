/* main funciones algebramodular
 * 
 */
 
#include "Modular.hpp"
#include <iostream>

using std::cout; using std::cin;

void IngresarBina(int &rA,int &rB,int &rModulo)
{
	cout << "a=? "; cin >> rA;
	cout << "b=? "; cin >> rB;
	cout << "mod=? "; cin >> rModulo;
}

void IngresarNona(int &rA,int &rModulo)
{
	cout << "a=? "; cin >> rA;
	cout << "mod=? "; cin >> rModulo;
}

void Menu()
{
	int opt;
	int a,b,modulo;
	int inverso;
	cout << "Operacion 1.suma 2.resta 3.multiplicacion 4.inverso 0.salir ...? ";
	cin >> opt;
	{
		switch (opt)
		{
			case 1:	
				IngresarBina(a,b,modulo);
				cout << Modular::Sumar(a,b,modulo) << std::endl;
				break;
			
			case 2:
				IngresarBina(a,b,modulo);
				cout << Modular::Restar(a,b,modulo) << std::endl;
				break;
			case 3:
				IngresarBina(a,b,modulo);
				cout << Modular::Multiplicar(a,b,modulo) << std::endl;	
				break;
				
			case 4:
				IngresarNona(a,modulo);
				inverso = Modular::Inversar(a,modulo);
	
				if (inverso >= 0)
				{
					cout<< inverso << "mod " << modulo << std::endl ;
				}
				else
				{
					cout << "no existe inverso" << std::endl;
				}
				
				break;
				
			default:
				cout << "Ingreso no valido" << std::endl;
				Menu();		
		}
							
	}
	 
}

int main()
{
	Menu();
	return 0;
}
	
