// cuadrado.cpp
/* Implementacion de cuadrado.hpp
 * 
 * 
 * */
#include "cuadrado.hpp"

//setter

void Cuadrado::set_mina (bool mina)
{
	_mina = mina;
}

void Cuadrado::set_minasVecinas (int minasVecinas)
{
	_minasVecinas = minasVecinas;
}

void Cuadrado::set_descubierto (bool descubierto)
{
	_descubierto = descubierto;
}

void Cuadrado::set_hayFlag(bool hayFlag)
{
	_hayFlag = hayFlag;
}

//getter
bool Cuadrado::get_mina()
{return _mina;}

bool Cuadrado::get_descubierto()
{return _descubierto;}

bool Cuadrado::get_hayFlag()
{return _hayFlag;}

int Cuadrado::get_minasVecinas()
{return _minasVecinas;}

//constructor
Cuadrado::Cuadrado()
{
	_mina = false;
	_descubierto = false;
	_hayFlag = false;
	_minasVecinas =0;
}

