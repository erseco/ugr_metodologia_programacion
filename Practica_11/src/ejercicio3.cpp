/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 *	entrada estandar y muestre en la salida estandar el numero total de 
 *	caracteres leidos.
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
// Cuenta el numero de caracteres
void contar (istream & entrada) {

	char c;
	int total_caracteres = 1; // Empieza de 1 por la entrada adelantada

	c = entrada.get();

	while (!entrada.eof()) {

		// Incrementamos el sumatorio
		total_caracteres++;
		
		// Vamos leyendo caracteres hasta el fin del fichero
		c = entrada.get();

	} 

	// Mostramos el total de caracteres en la salida estándar
	cout << "Número total de caracteres: " << total_caracteres << endl;


}
/************************************************/
