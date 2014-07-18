/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include "Lista.h"

using namespace std;

/*****************************************************************************/
// Constructor sin argumentos, que crea una lista vacia.
Lista::Lista(void) {

    ReservarMemoria(0);

}

/*****************************************************************************/
// Constructor con un argumento, que crea una lista con un numero de nodos indicado en el argumento.
Lista::Lista(int n) {

    ReservarMemoria(n);

}

/*****************************************************************************/
// Constructor con dos argumentos, que crea una lista con un numero de nodo indicado en el primer argumento. 
Lista::Lista(int n, TipoBase value) {

    ReservarMemoria(n);

    Inicializar(value);

}

/*****************************************************************************/
// Constructor de copia
Lista::Lista(const Lista & otro) {

    // Reserva de memoria para la lista
    ReservarMemoria(0);

    // Copia de los valores de la lista
    CopiarDatos(otro);

}


/*****************************************************************************/
// Destructor
Lista::~Lista() {

    // Liberamos la memoria usada, mostramos un mensaje para depuracion
    cout << "Destruyendo..." << endl;

    LiberarMemoria();

}

/*****************************************************************************/
// Esta función crea una lista, se llama desde los distintos constructores
void Lista::ReservarMemoria(int n) {

    lista=0;
    PNodo fin, nuevo; 

    if (n > 0) {

        //  crear e inicar el primer nodo 
        lista = new Nodo;
        // inic->valor = valor; 
        lista->sig = 0; 

        fin = lista; //  marcamos el ultimo nodo


        for (int i=1; i<n; i++) {

            //  crear e iniciar un nuevo nodo
            nuevo = new Nodo;
            // nuevo->valor = valor; 

            fin->sig = nuevo; //  enlazar (al final)
            fin = nuevo;      //  actualizar el ultimo

        }

        fin->sig = 0; //  marcar el final
    }


}

/*****************************************************************************/
// Metodo que inicializa todos los nodos al valor indicado como argumento. 
void Lista::Inicializar(TipoBase value) {

    PNodo p = lista;

    while (p!=0) {
        p->valor = value;
        p=p->sig;
    }

}

/*****************************************************************************/
// Metodo (valor devuelto: bool) que consulta si la lista esta vacia.
bool Lista::EstaVacia() {

    PNodo p = lista;

    while (p) {
  
        if (p->valor != 0) {
            return false;

        }

        p=p->sig;
  
    }

    return true;

}

/*****************************************************************************/
// Metodo para consultar el numero de nodos de la lista.
int Lista::NumeroNodos() {

    int numeronodos = 0;

    PNodo p = lista;

    while (p) {
        p=p->sig;
        numeronodos++;
    }

    return numeronodos;

}

/*****************************************************************************/
// Metodo para insertar un valor en la lista. Modifica la lista. 
void Lista::Insertar (TipoBase v, int pos) {

    if (lista!=0) { 

        //  Hay al menos un nodo

        PNodo p = lista; 
        PNodo ant = lista; 

        for (int i=0; i<pos; i++) {
            ant = p;
            p=p->sig;
        }

        //  Crear y rellenar el nuevo nodo
        PNodo nuevo = new Nodo;
        nuevo->valor = v; 

        if (ant==lista) { //  insertar el primero
            nuevo->sig = lista; 
            lista = nuevo; 
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
        lista = new Nodo;
        lista->valor = v; 
        lista->sig = 0;
    }

}

/*****************************************************************************/
// Metodo para borrar un nodo en la lista.
void Lista::Borrar(int pos) {


    PNodo l = lista; 

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
// Metodo para añadir un valor en la lista. 
void Lista::Aniadir(TipoBase val) {

    PNodo p = lista; 

    if (p!=0) { // Si la lista no está vacía

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

        lista = new Nodo;
        lista->valor = val; 
        lista->sig = 0;
    
    }

}

/*****************************************************************************/
// Pedir memoria para alojar 
void Lista::LiberarMemoria() {

    PNodo p, ant; 

    if (lista!=0) {

        ant = lista;  
        p = lista->sig; 

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
void Lista::CopiarDatos (const Lista & otro) {

    // Obtengo un puntero a la lista origen
    PNodo p_origen = otro.lista;

    // Recorro la lista
    while (p_origen) {

        // Agrego un nuevo elemento a la lista de nodos
        Aniadir(p_origen->valor);

        // Incremento el puntero origen 
        p_origen=p_origen->sig;

    }

}

/*****************************************************************************/
// Operador de asignación
Lista & Lista::operator = (const Lista & otro){

    if (this != &otro) { // Evitar autoasignacion

        // Libera la memoria ocupada
        LiberarMemoria();
        // Reserva de memoria para los nodos
        ReservarMemoria(0);
        // Copia los campos privados y los coeficientes
        CopiarDatos(otro);

    }

    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignacion

}

/*****************************************************************************/
// Operador de asignación sobrecargado para asignar a todos los elementos 
// un valor por defecto
Lista & Lista::operator = (const TipoBase & defaultvalue){

    Inicializar(defaultvalue);

    return (*this);  // Objeto implicito: parte
                 // izquierda de la asignacion


}

/*****************************************************************************/
// Sobrecarga del operador []
TipoBase & Lista::operator [] (const int indice){

    // Recorremos los nodos hasta indice
    PNodo p = lista;
    for (int i=0; i<indice; i++) {

        p=p->sig;
  
    }

    // Devolvemos el valor
    return  p->valor;

}

/*****************************************************************************/
// Imprime el vector en la salida estándar
void Lista::PrintValues() {

    PNodo p = lista;

    while (p) {
        cout << "Valor =  " << p->valor << endl;
        p=p->sig;
    }
    cout << endl;
}

