//Implementacion de auxiliar.hpp

#include "auxiliar.hpp"
#include <iostream>

//Semilla para la funcion Random
unsigned time_seed()
{
    time_t now = time(0);
    unsigned char *p = (unsigned char *)&now;
    unsigned seed = 0;

    for (size_t i = 0; i < sizeof now; i++)
    {
        seed = seed * (now) + p[i];
    }

    return seed;
}




