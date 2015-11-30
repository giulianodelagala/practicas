// Implementacion de pantalla.hpp

#include "pantalla.hpp"

//ctor

Pantalla::Pantalla(int fil, int col)
{
	/*Constructor de la Pantalla Inicial de juego
	 * 
	 * 
	 */
	_fil = fil; _col = col;
	
	_pantalla.resize (_fil);
	
	for (std::vector<std::vector<char> >::iterator it = _pantalla.begin(); it != _pantalla.end(); ++it)
	{
		it->resize (_col);
	}
	
    for (int i=0; i < _fil; i++)
    {
        for (int j=0; j < _col; j++)
        {
            _pantalla[i][j]= '#';
        }
    }

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

void Pantalla::refresca(std::vector <std::vector <Cuadrado> > mat)
{
	/*Metodo que refresca la Pantalla de juego a partir de los atributos
	 * de la Matriz de Juego
	 * 
	 * 
	 */
    char temp[1];
    char tempo;
    for (int i=0; i< _fil; i++)
    {
        for (int j=0; j < _col; j++)
        {
            if (mat[i][j].get_descubierto() and not mat[i][j].get_mina() )
            {
                sprintf(temp, "%d", mat[i][j].get_minasVecinas() );
                tempo = temp[0];
                _pantalla[i][j]= tempo;
            }
            else if (mat[i][j].get_descubierto() and mat[i][j].get_mina() )
            {
                _pantalla[i][j]= 'B';
            }
            else if (not mat[i][j].get_descubierto() and mat[i][j].get_hayFlag() )
            {
                _pantalla[i][j] = 'F';
            }
            else if (not mat[i][j].get_descubierto() and not mat[i][j].get_hayFlag() )
            {
                _pantalla[i][j] = '#';
            }
        }
    }
}
