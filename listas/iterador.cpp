//iterador.cpp

#include "iterador.h"

template <class T>

Lista <T> *Iterador <T>::post()
{
	Lista<T> *p = cursor;
	if (cursor)
	{
		cursor = cursor->next;
	}
	return p;
}

template class Iterador <int>
	
