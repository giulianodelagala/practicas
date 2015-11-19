//pila.hpp

template <typename T>
class Inicio_pila;

template <typename T>
class Nodo;

template <typename T>
class Nodo
{
	private:
		Nodo<T> *next; //puntero a sgte
		friend class Inicio_pila<T>; //compartir inicio
		//friend class Iterador <T>;
	
	public:
	
		T data;
		//destructor
		
};	                                                                                                                                                                                                                                                                                                                                                                 

template <typename T>
class Inicio_pila
{
	private:
		Nodo<T> *inicio; //puntero a inicio
		Nodo<T> *fin;    //puntero a fin
		//friend class Iterador <T>;
	
	public:
	
	//constructor
		Inicio_pila();
	
	//destructor
		~Inicio_pila();
	
	//metodos
		void insertar (T t);
		bool hallar (T t); 
		void imprimir ();
		bool eliminar ();
};

/*
template <typename T>
class Iterador
{
	private:
		
		Inicio_pila <T> *l;
		pila<T> *cursor;
		
	public:
		
		void reset()
		{
			cursor = l->inicio;
		}
		
	//constructor
	
		Iterador (Inicio_lista <T> *li)
		{
			l = li;
			reset();
		}
		
	//metodo
		
		Lista<T> *next();
};
	


#endif
*/
