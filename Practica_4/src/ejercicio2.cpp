/****************************************************************************** 
*
* Metodología de la Programación
* Grado en Ingeniería Informática
* 
* 2014 - Ernesto Serrano Collado
* ------------------------------
* 
* Ampliar el problema 1 de manera que una vez leidos los datos realice unos 
* calculos sobre los datos almacenados en la lista. Se pide que se escriban 
* tres funciones para calcular:
*	a) el numero de celdas enlazadas.
*	b) la media de los datos almacenados. 
*	c) la varianza de los datos almacenados.
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
int GetNumberOfCells() {

	int n = 0;

	Node *aux = p; //Colocamos aux al principio
	
	//Recorremos las celdas
	while (aux) {

		//Incrementamos el contador
		n++;
		
		//adelantamos aux
		aux = aux->next;   
	
	}

	//Devolvemos el resultado
	return n;

}

/*************************************************************/
//Esta función va leyendo numeros y los almacena en una estructura
//de celdas enlazadas y termina cuando se introduce un negativo
double GetDataMean() {

	//Creamos variables para almacenar los datos
	int sum = 0;
	int total = 0;
	int mean;

	Node *aux = p; //Colocamos aux al principio
	
	//Recorremos las celdas
	while (aux) {

		//Agregamos el valor a la suma
		sum += aux->number;

		//Incrementamos el contador del total
		total++;	

		//adelantamos aux
		aux = aux->next;   
	
	}

	//Calculamos el promedio
	mean = sum / total;

	//Devolvemos el resultado
	return mean;

} 

/*************************************************************/
//Esta función calcula la varianza de los datos almacenados
double GetDataVariance() {

	//Creamos variables para almacenar los datos
	double mean = GetDataMean();
	double sum = 0;
	double variance;

	Node *aux = p; //Colocamos aux al principio

	//Recorremos las celdas
	while (aux) {

		//hacemos los cálculos
		sum += (mean - aux->number) * (mean - aux->number);
		
		//adelantamos aux
		aux = aux->next;   

	}

	//Calculamos la varianza
	variance = sum / GetNumberOfCells();

	//Devolvemos el resultado
	return variance;

} 

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

	//Llamamos a las funciones que hacen cálculos sobre los datos
	cout << "Numero de celdas: " << GetNumberOfCells() << endl;
	cout << "Promedio: " << GetDataMean() << endl;
	cout << "Varianza: " << GetDataVariance() << endl;
	
    //Finalizamos el programa
    return 0;

}