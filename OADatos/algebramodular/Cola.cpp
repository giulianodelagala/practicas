//Implementacion Clase Cola

#include "Cola.hpp"
#include <iostream>

//constructor
template <typename T>
Cola<T>::Cola()
{ mpInicio =0;}


//Metodos

template <typename T>
void Cola <T>::Insertar (T t)
{
	Nodo <T> *p_p = mpInicio, *p_q = mpInicio, *p_r;
	while (p_p != NULL)
	{
		p_q = p_p;
		p_p = p_p->mpNext;
	}
	p_r = new Nodo <T>;
	p_r->mData = t; 
	p_r->mpNext = NULL;
	if (mpInicio!=0)
	{
		p_q->mpNext = p_r;
	}
	else
	{
		mpInicio = p_r;
	}
}

template<typename T>
bool Cola<T>::Hallar (T t)
{
	Nodo <T> *p_p = mpInicio, *p_q = mpInicio;
	while (p_p!=NULL)
	{
		p_q = p_p;
		p_p = p_p->mpNext;
		if (p_q->mData == t)
		{
			return true;
			
		}
	}
	return false;
}


template<typename T>
bool Cola<T>::Eliminar ()
{
	Nodo <T> *p_p = mpInicio; 

	if (p_p != NULL)
	{
		if (p_p->mpNext != NULL)
		{
			mpInicio = p_p->mpNext;
			delete p_p;	
			
		}
		else
		{
			mpInicio = 0;
			delete p_p;
		}
		return true;
	}
	
	return false;
}


template<typename T>
void Cola<T>::Imprimir ()
{
	Nodo <T> *p_p = mpInicio, *p_q = mpInicio;
	while (p_p!=0)
	{
		p_q = p_p;
		p_p = p_p->mpNext;
		std::cout << p_q->mData <<  "  ";
	}
	std::cout << std::endl;
}

template<typename T>
T Cola<T>::GetData()
{
	Nodo <T> *p_p = mpInicio;
	//std::cout << p_p->mData << " ";
	return p_p->mData;
	
}


// Destructor

template <typename T>
Cola<T>::~Cola()
{
	Nodo<T> *p_p = mpInicio, *p_q;
	while (p_p!= 0)
	{
		p_q = p_p;
		p_p = p_p->mpNext;
		delete p_q;
	}
	mpInicio = 0;
}

//Inicializando Templates
template class Cola <double>;
template class Nodo <double>;

template class Cola <char *>;
template class Nodo <char *>;

template class Cola <int>;
template class Nodo <int>;
		
		
	
