/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea un fichero como los generados en los problemas 
 *  8, 9 y 10 y que muestre en la salida estandar la suma de todos esos numeros.
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
// Suma los numeros de entrada en la salida
void copiar (istream & entrada) {

    int c;
    int sum = 0;

    // Vamos obteniendo palabras y conviertiendolas a int
    while (cin >> c) {

        // Vamos sumando
        sum += c; 
    
    }

    // Pintamos la suma de los valores
    cout << sum << endl;

}
/************************************************/
