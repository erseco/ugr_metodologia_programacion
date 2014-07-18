/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que reciba los nombres de dos ficheros de texto de la 
 *  linea de ordenes. El programa creara un fichero (cuyo nombre se especifica 
 *  en el segundo argumento) a partir de un fichero existente (cuyo nombre se 
 *  especifica en el primer argumento) copiando su contenido y añadiendo al 
 *  principio de cada linea, su numero.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (istream & entrada, ostream & salida);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ifstream fileEntrada;
    ofstream fileSalida;

    if (argc != 3) {
        cerr << "Error: Num. de params. erroneo\n";
        cerr << "Uso: " <<argv[0] << " ficheroEntrada ficheroSalida\n";
        exit(1); // Salimos con error
    } 

    
    fileEntrada.open (argv[1]);
    if (!fileEntrada) {
        cerr << "Error: no puedo abrir "  << argv[1] << endl;
        exit(1); // Salimos con error
    }

    fileSalida.open (argv[2]);
    if (!fileSalida) {
        cerr << "Error: no puedo crear "  << argv[2] << endl;
        exit(1); // Salimos con error
    }

    // Copiamos de cin
    copiar(fileEntrada, fileSalida);

    fileEntrada.close();
    fileSalida.close();

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Suma los numeros de entrada en la salida
void copiar (istream & entrada, ostream & salida) {

    int num_linea = 1;
    const int BUFF_SIZE = 256;
    char c[BUFF_SIZE];

   entrada.getline(c, BUFF_SIZE);

   while (!entrada.eof()) {

        salida << num_linea << ": " << c << endl;

        entrada.getline(c, BUFF_SIZE);

        num_linea++;
    }

   salida << num_linea << ": " << c << endl;;

}
/************************************************/
