/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa similar a grep que busque una cadena en una serie de 
 *  ficheros de texto. La cadena a buscar y los ficheros en los que buscar se 
 *  proporcionan en la linea de ordenes.
 *   
 *  Por ejemplo:
 *      busca Olga fich1 fich2 fich3
 *      busca la cadena Olga en los ficheros fich1, fich2 y fich3.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void buscar(istream & entrada, char *nombre, char *cadena);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    // Atributos
    ifstream fileEntrada;

    // Debemos comprobar todos los ficheros pasados
    if (argc < 3) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <cadena a buscar> <fichero1> <fichero2> <fichero3>..." << endl;
        exit(1); // Salimos con error
    } 

    // Recorremos los ficheros pasados (ilimitados hasta el limite de int)
    for (int i=2; i<argc; i++) {
    
        // Abrimos el fichero
        fileEntrada.open (argv[i]);
        if (!fileEntrada) {
            cerr << "Error: no puedo abrir "  << argv[i] << endl;
            exit(1); // Salimos con error
        }

        // Buscamos en el fichero actual
        buscar(fileEntrada, argv[i], argv[1]);

        // Cerramos el fichero
        fileEntrada.close();

    }

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Busca una cadena en las lineas de un fichero
void buscar(istream & entrada, char *nombre, char *cadena) {

    int num_linea = 1;
    const int BUFF_SIZE = 500;
    char linea[BUFF_SIZE];

   entrada.getline(linea, BUFF_SIZE);

   while (!entrada.eof()) {

        if (strstr(linea, cadena) != NULL) {

             cout << nombre << " (linea " << num_linea << "): " << linea << endl;

        }

        entrada.getline(linea, BUFF_SIZE);

        num_linea++;
    }

    if (strstr(linea, cadena) != NULL) {

         cout << nombre << " (linea " << num_linea << "): " << linea << endl;

    }
}
/************************************************/
