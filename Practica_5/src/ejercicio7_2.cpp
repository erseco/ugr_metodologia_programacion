/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Deseamos guardar un numero indefinido de valores double para poder procesarlos 
 * posteriormente. Resuelva el problema almacenando los datos en un vector dinamico 
 * que vaya creciendo conforme necesite espacio para almacernar un nuevo valor.
 * 
 * Escribir tres funciones diferentes, de manera que el problema se pueda resolver 
 * con cualquiera de ellas. Las funciones se diferencian en la manera en que hacen
 * crecer el vector dinamico, aumentando su capacidad cuando no haya espacio para 
 * almacernar un nuevo valor, ampliandolo:
 * 
 *  a) en una casilla
 *  b) en bloques de tamaño n 
 *  c) duplicando su tamaño
 * 
 * Nota: Reservar inicialmente 5 casillas.
 * Para la resolucion de este ejercicio proponemos dos programas diferentes.
 * 1) El primero tomara los valores a insertar en el vector dinamico directamente 
 * del teclado. 
 * 2) El segundo tomara los valores a insertar desde una lista.
 * 
 * Intentar que el almacenamiento en el vector dinamico (procesamiento) sea lo 
 * mas independiente posible de la entrada de datos.
 *
 ******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include "VectorDinamico.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main(){

    //Declaracion de variables
    int size = 5; //Valor inicial que pide el ejercicio
    int pos = 0;
    double value;

    //Declaramos un nuevo vector
    double *v = new double [size];

    do {
        //Solicitamos un valor al usuario
        cout << "Introduzca un numero (0 para salir): ";
        cin >> value;

        //Lo introducimos en el vector
        v = AddValue(v, pos, size, value);

    } while (value != 0); //Sale cuando introducimos un 0


    //Pintamos el vector en la salida estándar
    cout << "Pintando lista:" << endl;
    PrintValues(v, size);

    //Finalizamos el programa
    return 0;
    
}