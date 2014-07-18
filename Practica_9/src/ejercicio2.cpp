/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Ampliar la clase Matriz2D-1 con los siguientes metodos:
 *
 *  d) Sobregargar los operadores unarios + y -.
 *	e) Sobregargar los operadores binarios + y - para implementar la suma y resta 
 *		de matrices. Si los dos operadores son de tipo Matriz2D-1 solo se hara la 
 *		suma o la resta si las dos matrices tienen las mismas dimensiones. 
 *		Si no fuera asi, devolvera una matriz vacia. Se admite la posibilidad de 
 *		que algun operador fuera de tipo TipoBase.
 *		Importante: ninguno de los operandos se modifica.
 *	f) Sobregargar los operadores combinados +=, -=, *= y /= de manera que el 
 *		argumento explicito sea de tipo TipoBase y modifiquen la matriz convenientemente.
 *	g) Sobregargar los operadores == y != para comparar dos matrices dinamicas: 
 *		seran iguales si tienen el mismo numero de filas y columnas, y los contenidos 
 *		son iguales y en las mismas posiciones.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include "Matriz2D_1.h"

using namespace std;

/*****************************************************************************/
// Programa Principal
int main() {

	// Creamos y probamos una matriz
	cout << "Matriz 2x2 con valor establecido en 0,0:" << endl;
	Matriz2D_1 matriz1 = Matriz2D_1(2);
	matriz1(0,0) = 9;
	matriz1.PrintValues();
	cout << endl;

	// Creamos y probamos una matriz
	cout << "Matriz copiada (y valor establecido en 1,0):" << endl;
	Matriz2D_1 matriz2 = matriz1;
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