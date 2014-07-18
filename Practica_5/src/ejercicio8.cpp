/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Supongamos que para definir matrices bidimensionales dinamicas usamos una 
 * estructura como la que aparece en la figura 4(tipo Matriz2D-1). En los apuntes 
 * de clase se detalla como crear y liberar esta estructura.
 * Nota: Recuerde que los modulos que procesan estructuras de este tipo necesitan 
 * recibir como parametros el numero de filas y columnas de la matriz.
 *  
 *  a) Construir un modulo que lea del teclado fils×cols valores y los copie en la 
 *     matriz.
 *  b) Construir un modulo que muestre los valores guardados en la matriz.
 *  c) Construir un modulo que reciba una matriz de ese tipo, cree y devuelva una 
 *     copia.
 *  d) Construir un modulo que extraiga una submatriz de una matriz bidimensional 
 *     Matriz2D-1. Como argumento de la funcion se introduce desde que fila y 
 *     columna y hasta que fila y columna se debe realizar la copia de la matriz
 *     original. La submatriz devuelta es una nueva matriz.
 *  e) Construir un modulo que elimine una fila de una matriz bidimensional 
 *     Matriz2D-1. Obviamente, no se permiten “huecos” (filas vacias). El modulo 
 *     devuelve una nueva matriz.
 *  f) Construir un modulo como el anterior,pero que en vez de eliminar una fila,
 *     elimine una columna. El modulo devuelve una nueva matriz.
 *  g) Construir un modulo que devuelva la traspuesta de una matriz. La matriz 
 *     devuelta es una nueva matriz.
 *  h) Construir un modulo que reciba una matriz y la modifique, de tal manera 
 *     que “invierta” las filas: la primera sera la ultima, la segunda la
 *     penultima, y asi sucesivamente. El modulo devuelve una nueva matriz.
 *
 ******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <iomanip>
#include "Matriz2D_1.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main(){

	Matriz2D_1 m1; // "m1" matriz dinamicas 2D.
	int filas, cols;
	
	// Leer num. de filas y columnas
	cout << "Numero de filas : ";
	cin >> filas;
	cout << "Numero de columnas : ";
	cin >> cols;
	
	// Crear matrices dinamicas
	cout << "Creando Matriz ("<< filas << "X"<< cols << ")" << endl;
	m1 = CreaMatriz2D_1 (filas, cols);
	
	//Llena la matriz y muestra su contenido
	m1 = LlenarMatriz2D_1(m1, filas, cols);
	cout << endl << "Matriz Original:" << endl;
	PintaMatriz2D_1 (m1, filas, cols);


	//Copia la matriz y muestra su contenido
	Matriz2D_1 copia_m1 = CopiaMatriz2D_1(m1, filas, cols);
	cout << endl << "Copia Matriz:" << endl;
	PintaMatriz2D_1 (copia_m1, filas, cols);
	LiberaMatriz2D_1 (copia_m1, filas, cols);

	int desde = 0, hasta = 2;
	if (filas >= hasta && cols >= hasta) {
		//Crea una submatriz y muestra su contenido
		Matriz2D_1 sub_m1 = SubMatriz2D_1(m1, desde, desde, hasta, hasta);
		cout << endl << "Sub Matriz:" << endl;
		PintaMatriz2D_1 (sub_m1, hasta - desde, hasta - desde);
		LiberaMatriz2D_1 (sub_m1, hasta - desde, hasta - desde);
	}

	//Elimina una fila de la matriz y muestra su contenido
	Matriz2D_1 delf_m1 = EliminaFilaMatriz2D_1(m1, filas, cols, 0);
	cout << endl << "Matriz con fila eliminada:" << endl;
	PintaMatriz2D_1 (delf_m1, filas - 1, cols);
	LiberaMatriz2D_1 (delf_m1, filas - 1, cols);


	//Elimina una columna de la matriz y muestra su contenido
	Matriz2D_1 delc_m1 = EliminaColumnaMatriz2D_1(m1, filas, cols, 0);
	cout << endl << "Matriz con columna eliminada:" << endl;
	PintaMatriz2D_1 (delc_m1, filas, cols - 1);
	LiberaMatriz2D_1 (delc_m1, filas, cols - 1);


	//Obtiene la traspuesta de la matriz y muestra su contenido
	Matriz2D_1 tras_m1 = TraspuestaMatriz2D_1(m1, filas, cols);
	cout << endl << "Traspuesta Matriz:" << endl;
	PintaMatriz2D_1 (tras_m1, cols, filas);
	LiberaMatriz2D_1 (tras_m1, cols, filas);

	//Obtiene la inversa de la matriz y muestra su contenido
	Matriz2D_1 inv_m1 = InvierteMatriz2D_1(m1, filas, cols);
	cout << endl << "Matriz invertida:" << endl;
	PintaMatriz2D_1 (inv_m1, filas, cols);
	LiberaMatriz2D_1 (inv_m1, filas, cols);

	
	// Liberar la memoria ocupada
	cout << endl << "Liberando matriz" << endl;
	LiberaMatriz2D_1 (m1, filas, cols);


	return (0);

}