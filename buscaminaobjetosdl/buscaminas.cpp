/*Rutina principal del Juego
 * 
 * 
 */

#include "juego.hpp"
#include "auxiliar.hpp"
#include "matriz.hpp"
#include "pantalla.hpp"

using std::cout;
using std::endl;

int main ()
{
    //declaraciones
    
    Juego game;
    
    int coor[2]; 
    int op, mx,my;
    const int dim = 32;
    
    bool salir = false;
    int x,y; //captura coordenadas pantalla
    
     // menu inicial

    op = game.menuinicial(op);
    Matriz mat(9, 9);
    
    switch (op)
    {
    case 1:
		mat.set_fil_col(9, 9);
		game.set_prob (0.15);
		mat.iniciar (game);
        break;
    case 2:
		mat.set_fil_col(12, 12);
		game.set_prob (0.18);
		mat.iniciar (game);
        break;
    case 3:
		mat.set_fil_col(15, 15);
		game.set_prob (0.20);
		mat.iniciar (game);
        break;
    default:
        cout << "Opcion no valida" <<endl;
        op = game.menuinicial(op);
        break;
    }
    
    // pantalla de juego inicial
    
    Pantalla screen (mat.get_fil(), mat.get_col() ); 
     
    
    if ( !screen.init() )
	{
		printf ( "Fallo en iniciar SDL! \n") ;
	}
	else
	{
		 //Initialize SDL_ttf
		if( TTF_Init() == -1 )
		{
			printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
		}		
		//cargar imagen
		if (! screen.loadMedia() )
		{
			printf( "Fallo cargar archivo!\n") ;
		}
		else
		{			
			//aplicar imagen
			SDL_PixelFormat* fmt = screen.gScreenSurface->format;

			if (( screen.gtile = SDL_ConvertSurface (screen.tile, fmt, 0)) == NULL)
			{
				cout << "Error";
			}
			 
			for (int i = 0; i <= screen.width; i+=dim)
			{
				screen.rec.x = i;
				for (int j = 0; j<= screen.height; j+= dim)
				{
					screen.rec.y = j;		
					SDL_BlitSurface (screen.gtile, NULL , screen.gScreenSurface, &screen.rec);
				}
			}
			
			//Actualizar surface
			SDL_UpdateWindowSurface( screen.gWindow);
			
			//Bucle hasta usuario cierra ventana
			
			while ( !salir and game.get_jugando() )
			{
				if( SDL_PollEvent( &screen.event ) )
				{
					if (screen.event.type == SDL_QUIT)
					{
						salir = true;
					}
					
					// Si Click
					
					if( screen.event.type == SDL_MOUSEBUTTONDOWN )
					{
						// Consigue coordenadas
						
						x = screen.event.button.x;
						y = screen.event.button.y;
						mx = y / dim;
						my = x / dim;
						
						//Si Click Izquierdo
						
						if( screen.event.button.button == SDL_BUTTON_LEFT )
						{
							if ( ! mat.descubierto(mx, my) and !mat.flag(mx,my) )
							{
								game.set_jugando( mat.quehay (mx, my, screen ) );					
							}
													
							//cout << "L" << mx << "," << my << std::endl;
						}
						
						//Si Click Derecho
						
						if( screen.event.button.button == SDL_BUTTON_RIGHT )
						{
							game.set_cuantas_flag ( mat.pon_flag (mx, my, game.get_cuantas_flag(), screen ));
							mat.aciertos(game, mx, my); 						
							//cout << "R" << mx << "," << my << std::endl;
							
						}
					}
				}
				if (game.get_cuantas_acertadas() == game.get_cuantas_minas() )
				{
					game.set_gano( true);
					game.set_jugando(false);
				}
				
			}
						
			if ( game.get_gano () )
			{
				cout << " GANASTE!!! " << endl;
				screen.refresca_gano();
				
			}
			else
			{
				cout << " ...PERDISTE " << endl;	
			}	
			cout << "Opcion 1.Otra vez 2.Salir?" ; std::cin >> op;
			if (op==1)
			{
				screen.close();
				main();
			}	
			
		}
	}
	
	//Liberar recursos y cerrar SDL
	screen.close();

    
    return 0;
}
