/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include "Transformaciones.h"

using namespace std;

/*****************************************************************************/
// Esta función crea un objeto MiVectorDinamico a partir de un conjunto
MiVectorDinamico ConjuntoToVectorDinamico (Conjunto & un_conjunto) {

	MiVectorDinamico vector;

	// Obtenemos el numero de nodos del conjunto
	int n_elementos = NumeroNodos(un_conjunto);

	// Recorremos los nodos
	for (int i = 0; i < n_elementos; i++) {

		// Vamos agregando los nodos al vector dinámico 
		vector.AddValue(un_conjunto[i]);

	}


	// Devolvemos el resultado
	return vector;

}

/*****************************************************************************/
// Esta función crea un objeto conjunto a partir de un MiVectorDinamico
Conjunto VectorDinamicoToConjunto (MiVectorDinamico & un_vector_dinamico) {


	Conjunto conjunto;

	// Obtenemos el numero de elementos del vector dinamico
	int n_elementos = un_vector_dinamico.GetSize();

	// Recorremos los elementos
	for (int i = 0; i < n_elementos; i++) {

		// Vamos agregando los nodos al vector dinámico 
		conjunto.Aniadir(un_vector_dinamico[i]);

	}


	// Devolvemos el resultado
	return conjunto;
}




