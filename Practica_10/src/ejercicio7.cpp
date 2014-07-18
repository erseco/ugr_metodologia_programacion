/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 Ernesto Serrano Collado
 * ------------------------------
 *
 * Implementa una clase Conjunto que permita manipular un conjunto de elementos 
 * de tipo TipoBase. 
 * Para la representacion interna de los datos usar una conjunto de celdas enlazadas. 
 * El orden de los elementos no es importante desde un punto de vista teorico, 
 * pero aconsejamos que se mantengan los elementos ordenados para facilitar la 
 * implementacion de los metodos de la clase.
 * 
 * La clase Conjunto debe contener, al menos, las siguientes operaciones:
 * a) Constructor sin argumentos: crea un conjunto vacio.
 * b) Constructor con un argumento de tipo TipoBase: crea un conjunto con un unico elemento (el proporcio- nado como argumento).
 * c) Constructor de copia (empleando codigo reutilizable).
 * d) Destructor (empleando codigo reutilizable).
 * e) Metodo que consulta si el conjunto esta vacio.
 * f) Sobrecarga del operador de asignacion (empleando codigo reutilizable).
 * g) Metodo que nos diga cuantos elementos tiene el conjunto.
 * h) Metodo que reciba un dato de tipo TipoBase y consulte si pertence al conjunto.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include "Conjunto.h"
#include "Transformaciones.h"
#include "MiVectorDinamico.h"


using namespace std;

/*****************************************************************************/
// Programa Principal
int main() {

	// Declaramos un nuevo vector dinamico
	Conjunto conjunto1;
	
	// Agregamos datos
	conjunto1.Aniadir(3);
	conjunto1.Aniadir(4);
	conjunto1.Aniadir(6);
	conjunto1.Aniadir(10);

	//Creamos un nuevo conjunto usando el constructor de copia
	Conjunto conjunto2 = conjunto1;

	// Imprimimos los valores
	cout << "Conjunto con valores:" << endl;
	conjunto1.PrintValues();

	cout << "Son iguales?: " << (conjunto1 == conjunto2) << endl;
	cout << "Son diferentes?: " << (conjunto1 != conjunto2) << endl;

	cout << "Cambiamos un valor" << endl;
	conjunto2[1] = 20;

	cout << "Son iguales?: " << (conjunto1 == conjunto2) << endl;
	cout << "Son diferentes?: " << (conjunto1 != conjunto2) << endl;

	conjunto2.PrintValues();


	// Probamos las sobrecargas de los operadores +, - y *

	cout << "Creamos un conjunto (3) a partir de la suma de 1 y 2" << endl;
	Conjunto conjunto3 = conjunto1 + conjunto2;
	conjunto3.PrintValues();

	cout << "Agregamos un 2 al final" << endl;
	conjunto3 = conjunto3 + 2;
	cout << "Agregamos un 33 al principio" << endl;
	conjunto3 = 33 + conjunto3;

	Conjunto conjunto4 = conjunto3;

	conjunto3.PrintValues();


	cout << "Quitamos un 33 al conjunto 3" << endl;
	conjunto3 = conjunto3 - 33;
	cout << "Quitamos un 6 al conjunto 3" << endl;
	conjunto3 = conjunto3 - 6;
	conjunto3.PrintValues();

	cout << "Quitamo conjunto 1 al 3" << endl;
	conjunto3 = conjunto3 - conjunto1;

	conjunto3.PrintValues();

	// Obtenemos solo las intersecciones
	Conjunto conjunto5 = conjunto4 * conjunto3;
	cout << "Intersecciones de:" << endl;
	conjunto4.PrintValues();
	cout << "Son:" << endl;
	conjunto5.PrintValues();

	cout << "Pintando vector dinamico..." << endl;
	MiVectorDinamico vector = ConjuntoToVectorDinamico(conjunto5);
	vector.PrintValues();

	cout << "Pintando conjunto..." << endl;
	Conjunto conjunto6 = VectorDinamicoToConjunto(vector);
	conjunto6.PrintValues();


	// Terminamos la ejecución del programa
	return (0);


}