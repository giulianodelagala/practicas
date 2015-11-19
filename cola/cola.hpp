//cola.hpp

template <typename T>
class Inicio_cola;

template <typename T>
class Nodo;

template <typename T>
class Nodo
{
	private:
		Nodo<T> *next; //puntero a sgte
		friend class Inicio_cola<T>; //compartir inicio
		//friend class Iterador <T>;
	
	public:
	
		T data;
		//destructor
		
};	                                                                                                                                                                                                                                                                                                                                                                 

template <typename T>
class Inicio_cola
{
	private:
		Nodo<T> *inicio; //puntero a inicio
		//friend class Iterador <T>;
	
	public:
	
	//constructor
		Inicio_cola();
	
	//destructor
		~Inicio_cola();
	
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
		
		Inicio_cola <T> *l;
		Cola<T> *cursor;
		
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
