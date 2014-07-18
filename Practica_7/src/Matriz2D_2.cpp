/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include "Matriz2D_2.h"

using namespace std;

//Constructor sin argumentos, que crea una matriz vacia.
Matriz2D_2::Matriz2D_2(void) {

	CreaMatriz(0, 0);

}

//Constructor con un argumento, que crea una matriz cuadrada con el numero de filas y columnas indicado en el argumento.
Matriz2D_2::Matriz2D_2(int n) {

	CreaMatriz(n, n);

}
//Constructor con dos argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo.
Matriz2D_2::Matriz2D_2(int f, int c) {

	CreaMatriz(f, c);

}

//Constructor con tres argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo argumento. Ademas inicia todas las casillas de la matriz al valor especificado con el tercer argumento.
Matriz2D_2::Matriz2D_2(int f, int c, TipoBase value) {

	CreaMatriz(f, c);

	Inicializar(value);

}

//Destructor
Matriz2D_2::~Matriz2D_2() {

    //Liberamos la memoria usada, mostramos un mensaje para depuracion
    cout << "Destruyendo..." << endl;

	delete [] vector[0];  // Libera el vector de datos
	delete [] vector;     // Libera el vector de punteros

}


/*****************************************************************************/
//Crea una matriz de las dimensiones pasadas como parámetro
void Matriz2D_2::CreaMatriz (int f, int c) {

	filas = f;
	columnas = c;

	//Declaramos una nueva matriz
	vector = new TipoBase*[filas];

	vector[0] = new  int [filas*columnas];  
	for(int i=1; i<filas ; i++) {
		vector[i] = vector[i-1] + columnas; 
	}


}

void Matriz2D_2::Inicializar(TipoBase value) {

    for (int i=0; i<filas; i++) {
    	for (int h=0; h<columnas; h++) {

    		vector[i][h] = value;
    	}

    }

}

/*****************************************************************************/
//Metodo (valor devuelto: bool) que consulta si la matriz esta vacia.
bool Matriz2D_2::EstaVacia() {

    for (int i=0; i<filas; i++) {
    	for (int h=0; h<columnas; h++) {

    		if (vector[i][h] != 0) {
    			return false;
    		} 
       	}

    }

    return true;

}

/*****************************************************************************/
//Metodo que pone un valor en la posicion indicada
void Matriz2D_2::PonValor (int fila, int col, TipoBase val) {

	vector[fila][col] = val;

}

/*****************************************************************************/
//Metodo que devuelve un valor de la posicion indicada
TipoBase Matriz2D_2::LeeValor (int fila, int col){

	return vector[fila][col];

}

/*****************************************************************************/
//Imprime los valores en la salida estándar
void Matriz2D_2::PrintValues() {

	for (int f=0; f<filas; f++) {
		for (int c=0; c<columnas; c++)
		  cout << setw(4) << vector[f][c]; // acceso a un elemento
	  cout << endl; // cada fila se muestra en una linea diferente
	} 

}


