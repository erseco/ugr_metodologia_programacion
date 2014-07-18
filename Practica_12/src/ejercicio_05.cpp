/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Se trata de escribir un constructor para las clases Matriz2D_1 y Matriz2D_2 
 *  que reciba el nombre de un fichero con la estructura descrita y rellene las 
 *  casillas de la matriz con los datos contenidos en el fichero. Se sobreentiende 
 *  que los datos estan guardados por filas en el fichero.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>

#include "Matriz2D_1.h"
#include "Matriz2D_2.h"

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void llenar_matriz(char *nombrefichero);

/************************************************/
// Programa Principal
int main (int argc, char **argv) {


    // Debemos comprobar todos los ficheros pasados
    if (argc != 2) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <fichero entrada>" << endl;
        exit(1); // Salimos con error
    } 


    // Buscamos en el fichero actual
    llenar_matriz(argv[1]);

    // Terminamos la ejecución del programa
    return (0);
}

/************************************************/
// Crea un nuevo objeto de tipo Matriz2D_1 y Matriz2D_1 
// a  partir de un fichero, y luego los muestra en la 
// salida estándar
void llenar_matriz(char *nombrefichero) {

    cout << "Matriz2D_1..." << endl;
    Matriz2D_1 matriz1(nombrefichero);
    matriz1.PrintValues();

    cout << "Matriz2D_2..." << endl;
    Matriz2D_2 matriz2(nombrefichero);
    matriz2.PrintValues();

}
/************************************************/
