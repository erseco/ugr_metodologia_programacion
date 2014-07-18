/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Ampliar la clase Matriz2D-2 con los siguientes metodos:
 *
 *  a) Constructor de copia y sobrecarga del operador de asignacion, empleando 
 *		codigo reutilizable.
 *  b) Una sobrecarga alternativa del operador de asignacion, que recibe como 
 *		argumento un dato de tipo TipoBase e inicia toda la matriz al valor especificado.
 *  c) Sobregargar el operador () para que sirva de operador de acceso a los 
 *		elementos de la matriz dinamica y pueda actuar tanto como lvalue como rvalue.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include "Matriz2D_2.h"

using namespace std;

/*****************************************************************************/
// Programa Principal
int main() {

	// Creamos y probamos una matriz
	cout << "Matriz 2x2 con valor establecido en 0,0:" << endl;
	Matriz2D_2 matriz1 = Matriz2D_2(2);
	matriz1(0,0) = 9;
	matriz1.PrintValues();
	cout << endl;

	// Creamos y probamos una matriz
	cout << "Matriz copiada (y valor establecido en 1,0):" << endl;
	Matriz2D_2 matriz2 = matriz1;
	matriz2(1,0) = 8;
	matriz2.PrintValues();

	// Obtenemos un valor
    cout << "Obtenemos el valor de la posicion 0,0: " << matriz2(0,0) << endl;

    cout << "Matriz establecida a 0" << endl;
    matriz2 = 0;
	matriz2.PrintValues();    

	cout << "Esta vacia?: " << matriz2.EstaVacia() << endl;


	// Terminamos la ejecución del programa
	return (0);

}