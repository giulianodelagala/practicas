//Cola.hpp

template <typename T>
class Cola;

template <typename T>
class Nodo;

template <typename T>
class Nodo
{
	private:
		Nodo<T>* mpNext; //puntero a sgte
		friend class Cola<T>; 
	
	public:
	
		T mData; //Data de cada nodo
				
};	                                                                                                                                                                                                                                                                                                                                                                 

template <typename T>
class Cola
{
	private:
		Nodo<T> *mpInicio; //puntero a inicio
	
	public:
	
	//constructor
		Cola();
	
	//destructor
		~Cola();
	
	//metodos
		void Insertar (T t);
		bool Hallar (T t); 
		void Imprimir ();
		bool Eliminar ();
		T GetData();
};
