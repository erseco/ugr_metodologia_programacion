/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que escriba en la salida estandar una linea de resultado 
 *  por cada linea de entrada, y en cada linea mostrara las sumas de los valores 
 *  de cada grupo que la componen.
 *
 *	Un ejemplo de archivo sería:
 *
 * 	3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
 *
 * 	4 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7 2 2.2 2.2
 *	  	
 *	3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 4 5.2 4.7 8.1 3.2
 *
 * 	NOTA: Este ejercicio se ha resuelto de dos formas, procesar() y procesar2()
 *	La primera es la mas eficiente
 *
 ******************************************************************************/

#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void procesar(istream & entrada);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

	if (argc == 1) {
		// No hemos pasado ningun parametor, leemos de la entrada estándar
		procesar(cin);

	} else {
		// Hemos pasado algun parámetro, el primero será el fichero a leer
		ifstream fileEntrada;
		fileEntrada.open (argv[1]);
		if (!fileEntrada) {
			cerr << "Error: no puedo abrir "  << argv[1] << endl;
			exit(1); // Salimos con error
		}

	   // Buscamos en el fichero actual
		procesar(fileEntrada);

		// Cerramos el fichero
		fileEntrada.close();

	}


	// Terminamos la ejecución del programa
	return (0);

}
/************************************************/
// Procesa el fichero
void procesar(istream & entrada) {

	// Atributos
	const int BUFF_SIZE = 500;
	char linea[BUFF_SIZE];

	// Aqui vamos almacenando las palabras (omitirá espacios y demás)
	int grupo1; 

	// Recorremos los grupos 1
	while (entrada >> grupo1) {

		// Recorremos tantos elementos como tiene el grupo 1
		for (int i = 0; i < grupo1; i++) {

			int grupo2;
			entrada >> grupo2;

			double suma = 0;

			// Recorremos tantos elementos como tiene el grupo 2
			for (int j = 0; j < grupo2; j++) {

				double valor;
				entrada >> valor;

				// Incrementamos el sumatorio
				suma += valor;


			}
			// Pintamos el valor con un tabulador
			cout << suma << "\t";


		} 

		// Pintamos un salto de linea
		cout << endl;


	}


}

/************************************************/
// Procesa el fichero
// NOTA: Esta es una versión menos eficiente realizada en un primer momento
void procesar2(istream & entrada) {

	// Atributos
	const int BUFF_SIZE = 500;
	char linea[BUFF_SIZE];

	int cont_grupo_1 = 0; // Contador del grupo 1 (primer numero)
	int cont_grupo_2 = 0; // Contador del grupo 2 (segundo numero)
	double sum_grupo_3 = 0; // Sumatorio de numeros dentro del grupo 2

	// Recorremos las lineas
	while (entrada.getline(linea, BUFF_SIZE)) {

		// Creamos un objeto istringstream al que le asignaremos la linea
		istringstream iss;   
		iss.str (linea); 

		// Aqui vamos almacenando las palabras (omitirá espacios y demás)
		double valor; 

		// Vamos recorriendo las palabras (numeros) de la linea
		while (iss >> valor) {
				
				// Si el grupo1 está a 0 es la primera palabra
				if (cont_grupo_1 == 0) {

					// Obtenemos el numero del grupo
					cont_grupo_1 = valor;
					cont_grupo_2 = 0; // ¿hace falta?

				} else {

					// Si el grupo2 es que comienza un grupo (o es el primero o ha terminado el anterior)
					if (cont_grupo_2 == 0) {

						// Si la suma es distinto de 0 es porque ha terminado el anterior
						if (sum_grupo_3 > 0) {	
							// Lo mostramos con un tabulador
							cout << sum_grupo_3 << "\t";
						}

						// Obtenemos el número del grupo2
						cont_grupo_2 = valor;
						// Ponemos el sumatior a 0
						sum_grupo_3 = 0;
						

					} else {
						// Decrementamos el grupo2
						cont_grupo_2--;
						// Incrementamos el sumatorio
						sum_grupo_3 += valor;

					}

				}

		}

		// Fin de fila, si la suma es distinto de 0 es porque el anterior tenía numero 
		if (sum_grupo_3 > 0) {
			// Lo pintamos con un salto de linea y lo ponemos todo a 0
			cout << sum_grupo_3 << endl;
			sum_grupo_3 = 0;
			cont_grupo_2 =0;
			cont_grupo_1 = 0;
		}

	}


}
/************************************************/
