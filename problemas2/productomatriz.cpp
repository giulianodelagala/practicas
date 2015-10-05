#include <iostream>

using namespace std;


void dimensiones (int &dim1, int &dim2)
{
	cout << "Ingrese dimensiones matriz" << endl;
	cout << "dim1? " ; cin >> dim1;
	cout << "dim2? " ; cin >> dim2;
	
	
}

void ingreso (int dim1, int dim2, int *mat) //mat[dim1][dim2][dim3][dim4]
{
	for (int i=0; i< dim1; i++)
	{
		for (int j=0; j<dim2; j++)
		{
			
			cout <<"[" << i << "]" <<"[" << j <<  "]= "; //<< *((((mat+i*dim2*dim3*dim4)+j*dim3*dim4)+k*dim4)+l);
			cin >> *((mat+i*dim2)+j);
		}
	}
}
		

	

void mostrar (int dim1, int dim2, int *mat) 
{
	for (int i=0; i< dim1; i++)
	{
		for (int j=0; j<dim2; j++)
		{
				
			cout <<"[" << i << "]" <<"[" << j << "]" << *((mat+i*dim2)+j) << endl;
			//cin >> *((((mat+i*dim2*dim3*dim4)+j*dim3*dim4)+k*dim4)+l);
		}
	}
}	
	
void producto (int dim1, int dim2, int *mat1, int *mat2, int *result)
{
	long multi;
	for (int i = 0; i < dim1; i++) // para la matriz resultado
	{
		multi = 0;
		for (int j = 0; j < dim1; j++) // para la matriz resultado
		{
			for (int k = j; k < dim1; k++)
			{
				//cout << *((mat1+j)+k);
				multi += *((mat1+j)+k) * *((mat2+k)+j);  
				cout << multi << endl;
				//*(*(result+i)+j) =
				//cout <<  mat1[i][k];  
			}
		}
	}
}

		


int main ()
{
	int dim1, dim2;
	dimensiones (dim1, dim2);
	
	int mat1[dim1][dim2];
	int mat2[dim2][dim1];
	int result[dim1][dim1];
	
	
	
	ingreso (dim1, dim2, *mat1);
	ingreso (dim2, dim1, *mat2);
	producto (dim1, dim2, *mat1, *mat2, *result);
	//mostrar (dim1, dim1, *result);
	
	//cout << "prueba" << mat[1][1][1][1];
	
	
	return 0;
}
