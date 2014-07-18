/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef COLA
#define COLA

typedef int TipoBase;

struct Nodo {
	TipoBase valor;
	Nodo *sig;
};
typedef Nodo * PNodo;


class Cola {

	// Atributos
private:

	PNodo cola;

public:
	// Constructores;
	Cola(void);

	// Constructor de copia
	Cola(const Cola & otro);


	// Destructor
	~Cola();

	// Métodos
	void Aniadir (TipoBase val);
	TipoBase SacarValor();
	TipoBase ConsultarValor();
	
	bool EstaVacia();


	void PrintValues();

    // Operador de asignacion
    Cola & operator = (const Cola & otro);

private:

	void LiberarMemoria();

    void ReservarMemoria();
	void CopiarDatos (const Cola & otro);
};


#endif