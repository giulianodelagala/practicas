#include <iostream>
#include <string>

using std::string; using std::cout;
using std::endl;
struct alfabeto
{
	unsigned int digito;
	string romano;
};

string intaromano (int numero)
{
	string cadena = "";
	
	alfabeto alfa[13];
	
	alfa[0].digito = 1000; alfa[0].romano = "M";
	alfa[1].digito = 900;  alfa[1].romano = "CM";
	alfa[2].digito = 500;  alfa[2].romano = "D";
	alfa[3].digito = 400;  alfa[3].romano = "CD";
	alfa[4].digito = 100;  alfa[4].romano = "C";	
	alfa[5].digito = 90;  alfa[5].romano = "XC";
	alfa[6].digito = 50;  alfa[6].romano = "L";
	alfa[7].digito = 40;  alfa[7].romano = "XL";
	alfa[8].digito = 10;  alfa[8].romano = "X";
	alfa[9].digito = 9;  alfa[9].romano = "IX";
	alfa[10].digito = 5;  alfa[10].romano = "V";
	alfa[11].digito = 4;  alfa[11].romano = "IV";
	alfa[12].digito = 1;  alfa[12].romano = "I";									
	
	if (numero ==0)
	{
		cadena = " No existe romano de cero"; 
		return  cadena;
	}
	int i = 0;

	while (numero != 0)
	{	
		if (numero >= alfa[i].digito)
		{
			cadena += alfa[i].romano;
			numero -= alfa[i].digito;
		}
		else 
		{
			i++;
		}
	}

	return cadena;
}

int ingreso_numero (int numero)
{
	std::cout <<"numero? ";
	std::cin >> numero;
	return numero;
}


int main()
{
	int numero = 0;
	numero = ingreso_numero(numero);
	string cadena = "";
	cadena = intaromano(numero);
	cout << cadena << endl;
	
	return 0;
}

   
		
		
		 
