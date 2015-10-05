#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void ingreso (int *mat)
{
	for (int i = 0; i < 400000; i++)
	{
		*(mat+i) = rand() % 100;
	}
}



void imprime (int *mat)
{
	for (int i = 0; i < 400000; i++)
	{
		cout << *(mat+i) << " ";
	}
}

void ordena (int *mat)
{
	int temp;
	for (int i = 0; i < 400000; i++)
	{
		for (int j = i+1; j < 400000; j++)
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

void consort (int *mat)
{
	sort(mat, mat + 400000);
	
}

int main ()
{
	int mat[400000];
	ingreso (mat);
	//ordena (mat);
	consort (mat);
	imprime (mat);
	
	
	
	return 0;
}
