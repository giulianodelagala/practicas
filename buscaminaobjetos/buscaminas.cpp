/*Rutina principal del Juego
 * 
 * 
 * 
 * 
 */


#include "juego.hpp"
#include "auxiliar.hpp"
#include "matriz.hpp"
#include "pantalla.hpp"

//#include <SDL2/SDL.h>

using std::cout;
using std::endl;

int main ()
{
    //declaraciones
    
    Juego game;
    int coor[2]; 
    int op, mx,my;
    
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
    screen.imprimir();
    
    // Loop de juego

    do
    {
        op = game.menu(op);
        if (op==1)
        {
            game.ingresoCoor(coor);
            mx = coor[0];
            my = coor[1];
            game.set_jugando( mat.quehay (mx, my ));
            screen.refresca (mat.get_matriz() );
            screen.imprimir();

        }
        if (op==2)
        {
            game.ingresoCoor(coor);
            mx = coor[0];
            my = coor[1];
            game.set_cuantas_flag ( mat.pon_flag (mx, my, game.get_cuantas_flag() ));
            mat.aciertos(game, mx, my); 

            screen.refresca (mat.get_matriz() );
            screen.imprimir();
        }
        
        if (game.get_cuantas_acertadas() == game.get_cuantas_minas() )
        {
            game.set_gano( true);
            game.set_jugando(false);
        }
       
    //Comprobacion de Fin de juego


    }while (game.get_jugando() );

    if (not game.get_gano() )
    {
        cout << "GAME OVER!!!";
    }

    else
        cout << "YOU WIN!!!";

    return 0;
}
