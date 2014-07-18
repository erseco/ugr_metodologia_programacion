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

    ReservarMemoria();

}

/*****************************************************************************/
// Constructor de copia
Cola::Cola(const Cola & otro) {

    // Reserva de memoria para la lista
    ReservarMemoria();

    // Copia de los valores de la lista
    CopiarDatos(otro);

}

/*****************************************************************************/
//Destructor
Cola::~Cola() {

    //Liberamos la memoria usada, mostramos un mensaje para depuracion
    cout << "Destruyendo..." << endl;

    LiberarMemoria();

}

/*****************************************************************************/
// Esta función crea una lista, se llama desde los distintos constructores
void Cola::ReservarMemoria() {

    cola=0;
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
// Pedir memoria para alojar 
void Cola::LiberarMemoria() {

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

/*******************************************************/
// Copiar nodos
void Cola::CopiarDatos (const Cola & otro) {

    // Obtengo un puntero a la cola origen
    PNodo p_origen = otro.cola;

    // Recorro la cola
    while (p_origen) {

        // Agrego un nuevo elemento a la cola de nodos
        Aniadir(p_origen->valor);

        // Incremento el puntero origen 
        p_origen=p_origen->sig;

    }

}

/*****************************************************************************/
// Operador de asignación
Cola & Cola::operator = (const Cola & otro){

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
// Sobrecarga del operador combinado +=
Cola & Cola::operator += (TipoBase value) {

    //Llamamos a la función que agrega un valor
    Aniadir(value);


    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignacion

}

/*****************************************************************************/
// Sobrecarga del operador unario -- (cuando se usa --cola)
Cola & Cola::operator -- (void){

    //Llamamos a la función que saca un valor, pero no lo asignamos a nada
    SacarValor();


    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignacion

}

/*****************************************************************************/
// Sobrecarga del operador unario -- (cuando se usa cola--)
Cola & Cola::operator -- (TipoBase){

    //Llamamos a la función que saca un valor, pero no lo asignamos a nada
    SacarValor();


    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignacion

}

/*****************************************************************************/
// Sobrecarga del operador unario ^
TipoBase Cola::operator ^ (TipoBase value) {

    // Consultamos el ultimo valor de la cola (no se modifica la misma)
    return ConsultarValor();
}

/*****************************************************************************/
// Sobreescribir el operador <<
Cola & Cola::operator << (TipoBase value) {

Aniadir(value);

return (*this);  // Objeto implicito: parte
                 // izquierda de la asignacion

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

