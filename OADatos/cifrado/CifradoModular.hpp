/* CifradoModular.hpp
 * 
 * 
 * 
 */
 
#ifndef __CifradoModular_hpp__
#define __CifradoModular_hpp__

 
#include "Modular.hpp"
#include <string>

class CifradoModular
{
	public:
	
		// Metodos
		
		static std::string Cifrar(std::string cadena, int kpr, int SIZEASCII);
		static std::string Descifrar(std::string cadena, int kpu, int SIZEASCII);
			
	private:
		// Constructor
		
		CifradoModular(){}
		
	
	
};

#endif
