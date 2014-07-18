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

    // Sobrecarga del operador combinado +=
    Pila & operator += (const TipoBase value);

	// Sobrecarga del operador unario -- (usamos las dos posibilidad --pila y pila--)
	Pila & operator -- (void);
	Pila & operator -- (TipoBase);

    // Sobrecarga del operador unario ^
	TipoBase operator ^ (TipoBase);

    // Sobreescribir el operador <<
	Pila & operator << (TipoBase);

private:

	void LiberarMemoria();

    void ReservarMemoria();
	void CopiarDatos (const Pila & otro);

};


#endif