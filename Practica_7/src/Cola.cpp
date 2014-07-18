/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include "Cola.h"

using namespace std;

/*****************************************************************************/
//Constructor sin argumentos, que crea una cola vacia.
Cola::Cola(void) {

    cola = 0;

}

/*****************************************************************************/
//Destructor
Cola::~Cola() {

    //Liberamos la memoria usada, mostramos un mensaje para depuracion
    cout << "Destruyendo..." << endl;
    PNodo p, ant; 

    if (cola!=0) {

        ant = cola;  
        p = cola->sig; 

        while (p!=0) {
            delete ant;
            ant = p;
            p = p->sig;
        }

        delete ant;
    }

}


/*****************************************************************************/
//Metodo (valor devuelto: bool) que consulta si la cola esta vacia.
bool Cola::EstaVacia() {

    PNodo p = cola;


    while (p) {
  
        if (p->valor != 0) {
            return false;

        }

        p=p->sig;
  
    }


    return true;

}

/*****************************************************************************/
//Metodo para añadir un valor en la cola. 
void Cola::Aniadir(TipoBase val) {

    PNodo p = cola; 

    if (p!=0) { //Si la cola no está vacía

        //Agregamos un nodo al principio (su sig = 0)
        PNodo nuevo = new Nodo;
        nuevo->valor = val;
        nuevo->sig = p;

        cola = nuevo;

    } else { // el nodo nuevo es el primero y unico

        cola = new Nodo;
        cola->valor = val; 
        cola->sig = 0;
    
    }

}

/*****************************************************************************/
//Metodo para sacar un valor.
TipoBase Cola::SacarValor () {

    PNodo p = cola, primera;

    //Nos guardamos el puntero a la primera y guardamo el valor que tiene
    primera = p;
    TipoBase valor = primera->valor;
    
    //Ponemos la cola en la siguiente posicion
    cola = cola->sig;

    //Borramos la referencia de la primera
    delete primera;

    //Devolvemos el valor
    return valor;

}

/*****************************************************************************/
//Metodo para consultar un valor.
TipoBase Cola::ConsultarValor () {

    PNodo p = cola;

    //Devolvemos el primer valor
    return p->valor;


}

/*****************************************************************************/
//Imprime el vector en la salida estándar
void Cola::PrintValues() {

    PNodo p = cola;

    while (p) {
        cout << "Valor =  " << p->valor << endl;
        p=p->sig;
    }
    cout << endl;
}

