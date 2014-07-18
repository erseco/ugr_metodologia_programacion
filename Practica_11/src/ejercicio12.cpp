/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una secuencia indefinida de caracteres de la 
 *  entrada estandar y reciba como argumento desde la linea de ordenes un 
 *  dato de tipo char. El programa mostrara en la salida estandar el numero de 
 *  caracteres leidos de la entrada estandar iguales al argumento suministrado.
 *  
 *  Por ejemplo: cuenta_letra a < ElQuijote.txt mostrara el numero de caracteres 
 *  'a' que hay en ElQuijote.txt
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (istream & entrada, char c);

/************************************************/
// Programa Principal
int main (int argc, char **argv) {

    if (argc != 2) {
        cerr << "Error: Num. de params. erroneo\n";
        cerr << "Uso: " <<argv[0] << " <char> < ficheroE\n";
        exit(1); // Salimos con error
    } 


    char c = *argv[1];

    // Copiamos de cin
    copiar(cin, c);

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Suma los numeros de entrada en la salida
void copiar (istream & entrada, char c) {


    char char_leido;
    int sum = 0;

    // Vamos obteniendo palabras y conviertiendolas a int
    while (cin >> char_leido) {

        if (char_leido == c) {
            // Vamos sumando
            sum += 1; 
        }

    
    }

    // Pintamos la suma de los valores
    cout << sum << endl;

}
/************************************************/
