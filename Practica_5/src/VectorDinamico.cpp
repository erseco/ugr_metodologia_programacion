/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include "VectorDinamico.h"

using namespace std;

/*****************************************************************************/
//Agrega un elemento al vector
//NOTA: El parámetro size se pasa por referencia porque cambia el tamaño del vector
//Y la posición tambien se pasa por referencia
double * AddValue(double *v, int &pos, int &size, double value) {

    //Si la posicion es igual al tamaño...
    if (pos == size) {

        //Incrementamos el vector dinámico
        v = Incrementa_En_Uno(v, size);
    }

    //Asignamos el valor en la posición
    v[pos] = value;

    //Incrementamos la posicion (valor por referencia)
    pos++;    

    //Devolvemos el vector
    return v;

}

/*****************************************************************************/
//Incremetna el vector en uno (redirección a la función incrementa en bloque)
//NOTA: El parámetro size se pasa por referencia porque cambia el tamaño del vector
double * Incrementa_En_Uno(double *v, int &size) {

    //Llamamos a la funcion pasandole 1 como incremento
    return Incrementa_En_Bloque(v, size, 1);

}

/*****************************************************************************/
//Incrementa el vector al doble (redirección a la función incrementa en bloque)
//NOTA: El parámetro size se pasa por referencia porque cambia el tamaño del vector
double * Incrementa_En_Doble(double *v, int &size) {

    //Llamamos a la funcion pasandole el tamaño 
    //actual como bloque (el resultado sera el doble)
    return Incrementa_En_Bloque(v, size, size);

}

/*****************************************************************************/
//Incrementa el vector un determinado bloque
//NOTA: El parámetro size se pasa por referencia porque cambia el tamaño del vector
double * Incrementa_En_Bloque(double *v, int &size, int increment) {

    //Declaramos un nuevo vector del tamaño del original mas el incremento
    double * nueva = new double [size + increment];

    //Copiamos los valores del vector antiguo al nuevo
    for (int i= 0; i<size; i++) {
        nueva[i] = v[i];
    }

    //Incrementamos la variable (por referencia) size
    size += increment;

    //Liberamos el vector antiguo
    delete [] v;

    //Devolvemos el resultado
    return (nueva);

}

/*****************************************************************************/
//Imprime el vector en la salida estándar
void PrintValues(double *v, int size) {

    //Pintamos los valores en la consola
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

}
