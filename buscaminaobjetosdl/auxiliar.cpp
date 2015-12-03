//Implementacion de auxiliar.hpp

#include "auxiliar.hpp"
#include <iostream>
#include <sstream>
#include <string>

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

std::string stringify (int num)
{
	
	std::string result;//string which will contain the result
	std::ostringstream convert; // stringstream used for the conversion
	convert << num;//add the value of Number to the characters in the stream
	result = convert.str();
	return result;

}


