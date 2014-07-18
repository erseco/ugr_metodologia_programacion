/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include "Pila.h"

using namespace std;

/*****************************************************************************/
//Constructor sin argumentos, que crea una pila vacia.
Pila::Pila(void) {

    pila = 0;

}

/*****************************************************************************/
//Destructor
Pila::~Pila() {

    //Liberamos la memoria usada, mostramos un mensaje para depuracion
    cout << "Destruyendo..." << endl;
    PNodo p, ant; 

    if (pila!=0) {

        ant = pila;  
        p = pila->sig; 

        while (p!=0) {
            delete ant;
            ant = p;
            p = p->sig;
        }

        delete ant;
    }

}


/*****************************************************************************/
//Metodo (valor devuelto: bool) que consulta si la pila esta vacia.
bool Pila::EstaVacia() {

    PNodo p = pila;


    while (p) {
  
        if (p->valor != 0) {
            return false;

        }

        p=p->sig;
  
    }


    return true;

}

/*****************************************************************************/
//Metodo para añadir un valor en la pila. 
void Pila::Aniadir(TipoBase val) {

    PNodo p = pila; 

    if (p!=0) { //Si la pila no está vacía

        PNodo ant;

        while (p) {
            ant = p; //Nos guardamos el anterior
            p=p->sig; //Incrementamos nodo
        }

        //Agregamos un nodo al final (su sig = 0)
        ant->sig = new Nodo;
        (ant->sig)->valor = val;
        (ant->sig)->sig = 0;

    } else { // el nodo nuevo es el primero y unico

        pila = new Nodo;
        pila->valor = val; 
        pila->sig = 0;
    
    }

}

/*****************************************************************************/
//Metodo para sacar un valor.
TipoBase Pila::SacarValor () {

    PNodo p = pila, ultima, penultima;

    while(p) {
        
        penultima = ultima;
        ultima = p;
        p=p->sig;
  
    }

    TipoBase valor = ultima->valor;

    penultima->sig = 0;

    delete ultima;

    return valor;

}

/*****************************************************************************/
//Metodo para consultar un valor.
TipoBase Pila::ConsultarValor () {

    PNodo p = pila, ant, temp;

    while(p) {
        
        ant = p;
        p=p->sig;
  
    }

    return ant->valor;


}

/*****************************************************************************/
//Imprime el vector en la salida estándar
void Pila::PrintValues() {

    PNodo p = pila;

    while (p) {
        cout << "Valor =  " << p->valor << endl;
        p=p->sig;
    }
    cout << endl;
}

