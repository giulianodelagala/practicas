
#include <iostream>
#include <sstream>
#include <string>
#include "stringify.h"

using namespace std;

string stringify (int num)
{
	
	string Result;//string which will contain the result
	stringstream convert; // stringstream used for the conversion
	convert << num;//add the value of Number to the characters in the stream
	Result = convert.str();
	return Result;

}
