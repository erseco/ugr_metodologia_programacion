/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Ampliar la clase Cola con los siguientes metodos:
 *
 *  a) Constructor de copia y sobrecarga del operador de asignacion, empleando 
 *      codigo reutilizable.
 * 
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include "Cola.h"

using namespace std;

/*****************************************************************************/
// Programa Principal
int main() {

    // Declaramos un nuevo vector dinamico
    Cola cola1 = Cola();
    
    // Agregamos datos
    cola1.Aniadir(1);
    cola1.Aniadir(2);
    cola1.Aniadir(3);
    cola1.Aniadir(4);

    //cola1.PrintValues();

    // Creando una cola nueva a partir de la anterior y mostrandola
    Cola cola2 = cola1;
    cola2.PrintValues();



    // Terminamos la ejecución del programa
    return (0);


}