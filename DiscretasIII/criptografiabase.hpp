/* Clase Criptografia
 * 
 * 
 */

#include <iostream>
#include <string>

using std::string; 

class Criptografia
{
	private :
		int _clave;
	
	public:
		string _alfabeto;
		string cifrar (string msj_original);
		string descifrar (string msj_cifrado);
	
	//getter
		int get_clave();
	
	//setter
	
	//Ctor
		Criptografia(int clave);
		
		
};


