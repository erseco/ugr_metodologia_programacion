/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef MATRIZ2D_2
#define MATRIZ2D_2

typedef int TipoBase;


class Matriz2D_2 {

	//Atributos
private:
	TipoBase ** vector;
	int filas;
	int columnas;

public:
	//Constructores;
	Matriz2D_2(void);
	Matriz2D_2(int n);
	Matriz2D_2(int f, int c);
	Matriz2D_2(int f, int c, TipoBase value);

	//Destructor
	~Matriz2D_2();

	//Métodos
	bool EstaVacia();

	void PonValor (int fila, int col, TipoBase val);
	TipoBase LeeValor (int fila, int col);

	void Inicializar(TipoBase value = 0);

	void PrintValues();


private:

	void CreaMatriz(int fils, int cols);

};

#endif