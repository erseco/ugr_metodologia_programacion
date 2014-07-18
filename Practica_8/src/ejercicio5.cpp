/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Ampliar la clase Pila con los siguientes metodos:
 *
 *  a) Constructor de copia y sobrecarga del operador de asignacion, empleando 
 *      codigo reutilizable.
 * 
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include "Pila.h"

using namespace std;

/*****************************************************************************/
// Programa Principal
int main() {

    // Declaramos un nuevo vector dinamico
    Pila pila1 = Pila();
    
    // Agregamos datos
    pila1.Aniadir(1);
    pila1.Aniadir(2);
    pila1.Aniadir(3);
    pila1.Aniadir(4);

    //pila1.PrintValues();

    // Creando una pila nueva a partir de la anterior y mostrandola
    Pila pila2 = pila1;
    pila2.PrintValues();


    // Terminamos la ejecución del programa
    return (0);


}