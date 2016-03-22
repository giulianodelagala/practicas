/* Implementacion clase algebra modular
 * 
 * 
 */
 
#include "Modular.hpp"
#include "Cola.hpp"

int Modular::Sumar(int vA, int vB, int vModulo)
{
	int resultado;
	resultado = (vA + vB)% vModulo;
	//std::cout << "a: " << vA << std::endl;
	//std::cout << "b: " << vB << std::endl;
	//std::cout << "R: " << resultado << std::endl;
	if (resultado < 0)
	{
		resultado = IsNegativo(resultado, vModulo);
		return resultado;
	}
	return resultado; 
}

int Modular::Restar (int vA, int vB, int vModulo)
{
	int resultado;
	resultado = (vA - vB)% vModulo;
	if (resultado < 0)
	{
		resultado = IsNegativo(resultado, vModulo);
		return resultado;
	}
	
	return resultado; 
}

int Modular::IsNegativo (int vA, int vModulo)
{
	//corrige un numero negativo
	int resultado;
	resultado = vModulo + vA;
	return resultado;
}

int Modular::Multiplicar (int vA, int vB, int vModulo)
{
	int resultado;
	resultado = (vA * vB) % vModulo;
	if (resultado < 0)
	{
		resultado = IsNegativo(resultado, vModulo);
		return resultado;
	}
	return resultado; 
}

int Modular::Inversar (int vA, int vModulo)
{
	int k, cociente, resto, divisor, resto_pre;
	Cola <int> ColaCociente;
	k = 0; resto = -1;
	divisor=vA;
	cociente = vModulo;
	
	// rutina crea Cola de cocientes ColaQ , resto previo, paso k
	
	while (resto!=0)
	{
		resto_pre = resto;
		resto = cociente % divisor;
		cociente = cociente / divisor;
			
		ColaCociente.Insertar(cociente);
		
		cociente = divisor;
		divisor = resto;
		k++;
		//std::cout << "resto_pre"<< resto_pre ;
	}
	
	// Comprobacion si existe Inverso resto_pre = 1
	//std::cout << "fueraresto_pre"<< resto_pre ;
	if (resto_pre == 1) //existe Inverso en k+2, (rutina while agrega
	// un valor de mas, considerar k+1)
	{
		int p, q, paso;
		int inverso;
		inverso = -1;
		p = 0; q = 1;
		paso = 2;
		//std::cout << "k"<< k ;
		for (paso; paso < k + 1; paso++)
		{
			inverso = Restar(p, q*ColaCociente.GetData(), vModulo);
			//std::cout << "cociente" << ColaCociente.GetData() << std::endl;
			//std::cout << "inver" << inverso << std::endl;
			ColaCociente.Eliminar();
			p = q;
			q = inverso;
			
		}
		return inverso;
	}
	
	return -1;
	
	//std::cout << "resto" << resto_pre << std::endl;
	//ColaQ.Imprimir();
	
}
