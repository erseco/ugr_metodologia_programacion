/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include "MiVectorDinamico.h"

using namespace std;

//Constructor sin argumentos, que crea un vector dinamico con un numero de casillas predeterminado.
MiVectorDinamico::MiVectorDinamico(void) {

    size = 2;
    pos = 0;
    dimension_type = 0;

    vector = new TipoBase[size];

}

//Constructor con dos argumentos, que crea un vector dinamico con un numero de casillas indicado en el primer argumento. Inicia todas la casillas al valor indicado en el segundo argumento. Por defecto tomara el valor 0.
MiVectorDinamico::MiVectorDinamico(int psize, TipoBase defaultvalue) {

    size = psize;
    pos = 0;
    dimension_type = 0;

    vector = new TipoBase[size];
    
    for (int i=0; i<size; i++) {

        vector[i] = defaultvalue;

    }

}

//Destructor
MiVectorDinamico::~MiVectorDinamico() {

    //Liberamos la memoria usada, mostramos un mensaje para depuracion
    cout << "Destruyendo..." << endl;
    delete [] vector;

}

//Metodos para consultar el numero de casillas reservadas. 
int MiVectorDinamico::GetSize() {

    return size;

}

//Metodos para consultar el numero de casillas ocupadas. 
int MiVectorDinamico::GetUsed() {

    return pos;

}

void MiVectorDinamico::SetRedimensionType(int type) {

    dimension_type = type;

}
int MiVectorDinamico::GetRedimensionType() {

    return dimension_type;

}


/*****************************************************************************/
//Metodo para añadir un valor (siempre al final).
void MiVectorDinamico::AddValue(TipoBase value) {

    //Si la posicion es igual al tamaño...
    if (pos == size) {

        //Incrementamos el vector dinámico
        if (dimension_type == 0) 
           Incrementa_En_Uno();
        else if (dimension_type == 1)
            Incrementa_En_Doble();
    }

    cout << "Agregando valor: " << value << endl;

    //Asignamos el valor en la posición
    vector[pos] = value;

    //Incrementamos la posicion (valor por referencia)
    pos++;    

}

/*****************************************************************************/
//Incremetna el vector en uno (redirección a la función incrementa en bloque)
void MiVectorDinamico::Incrementa_En_Uno() {

    //Llamamos a la funcion pasandole 1 como incremento
    Incrementa_En_Bloque(1);

}

/*****************************************************************************/
//Incrementa el vector al doble (redirección a la función incrementa en bloque)
void MiVectorDinamico::Incrementa_En_Doble() {

    //Llamamos a la funcion pasandole el tamaño 
    //actual como bloque (el resultado sera el doble)
    Incrementa_En_Bloque(size);

}

/*****************************************************************************/
//Incrementa el vector un determinado bloque
void MiVectorDinamico::Incrementa_En_Bloque(int increment) {

    //Declaramos un nuevo vector del tamaño del original mas el incremento
    TipoBase *nueva = new TipoBase[size + increment]; 

    //Copiamos los valores del vector antiguo al nuevo
    for (int i= 0; i<size; i++) {
        nueva[i] = vector[i];
    }

    //Incrementamos la variable (por referencia) size
    size += increment;

    //Liberamos el vector antiguo
    delete [] vector;

    //Devolvemos el resultado
    vector = nueva;

}

//Metodo para devolver el valor que ocupa una posicion dada. 
TipoBase MiVectorDinamico::GetValue(int pos) {

    return vector[pos];

}

/*****************************************************************************/
//Imprime el vector en la salida estándar
void MiVectorDinamico::PrintValues() {

    //Pintamos los valores en la consola
    for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

}

