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
Conjunto::Conjunto(const TipoBase valor) {

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
int NumeroNodos(const Conjunto & otro) {

	int numeronodos = 0;

	PNodo p = otro.conjunto;

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
TipoBase & Conjunto::operator [] (int indice){

	// Recorremos los nodos hasta indice
	PNodo p = conjunto;
	for (int i=0; i<indice; i++) {

		p=p->sig;
  
	}

	// Devolvemos el valor
	return  p->valor;

}

bool ContieneElemento(const Conjunto & otro, TipoBase elemento) {

	// Recorremos los nodos hasta indice
	PNodo p = otro.conjunto;
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
// Sobrecarga del operador ==
bool Conjunto::operator == (Conjunto & otro){

	return  SonIguales(otro);

}

/*****************************************************************************/
// Sobrecarga del operador !=
bool Conjunto::operator != (Conjunto & otro){

	return  !SonIguales(otro);

}

/*****************************************************************************/
// Esta funcion comprueba que dos conjuntos sean iguales
bool Conjunto::SonIguales(const Conjunto & otro) {

	// NOTA: Sé que está desaconsejado tener mas de un return en la misma función
	// pero en este caso quedaría mucho mas sencillo de entender el código, aun 
	// así lo he realizado como se aconseja.

	bool resultado = true;

	int n1 = NumeroNodos(*this);
	int n2 = NumeroNodos(otro);


	// Comprobamos que tengan el mismo tamañano
	if (n1 != n2) {

		// Difieren
		resultado = false;

	} else {

		// Comprobamos si el otro conjunto contiene el elemento del actual (nos da igual la posicion)
		PNodo p = conjunto;
		while (resultado && p) {
			resultado = ContieneElemento(otro, p->valor);
			p=p->sig;
		}

	}

	// Devolvemos el resultado
	return resultado;

}

/*****************************************************************************/
// Esta funcion suma un conjunto a otro
Conjunto operator + (Conjunto & c1, Conjunto & c2) {

	Conjunto c3 = c1;

	PNodo p = c2.conjunto;


	// Recorremos el conjunto dos
	while (p) {
		// Solo agregamos aquellos elementos que no estén en el destino (la union de conjuntos
		// no contempla repetidos) 
		if (!ContieneElemento(c3, p->valor)) 
			c3.Aniadir(p->valor);

		// Pasamos al siguiente nodo
		p=p->sig;
	}

	// Devolvemos la suma
	return c3;

}

/*****************************************************************************/
// Esta funcion suma un tipobase a un conjunto  (al final)
Conjunto operator + (Conjunto & c1, TipoBase value) {

	// Solo agregamos aquellos elementos que no estén en el destino (la union de conjuntos
	// no contempla repetidos) 
	if (!ContieneElemento(c1, value)) 
		c1.Aniadir(value);

	return c1;

}

/*****************************************************************************/
// Esta funcion suma un tipobase a un conjunto  (al principio)
Conjunto operator + (TipoBase value, Conjunto & c1) {

	// Solo agregamos aquellos elementos que no estén en el destino (la union de conjuntos
	// no contempla repetidos) 
	if (!ContieneElemento(c1, value)) 
		c1.Insertar(value, 0);

	return c1;

}


/*****************************************************************************/
// Esta funcion elimina los valores de un conjunto en base a otro conjunto
Conjunto Conjunto::operator - (const Conjunto & otro) {

	PNodo p = otro.conjunto;

	while (p) {
		EliminarValor(p->valor);
		p=p->sig;
	}


	return *this;

}

/*****************************************************************************/
// Esta funcion elimina un valor del conjunto
Conjunto Conjunto::operator - (TipoBase value) {

	EliminarValor(value);

	return *this;

}

/*****************************************************************************/
// Esta función elimina el valor indicado del conjunto
void Conjunto::EliminarValor(TipoBase value) {

	//¡ Puntero al conjunto, desde aqui empezaremos a recorrer
	PNodo & l = conjunto; 

	if (l!=0) { 

		//  Hay al menos un nodo

		PNodo p = l; 
		PNodo ant = p; 
		PNodo ant2 = p; 

		// Bandera para cuando encontremos el valor
		bool encontrado = false;

		// Buscar el sitio: "ant" apuntará al nodo con 
		// el valor buscado
		while (!encontrado && p) {

			if (p->valor == value) {
				encontrado = true;
			}

			ant2 = ant;
			ant = p;
			p=p->sig;
	  
		}

		// Si hemos encontrado un nodo con el valor
		if (encontrado) {
			if (ant==l) {//  borrar el primero
				l = ant->sig; 
			} else { //  borra un nodo intermedio (o final)
				ant2->sig = ant->sig; 
			}
		}

	} 

}

/*****************************************************************************/
// Esta funcion obtiene la interseccion de dos cojuntos
Conjunto operator * (Conjunto & c1, Conjunto & c2) {

	Conjunto c3;

	PNodo p = c2.conjunto;


	// Recorremos el conjunto dos (c2)
	while (p) {
		// Solo agregamos aquellos elementos que estén en el conjunto uno (c1)
		if (ContieneElemento(c1, p->valor)) 
			c3.Aniadir(p->valor);

		// Pasamos al siguiente nodo
		p=p->sig;
	}

	// Devolvemos un conjunto de los valores que esten en ambos conjuntos
	return c3;

}

/*****************************************************************************/
// Esta funcion suma un tipobase a un conjunto  (al final)
Conjunto operator * (Conjunto & c1, TipoBase value) {

	// Solo agregamos aquellos elementos que no estén en el destino (la union de conjuntos
	// no contempla repetidos) 
	if (ContieneElemento(c1, value)) 
		c1.Aniadir(value);

	return c1;

}

/*****************************************************************************/
// Esta funcion suma un tipobase a un conjunto  (al principio)
Conjunto operator * (TipoBase value, Conjunto & c1) {

	// Solo agregamos aquellos elementos que no estén en el destino (la union de conjuntos
	// no contempla repetidos) 
	if (ContieneElemento(c1, value)) 
		c1.Insertar(value, 0);

	return c1;

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

