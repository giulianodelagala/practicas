//cola.cpp

#include "cola.hpp"
#include <iostream>

//constructor
template <typename T>
Inicio_cola<T>::Inicio_cola()
{ inicio =0;}


template <typename T>
void Inicio_cola <T>::insertar (T t)
{
	Nodo <T> *p = inicio, *q = inicio, *r;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		//std::cout << "contenido " << p << std::endl; 
	}
	r = new Nodo <T>;
	r->data = t; 
	r->next = NULL;
	//std::cout << "contenido " << inicio << std::endl;
	if (inicio!=0)
	{
		q->next = r;
	}
	else
	{
		inicio = r;
	}
}

template<typename T>
bool Inicio_cola<T>::hallar (T t)
{
	Nodo <T> *p = inicio, *q = inicio;
	while (p!=NULL)
	{
		q = p;
		p = p->next;
		if (q->data == t)
		{
			//std::cout << q << std::endl;
			//std::cout << inicio << std::endl;
			return true;
			
		}
	}
	return false;
}


template<typename T>
bool Inicio_cola<T>::eliminar ()
{
	Nodo <T> *p = inicio, *q = inicio;

	//p = p->next;
	//std::cout << "pdata" << p->data;
	if (p != NULL)
	{
		//std::cout << "p es no null";
		if (p->next != NULL)
		{
			//std::cout << "p next no null";
			inicio = p->next;
			delete p;	
			
		}
		else
		{
			inicio = 0;
			delete p;
		}
		return true;
		
	}
	
	return false;
	
}


template<typename T>
void Inicio_cola<T>::imprimir ()
{
	Nodo <T> *p = inicio, *q = inicio;
	while (p!=0)
	{
		q = p;
		p = p->next;
		std::cout << q->data <<  "  ";
	}
	std::cout << std::endl;
}

template <typename T>
Inicio_cola<T>::~Inicio_cola()
{
	Nodo<T> *p = inicio, *q;
	while (p!= 0)
	{
		q = p;
		p = p->next;
		delete q;
	}
	inicio = 0;
}

/*
template <typename T>
Nodo <T> *Iterador <T>::next()
{
	Nodo<T> *p = cursor;
	if (cursor)	cursor = cursor->next;
	return p;
}
*/

template class Inicio_cola <double>;
template class Nodo <double>;
//template class Iterador <double>;

template class Inicio_cola <char *>;
template class Nodo <char *>;
//template class Iterador <char *>;

		
		
	
