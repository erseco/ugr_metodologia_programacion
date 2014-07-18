/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 * 	entrada estandar y los copie en la salida estandar, exceptuando las vocales.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (istream & entrada);

/************************************************/
// Programa Principal
int main (int argc, char **argv) {

	// Copiamos de cin
	copiar(cin);

	// Terminamos la ejecución del programa
	return (0);
}
/************************************************/
// Copia la entrada en la salida omitiendo las vocales
void copiar (istream & entrada) {

	char c;

	c = entrada.get();

	while (!entrada.eof()) {

		if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && tolower(c) != 'o' && tolower(c) != 'u') {

			cout.put(c); 
		
		}		

		// Vamos leyendo caracteres hasta el fin del fichero
		c = entrada.get();

	}

	cout << endl; // Al final escribimos un salto

}
/************************************************/
