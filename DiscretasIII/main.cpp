/* Principal de Criptografia
 * 
 * 
 */

#include "criptografiabase.hpp"
 
string ingreso(string msj)
{
	std::cout << "msj? " ;
	std::cin >> msj;
	return msj;
}

void impresion(string msjcifrado)
{
	std::cout << "cifrado" << msjcifrado;
}

int main()
{
	Criptografia Emisor(5); //construir Clase con clave "5";
	string msj = ingreso (msj);
	
	string msjcifrado = Emisor.cifrar(msj);
	
	Criptografia Receptor(5);
	string msjoriginal = Receptor.descifrar(msjcifrado);
	
	
	
	
	return 0;
}
