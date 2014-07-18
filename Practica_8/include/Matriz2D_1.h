/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef MATRIZ2D_1
#define MATRIZ2D_1

typedef int TipoBase;


class Matriz2D_1 {

	// Atributos
private:
	TipoBase ** vector;
	int filas;
	int columnas;

public:
	// Constructores;
	Matriz2D_1(void);
	Matriz2D_1(int n);
	Matriz2D_1(int f, int c);
	Matriz2D_1(int f, int c, TipoBase value);

	// Constructor de copia
	Matriz2D_1(const Matriz2D_1 & otro);

	// Destructor
	~Matriz2D_1();

	// Métodos
	bool EstaVacia();

	void Inicializar(TipoBase value = 0);

	void PrintValues();

    // Operador de asignacion
    Matriz2D_1 & operator = (const Matriz2D_1 & otro);
    Matriz2D_1 & operator = (const TipoBase & defaultvalue);

    // Sobrecarga del operador ()
	TipoBase & operator () (const int fila, const int columna);

private:

	void LiberarMemoria();

    void ReservarMemoria (int fils, int cols);
	void CopiarDatos (const Matriz2D_1 & otro);


};

#endif