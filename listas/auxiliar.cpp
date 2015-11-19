//auxiliar.cpp

#include "auxiliar.hpp" 
//#include "lista.hpp"
#include <iostream>

int Auxiliar::menu()
{
	int op;
	std::cout<< "Ingrese OP" << std::endl;
	std::cout<< "1.Insertar 2.Imprimir 3.Hallar 4.Eliminar 0.Salir " ; std::cin >> op;
	
	return op;
}
		 
		
	
