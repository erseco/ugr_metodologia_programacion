/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef CONJUNTO
#define CONJUNTO

typedef int TipoBase;

struct Nodo {
	TipoBase valor;
	Nodo *sig;
};
typedef Nodo * PNodo;


class Conjunto {

	// Atributos
private:

	PNodo conjunto;

public:
	// Constructores;
	Conjunto(void);
	Conjunto(TipoBase valor);

	// Constructor de copia
	Conjunto(const Conjunto & otro);

	// Destructor
	~Conjunto();

	// Métodos
	void Insertar (TipoBase val, int pos);
	void Borrar (int pos);
	void Aniadir (TipoBase val);

	void Inicializar(TipoBase value = 0);

	bool EstaVacia();
	int NumeroNodos();


	bool ContieneElemento(TipoBase elemento);


	void PrintValues();

    // Operador de asignacion
    Conjunto & operator = (const Conjunto & otro);
    Conjunto & operator = (const TipoBase & defaultvalue);

    // Sobrecarga del operador []
	TipoBase & operator [] (const int indice);



private:

	void LiberarMemoria(void);

    void ReservarMemoria(void);
	void CopiarDatos(const Conjunto & otro);
	
};




#endif