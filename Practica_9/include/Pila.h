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

	// Atributos
private:

	PNodo pila;

public:
	// Constructores;
	Pila(void);

	// Constructor de copia
	Pila(const Pila & otro);


	// Destructor
	~Pila();

	// Métodos
	void Aniadir (TipoBase val);
	TipoBase SacarValor();
	TipoBase ConsultarValor();
	
	bool EstaVacia();


	void PrintValues();
    // Operador de asignacion
    Pila & operator = (const Pila & otro);
    // Operador de asignacion
    Pila &  operator -- (const Pila & otro);

private:

	void LiberarMemoria();

    void ReservarMemoria();
	void CopiarDatos (const Pila & otro);

};


#endif