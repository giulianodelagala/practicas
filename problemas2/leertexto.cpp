#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    string STRING;
	ifstream infile;
	infile.open ("texto.txt");
    while(!infile.eof()) // To get you all the lines.
        {
	        getline(infile,STRING); // Saves the line in STRING.
	        cout<<STRING; // Prints our STRING.
        };
	infile.close();
	//system ("pause");
}
