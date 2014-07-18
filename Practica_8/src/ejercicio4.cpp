/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Ampliar la clase Lista con los siguientes metodos:
 *
 *  a) Constructor de copia y sobrecarga del operador de asignacion, empleando 
 *      codigo reutilizable.
 *  b) Una sobrecarga alternativa del operador de asignacion, que recibe como 
 *      argumento un dato de tipo TipoBase e inicia toda la lista al valor especificado.
 *  c) Sobregargar el operador [] para que sirva de operador de acceso a los 
 *      elementos de la lista y pueda actuar tanto como lvalue como rvalue. 
 *      El indice hace referencia a la posicion, de tal manera que 1 indica el primer nodo, 2 el segundo, etc.)
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include "Lista.h"

using namespace std;

/*****************************************************************************/
// Programa Principal
int main() {

    // Declaramos un nuevo vector dinamico
    Lista lista1 = Lista(3);
    
    // Agregamos datos
    lista1[1] = 1;

    lista1.Insertar(12, 2);


    lista1.Aniadir(3);
    lista1.Aniadir(4);

    // Imprimimos los valores
    cout << "Lista con valores:" << endl;
    lista1.PrintValues();

    // Obtenemos el tamaño del vector
    cout << "Numero de nodos: " << lista1.NumeroNodos() << endl;

    // Cambiamos un valor
    int pos = 1;
    int val = 20;
    cout << "Establecemos el valor de la posicion " << pos << " a " << val << endl;
    lista1[pos] = val;

    // Obtenemos el valor cambiado
    cout << "Obtenemos el valor de la posicion " << pos << ": " << lista1[pos] << endl;

    // Creamos una lista a partir de una existente, la imprimimos, la asignamos a 0 y la volvemos a imprimir
    cout << "Creamos una lista a partir de una existente, la imprimimos, la asignamos a 0 y la volvemos a imprimir:" << endl;
    Lista lista2 = lista1;
    lista2.PrintValues();
    lista2 = 0;
    lista2.PrintValues();


    // Terminamos la ejecución del programa
    return (0);


}