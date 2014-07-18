/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef LISTA
#define LISTA

typedef int TipoBase;

struct Nodo {
	TipoBase valor;
	Nodo *sig;
};
typedef Nodo * PNodo;


class Lista {

	//Atributos
private:

	PNodo lista;

public:
	//Constructores;
	Lista(void);
	Lista(int n);
	Lista(int n, TipoBase value);

	//Destructor
	~Lista();

	//Métodos
	void Insertar (TipoBase val, int pos);
	void Borrar (int pos);
	void Aniadir (TipoBase val);
	TipoBase ObtenerValor (int pos);
	void PonerValor (int pos, TipoBase val);
	void Inicializar(TipoBase value = 0);

	bool EstaVacia();
	int NumeroNodos();

	void CrearLista(int n);


	void PrintValues();

};


#endif