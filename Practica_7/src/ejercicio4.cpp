/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Implementar la clase Lista para trabajar con listas (de tamaño arbitrario, y no 
 * definido a priori, cuyos nodos residen en el heap) de datos de tipo TipoBase. 
 * De acuerdo con TipoBase establecer el valor nulo (0 si TipoBase es int, 0.0 
 * si TipoBase es double o float, "" si TipoBase es string,. . . ).
 *
 * Proponer una representacion para la clase (basada en el almacenamiento de los 
 * nodos en memoria dinamica) e implementar los siguientes metodos:
 *
 *  a) Constructor sin argumentos, que crea una lista vacia.
 *  b) Constructor con un argumento, que crea una lista con un numero de nodos 
 *      indicado en el argumento.
 *  c) Constructor con dos argumentos, que crea una lista con un numero de nodo 
 *      indicado en el primer argumento. 
 *      Inicia todos los nodos de la lista al valor indicado en el segundo argumento.
 *  d) Destructor.
 *  e) Metodo (valor devuelto: bool) que consulta si la lista esta vacia.
 *  f) Metodo para consultar el numero de nodos de la lista.
 *  g) Metodo para insertar un valor en la lista. Modifica la lista. 
 *      Respondera al siguiente prototipo: 
 *      void Insertar (TipoBase val, int pos);
 *  h) Metodo para borrar un nodo en la lista. Respondera al siguiente prototipo: 
 *      void Borrar (int pos);
 *  k) Metodo para añadir un valor en la lista. 
 *      La adicion siempre se hace al final de la lista. Modifica la lista. 
 *      Respondera al siguiente prototipo:
 *      void Aniadir (TipoBase val);
 *  j) Metodos para leer/escribir un valor.
 *      TipoBase ObtenerValor (int pos);
 *      void PonerValor (int pos, TipoBase val);
 *  k) Metodo que inicializa todos los nodos al valor indicado como argumento. 
 *      Si no se especifica ninguno, inicia todos los nodos al valor nulo.
 *  l) Escribir una funcion main() que permita probar la clase.
 *
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include "Lista.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main() {

    //Declaramos un nuevo vector dinamico
    Lista lista1 = Lista(5);
    


    //Agregamos datos
    lista1.PonerValor(1, 1);

    lista1.Insertar(12, 2);


    lista1.Aniadir(3);
    lista1.Aniadir(4);

    //Imprimimos los valores
    cout << "Lista con valores:" << endl;
    lista1.PrintValues();

    cout << "Borramos un nodo" << endl;
    lista1.Borrar(2);

    //Obtenemos el tamaño del vector
    cout << "Numero de nodos: " << lista1.NumeroNodos() << endl;

    //Obtenemos el tamaño de los utilizados
    cout << "Esta vacia?: " << lista1.EstaVacia() << endl;

    //Cambiamos un valor
    int pos = 1;
    int val = 20;
    cout << "Establecemos el valor de la posicion " << pos << " a " << val << endl;
    lista1.PonerValor(pos, val);

    //Obtenemos el valor cambiado
    cout << "Obtenemos el valor de la posicion " << pos << ": " << lista1.ObtenerValor(pos) << endl;

    //Creamos una lista vacía, agregamos un valor y la imprimimos

    cout << "Creamos una lista vacía, agregamos un valor e imprimimos:" << endl;
    Lista lista2 = Lista(0);
    lista2.Aniadir(1);
    lista2.PrintValues();


    //Terminamos la ejecución del programa
    return (0);


}