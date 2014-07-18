/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una serie indefinida de numeros enteros de la 
 *  entrada estandar y los copie, en orden inverso, en la salida estandar.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>

#include "pila.h"

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
// Copia los numeros entrada en la salida invertidos
void copiar (istream & entrada) {

    int c;
    Pila pila;

    // Vamos obteniendo palabras y conviertiendolas a int
    while (cin >> c) {
        // Las metemos en una pila
        pila += c;

    }

    // Recorremos la pila hasta que se vacie
    while (!pila.EstaVacia()) {
        // Vamos sacando valores de la pila
        cout << pila.SacarValor() << endl;
    }


}
/************************************************/
