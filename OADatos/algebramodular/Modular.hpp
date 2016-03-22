/* clase algebra modular
 * 
 * 
 */
#include <iostream>

class Modular
{
	private:
		Modular() {}
	
	public:
		static int Sumar(int vA, int vB, int vModulo);
		static int Restar (int vA, int vB, int vmodulo);
		static int IsNegativo (int vA, int vModulo);
		static int Multiplicar (int vA, int vB, int vModulo);
		static int Inversar (int vA, int vModulo);
		
};
