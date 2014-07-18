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

/*****************************************************************************/
// Constructor sin argumentos, que crea una matriz vacia.
Matriz2D_2::Matriz2D_2(void) {

	ReservarMemoria(0, 0);

}

/*****************************************************************************/
// Constructor con un argumento, que crea una matriz cuadrada con el numero de filas y columnas indicado en el argumento.
Matriz2D_2::Matriz2D_2(int n) {

	ReservarMemoria(n, n);

}

/*****************************************************************************/
// Constructor con dos argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo.
Matriz2D_2::Matriz2D_2(int f, int c) {

	ReservarMemoria(f, c);

}

/*****************************************************************************/
// Constructor con tres argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo argumento. Ademas inicia todas las casillas de la matriz al valor especificado con el tercer argumento.
Matriz2D_2::Matriz2D_2(int f, int c, TipoBase value) {

	ReservarMemoria(f, c);

	Inicializar(value);

}


/*****************************************************************************/
// Constructor de copia
Matriz2D_2::Matriz2D_2(const Matriz2D_2 & otro) {

	// Reserva de memoria para el vector
	ReservarMemoria(otro.filas, otro.columnas);

	// Copia de los valores del vector
	// y de los campos privados
	CopiarDatos(otro);

}

/*****************************************************************************/
// Destructor
Matriz2D_2::~Matriz2D_2() {

    // Liberamos la memoria usada
    LiberarMemoria();

}


/*****************************************************************************/
// Pedir memoria para alojar 
void Matriz2D_2::ReservarMemoria (int f, int c) {

	filas = f;
	columnas = c;

	// Declaramos una nueva matriz
	vector = new TipoBase*[filas];

	vector[0] = new  int [filas*columnas];  
	for(int i=1; i<filas ; i++) {
		vector[i] = vector[i-1] + columnas; 
	}


}

/*****************************************************************************/
void Matriz2D_2::Inicializar(TipoBase value) {

    for (int i=0; i<filas; i++) {
    	for (int h=0; h<columnas; h++) {

    		vector[i][h] = value;
    	}

    }

}

/*****************************************************************************/
// Metodo (valor devuelto: bool) que consulta si la matriz esta vacia.
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
// Pedir memoria para alojar 
void Matriz2D_2::LiberarMemoria() {


	delete [] vector[0];  //  Libera el vector de datos
	delete [] vector;     //  Libera el vector de punteros

}



/*******************************************************/
// Copiar campos privados y los coeficientes
void Matriz2D_2::CopiarDatos (const Matriz2D_2 & otro) {

	// Copia los campos privados
	filas = otro.filas;
	columnas = otro.columnas;

	// Copia los valores del vector
	for (int f=0; f<filas; f++){
		for (int c=0; c<columnas; c++) {
			vector[f][c] = otro.vector[f][c];
		}
	}
}

/*****************************************************************************/
// Operador de asignación
Matriz2D_2 & Matriz2D_2::operator = (const Matriz2D_2 & otro){

	if (this != &otro) { // Evitar autoasignacion

	    // Libera la memoria ocupada
	    LiberarMemoria();
	    // Reserva de memoria para los coeficientes
	    ReservarMemoria (otro.filas, otro.columnas);
	    // Copia los campos privados y los coeficientes
	    CopiarDatos(otro);

	}

    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignacion

}

/*****************************************************************************/
// Operador de asignación sobrecargado para asignar a todos los elementos 
// un valor por defecto
Matriz2D_2 & Matriz2D_2::operator = (const TipoBase & defaultvalue){

	Inicializar(defaultvalue);

    return (*this);  // Objeto implicito: parte
                 // izquierda de la asignacion


}

/*****************************************************************************/
// Sobrecarga del operador []
TipoBase & Matriz2D_2::operator () (const int fila, const int columna){

    return  vector[fila][columna];

}

/*****************************************************************************/
// Imprime los valores en la salida estándar
void Matriz2D_2::PrintValues() {

	for (int f=0; f<filas; f++) {
		for (int c=0; c<columnas; c++)
		  cout << setw(4) << vector[f][c]; //  acceso a un elemento
	  cout << endl; //  cada fila se muestra en una linea diferente
	} 

}


