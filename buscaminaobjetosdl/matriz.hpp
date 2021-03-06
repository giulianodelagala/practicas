//matriz.h
/*
 * Matriz de Juego
 * Atributos:
 * 
 * Define un vector de vectores contienendo la Clase Cuadrado
 * 
 * 
 * 
 * */

#ifndef __matriz_hpp__
#define __matriz_hpp__

#include "matrix.hpp"
#include "cuadrado.hpp"
#include "auxiliar.hpp"
#include "juego.hpp"
#include "pantalla.hpp"

#include <vector>
#include <cstdlib>
#include <iostream>

//class Juego;

class Matriz : public Matrix
{
	private :
		
		std::vector <std::vector <Cuadrado> > _matriz ;
			
	public :
	
		friend class Pantalla;
		
		//getters
		
		std::vector <std::vector <Cuadrado> > get_matriz();

		//setter

			
		// Constructor
			
		Matriz(int fil, int col);
		
		// Metodos
		
		
		void iniciar (Juego &game);
		void vecindad ();
		void aciertos (Juego &game, int mx, int my);
		bool quehay (int mx, int my, Pantalla screen );
		int pon_flag (int mx, int my, int cuantasFlag, Pantalla screen);
		bool descubierto (int mx, int my );
		int vecinas (int mx, int my );
		bool flag (int mx, int my );
		void revelar_bomba(Pantalla screen);
		
		//Impresores de comprobacion
		
		void imprimemina ();
		void imprimeVec ();
		void imprimeDes ();
	
};

#endif
