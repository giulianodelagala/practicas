//lista.hpp

template <typename T>
class Inicio_lista;

template <typename T>
class Iterador;

template <typename T>
class Nodo;

template <typename T>
class Nodo
{
	private:
		Nodo<T> *next; //puntero a sgte
		friend class Inicio_lista<T>; //compartir inicio
		//friend class Iterador <T>;
	
	public:
	
		T data;
		
};	                                                                                                                                                                                                                                                                                                                                                                 

template <typename T>
class Inicio_lista
{
	private:
		Nodo<T> *inicio; //puntero a inicio
		//friend class Iterador <T>;
	
	public:
	
	//constructor
		Inicio_lista();
	
	//destructor
		~Inicio_lista();
	
	//metodos
		void insertar (T t);
		bool hallar (T t); 
		void imprimir ();
		bool eliminar (T t);
		Inicio_lista<T> operator+ (Inicio_lista<T> b);
};

/*
template <typename T>
class Iterador
{
	private:
		
		Inicio_lista <T> *l;
		Lista<T> *cursor;
		
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
