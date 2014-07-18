/****************************************************************************** 
*
* Metodología de la Programación
* Grado en Ingeniería Informática
* 
* 2014 - Ernesto Serrano Collado
* ------------------------------
* 
* Considere una secuencia de datos almacenada en una lista. Implemente una 
* funcion para ordenar la secuencia empleando el metodo de ordenacion por 
* seleccion.
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
//Esta función comprueba leyendo numeros y los almacena en una estructura
//de celdas enlazadas y termina cuando se introduce un negativo
bool IsOrdered() {

	bool ordered = true;
	double prev = 0;

	//Colocamos aux al principio
	Node *aux = p; 
	
	//Recorremos las celdas hasta encontrar uno desordenado
	while (aux && ordered) {


		if (prev > aux->number) {

			ordered = false;

		}
		//Nos guardamos el valor del numero para la siguiente iteracción
		prev = aux->number;

		//adelantamos aux
		aux = aux->next;   


	
	}

	return ordered;

}


/*************************************************************/
//Esta función ordena los elementos contenidos en las celdas
//usando el ordenamiento por seleccion
void SortValues() {
    
    
	//Colocamos aux al principio
	Node *aux1 = p;
	Node *aux2;
    
	double min; //Aqui almacenamos el minimo, se podria hacer solo con nodemin
				//pero entonces necesitariamos otro puntero auxiliar para hacer el intercambio
	Node *nodemin = nullptr; //La inicializamos a nulo
    
	//Recorremos las celdas
	while (aux1) {
        
		//Nos guardamos el valor actual
		min = aux1->number;
        
		//Comprobamos que el siguiente no sean nulo (para el caso
		//del ultimo nodo)
        if (aux1->next) {
            
            //Establecemos el siguiente nodo a aux2
            aux2 = aux1->next;
            
			
			//Recorremos las celdas desde la posicion siguiente a aux1
            while (aux2) {
                
				//Ponemos a null la variable nodemin
				nodemin = nullptr;
				
				//Si el numero que hay almacenado es menor que min
                if (aux2->number < min) {
                    
					//nos lo guardamos como min, y nos guardamos tambien
					//el nodo, para poder hacer la sustitucion
                    min = aux2->number;
					nodemin = aux2;

                }
                
				//adelantamos aux
				aux2 = aux2->next;
                
            }

			//Intercambiamos los valores
			if (nodemin) {
				nodemin->number = aux1->number;
				aux1->number = min;
			}
		}
        
		//adelantamos aux
		aux1 = aux1->next;
        
	}
    
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
	cout << "Secuencia ordenada?: " << IsOrdered() << endl;

	//Ordenamos los valores
	SortValues();

	//Llamamos a la funcion que pinta los valores
	PrintValues();
	cout << "Secuencia ordenada?: " << IsOrdered() << endl;

    
    //Finalizamos el programa
    return 0;

}