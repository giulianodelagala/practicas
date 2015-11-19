//pila.cpp

#include "pila.hpp"
#include <iostream>

//constructor
template <typename T>
Inicio_pila<T>::Inicio_pila()
{
	inicio =0;
	fin = 0;
}


template <typename T>
void Inicio_pila <T>::insertar (T t)
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
		fin = r;
	}
	else
	{
		inicio = r;
	}
}

template<typename T>
bool Inicio_pila<T>::hallar (T t)
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
bool Inicio_pila<T>::eliminar ()
{
	Nodo <T> *p = inicio, *q = inicio;
	while (p != fin)
	{
		q = p;
		p = p->next;
	}
		
	if (fin != inicio )
	{
		fin = q;
		q->next = NULL;
		delete p;
		
		return true;
		
	}
	
	else 
	{
		delete q;
	}
	
	return false;
	
}


template<typename T>
void Inicio_pila<T>::imprimir ()
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
Inicio_pila<T>::~Inicio_pila()
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

template class Inicio_pila <double>;
template class Nodo <double>;
//template class Iterador <double>;

template class Inicio_pila <char *>;
template class Nodo <char *>;
//template class Iterador <char *>;

		
		
	
