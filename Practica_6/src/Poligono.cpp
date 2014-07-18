/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Poligono.h"

using namespace std;

/*************************************************************/
//Esta función va agregando puntos en una estructura
//de celdas enlazadas, los puntos se le pasan como un vector de Punto2D
Poligono LlenarPoligono (vector<Punto2D> puntos, int tamanio) {

	//Declaramos dos punteros a Nodo
  	Nodo *p, *aux;
   	p = new Nodo; // Pedimos memoria para el primer nodo

   	//Comprobamos que tengamos en el vector por lo menos tantos 
   	//elementos como se pide en el parametro
   	if (puntos.size() >=  tamanio ) {

	   	p->punto = puntos.at(0); //Asignamos el primer punto
	   
	    p->next = new Nodo; // Pedimos memoria para un nuevo nodo
	                        // y queda "enlazado" con el primero
		aux = p->next;  	// aux apunta al nuevo nodo
	    
	    //Recorremos los puntos pasados como vector desde el 2º (el primero lo asignamos previamente)
	    for (int i = 1; i < tamanio; i++) {

			//Asignamos el punto
		   	aux->punto = puntos.at(i);

		   	//Comprobamos si es el último
			if (i == tamanio -1) {
				//Si es el último, le asignamos a next el primer nodo, así cerramos el círculo
				aux->next = p;
			}else{
				//Si no, creamos un nuevo nodo que rellenaremos en la próxima iteracción
				aux->next = new Nodo;
			}
			//Incrementamos aux al siguiente elemento, para trabajar con el en la próxima iteracción
			aux = aux->next;


		}

	}

	//Devolvemos el resultado
	return p;

}

/*************************************************************/
//Esta función devuelve el numero de lados de un polígono dado
int NumeroLados (Poligono poligono) {

	Nodo *aux = poligono; //Colocamos aux al principio
	bool igual = false;
	int lados = 0; //Contador de lados

	//Nos guardamos el primer punto
	Punto2D primero = aux->punto;

	//Recorremos los puntos hasta que el actual sea igual al primero
	while (!igual) {

		//Incrementamos aux al siguiente elemento, para trabajar con el
		aux = aux->next;

		//Obtenemos el punto actual
		Punto2D segundo  = aux->punto;

		//Si es igual que el primero...
		if (primero.x == segundo.x && primero.y == segundo.y) {

			//...marcamos la bandera
			igual = true;

		}
		//Incrementamos el número de lados
		lados++;
	}

	//Devolvemos el resultado
	return lados;

}

/*****************************************************************************/
//Liberal la memoria de la matriz pasada como parámetro
void LiberaPoligono (Poligono poligono) {

	//Declaramos punteros para trabajar con el poligono
	Nodo *previo, *actual;

	int tamanio = NumeroLados(poligono); //Obtenemos el número de lados usando nuestra funcióin


	//Guardamos el primero en previo
	previo = poligono;
	
	//Recorremos los puntos del polígono
	for (int i=1; i<tamanio; i++) {

		//Incrementamos aux al siguiente elemento, para trabajar con el
		actual = previo->next;

		cout << "Liberando x=" << previo->punto.x << ", y=" << previo->punto.y << endl;
		//Liberamos la memoria del elemento previo
		delete [] previo;

		//Asignamos el actual a previo para usarlo en la proxima iteracción
		previo = actual;

	}

	//Ahora liberaremos el último valor
	cout << "Liberando x=" << previo->punto.x << ", y=" << previo->punto.y << endl;
	delete [] previo; // Libera el vector de punteros
  
}

/*****************************************************************************/
//Pinta una recta en la salida estándar, esta función no hace nada porque es un
//supuesto del ejercicio, de todas formas se han realizado unas funciones 
//para poder pintar los puntos de un poligono en la salida estándar
void PintaRecta (Punto2D p1, Punto2D p2) {

	//Pintamos el resultado en la consola
	cout << setprecision(2) << "Pintado punto de: x1=" << setw(5) << p1.x << ", y1=" << setw(5) << p1.y << " a: x2=" << setw(5) << p2.x << ", y2=" << p2.y << endl;

}

/*****************************************************************************/
//Pinta un polígono en la salida estándar
void PintarPoligono (Poligono poligono) {

	//Declaramos punteros para trabajar con el poligono
	Nodo *p = poligono;

	int tamanio = NumeroLados(poligono); //Obtenemos el número de lados usando nuestra funcióin

	//Recorremos los puntos del polígono
	for (int i=0; i < tamanio; i++) {

		//Obtenemos un punto y su siguiente
		Punto2D punto1 = p->punto;
		Punto2D punto2 = (p->next)->punto;

		//Llamamos a la función que pinta una recta
		//NOTA: Dicha función solo pintará en la consola los numeros de los puntos
		//ya que aun no hemos visto como pintar primitivas gráficas
		PintaRecta(punto1, punto2);

		//Incrementamos p al siguiente elemento para trabajar con el en la próxima iteracción
		p = p->next;
	
	}

}

/*****************************************************************************/
//Esta función devuelve un vector con dos polígonos a partir de un cuadrado
vector<Poligono> ObtenerTriangulosDesdeCuadrado(Poligono p) {

	//Declaramos un vector de poligonos que será el resultado
	vector<Poligono> triangulos;

	//Comprobamos que sea un cuadrado
	if (NumeroLados(p) == 4) {

		//Declaramos un vector de puntos para crear un nuevo poligono
		vector<Punto2D> puntos;
		
		//Agregamos los puntos 0-2-3
		puntos.push_back(p->punto);
		puntos.push_back(((p->next)->next)->punto);
		puntos.push_back((((p->next)->next)->next)->punto);

		//Creamos un nuevo poligono
		Poligono triangulo1 = LlenarPoligono(puntos, puntos.size());

		//Vaciamos el vector para reutilizarlo
		puntos.clear();

		//Agregamos los puntos 0-1-2
		puntos.push_back(p->punto);
		puntos.push_back((p->next)->punto);
		puntos.push_back(((p->next)->next)->punto);

		//Creamos un nuevo poligono
		Poligono triangulo2 = LlenarPoligono(puntos, puntos.size());

		//Agregamos los triangulos al resultado
		triangulos.push_back(triangulo1);
		triangulos.push_back(triangulo2);

	}

	//Devolvemos el resultado
	return triangulos;

}

/*****************************************************************************/
//Esta función devuelve un triangulo a partir de las medianas de los vertices
//del triangulo proporcionado
Poligono ObtenerTrianguloInterno(Poligono p) {

	//Declaramos un nuevo poligono que será el resultado
	Poligono triangulo;

	//Comprobamos que sea un triándulo
	if (NumeroLados(p) == 3) {

		//Declaramos un vector de puntos para crear un nuevo poligono
		vector<Punto2D> puntos;

		//Creamos un punto a partir de la mediana de sus vertices
		Punto2D punto;
		punto.x = (p->punto.x + (p->next)->punto.x) / 2;
		punto.y = (p->punto.y + (p->next)->punto.y) / 2;
		puntos.push_back(punto); //Lo agregamos al vector de puntos
		p = p->next; //Pasamos al siguiente punto del poligono
		
		//Creamos un punto a partir de la mediana de sus vertices
		punto.x = (p->punto.x + (p->next)->punto.x) / 2;
		punto.y = (p->punto.y + (p->next)->punto.y) / 2;
		puntos.push_back(punto); //Lo agregamos al vector de puntos
		p = p->next; //Pasamos al siguiente punto del poligono

		//Creamos un punto a partir de la mediana de sus vertices
		punto.x = (p->punto.x + (p->next)->punto.x) / 2;
		punto.y = (p->punto.y + (p->next)->punto.y) / 2;
		puntos.push_back(punto); //Lo agregamos al vector de puntos


		//Creamos un nuevo poligono
		triangulo = LlenarPoligono(puntos, puntos.size());

	}

	//Devolvemos el resultado
	return triangulo;

}

/*****************************************************************************/
//Esta función devuelve un poligono a raiz de una circunferencia proporcionada
Poligono ObtenerPoligonoInscritoCircunferencia(int lados, int radio, Punto2D centro) {

	//Declaramos un vector de puntos para crear un nuevo poligono
	vector<Punto2D> puntos;

	//Agregarmos tantos puntos como lados se ha pasado como parámetro
	for (int i = 0; i < lados; i++) {

		//Creamos un nuevo punto
		Punto2D punto;

		//Obtenemos las coordenadas en base a la formula dada en el ejercicio
		punto.x = centro.x + radio * cos(i); 
		punto.y = centro.y + radio * sin(i); 

		//Agregamos el punto al vector de puntos
		puntos.push_back(punto);

	}

	//Creamos un nuevo poligono
	Poligono poligono = LlenarPoligono(puntos, puntos.size());

	//Devolvemos el resultado
	return poligono;

}





////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//
//	ESTAS FUNCIONES NO SE HAN PEDIDO EN EL EJERCICIO
//
//	Las siguientes funciones se pueden utilizar para pintar poligonos en la salida estándar
//	
//
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

/*************************************************************/
//Esta función pinta información del poligono suministrado, primero
//pinta los puntos que contiene, y luego una representación gráfica
//de dicho polígono (dibuja en la salida estándar)
void PintarInformacionPoligono (Poligono poligono) {

	cout << "-------------------------------------" << endl;
	cout << "Pintando poligono:" << endl;
	cout << "Información:" << endl;
	PintarPoligono(poligono);

	cout << endl << "Grafica:" << endl;
	PintarGrafica(poligono);

	cout << endl;

}

/*************************************************************/
//Esta función comprueba si algún coincide con las coordenadas suministradas
bool ExistePunto(Poligono poligono, int tamanio, int x, int y) {

	Nodo *p = poligono;
	bool existe = false;

	//Bucle while en forma de for (si se encuentra un punto termina y devuelve true)
	for (int i=0; (!existe && i<tamanio); i++) {

		//Obtenemos el punto
		Punto2D punto = p->punto;

		//Comprobamos si el punto coincide con las coordenadas suministradas
		//NOTA: Redondeamos a int los puntos del poligono, ya que las coordenadas seran enteros
		if ((int)punto.x == x && (int)punto.y == y) {
			//Activamos la bandera
			existe = true;
		}

		//Pasamos al siguiente punto
		p = p->next;
	
	}

	//Devolvemos el resultado
	return existe;

}

/*************************************************************/
//Esta función pinta una gráfica de puntos en base a un poligono, 
//pintará un "*" si el poligono contiene un punto dado, si no 
//pintará un espacio
void PintarGrafica(Poligono poligono) {

	//Constante del tamaño de la matriz a pintar
	const int TAMANIO_GRAFICA = 15;
	const int ESPACIADO = 3;
	int tamanio = NumeroLados(poligono); //Obtenemos el numero de lados

	//Recorremos tantas filas como tamaño tenga la gráfica
	for (int i = 0; i < TAMANIO_GRAFICA; i++) {

		//Si estamos en la primera...
        if (i == 0) {
        	//...pintamos un espacio
           	cout << setw(ESPACIADO) << " " << "|";
    	
    		//...recorremos las columnas
            for (int j=0; j<TAMANIO_GRAFICA; j++) {
                	
                //...pintamos el numero de columna para hacer mas bonita
            	//la gráfica
                cout << setw(ESPACIADO) << j;

            }
            //Pintamos un salto de línea
            cout << endl;
        }

        //Pintamos el numero de fila (pra hacerlo mas bonito)
        cout << setw(ESPACIADO) << i << "|";

        //Recorremos la gráfica
		for (int j = 0; j < TAMANIO_GRAFICA; j++) {

			//Comprobamos si hay un punto para las coordenadas actuales de la gráfica
			if(ExistePunto(poligono, tamanio, i, j)) {
				//Si existe pintamos el punto
				cout << "*";
			}else {
				//Si no dejamos ese elemnto en blanco
				cout << " ";
			}

			
		}
		//Pintamos un salto de línea (vamos al a siguiente fila)
		cout << endl;

	}


}

