// juego.cpp
/*
 * Implementacion de jueo.hpp
 * 
 * */


#include "juego.hpp"
	
//constructor

Juego::Juego()
{
	 _cuantas_minas = 0;
	 _cuantas_acertadas = 0;
	 _jugando = true;
	 _cuantas_flag = 0;
	 _gano = false;
}

// metodos
//get
float Juego::get_prob () 
{ return _prob;}

int Juego::get_cuantas_minas()
{ return _cuantas_minas;}

int Juego::get_cuantas_acertadas()
{ return _cuantas_acertadas;}

bool Juego::get_jugando()
{ return _jugando;}

int Juego::get_cuantas_flag()
{ return _cuantas_flag;}

bool Juego::get_gano()
{ return _gano;}

//set

void Juego::set_prob (float prob)  
{ _prob = prob;}

void Juego::set_cuantas_minas(int cuantas_minas)
{ _cuantas_minas = cuantas_minas;}

void Juego::set_cuantas_acertadas (int cuantas_acertadas)
{ _cuantas_acertadas = cuantas_acertadas;}

void Juego::set_jugando(bool jugando)
{ _jugando = jugando;}

void Juego::set_cuantas_flag(int cuantas_flag)
{ _cuantas_flag = cuantas_flag;}

void Juego::set_gano(bool gano)
{ _gano = gano;}

//metodos
//Menu inicial de juego

int Juego::menuinicial (int op)
{
    std::cout << "Buscaminas" << std::endl << "Ingrese el número de opcion:" <<std::endl
         <<  "1.Facil 2.Medio 3.Dificil" << std::endl;
    std::cin >> op;
    
    return op;
    
}


int Juego::menu(int op)
{
    std::cout << "B : Mina - F: Bandera" <<std::endl << "Ingrese el número de opcion:" <<std::endl
         <<  "1.Descubrir 2.Poner/Retirar Bandera" << std::endl;
    std::cin >> op;
    if (op != 1 and op!= 2)
    {
        std::cout << "Opcion no valida" <<std::endl;
        menu(op);
    }

    return op;
}

void Juego::ingresoCoor (int coor[2])
{
    std::cout << "Ingrese coordenadas" << std::endl;
    std::cout << "X? ";
    std::cin >> coor[0];
    std::cout << "Y? ";
    std::cin >> coor[1];

}
