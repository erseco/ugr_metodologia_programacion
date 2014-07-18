/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include "MiVectorDinamico.h"

using namespace std;

/*****************************************************************************/
// Constructor sin argumentos, que crea un vector dinamico con un numero de casillas predeterminado.
MiVectorDinamico::MiVectorDinamico(void) {

	size = 2;
	pos = 0;
	dimension_type = 0;

	ReservarMemoria(size);

}

/*****************************************************************************/
// Constructor con dos argumentos, que crea un vector dinamico con un numero de 
// casillas indicado en el primer argumento. Inicia todas la casillas al valor 
// indicado en el segundo argumento. Por defecto tomara el valor 0.
MiVectorDinamico::MiVectorDinamico(int psize, TipoBase defaultvalue) {

	size = psize;
	pos = 0;
	dimension_type = 0;

	ReservarMemoria(size);

	AsignarValor(defaultvalue);

}

/*****************************************************************************/
// Constructor de copia
MiVectorDinamico::MiVectorDinamico(const MiVectorDinamico & otro) {

	// Reserva de memoria para el vector
	ReservarMemoria(otro.size);

	// Copia de los valores del vector
	// y de los campos privados
	CopiarDatos(otro);
}

/*****************************************************************************/
// Destructor
MiVectorDinamico::~MiVectorDinamico() {

	// Liberamos la memoria usada, mostramos un mensaje para depuracion
	cout << "Destruyendo..." << endl;
	LiberarMemoria();

}

/*****************************************************************************/
// Metodos para consultar el numero de casillas reservadas. 
int MiVectorDinamico::GetSize() {

	return size;

}

/*****************************************************************************/
// Metodos para consultar el numero de casillas ocupadas. 
int MiVectorDinamico::GetUsed() {

	return pos;

}

/*****************************************************************************/
void MiVectorDinamico::SetRedimensionType(int type) {

	dimension_type = type;

}

/*****************************************************************************/
int MiVectorDinamico::GetRedimensionType() {

	return dimension_type;

}

/*****************************************************************************/
// Metodo para añadir un valor (siempre al final).
void MiVectorDinamico::AddValue(TipoBase value) {

	// Si la posicion es igual al tamaño...
	if (pos == size) {

		// Incrementamos el vector dinámico
		if (dimension_type == 0) 
		   Incrementa_En_Uno();
		else if (dimension_type == 1)
			Incrementa_En_Doble();
	}

	cout << "Agregando valor: " << value << endl;

	// Asignamos el valor en la posición
	vector[pos] = value;

	// Incrementamos la posicion (valor por referencia)
	pos++;    

}

/*****************************************************************************/
// Incremetna el vector en uno (redirección a la función incrementa en bloque)
void MiVectorDinamico::Incrementa_En_Uno() {

	// Llamamos a la funcion pasandole 1 como incremento
	Incrementa_En_Bloque(1);

}

/*****************************************************************************/
// Incrementa el vector al doble (redirección a la función incrementa en bloque)
void MiVectorDinamico::Incrementa_En_Doble() {

	// Llamamos a la funcion pasandole el tamaño 
	// actual como bloque (el resultado sera el doble)
	Incrementa_En_Bloque(size);

}

/*****************************************************************************/
// Incrementa el vector un determinado bloque
void MiVectorDinamico::Incrementa_En_Bloque(int increment) {

	// Declaramos un nuevo vector del tamaño del original mas el incremento
	TipoBase *nueva = new TipoBase[size + increment]; 

	// Copiamos los valores del vector antiguo al nuevo
	for (int i= 0; i<size; i++) {
		nueva[i] = vector[i];
	}

	// Incrementamos la variable (por referencia) size
	size += increment;

	// Liberamos el vector antiguo
	delete [] vector;

	// Devolvemos el resultado
	vector = nueva;

}

/*******************************************************/
// Copiar campos privados y los coeficientes
void MiVectorDinamico::CopiarDatos (const MiVectorDinamico & otro) {

	// Copia los campos privados
	size = otro.size;
	pos = otro.pos;
	dimension_type = otro.dimension_type;

	// Copia los valores del vector
	for (int i=0; i<size; i++)
		vector[i] = otro.vector[i];

}

/*****************************************************************************/
// Pedir memoria para alojar 
void MiVectorDinamico::LiberarMemoria() {

	delete [] vector;

}

/*****************************************************************************/
// Pedir memoria para alojar 
void MiVectorDinamico::ReservarMemoria (int num_casillas){
	vector = new TipoBase[num_casillas];
}

/*****************************************************************************/
// Operador de asignación
MiVectorDinamico & MiVectorDinamico::operator = (const MiVectorDinamico & otro){

	if (this != &otro) { // Evitar autoasignacion

		// Libera la memoria ocupada
		LiberarMemoria();
		// Reserva de memoria para los coeficientes
		ReservarMemoria (otro.size);
		// Copia los campos privados y los coeficientes
		CopiarDatos(otro);

	}

	return (*this);  // Objeto implicito: parte
					 // izquierda de la asignacion

}

/*****************************************************************************/
// Operador de asignación sobrecargado para asignar a todos los elementos 
// un valor por defecto
MiVectorDinamico & MiVectorDinamico::operator = (const TipoBase & defaultvalue){

	AsignarValor(defaultvalue);

	return (*this);  // Objeto implicito: parte
				 // izquierda de la asignacion


}

/*****************************************************************************/
// Asignamos un valor a todos los elementos del vector
void MiVectorDinamico::AsignarValor(TipoBase defaultvalue) {

	for (int i=0; i<size; i++) {

		vector[i] = defaultvalue;

	}

}

/*****************************************************************************/
// Sobrecarga del operador []
TipoBase & MiVectorDinamico::operator [] (const int indice){

	return  vector[indice];

}

/*****************************************************************************/
// Sobrecarga del operador ==
bool MiVectorDinamico::operator == (const MiVectorDinamico & otro){

	return  SonIguales(otro);

}

/*****************************************************************************/
// Sobrecarga del operador !=
bool MiVectorDinamico::operator != (const MiVectorDinamico & otro){

	return  !SonIguales(otro);

}

/*****************************************************************************/
// Esta funcion comprueba que dos vectores dinamicos sean iguales
bool MiVectorDinamico::SonIguales(const MiVectorDinamico & otro) {

	// NOTA: Sé que está desaconsejado tener mas de un return en la misma función
	// pero en este caso quedaría mucho mas sencillo de entender el código, aun 
	// así lo he realizado como se aconseja.

	bool resultado = true;

	// Comprobamos que tengan el mismo tamañano
	if (size != otro.size) {

		// Difieren
		resultado = false;

	} else {

		// Recorremos los elementos del vector para compararlos con el proporcionado como parametro
		// usamos un bucle while en forma de for
		for (int i=0; resultado && i<size; i++) {

			if (vector[i] != otro.vector[i]) {

				// Difieren
				resultado = false;

			}

		}


	}

	// Devolvemos el resultado
	return resultado;

}

/*****************************************************************************/
// Esta funcion compara el tamaño del vector actual comparado con el otro
bool MiVectorDinamico::operator > (const MiVectorDinamico & otro) {

	return size > otro.size;

}
/*****************************************************************************/
// Esta funcion compara el tamaño del vector actual comparado con el otro
bool MiVectorDinamico::operator < (const MiVectorDinamico & otro) {

	return size < otro.size;

}
/*****************************************************************************/
// Esta funcion compara el tamaño del vector actual comparado con el otro
bool MiVectorDinamico::operator >= (const MiVectorDinamico & otro) {

	return size >= otro.size;

}
/*****************************************************************************/
// Esta funcion compara el tamaño del vector actual comparado con el otro
bool MiVectorDinamico::operator <= (const MiVectorDinamico & otro) {

	return size <= otro.size;

}

/*****************************************************************************/
// Imprime el vector en la salida estándar
void MiVectorDinamico::PrintValues() {

	// Pintamos los valores en la consola
	for (int i = 0; i < size; i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
	
}



