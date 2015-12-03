//matriz.cpp
#include "matriz.hpp"

//getters

std::vector <std::vector <Cuadrado> > Matriz::get_matriz()
{ return _matriz;}

//setter 

//definido en matrix.hpp

// Constructor
	
	
Matriz::Matriz(int fil = 9, int col = 9)
{
	
	_fil = fil;
	_col = col;
		
}

void Matriz::iniciar (Juego &game)
{
	/*Inicia matriz de juego, Modifica el atributo Cuadrado.mina
	 * de acuerdo al atributo Juego.prob de manera aleatoria
	 * Notese el uso previo de la funcion vector.resize para modificar el tamaño
	 * del vector de vectores y el uso del iterador.
	
	*/
	
	_matriz.resize (_fil);
	for (std::vector<std::vector<Cuadrado> >::iterator it = _matriz.begin(); it != _matriz.end(); ++it)
	{
		it->resize (_col);
	}
	 
	
	time_t t;
	
	for (int i=0; i<_fil;i++)
	{
		for (int j=0; j<_col; j++)
		{
			
			
			srand(time_seed()+i*i-j);
			float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			
			if (x < game.get_prob() )
			{
				_matriz[i][j].set_mina(true);
				game.set_cuantas_minas( game.get_cuantas_minas() +1);

			}
		}
	}
	vecindad();
}

void Matriz::vecindad ()
{
	/* Metodo que modifica el atributo Cuadrado.minasVecinas al 
	 * recorrer el contorno de cada "tile" de la Matriz de juego
	 * 
	 *  
	 * 
	 */
    for (int x = 0; x< _fil; x++)
    {
        for (int y=0;y < _col; y++)
        {
            for (int i=x-1; i < x+2; i++)
            {
                for (int j= y-1; j<y+2; j++)
                {
                    if (i>=0 and i < _fil and j>=0 and j< _col)
                    {
                        if (x != i or y != j)
                        {
                            if (_matriz[x][y].get_mina() )
                            {
                          
                                _matriz[i][j].set_minasVecinas
                                    (_matriz[i][j].get_minasVecinas()+1);
                            }

                        }
                    }
                }
            }
        }
    }
}

void Matriz::aciertos (Juego &game, int mx, int my)
{
	/*
	 * Metodo que modifica Juego._cuantas_acertadas al comprobar
	 * Matriz.Cuadrado.mina = Matriz.Pantalla.hayFlag
	 * 
	 * 
	 * 
	 */
	
    if (_matriz[mx][my].get_mina() and _matriz[mx][my].get_hayFlag() )
    {
        game.set_cuantas_acertadas (game.get_cuantas_acertadas() +1);
    }

    else if (_matriz[mx][my].get_mina() and not _matriz[mx][my].get_hayFlag() )
    {
        game.set_cuantas_acertadas (game.get_cuantas_acertadas() -1);
    }
}


bool Matriz::quehay (int mx, int my, Pantalla screen )
{
	/*Metodo que verifica si Cuadrado.mina es true
	 * modifica Matriz.Cuadrado.descubierto y devuelve un valor true
	 * 
	 * Si Cuadrado.mina es false y Cuadrado.mina.hayFlag es false
	 * modifica Matriz.Cuadrado.descubierto y se llama recursivamente 
	 * los alrededores del "tile"
	 * 
	 * 
	 */
    if (mx>=0 and mx < _fil and my >=0 and my < _col)
    {
		
        if (_matriz[mx][my].get_mina() )
        {
            _matriz[mx][my].set_descubierto(true);
            revelar_bomba (screen);
            
            return false;

        }

        else if(not _matriz[mx][my].get_descubierto() and not _matriz[mx][my].get_hayFlag() )
        {
             _matriz[mx][my].set_descubierto(true);
             //llamar a pantalla 
             screen.refresca(mx, my, _matriz[mx][my].get_minasVecinas() );
             
             if (_matriz[mx][my].get_minasVecinas() == 0)
             {
                 quehay (mx+1, my, screen );
                 quehay (mx, my+1, screen );
                 quehay (mx+1, my+1, screen );
                 quehay (mx-1, my, screen );
                 quehay (mx-1, my+1 , screen);
                 quehay (mx, my-1, screen );
                 quehay (mx-1, my-1, screen );
                 quehay (mx+1, my-1, screen );

             }


		return true;
        }
    }
}

bool Matriz::descubierto (int mx, int my )
{
	if ( _matriz[mx][my].get_descubierto() )
	{
		return true;
	}
	
	return false; 
	
}

int Matriz::vecinas (int mx, int my )
{
	 return _matriz[mx][my].get_minasVecinas() ;
	
}

bool Matriz::flag (int mx, int my )
{
	if ( _matriz[mx][my].get_hayFlag() )
	{
		return true;
	}
	
	return false; 
	
}

void Matriz::revelar_bomba(Pantalla screen)
{
	for (int i=0; i<_fil;i++)
	{
		for (int j=0; j<_col; j++)
		{
			if (_matriz[i][j].get_mina() )
			{
				screen.refresca_bomba(i, j);
			}
		}
	}
	
}


int Matriz::pon_flag (int mx, int my, int cuantas_flag, Pantalla screen)
{
	/*Metodo que modifica Pantalla.hayFlag 
	 * y setea Juego.cuantas_flag
	 * 
	 * 
	 */
   if (not _matriz[mx][my].get_descubierto() )
   {
       if (not _matriz[mx][my].get_hayFlag() )
       {
           _matriz[mx][my].set_hayFlag(true);
           
           screen.refresca_flag(mx, my);
           return cuantas_flag ++;
       }
       else
       {
           _matriz[mx][my].set_hayFlag(false);
           screen.refresca_tile(mx, my);
           return cuantas_flag --;
       }
   }
}

/*
 * Metodos usados para inspeccion y testeo del juego
 * 
 */
 
void Matriz::imprimemina ()
{
    for (int i=0; i< _fil; i++)
    {
        for (int j=0; j< _col; j++)
        {
            std::cout << _matriz[i][j].get_mina() << " ";

        }
        std::cout << std::endl ;
    }

}

void Matriz::imprimeVec ()
{
    for (int i=0; i< _fil;i++)
    {
        for (int j=0; j< _col; j++)
        {
            std::cout << _matriz[i][j].get_minasVecinas() << " ";

        }
        std::cout << std::endl ;
    }
}

void Matriz::imprimeDes ()
{
    for (int i=0; i< _fil;i++)
    {
        for (int j=0; j< _col; j++)
        {
            std::cout << _matriz[i][j].get_descubierto() << " ";

        }
        std::cout << std::endl ;
    }
}

