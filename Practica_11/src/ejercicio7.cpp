/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 *	entrada estandar y copie en la salida estandar las lineas que no comiencen 
 *	por el caracter #
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
// Copia la entrada en la salida omitiendo los separadores (excepto \n)
void copiar (istream & entrada) {

    // Definimos los literales de los separadores
    char newline = '\n';
    char sharp = '#';

    char c[256];

    entrada.getline(c, 256);

    while (!entrada.eof()) {

        // Comprobamos si el primer caracter del array es una #
        if (c[0] != sharp) {

            cout << c << endl; 
        
        }       

        // Vamos leyendo caracteres hasta el fin del fichero
	    entrada.getline(c, 256);

    }

}
/************************************************/
