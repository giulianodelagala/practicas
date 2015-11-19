//lista.cpp

#include "lista.hpp"
#include <iostream>

//constructor
template <typename T>
Inicio_lista<T>::Inicio_lista()
{ inicio =0;}


template <typename T>
void Inicio_lista <T>::insertar (T t)
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
bool Inicio_lista<T>::hallar (T t)
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
bool Inicio_lista<T>::eliminar (T t)
{
	Nodo <T> *p = inicio, *q = inicio, *r;
	while (p!=NULL)
	{
		r = q;
		q = p;
		p = p->next;
		if (q->data == t)
		{
			if (q== inicio)
			{
				inicio = p;
				delete q;
			}
			else
			{
				r->next = p;
				delete q; 
			}
			
			
			return true;
		}
	}
	return false;
	
}


template<typename T>
void Inicio_lista<T>::imprimir ()
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
Inicio_lista<T>::~Inicio_lista()
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

template <typename T>
void Inicio_lista<T>::operator+(Inicio_lista<T> b)
{
	Nodo <T> *pb = b.inicio, *qb = b.inicio;
	
	//ubicamos data de b
	
	while (pb != NULL)
	{
		qb = pb;
		pb = pb->next;
		
		insertar (qb->data);
	}
	
}
	

template class Inicio_lista <double>;
//template class Inicio_lista <Inicio_lista>;
template class Nodo <double>;
//template class Iterador <double>;

template class Inicio_lista <char *>;
template class Nodo <char *>;
//template class Iterador <char *>;

		
		
	
