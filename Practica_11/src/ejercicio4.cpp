/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 *	entrada estandar y muestre en la salida estandar el numero de lineas 
 *	no vacias que hay en esa secuencia.
 *
 *	Nota: Se entendera que una linea es vacia si contiene unicamente el caracter ’\n’
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void contar (istream & entrada);

/************************************************/
// Programa Principal
int main (int argc, char **argv) {

	contar(cin);

	// Terminamos la ejecución del programa
	return (0);
}
/************************************************/
// Cuanta las lineas no vacias
void contar (istream & entrada) {

	char c[256];
	int numero_lineas = 0;

	entrada.getline(c, 256);

	while (!entrada.eof()) {


		// Comprobamos que la linea no esté vacia
		if (strlen(c) > 0) {
			// Incrementamos el sumatorio
			numero_lineas++;
		}

		// Vamos leyendo líneas
		entrada.getline(c, 256);

	} 

	// Comprobamos que la linea no esté vacia
	if (strlen(c) > 0) {
		// Incrementamos el sumatorio
		numero_lineas++;
	}

	// Mostramos el total de lineas en la salida estándar
	cout << "Número total de lineas (no vacias): " << numero_lineas << endl;


}
/************************************************/
