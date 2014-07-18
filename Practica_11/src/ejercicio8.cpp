/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una serie indefinida de numeros enteros de la 
 *  entrada estandar y los copie, en el mismo orden, en la salida estandar.
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
// Copia los numeros entrada en la salida
void copiar (istream & entrada) {


    int c;

    // Vamos obteniendo palabras y conviertiendolas a int
    while (cin >> c) {

        // Pintamos el numero en la salida estandar con un salto de linea
        cout << c << endl; 
    
    }


}
/************************************************/
