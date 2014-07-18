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

    cout << "Agregamos 1 y 3..." << endl;
    pila2 += 1;
    pila2 += 3;

    pila2.PrintValues();

    cout << "Quitamos los dos ultimos" << endl;
    --pila2;    
    pila2--;

    // NOTA: Hacemos el apaño de pila2^0 porque la mayoría de los 
    //compiladores toman ^como comparador binario y no dejan como unario

    cout << "El ultimo valor es: " << (pila2^0) << endl;

    // Agregamos un nuevo elemento usando la sobrecarga del operador << 
    pila2 << 20;


    pila2.PrintValues();


    // Terminamos la ejecución del programa
    return (0);


}