// Implementacion de pantalla.hpp

#include "pantalla.hpp"
#include "auxiliar.hpp"

//ctor

Pantalla::Pantalla(int fil, int col)
{
	/*Constructor de la Pantalla Inicial de juego
	 * 
	 * 
	 */
	_fil = fil; _col = col;
	
	width = 32 * fil;
	height = 32* col;
	
	
}

//metodos

void Pantalla::imprimir ()
{
	/*Metodo que imprime Pantalla de Juego
	 * 
	 * 
	 */
    //marco superior
    system("clear");
    std::cout << "  ";
    for (int i=0; i < _col; i++ )
    {
        std::cout << i << " ";
    }
    std::cout<< std::endl;

    //matriz de juego
    for (int i=0; i < _fil; i++)
    {
        std::cout << i << " ";
        for (int j=0; j < _col; j++)
        {
            std::cout << _pantalla[i][j] << " ";

        }
        std::cout << std::endl ;
    }
}

void Pantalla::refresca(int mx, int my, int vecinas)
{
	/*Metodo que refresca la Pantalla de juego a partir de los atributos
	 * de la Matriz de Juego
	 * 
	 * 
	 */
	
	texto = stringify (vecinas);
	rec = { (my*32)+6 , (mx*32) ,0,0}; 
	SDL_Color textColor = { 0, 0, 0 };	
	
	textSurface = TTF_RenderText_Solid( gFont, texto.c_str(), textColor );
	SDL_BlitSurface (textSurface, NULL , gScreenSurface, &rec);
	SDL_UpdateWindowSurface( gWindow);
    
}

void Pantalla::refresca_bomba(int mx, int my)
{
	rec = { (my*32), (mx*32) ,0,0}; 
	SDL_BlitSurface (bomba, NULL , gScreenSurface, &rec);
	SDL_UpdateWindowSurface( gWindow);
	
}

void Pantalla::refresca_flag(int mx, int my)
{
	rec = { (my*32) , (mx*32) ,0,0}; 
	SDL_BlitSurface (flag, NULL , gScreenSurface, &rec);
	SDL_UpdateWindowSurface( gWindow);
	
}

void Pantalla::refresca_tile(int mx, int my)
{
	rec = { (my*32) , (mx*32) ,0,0}; 
	SDL_BlitSurface (tile, NULL , gScreenSurface, &rec);
	SDL_UpdateWindowSurface( gWindow);
	
}

void Pantalla::refresca_gano()
{
	rec = { width/2-100 , height/2-80 ,0,0}; 
	SDL_BlitSurface (gano, NULL , gScreenSurface, &rec);
	SDL_UpdateWindowSurface( gWindow);
	
}


// Metodos SDL

bool Pantalla::init()
{
	bool success = true;
	
	
	//Iniciar SDL
	
	if ( SDL_Init ( SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL no pudo iniciar! SDL_Error: %s \n", SDL_GetError() );
		success = false;
	}
	else
	{
		//crear ventana
		gWindow = SDL_CreateWindow( "Buscaminas", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
		
		if ( gWindow == NULL)
		{
			printf( "Ventana no pudo ser creada! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//get surface
			gScreenSurface = SDL_GetWindowSurface ( gWindow);
		}
	}
	return success;
}

bool Pantalla::loadMedia()
{
	//carga exitosa
	bool success = true;
	
	//carga de imagen
	tile = SDL_LoadBMP( "button.bmp");
	if ( tile == NULL)
	{
		printf ( "No se pudo cargar imagen %s SDL Error: %s\n", "button.bmp", SDL_GetError() );
		success = false;
	}
	
	bomba = SDL_LoadBMP( "bomba.bmp");
	if ( bomba == NULL)
	{
		printf ( "No se pudo cargar imagen %s SDL Error: %s\n", "bomba.bmp", SDL_GetError() );
		success = false;
	}
	
	flag = SDL_LoadBMP( "flag.bmp");
	if ( bomba == NULL)
	{
		printf ( "No se pudo cargar imagen %s SDL Error: %s\n", "flag.bmp", SDL_GetError() );
		success = false;
	}
	
	gano = SDL_LoadBMP( "gano.bmp");
	if ( bomba == NULL)
	{
		printf ( "No se pudo cargar imagen %s SDL Error: %s\n", "gano.bmp", SDL_GetError() );
		success = false;
	}
	
	gFont = TTF_OpenFont( "LiberationMono-Regular.ttf", 28 );
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		
		textSurface = TTF_RenderText_Solid( gFont, texto.c_str(), textColor );

		if( textSurface == NULL )
		{
			printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
			success = false;
		}
		
	}
	
	
	return success;
}

void Pantalla::close()
{
	//liberar surface
	SDL_FreeSurface( gtile) ;
	gtile == NULL;
	
	//destruir ventana
	SDL_DestroyWindow (gWindow);
	gWindow = NULL;
	
	//Salir SDL
	SDL_Quit();
}
