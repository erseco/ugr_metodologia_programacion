/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que reciba el nombre de dos ficheros. 
 *	El programa copiara, en el mismo orden, los numeros que contiene el fichero 
 *	de entrada en el fichero de salida.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S
#include <stdlib.h>

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copia(istream & entrada, ostream & salida);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ifstream fileEntrada;
    ofstream fileSalida;

    if (argc != 3) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <ficheroE> <ficheroS>" << endl;
        exit(1); // Salimos con error
    } 

    fileEntrada.open(argv[1]);
    if (!fileEntrada) {
        cerr << "Error: no puedo abrir "  << argv[1] << endl;
        exit(1); // Salimos con error
    }

    fileSalida.open(argv[2], ios::binary);
    if (!fileSalida) {
        cerr << "Error: no puedo crear "  << argv[2] << endl;
        exit(1); // Salimos con error
    }

	copia(fileEntrada, fileSalida);
   

    fileEntrada.close();
    fileSalida.close();

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Copia los numeros del fichero de entrada en el de salida
void copia(istream & entrada, ostream & salida) {

	unsigned int num;

	// Vamos obteniendo numeros
	while (entrada >> num) {

		salida.write(reinterpret_cast<char *>(&num), sizeof(unsigned int));

	}

}
/************************************************/
