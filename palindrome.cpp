#include <iostream>


using namespace std;

bool espalindrome (char *palabra, int i, int tamanio, int ultimo)
{
	//cout << palabra[0]; 


	if (tamanio <= 1)
	{return true;}
	else if (palabra[i] == palabra[ultimo])
	{
		cout << "i" << i << "tam=" << tamanio << "ul" << ultimo << endl;
		return espalindrome (palabra, i+1, tamanio-2, ultimo-1);
	}
	else
	{
	return false;}
}
	


int main ()
{
	bool palindrome = false;
	char palabra[] = {"2525252"};
	int tamanio = sizeof (palabra) -1;
	//cout << tamanio;
	
	palindrome = espalindrome(palabra, 0, tamanio, tamanio-1);
	if (palindrome)
	{
		cout << "palindrome";
	}
	else
	{
		cout << "no";
	}
	
	
	
	//cout << palabra[0];
	return 0;
}
