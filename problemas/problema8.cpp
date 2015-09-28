#include <iostream>

using namespace std;

void ingreso (int *mat)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "num" << i+1 << " "; cin >> *(mat+i);
	}
}

void imprime (int *mat)
{
	for (int i = 0; i < 10; i++)
	{
		cout << *(mat+i) << " ";
	}
}

void ordena (int *mat)
{
	int temp;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i+1; j < 10; j++)
		{
			if (*(mat+i) > *(mat+j))
			{
				temp = *(mat+i);
				*(mat+i) = *(mat+j);
				*(mat+j) = temp;
			}
		}
	} 
	
}

int main ()
{
	int mat[10];
	ingreso (mat);
	ordena (mat);
	imprime (mat);
	
	
	
	return 0;
}
