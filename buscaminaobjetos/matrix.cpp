// matriz.cpp
// Definicion de matrix.hpp

#include "matrix.hpp"

//getters

int Matrix::get_fil()
{ return _fil;}

int Matrix::get_col ()
{ return _col;}


//setter

void Matrix::set_fil_col (int fil, int col)
{
	_fil = fil; _col=col;
}
