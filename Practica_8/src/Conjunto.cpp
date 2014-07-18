/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include "Conjunto.h"

using namespace std;

/*****************************************************************************/
// Constructor sin argumentos, que crea una conjunto vacia.
Conjunto::Conjunto(void) {

    ReservarMemoria();

}

/*****************************************************************************/
// Constructor con un argumento, que crea una conjunto con un numero de nodos indicado en el argumento.
Conjunto::Conjunto(TipoBase valor) {

    ReservarMemoria();

    Aniadir(valor);

}

/*****************************************************************************/
// Constructor de copia
Conjunto::Conjunto(const Conjunto & otro) {

    // Reserva de memoria para la conjunto
    ReservarMemoria();

    // Copia de los valores de la conjunto
    CopiarDatos(otro);

}


/*****************************************************************************/
// Destructor
Conjunto::~Conjunto() {

    // Liberamos la memoria usada, mostramos un mensaje para depuracion
    cout << "Destruyendo..." << endl;

    LiberarMemoria();

}

/*****************************************************************************/
// Esta función crea una conjunto, se llama desde los distintos constructores
void Conjunto::ReservarMemoria(void) {

    conjunto=0;

}

/*****************************************************************************/
// Metodo que inicializa todos los nodos al valor indicado como argumento. 
void Conjunto::Inicializar(TipoBase value) {

    PNodo p = conjunto;

    while (p!=0) {
        p->valor = value;
        p=p->sig;
    }

}

/*****************************************************************************/
// Metodo (valor devuelto: bool) que consulta si la conjunto esta vacia.
bool Conjunto::EstaVacia() {

    PNodo p = conjunto;

    while (p) {
  
        if (p->valor != 0) {
            return false;

        }

        p=p->sig;
  
    }

    return true;

}

/*****************************************************************************/
// Metodo para consultar el numero de nodos de la conjunto.
int Conjunto::NumeroNodos() {

    int numeronodos = 0;

    PNodo p = conjunto;

    while (p) {
        p=p->sig;
        numeronodos++;
    }

    return numeronodos;

}

/*****************************************************************************/
// Metodo para insertar un valor en la conjunto. Modifica la conjunto. 
void Conjunto::Insertar (TipoBase v, int pos) {

    if (conjunto!=0) { 

        //  Hay al menos un nodo

        PNodo p = conjunto; 
        PNodo ant = conjunto; 

        for (int i=0; i<pos; i++) {
            ant = p;
            p=p->sig;
        }

        //  Crear y rellenar el nuevo nodo
        PNodo nuevo = new Nodo;
        nuevo->valor = v; 

        if (ant==conjunto) { //  insertar el primero
            nuevo->sig = conjunto; 
            conjunto = nuevo; 
        } else {

            if (p->sig==0){ //  insertar el ultimo
                p->sig = nuevo;
                nuevo->sig = 0;
            }
            else { //  insertar en medio
                ant->sig = nuevo;
                nuevo->sig = p;
            }
        }

    } else { //  el nodo nuevo es el primero y unico
        conjunto = new Nodo;
        conjunto->valor = v; 
        conjunto->sig = 0;
    }

}

/*****************************************************************************/
// Metodo para borrar un nodo en la conjunto.
void Conjunto::Borrar(int pos) {


    PNodo l = conjunto; 

    if (l!=0) { 

        //  Hay al menos un nodo

        PNodo p = l; 
        PNodo ant = p; 

        //  Buscar el sitio: "p" apuntará al nodo con 
        //  el valor buscado, o al último (si no está)

        for (int i=0; i<pos; i++) {

            ant = p;
            p=p->sig;
      
        }

            
        if (p==l) //  borrar el primero
            l = l->sig; 
        else //  borra un nodo intermedio (o final)
            ant->sig = p->sig; 
        delete p; // Borramos la referencia 



    } 


}

/*****************************************************************************/
// Metodo para añadir un valor en la conjunto. 
void Conjunto::Aniadir(TipoBase val) {

    PNodo p = conjunto; 

    if (p!=0) { // Si la conjunto no está vacía

        PNodo ant;

        while (p) {
            ant = p; // Nos guardamos el anterior
            p=p->sig; // Incrementamos nodo
        }

        // Agregamos un nodo al final (su sig = 0)
        ant->sig = new Nodo;
        (ant->sig)->valor = val;
        (ant->sig)->sig = 0;

    } else { //  el nodo nuevo es el primero y unico

        conjunto = new Nodo;
        conjunto->valor = val; 
        conjunto->sig = 0;
    
    }

}

/*****************************************************************************/
// Pedir memoria para alojar 
void Conjunto::LiberarMemoria() {

    PNodo p, ant; 

    if (conjunto!=0) {

        ant = conjunto;  
        p = conjunto->sig; 

        while (p!=0) {
            delete ant;
            ant = p;
            p = p->sig;
        }

        delete ant;
    }

}

/*******************************************************/
// Copiar nodos
void Conjunto::CopiarDatos (const Conjunto & otro) {

    // Obtengo un puntero a la conjunto origen
    PNodo p_origen = otro.conjunto;

    // Recorro la conjunto
    while (p_origen) {

        // Agrego un nuevo elemento a la conjunto de nodos
        Aniadir(p_origen->valor);

        // Incremento el puntero origen 
        p_origen=p_origen->sig;

    }

}

/*****************************************************************************/
// Operador de asignación
Conjunto & Conjunto::operator = (const Conjunto & otro){

    if (this != &otro) { // Evitar autoasignacion

        // Libera la memoria ocupada
        LiberarMemoria();
        // Reserva de memoria para los nodos
        ReservarMemoria();
        // Copia los campos privados y los coeficientes
        CopiarDatos(otro);

    }

    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignacion

}

/*****************************************************************************/
// Operador de asignación sobrecargado para asignar a todos los elementos 
// un valor por defecto
Conjunto & Conjunto::operator = (const TipoBase & defaultvalue){

    Inicializar(defaultvalue);

    return (*this);  // Objeto implicito: parte
                 // izquierda de la asignacion


}

/*****************************************************************************/
// Sobrecarga del operador []
TipoBase & Conjunto::operator [] (const int indice){

    // Recorremos los nodos hasta indice
    PNodo p = conjunto;
    for (int i=0; i<indice; i++) {

        p=p->sig;
  
    }

    // Devolvemos el valor
    return  p->valor;

}

bool Conjunto::ContieneElemento(TipoBase elemento){

    // Recorremos los nodos hasta indice
    PNodo p = conjunto;
    while (p) {

        // Comprobamos si contiene el elemento
        if (p->valor == elemento) {

            return true;
        }

        p=p->sig;
  
    }

    // No lo contiene
    return  false;

}

/*****************************************************************************/
// Imprime el vector en la salida estándar
void Conjunto::PrintValues() {

    PNodo p = conjunto;

    while (p) {
        cout << "Valor =  " << p->valor << endl;
        p=p->sig;
    }
    cout << endl;
}

