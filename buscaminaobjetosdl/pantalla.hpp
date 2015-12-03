//pantalla.hpp

#ifndef __pantalla_hpp__
#define __pantalla_hpp__

#include "matrix.hpp"
#include "cuadrado.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


class Pantalla : public Matrix
{
	//private:
	
	public :
		std::vector <std::vector <char> > _pantalla ;
		
		int width;
		int height;

		std::string texto = "texto";

		SDL_Window* gWindow = NULL;
		SDL_Surface* gScreenSurface =NULL;
		SDL_Surface* tile =NULL;
		SDL_Surface* gtile =NULL;
		SDL_Surface* bomba =NULL;
		SDL_Surface* flag =NULL;
		SDL_Surface* gano =NULL;
		SDL_Surface* textSurface = NULL;

		SDL_Rect rec = {0,0,0,0}; 

		SDL_Event event;

		TTF_Font *gFont = NULL;

		
	
	//public :
	
	//ctor
	
		Pantalla(int fil, int col);
	
	//metodo

		bool init();
		bool loadMedia();
		void close();
		
		void imprimir ();
		void refresca(int mx, int my, int vecinas);
		void refresca_bomba(int mx, int my);
		void refresca_flag(int mx, int my);
		void refresca_tile(int mx, int my);
		void refresca_gano();
	
};


#endif
