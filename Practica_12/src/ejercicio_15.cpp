/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Implementar un programa que similar a head que muestre las primeras lineas 
 *  de un fichero de texto.
 *  
 *  Por ejemplo, la ejecucion de cabecera 15 reconstruye.cpp mostrara las primeras 
 *  15 lineas del fichero de texto reconstruye.cpp
 *  
 *  Se aplican las mismas restricciones que las indicadas en el problema 14 
 *  (excepto la primera, evidentemente).
 *
 ******************************************************************************/

#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void mostrar(istream & entrada, int lineas);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    // Atributos
    ifstream fileEntrada;
    int lineas;

    // Debemos comprobar todos los ficheros pasados
    if (argc != 3) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <num lineas> <fichero1>" << endl;
        exit(1); // Salimos con error
    } 

    // Obtenemos el numero de lineas
    lineas = atoi(argv[1]);

    fileEntrada.open (argv[2]);
    if (!fileEntrada) {
        cerr << "Error: no puedo abrir "  << argv[2] << endl;
        exit(1); // Salimos con error
    }

    // Buscamos en el fichero actual
    mostrar(fileEntrada, lineas);

    // Cerramos el fichero
    fileEntrada.close();

    // Terminamos la ejecución del programa
    return (0);

}
/************************************************/
// Muestra las n primeras lineas de un fichero
void mostrar(istream & entrada, int lineas) {

    int num_linea = 0;
    const int BUFF_SIZE = 500;
    char linea[BUFF_SIZE];

    // Obtenemos una nueva linea
   entrada.getline(linea, BUFF_SIZE);

   while (!entrada.eof() && num_linea < lineas) {

        // Mostramos la linea
        cout << linea << endl;

        // Obtenemos una nueva linea
        entrada.getline(linea, BUFF_SIZE);

        // Incrementamos el contador
        num_linea++;
    }

}
/************************************************/
