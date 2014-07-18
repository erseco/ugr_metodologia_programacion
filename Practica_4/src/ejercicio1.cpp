/****************************************************************************** 
*
* Metodología de la Programación
* Grado en Ingeniería Informática
* 
* 2014 - Ernesto Serrano Collado
* ------------------------------
* 
* Escriba un programa para que lea una secuencia con un numero indefinido de 
* valores double hasta que se introduzca un valor negativo. Estos valores 
* (excepto el ultimo, el negativo) los almacenara en una estructura de celdas 
* enlazadas (una lista) y despues mostara los valores almacenados.
* 
* Escribir un programa para solucionar este problema, con dos funciones: 
* 	a) Una para leer y almacenar los valores.
* 	b) Otra para mostrarlos.
* 	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std; 

/*************************************************************/
//Estructura donde se almacenarán los datos
struct Node{
      double number;
      Node *next;
};

/*************************************************************/
//Atributos
Node *p, *pend ;

/*************************************************************/
//Esta función va leyendo numeros y los almacena en una estructura
//de celdas enlazadas y termina cuando se introduce un negativo
void ReadValues() {

	double n;
	p = 0; // inicializacion a la direccion nula

	//Primera lectura
	cout << "Introduzca valor (0 para terminar): ";
   	cin >> n;

	if (n > 0) {
		
		p = new Node; 	//Pedimos memoria para el primer nodo
		p->number = n;  //Guardamos el valor leido en el nodo
		p->next = 0;    //Este nodo va a ser, por ahora, el ultimo
		pend = p; 		//el ultimo tambien es el primero (solo hay uno)
		
		// Segunda lectura
		cout << "Introduzca valor (0 para terminar): ";
		cin >> n;

		while (n > 0) {

			//Pedimos memoria para el siguiente nodo
			pend->next = new Node;
			pend = pend->next; 	//Actualizamos la posicion del ultimo
			pend->number = n; 	//Guardamos el valor leido en el nuevo nodo
			pend->next = 0;  	//Este nodo va a ser, por ahora, el ultimo
			
			// Siguiente lectura
			cout << "Introduzca valor (0 para terminar): ";
			cin >> n;

		} 
	} 

}

/*************************************************************/
//Esta función pinta el contenido de la estructura enlazada
void PrintValues() {

	Node *aux = p; //Colocamos aux al principio
	
	while (aux) {

		//Pintamos el resultado en la consola
		cout << aux->number << endl;
		aux = aux->next;   //adelantamos aux
	
	}

}

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Llamamo a la funcion que lee los valores
	ReadValues();

	//Llamamos a la funcion que pinta los valores
	PrintValues();

    //Finalizamos el programa
    return 0;
    
}