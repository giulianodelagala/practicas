#include "CifradoModular.hpp"
#include "Modular.hpp"
#include "TxtFile.hpp"

#include <fstream>
#include <string>
#include <cerrno>
#include <string.h>
#include <iostream>

using std::cout; using std::cin;
using std::endl;

int SIZEASCII = 256;


int PruebaClave(int &kpr, int kpu)
{
	cout << "Ingrese clave privada"; cin >> kpr;
	cin.clear(); cin.sync(); cin.ignore();
	kpu = Modular::Inversar (kpr, SIZEASCII);
	if (kpu >= 0)
	{
		return kpu;
	}
	cout << "Clave no valida, intente con otro numero" << endl;
	PruebaClave (kpr, kpu);
}

int main()
{

	std::string cadena;
	char archivo[30];
	//archivo = "";
	cadena= "";
	int kpr, kpu; kpr = 1; kpu = 1;
		
	int opt; opt = 1;
	
	cout << "1.Cifrar 2.Descifrar"; cin >> opt;
	cin.clear(); cin.sync(); cin.ignore();
	
	switch (opt)
	{
		// Cifrado  
		case 1:
		{
			//get clave privada return clave publica
			
			kpu = PruebaClave(kpr, kpu);
			cout << "Su Clave Publica es: " << kpu << endl;
			
			//get archivo
			cout<< "archivo a cifrar? ";
			cin.getline (archivo, 30);
	
			try
			{
				cadena = TxtFile::GetFileContents(archivo);
			}
			catch (int e)
			{
				std::cout << "Error al intentar abrir archivo: " << strerror(e) << '\n';
				break;
			}
			
			cadena = CifradoModular::Cifrar(cadena, kpr, SIZEASCII);
			
			// guardado de archivo cifrado
			
			cout<< "guardar cifrado como? ";
			cin.getline (archivo, 30);
			try
			{
				TxtFile::SetFileContents(cadena, archivo);
			}
			catch (int e)
			{
				std::cout << "Error al intentar guardar archivo: " << strerror(e) << '\n';
			}
			break;
		}
		
		//Descifrado
		case 2:
		{
			//get archivo
			cout<< "archivo? ";
			cin.getline (archivo, 30);
			
			try
			{
				cadena = TxtFile::GetFileContents(archivo);
			}
			catch (int e)
			{
				std::cout << "Error al intentar abrir archivo: " << strerror(e) << '\n';
				break;
			}
			
			// solicitar clave publica
			
			cout << "Ingrese su clave publica" ; cin >> kpu;
			
			cadena = CifradoModular::Descifrar(cadena, kpu, SIZEASCII);
			
			//guardado archivo descifrado
			cout<< "guardar descifrado como? ";
			cin.clear(); cin.sync(); cin.ignore();
			cin.getline (archivo, 30);
			
			try
			{
				TxtFile::SetFileContents(cadena, archivo);

			}
			catch (int e)
			{
				std::cout << "Error al intentar guardar archivo: " << strerror(e) << '\n';
			}
			break;
		}
	
	}
	return 0;

}


