/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 *  entrada estandar y “comprima” todas las lineas de esa secuencia, eliminando 
 *  los separadores que hubiera en cada linea. Solo se mantendra el caracter ’\n’
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
    char space = ' ';
    char tab = '\t';

    char c;

    c = entrada.get();

    while (!entrada.eof()) {

        // Imprimimos los caracteres que no sean un separador
        if (c != space && c != tab) {

            cout.put(c); 
        
        }       

        // Vamos leyendo caracteres hasta el fin del fichero
        c = entrada.get();

    }

    cout << endl; // Al final escribimos un salto

}
/************************************************/
