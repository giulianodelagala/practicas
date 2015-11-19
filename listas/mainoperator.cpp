//#include "lista.hpp"
#include "auxiliar.hpp"
#include <iostream>


typedef Inicio_lista <double> list_double;
typedef Nodo<double> *list_double_ptr;
//typedef Iterador <double> list_double_iterator;

typedef Inicio_lista <char *> list_string;
typedef Nodo<char *> *list_string_ptr;
//typedef Iterador <char *> list_string_iterator;



int main()
{
	list_double numero1;
	list_double numero2;
	list_double numero3;
	list_double_ptr p;
	//list_double_iterator x (&numero);
	
	list_string cadena;
	list_string_ptr q;
	//list_string_iterator y (&cadena);
	
	int op=1;
	Auxiliar programa;
	
	numero1.insertar (5);
	numero1.insertar (4);
	numero1.insertar (3);
	numero1.insertar (2);
	
	numero2.insertar (4);
	numero2.insertar (4);
	numero2.insertar (4);
	numero2.insertar (4);
	
	numero1 + numero2;
	numero1.imprimir();
	
	numero3.insertar (5);
	numero3.insertar (5);
	numero3.insertar (5);
	numero3.insertar (5);
	
	numero1 - numero3;
	
	numero1.imprimir();
	
	
	
	/*
	while (op != 0)
	{
		op = programa.menu();
		double v;
		switch (op)
		{
			case 0:
				break;
			case 1:
				std::cout<< "Valor? ";
				std::cin >> v;
				numero.insertar(v);
				break;
			case 2:
				numero.imprimir();
				break;
			case 3:
				std::cout<< "Valor? ";
				std::cin >> v;
				if (numero.hallar(v))
					std::cout << "Hallado"<< std::endl;
				else
					std::cout << "No Hallado" << std::endl;
				break;
			case 4:
				std::cout<< "Valor? ";
				std::cin >> v;
				if (numero.eliminar(v))
					std::cout << "Eliminado"<< std::endl;
				else
					std::cout << "No Hallado" << std::endl;
				break;
				
			default:
				std::cout<< "No valido" <<std::endl;
				programa.menu();
				break;
		}
	
	} 
	
	*/
	return 0;
}
