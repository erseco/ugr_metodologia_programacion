/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Implementar la clase Cola.
 * Una cola es una estructura de datos que permite la gestion de problemas en 
 * los que la gestion se realiza empleando un protocolo FIFO (first in first out).
 * Proponer una representacion para la clase (basada en el almacenamiento de los 
 * nodos en memoria dinamica) e implementar los siguientes metodos:
 *
 *  a) Constructor sin argumentos, que crea una cola vacia.
 *  b) Destructor.
 *  c) Metodo (valor devuelto: bool) que consulta si la cola esta vacia.
 *  d) Metodo para añadir un valor. La cola se modifica.
 *  e) Metodo para sacar un valor. Obtiene (devuelve) el elemento extraido. La cola se modifica.
 *  f) Metodo para consultar que elemento esta en el tope de la cola. La cola no se modifica. 
 *  g) Escribir una funcion main() que permita probar la clase.
 * 
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include "Cola.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main() {

    //Declaramos un nuevo vector dinamico
    Cola cola1 = Cola();
    
    //Obtenemos el tamaño de los utilizados
    cout << "Esta vacia?: " << cola1.EstaVacia() << endl;


    //Agregamos datos
    cola1.Aniadir(1);
    cola1.Aniadir(2);
    cola1.Aniadir(3);
    cola1.Aniadir(4);

    cola1.PrintValues();

    cout << "Sacando primer valor: " << cola1.SacarValor() << endl;
    cout << "Consultando primer valor: " << cola1.ConsultarValor() << endl;

    cola1.PrintValues();

    //Obtenemos el tamaño de los utilizados
    cout << "Esta vacia?: " << cola1.EstaVacia() << endl;


    //Terminamos la ejecución del programa
    return (0);


}