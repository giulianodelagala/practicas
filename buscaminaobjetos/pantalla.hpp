//pantalla.hpp

#ifndef __pantalla_hpp__
#define __pantalla_hpp__

#include "matrix.hpp"
#include "cuadrado.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

class Pantalla : public Matrix
{
	private:
	
		std::vector <std::vector <char> > _pantalla ;
	
	public :
	
	//ctor
	
		Pantalla(int fil, int col);
	
	//metodo

		void imprimir ();
		void refresca (std::vector <std::vector <Cuadrado> > mat);
	
};


#endif
