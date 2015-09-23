#include <iostream>

using namespace std;


void dimensiones (int &dim1, int &dim2, int &dim3, int &dim4)
{
	cout << "Ingrese dimensiones matriz" << endl;
	cout << "dim1? " ; cin >> dim1;
	cout << "dim2? " ; cin >> dim2;
	cout << "dim3? " ; cin >> dim3;
	cout << "dim4? " ; cin >> dim4;
	
}

void ingreso (int dim1, int dim2, int dim3, int dim4, int *mat) //mat[dim1][dim2][dim3][dim4]
{
	for (int i=0; i< dim1; i++)
	{
		for (int j=0; j<dim2; j++)
		{
			for (int k=0; k< dim3; k++)
			{
				for (int l=0; l<dim4; l++)
				{
					cout <<"[" << i << "]" <<"[" << j << "]"<<"[" << k << "]"<<"[" << l << "]= "; //<< *((((mat+i*dim2*dim3*dim4)+j*dim3*dim4)+k*dim4)+l);
					cin >> *((((mat+i*dim2*dim3*dim4)+j*dim3*dim4)+k*dim4)+l);
				}
			}
		}
	
	}
	
}

void mostrar (int dim1, int dim2, int dim3, int dim4, int *mat) //mat[dim1][dim2][dim3][dim4]
{
	for (int i=0; i< dim1; i++)
	{
		for (int j=0; j<dim2; j++)
		{
			for (int k=0; k< dim3; k++)
			{
				for (int l=0; l<dim4; l++)
				{
					cout <<"[" << i << "]" <<"[" << j << "]"<<"[" << k << "]"<<"[" << l << "]" << *((((mat+i*dim2*dim3*dim4)+j*dim3*dim4)+k*dim4)+l) << endl;
					//cin >> *((((mat+i*dim2*dim3*dim4)+j*dim3*dim4)+k*dim4)+l);
				}
			}
		}
	
	}
	
}



int main ()
{
	int dim1, dim2, dim3, dim4;
	dimensiones (dim1, dim2, dim3, dim4);
	
	int mat[dim1][dim2][dim3][dim4];
	
	
	
	ingreso (dim1, dim2, dim3, dim4, ***mat);
	mostrar (dim1, dim2, dim3, dim4, ***mat);
	
	//cout << "prueba" << mat[1][1][1][1];
	
	
	return 0;
}
