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
	Conjunto(const TipoBase valor);

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
	friend int NumeroNodos(const Conjunto & otro);


	friend bool ContieneElemento(const Conjunto & otro, TipoBase elemento);


	void PrintValues();

	// Operador de asignacion
	Conjunto & operator = (const Conjunto & otro);
	Conjunto & operator = (const TipoBase & defaultvalue);

	// Sobrecarga del operador []
	TipoBase & operator [] (int indice);

	// Sobrecarga de los operadores == y !=
	bool operator == (Conjunto & otro);
	bool operator != (Conjunto & otro);

	// Sobrecarga de los operadores +, - y *
	friend Conjunto operator + (Conjunto & c1, Conjunto & c2);
	friend Conjunto operator + (Conjunto & c1, TipoBase value);
	friend Conjunto operator + (TipoBase value, Conjunto & c1);

	Conjunto operator - (const Conjunto & otro);
	Conjunto operator - (TipoBase value);

	friend Conjunto operator * (Conjunto & c1, Conjunto & c2);
	friend Conjunto operator * (Conjunto & c1, TipoBase value);
	friend Conjunto operator * (TipoBase value, Conjunto & c1);

private:

	void LiberarMemoria(void);

	void ReservarMemoria(void);
	void CopiarDatos(const Conjunto & otro);

	bool SonIguales(const Conjunto & otro);
	
	void EliminarValor(TipoBase value);


};


#endif