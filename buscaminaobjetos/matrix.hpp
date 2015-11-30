/* matrix.hpp Padre de
  matriz.cpp pantalla.cpp
  *  Atributos:
  *  fil, col : tamaño de la matriz 
  * 
  * 
*/

#ifndef __matrix_hpp__
#define __matrix_hpp__

class Matrix
{
	protected:
	
	//atributos	
		int _fil, _col;
	
	//getters
	
	public:
	
		int get_fil();
		int get_col();
	
	//setters
		
		void set_fil_col (int fil, int col);


};

#endif
