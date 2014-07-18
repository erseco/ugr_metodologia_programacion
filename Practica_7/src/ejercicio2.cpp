/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Implementar la clase Matriz2D-1 para elementos de tipo TipoBase. De acuerdo con 
 * TipoBase establecer el valor nulo (0 si TipoBase es int, 0.0 si TipoBase es 
 * double o float, "" si TipoBase es string,. . . ). 
 *
 * Empleando la representacion basica conocida, se trata de implementar los siguientes metodos:
 *
 *  a) Constructor sin argumentos, que crea una matriz vacia.
 *  b) Constructor con un argumento, que crea una matriz cuadrada con el numero de filas y columnas indicado en el argumento.
 *  c) Constructor con dos argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo.
 *  d) Constructor con tres argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo argumento. Ademas inicia todas las casillas de la matriz al valor especificado con el tercer argumento.
 *  e) Destructor.
 *  f) Metodo (valor devuelto: bool) que consulta si la matriz esta vacia.
 * 	g) Metodos para escribir/leer un valor. Responderan a los prototipos:
		void PonValor (int fila, int col, TipoBase val);
		TipoBase LeeValor (int fila, int col);
 *	h) Metodo que inicializa todas las casillas de la matriz al valor indicado como argumento. Si no se especifica ninguno, inicia todas las casillas al valor nulo.
 * 	i) Escribir una funcion main() que permita probar la clase.
 *
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include "Matriz2D_1.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main() {

	//Creamos y probamos una matriz
	cout << "Matriz 2x2:" << endl;
	Matriz2D_1 matriz1 = Matriz2D_1(2);
	matriz1.PonValor(0, 0, 1);
	matriz1.PrintValues();
	cout << endl;

	//Creamos y probamos una matriz
	cout << "Matriz 4x3 con valor 2:" << endl;
	Matriz2D_1 matriz2 = Matriz2D_1(4,3,2);
	matriz2.PonValor(1, 1, 26);
	matriz2.PrintValues();
	cout << "Esta vacia?: " << matriz2.EstaVacia() << endl;


	//Terminamos la ejecución del programa
	return (0);

}