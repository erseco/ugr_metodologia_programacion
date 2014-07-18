/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Implementa una clase Conjunto que permita manipular un conjunto de elementos 
 * de tipo TipoBase. 
 * Para la representacion interna de los datos usar una conjunto de celdas enlazadas. 
 * El orden de los elementos no es importante desde un punto de vista teorico, 
 * pero aconsejamos que se mantengan los elementos ordenados para facilitar la 
 * implementacion de los metodos de la clase.
 * 
 * La clase Conjunto debe contener, al menos, las siguientes operaciones:
 * a) Constructor sin argumentos: crea un conjunto vacio.
 * b) Constructor con un argumento de tipo TipoBase: crea un conjunto con un unico elemento (el proporcio- nado como argumento).
 * c) Constructor de copia (empleando codigo reutilizable).
 * d) Destructor (empleando codigo reutilizable).
 * e) Metodo que consulta si el conjunto esta vacio.
 * f) Sobrecarga del operador de asignacion (empleando codigo reutilizable).
 * g) Metodo que nos diga cuantos elementos tiene el conjunto.
 * h) Metodo que reciba un dato de tipo TipoBase y consulte si pertence al conjunto.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include "Conjunto.h"

using namespace std;

/*****************************************************************************/
// Programa Principal
int main() {

    // Declaramos un nuevo vector dinamico
    Conjunto conjunto1 = Conjunto(3);
    
    // Agregamos datos
    conjunto1.Aniadir(3);
    conjunto1.Aniadir(4);
    conjunto1[1] = 1;

    conjunto1.Aniadir(6);
    conjunto1.Aniadir(10);

    //Creamos un nuevo conjunto usando el constructor de copia
    Conjunto conjunto2 = conjunto1;

    // Imprimimos los valores
    cout << "Conjunto con valores:" << endl;
    conjunto1.PrintValues();

    // Obtenemos el tamaño del vector
    cout << "Numero de elementos: " << conjunto1.NumeroNodos() << endl;

    // Cambiamos un valor
    int pos = 1;
    int val = 20;
    
    cout << "Contiene elemento " << val << "?: " << conjunto1.ContieneElemento(val) << endl; 

    cout << "Establecemos el valor de la posicion " << pos << " a " << val << endl;
    conjunto1[pos] = val;

    cout << "Contiene elemento " << val << "?: " << conjunto1.ContieneElemento(val) << endl; 



    // Obtenemos el valor cambiado
    cout << "Obtenemos el valor de la posicion " << pos << ": " << conjunto1[pos] << endl;

    // Creamos una conjunto a partir de una existente, la imprimimos, la asignamos a 0 y la volvemos a imprimir
    cout << "Creamos una conjunto a partir de una existente, la imprimimos, la asignamos a 0 y la volvemos a imprimir:" << endl;
    Conjunto conjunto3 = conjunto2;
    conjunto3.PrintValues();
    conjunto3 = 0;
    conjunto3.PrintValues();


    // Terminamos la ejecución del programa
    return (0);


}