#include <iostream>
#include <vector>
//#include <SDL2/SDL.h>
#include <stdio.h>
#include <cstdlib>
//#include <random>

using namespace std;

struct opciones
{

    int fil;
    int col;
    float prob;

};

struct cuadrado
{
    bool mina = false;
    bool descubierto = false;
    bool hayFlag = false;
    int minasVecinas =0;

};


struct opciones menuinicial (opciones elec)
{
    int op;
    cout << "Buscaminas" <<endl << "Ingrese el número de opcion:" <<endl
         <<  "1.Facil 2.Medio 3.Dificil" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        elec.fil = 9;
        elec.col = 9;
        elec.prob = 0.15;
        break;
    case 2:
        elec.fil = 12;
        elec.col = 12;
        elec.prob = 0.25;
        break;
    case 3:
        elec.fil = 15;
        elec.col = 15;
        elec.prob = 0.35;
        break;
    default:
        cout << "Opcion no valida" <<endl;
        menuinicial(elec);
        break;
    }
    return elec;
};

unsigned time_seed()
{
    time_t now = time(0);
    unsigned char *p = (unsigned char *)&now;
    unsigned seed = 0;

    for (size_t i = 0; i < sizeof now; i++)
    {
        seed = seed * (now) + p[i];
    }

    return seed;
}


int creaMat (vector <vector <cuadrado> > &mat,int fil, int col,float prob)
{
    time_t t;
    int cuantas=0;
    //cout << prob << "en creamat" << endl;
    for (int i=0; i<fil;i++)
    {
        for (int j=0; j<col; j++)
        {
            srand(time_seed()+i*i-j);
            float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            //random_device seed;
            //mt19937 gen(seed());
            //uniform_int_distribution<int> dist(0, 100);


            //cout << x << endl;
            if (x < prob)
            {
                mat[i][j].mina = true;
                cuantas++;

                // *(*(Mat +i)+j)->mina ;
                //juego.cuantas_minas ++
            }
            //cout << mat[i][j].mina << endl;
        }
    }
    return cuantas;
}

void vecindad (vector <vector <cuadrado> > &mat,int fil, int col)
{
    for (int x = 0; x< fil; x++)
    {
        for (int y=0;y<col; y++)
        {
            for (int i=x-1; i <x+2;i++)
            {
                for (int j= y-1; j<y+2; j++)
                {
                    if (i>=0 and i < fil and j>=0 and j< col)
                    {
                        if (x != i or y != j)
                        {
                            if (mat[x][y].mina)
                            {
                                //cout<< "ingrese";
                                mat[i][j].minasVecinas++ ;
                            }

                        }
                    }
                }
            }
        }
    }
}

void imprime (vector <vector <cuadrado> > mat,int fil, int col)
{
    for (int i=0; i<fil;i++)
    {
        for (int j=0; j<col; j++)
        {
            cout << mat[i][j].mina << " ";

        }
        cout << endl ;
    }

}

void imprimeVec (vector <vector <cuadrado> > mat,int fil, int col)
{
    for (int i=0; i<fil;i++)
    {
        for (int j=0; j<col; j++)
        {
            cout << mat[i][j].minasVecinas << " ";

        }
        cout << endl ;
    }
}

void imprimeDes (vector <vector <cuadrado> > mat,int fil, int col)
{
    for (int i=0; i<fil;i++)
    {
        for (int j=0; j<col; j++)
        {
            cout << mat[i][j].descubierto << " ";

        }
        cout << endl ;
    }
}


void imprimePantalla (vector <vector <char> > pantalla,int fil, int col)
{
    //marco superior
    system("clear");
    cout << "  ";
    for (int i=0;i<col;i++ )
    {
        cout << i << " ";
    }
    cout<< endl;

    //matriz de juego
    for (int i=0; i<fil;i++)
    {
        cout << i << " ";
        for (int j=0; j<col; j++)
        {
            cout << pantalla[i][j] << " ";

        }
        cout << endl ;
    }
}

void creaPantalla (vector <vector <char> > &pantalla,int fil, int col)
{
    for (int i=0; i< fil; i++)
    {
        for (int j=0; j<col; j++)
        {
            pantalla[i][j]= '#';
        }
    }

}

void refrescaPantalla (vector <vector <char> > &pantalla, vector <vector <cuadrado> > &mat, int fil, int col)
{
    char temp[1];
    char tempo;
    for (int i=0; i< fil; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (mat[i][j].descubierto and not mat[i][j].mina)
            {
                sprintf(temp, "%d", mat[i][j].minasVecinas);
                tempo = temp[0];
                pantalla[i][j]= tempo;
            }
            else if (mat[i][j].descubierto and mat[i][j].mina)
            {
                pantalla[i][j]= 'B';
            }
            else if (not mat[i][j].descubierto and mat[i][j].hayFlag)
            {
                pantalla[i][j] = 'F';
            }
            else if (not mat[i][j].descubierto and not mat[i][j].hayFlag)
            {
                pantalla[i][j] = '#';
            }


        }
    }

}

void ingresoCoor (int coor[2])
{
    cout << "Ingrese coordenadas" << endl;
    cout << "X? ";
    cin >> coor[0];
    cout << "Y? ";
    cin >> coor[1];

}

bool quehay (vector <vector <cuadrado> > &mat,int fil, int col, int mx, int my )
{
    if (mx>=0 and mx < fil and my >=0 and my < col)
    {
        if (mat[mx][my].mina)
        {
            mat[mx][my].descubierto = true;
            return false;

        }

        else if(not mat[mx][my].descubierto and not mat[mx][my].hayFlag) //incluir el la funcion hayflag
        {
             mat[mx][my].descubierto = true;
             if (mat[mx][my].minasVecinas == 0)
             {
                 quehay (mat,fil, col, mx+1, my );
                 quehay (mat,fil, col, mx, my+1 );
                 quehay (mat,fil, col, mx+1, my+1 );
                 quehay (mat,fil, col, mx-1, my );
                 quehay (mat,fil, col, mx-1, my+1 );
                 quehay (mat,fil, col, mx, my-1 );
                 quehay (mat,fil, col, mx-1, my-1 );
                 quehay (mat,fil, col, mx+1, my-1 );

             }


    return true;
        }
    }
}

int ponFlag (vector <vector <char> > &pantalla, vector <vector <cuadrado> > &mat, int mx, int my, int cuantasFlag)
{
   if (not mat[mx][my].descubierto)
   {
       if (not mat[mx][my].hayFlag)
       {
           mat[mx][my].hayFlag = true;
           return cuantasFlag ++;
       }
       else
       {
           mat[mx][my].hayFlag = false;
       }
   }
}

int menu(int op)
{
    cout << "B : Mina - F: Bandera" <<endl << "Ingrese el número de opcion:" <<endl
         <<  "1.Descubrir 2.Poner/Retirar Bandera" << endl;
    cin >> op;
    if (op != 1 and op!= 2)
    {
        cout << "Opcion no valida" <<endl;
        menu(op);
    }

    return op;
}

int aciertos (vector <vector <cuadrado> > &mat, int mx, int my, int cuantasAcertadas)
{
    if (mat[mx][my].mina and mat[mx][my].hayFlag)
    {
        cuantasAcertadas ++;
        //cout << "en aciertos" << cuantasAcertadas;
        return cuantasAcertadas ;
    }

    else if (mat[mx][my].mina and not mat[mx][my].hayFlag)
    {
        return cuantasAcertadas --;
    }
}



int main ()
{
    opciones elec;
    int coor[2];
    bool enJuego;
    int cuantasMinas;
    int cuantasFlag=0, cuantasAcertadas = 0;
    int op, mx,my;
    bool gano = false;

    elec = menuinicial(elec);

    //cuadrado mat[elec.fil][elec.col], (*ptrMat)[elec.col];
    vector <vector <cuadrado> > mat((elec.fil),vector<cuadrado>(elec.col));
    vector <vector <char> > pantalla((elec.fil),vector<char>(elec.col));
    // vector< vector<int> > vec(4, vector<int>(4));
    //ptrMat = mat;
    //cout << mat[0][0].mina; funciona en vector

    //value = *(ptrMat)->mina;
    //cout << "ptrMat" << ptrMat << endl;
    //cout << "Mat" << mat;
    //cout << "value" << value;

    //cout << Mat[0][0].mina << Mat[0][0].hayFlag;
    //
    //cuadrado **ptr = Mat;
    cuantasMinas = creaMat(mat, elec.fil, elec.col, elec.prob);

    //imprime (mat,elec.fil,elec.col);
    vecindad (mat,elec.fil,elec.col);
    imprimeVec (mat,elec.fil,elec.col);
    creaPantalla (pantalla,elec.fil, elec.col);
    imprimePantalla (pantalla,elec.fil,elec.col);

    do
    {
        op = menu(op);
        if (op==1)
        {
            ingresoCoor(coor);
            mx = coor[0];
            my = coor[1];
            enJuego = quehay (mat,elec.fil, elec.col, mx, my );
            //imprimeDes (mat,elec.fil, elec.col);
            refrescaPantalla (pantalla,mat, elec.fil, elec.col);
            imprimePantalla (pantalla,elec.fil,elec.col);

        }
        if (op==2)
        {
            ingresoCoor(coor);
            mx = coor[0];
            my = coor[1];
            cuantasFlag = ponFlag (pantalla, mat, mx, my, cuantasFlag);
            cuantasAcertadas = aciertos (mat, mx, my, cuantasAcertadas);

            refrescaPantalla (pantalla,mat, elec.fil, elec.col);
            imprimePantalla (pantalla,elec.fil,elec.col);
            //cout << "cuantas" << cuantasAcertadas;
        }
        if (cuantasAcertadas==cuantasMinas)
        {
            gano = true;
            enJuego=false;
        }


    }while (enJuego);

    if (not gano)
    {
        cout << "GAME OVER!!!";
    }

    else
        cout << "YOU WIN!!!";







    return 0;
}
