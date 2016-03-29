/* Implementacion CifradoModular
 * 
 * 
 * 
 */
 
#include "CifradoModular.hpp"



std::string CifradoModular::Cifrar(std::string cadena, int kpr, int SIZEASCII)
{
		for (std::string::iterator it = cadena.begin(); it != cadena.end(); ++it)
	{
		*it = Modular::Multiplicar (*it, kpr, SIZEASCII);
	}
	
	return cadena;
}

std::string CifradoModular::Descifrar(std::string cadena, int kpu, int SIZEASCII)
{
		for (std::string::iterator it = cadena.begin(); it != cadena.end(); ++it)
	{
		*it = Modular::Multiplicar (*it, kpu, SIZEASCII);
	}
	
	return cadena;
	
}
