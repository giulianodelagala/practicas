//cuadrado.h

/*
 * Clase que define cada "tile" del juego
 * 
 * 
 * */

#ifndef __cuadrado_hpp__
#define __cuadrado_hpp__

class Cuadrado
{
	private :
		bool _mina;
		bool _descubierto;
		bool _hayFlag;
		int _minasVecinas;
		
	public:
	
	//setter
	
	void set_mina (bool mina);
	void set_minasVecinas (int minasVecinas);
	void set_descubierto(bool descubierto);
	void set_hayFlag(bool hayFlag);
	
	//getters
	
	bool get_mina();
	bool get_descubierto();
	bool get_hayFlag();
	int get_minasVecinas();
	
		
	//constructor
		
	Cuadrado();
		

};

#endif
