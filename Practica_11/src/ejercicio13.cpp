/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 *  entrada estandar y reciba como argumento desde la linea de ordenes un dato 
 *  de tipo int.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (istream & entrada, int n);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    if (argc != 2) {
        cerr << "Error: Num. de params. erroneo\n";
        cerr << "Uso: " <<argv[0] << " <int> < ficheroE\n";
        exit(1); // Salimos con error
    } 

    int n = atoi(argv[1]);

    // Copiamos de cin
    copiar(cin, n);

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Suma los numeros de entrada en la salida
void copiar (istream & entrada, int n) {

    char palabra[256];
    int sum = 0;

    // Vamos obteniendo palabras y conviertiendolas a int
    while (cin >> palabra) {

        // Comprobamos la longitud de la palabra
        if (strlen(palabra) == n) {
            // Vamos sumando
            sum += 1; 
        }
    
    }

    // Pintamos la suma de los valores
    cout << sum << endl;

}
/************************************************/
