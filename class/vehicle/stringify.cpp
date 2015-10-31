#include "stringify.h"
#include <iostream>
#include <sstream>
#include <string>


//using namespace std;

std::string stringify (int num)
{
	
	std::string result;//string which will contain the result
	std::ostringstream convert; // stringstream used for the conversion
	convert << num;//add the value of Number to the characters in the stream
	result = convert.str();
	return result;

}
