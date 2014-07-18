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

	// Atributos
private:

	PNodo lista;

public:
	// Constructores;
	Lista(void);
	Lista(int n);
	Lista(int n, TipoBase value);

	// Constructor de copia
	Lista(const Lista & otro);

	// Destructor
	~Lista();

	// Métodos
	void Insertar (TipoBase val, int pos);
	void Borrar (int pos);
	void Aniadir (TipoBase val);
	void AniadirOrdenado (TipoBase val);


	TipoBase ObtenerValor(int pos);

	void Inicializar(TipoBase value = 0);

	bool EstaVacia();
	int NumeroNodos();


	void PrintValues();

    // Operador de asignacion
    Lista & operator = (const Lista & otro);
    Lista & operator = (const TipoBase & defaultvalue);

    // Sobrecarga del operador []
	TipoBase & operator [] (const int indice);



    // Operadores relacionales
    bool operator == (const Lista & otro);
    bool operator != (const Lista & otro);
    bool operator  > (const Lista & otro);
    bool operator <= (const Lista & otro);
    bool operator  < (const Lista & otro);
    bool operator >= (const Lista & otro);

private:

	void LiberarMemoria();

    void ReservarMemoria (int n);
	void CopiarDatos (const Lista & otro);
	
};




#endif