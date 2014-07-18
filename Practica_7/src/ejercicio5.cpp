/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Implementar la clase Pila.
 * Una pila es una estructura de datos que permite la gestion de problemas en 
 * los que la gestion se realiza empleando un protocolo LIFO (last in first out).
 * Proponer una representacion para la clase (basada en el almacenamiento de los 
 * nodos en memoria dinamica) e implementar los siguientes metodos:
 *
 *  a) Constructor sin argumentos, que crea una pila vacia.
 *  b) Destructor.
 *  c) Metodo (valor devuelto: bool) que consulta si la pila esta vacia.
 *  d) Metodo para añadir un valor. La pila se modifica.
 *  e) Metodo para sacar un valor. Obtiene (devuelve) el elemento extraido. La pila se modifica.
 *  f) Metodo para consultar que elemento esta en el tope de la pila. La pila no se modifica. 
 *  g) Escribir una funcion main() que permita probar la clase.
 * 
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include "Pila.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main() {

    //Declaramos un nuevo vector dinamico
    Pila pila1 = Pila();
    
    //Obtenemos el tamaño de los utilizados
    cout << "Esta vacia?: " << pila1.EstaVacia() << endl;


    //Agregamos datos
    pila1.Aniadir(1);
    pila1.Aniadir(2);
    pila1.Aniadir(3);
    pila1.Aniadir(4);

    pila1.PrintValues();

    cout << "Sacando ultimo valor: " << pila1.SacarValor() << endl;
    cout << "Consultando ultimo valor: " << pila1.ConsultarValor() << endl;

    pila1.PrintValues();

    //Obtenemos el tamaño de los utilizados
    cout << "Esta vacia?: " << pila1.EstaVacia() << endl;


    //Terminamos la ejecución del programa
    return (0);


}