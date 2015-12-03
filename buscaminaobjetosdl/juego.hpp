/*
 * Clase Juego
 * Atributos propios:
 * 
 * prob: define la probabilidad de que un Cuadrado contenga una bomba
 * 	nos permite definir la dificultad del juego
 * 
 * jugando, gano: define si el juego esta en ejecucion, si hemos ganado 
 *  o perdido
 * 
 * Toma datos de la Clase Matriz:
 *  cuantas_minas
 *  cuantas_acertadas
 * 
 * Toma datos de la Clase Pantalla:
 *  cuantas flag
 * 
 * 
 * 
 * */


#ifndef __juego_hpp__
#define __juego_hpp__


#include <iostream>


class Juego
{
	private:
	
		float _prob;
		int _cuantas_minas;
		int _cuantas_acertadas;
		int _cuantas_flag;
		bool _jugando;
		bool _gano;
		
		
	public:
	
		friend class Matriz;
		
	//getters
		
		float get_prob ();
		int get_cuantas_minas();
		int get_cuantas_acertadas();
		int get_cuantas_flag();
		bool get_jugando();
		bool get_gano();
	
	//setters
		
		void set_prob (float prob);
		void set_cuantas_minas(int cuantas_minas);
		void set_cuantas_acertadas (int cuantas_acertadas);
		void set_cuantas_flag (int cuantas_flag);
		void set_jugando(bool jugando);
		void set_gano(bool gano);
		
		
	//metodos
	
		int menuinicial (int op);
		int menu(int op);
		void ingresoCoor (int coor[2]);
	
	//ctor	
	
		Juego();

};

#endif
