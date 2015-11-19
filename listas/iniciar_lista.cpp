//iniciar_lista.cpp

#include "iniciar_lista.h"
#include <iostream>

template <typename T>
void Iniciar_lista <T>::insertar (T t)
{
	Lista <T> *p = inicio, *q = inicio, *r;
	while (p != 0)
	{
		q = p;
		p = p->post;
	}
	r = new Lista <T>;
	r->data = t;
	r->post = 0;
	if (inicio)
	{
		q-> post = r;
	}
	else
	{
		inicio = r;
	}
}

template<typename T>
int Iniciar_lista<T>::hallar (T t)
{
	Lista <T> *p = inicio, *q = inicio;
	while (p!=0)
	{
		q = p;
		p = p->post;
		if (q->data == t)
		{
			return 1;
		}
	}
	return 0;
}

template<typename T>
void Iniciar_lista<T>::imprimir ()
{
	Lista <T> *p = inicio, *q = inicio;
	while (p!=0)
	{
		q = p;
		p = p->post;
		std::cout << q->data << std::endl;
	}
}

template <typename T>
Iniciar_lista<T>::~Iniciar_lista()
{
	Lista<T> *p = inicio, *q;
	while (p!= 0)
	{
		q = p;
		p = p->post;
		delete q;
	}
	inicio = 0;
}

template <typename T>
Lista <T> *Iterador <T>::post()
{
	Lista<T> *p = cursor;
	if (cursor)	cursor = cursor->post;
	return p;
}


template class Iniciar_lista <double>;
template class Lista <double>;
template class Iterador <double>;

template class Iniciar_lista <char *>;
template class Lista <char *>;
template class Iterador <char *>;

		
		
	
