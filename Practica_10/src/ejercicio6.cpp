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

    cout << "Agregamos 1 y 3..." << endl;
    cola2 += 1;
    cola2 += 3;

    cola2.PrintValues();

    cout << "Quitamos los dos ultimos" << endl;
    --cola2;    
    cola2--;

    // NOTA: Hacemos el apaño de cola2^0 porque la mayoría de los 
    //comcoladores toman ^como comparador binario y no dejan como unario

    cout << "El ultimo valor es: " << (cola2^0) << endl;

    // Agregamos un nuevo elemento usando la sobrecarga del operador << 
    cola2 << 20;


    cola2.PrintValues();


    // Terminamos la ejecución del programa
    return (0);


}