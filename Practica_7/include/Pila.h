/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef PILA
#define PILA

typedef int TipoBase;

struct Nodo {
	TipoBase valor;
	Nodo *sig;
};
typedef Nodo * PNodo;


class Pila {

	//Atributos
private:

	PNodo pila;

public:
	//Constructores;
	Pila(void);

	//Destructor
	~Pila();

	//Métodos
	void Aniadir (TipoBase val);
	TipoBase SacarValor();
	TipoBase ConsultarValor();
	
	bool EstaVacia();


	void PrintValues();

};


#endif