#include <iostream>
#include <sstream>

using namespace std;


bool espalindrome (string palabra, int i, int tamanio, int ultimo)
{
	//cout << palabra[0]; 


	if (tamanio <= 1)
	{return true;}
	else if (palabra[i] == palabra[ultimo])
	{
		//cout << "i" << i << "tam=" << tamanio << "ul" << ultimo << endl;
		return espalindrome (palabra, i+1, tamanio-2, ultimo-1);
	}
	else
	{
	return false;}
}
	




int main ()
{
	bool palindrome = false;
	long num;
	long mayor;
	int m1, m2;
	string palabra; 
	for (int i = 999; i > 10; i--)
	{
		for (int j = 999; j > 10; j--)
		{
			if (i ==999)
			{
				num = i*j;
				mayor = num;
			}
	
			num = i * j;
			//cout << num;
			ostringstream convert;   // stream used for the conversion
			convert << num;      // insert the textual representation of 'Number' in the characters in the stream
			palabra = convert.str();
			//cout << palabra;
			int tamanio = palabra.length();
			//cout << tamanio;
			
			palindrome = espalindrome(palabra, 0, tamanio, tamanio-1);
			if (palindrome)
			{
				//cout << i << " x " << j << "= ";
				//cout << num << " es palindrome";
				if (num > mayor)
				{
					mayor = num;
					m1 = i; m2 = j;
				}
				break;
			
			}
			
		}
	
		//if (palindrome)
		//break;
	}
	
	
	cout << m1 << " x " << m2 << "=" << mayor;
	//cout << palabra[0];
	return 0;
}
