/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Construir un programa que reconstruya un fichero a partir de una serie de 
 *  ficheros que contienen sus “partes”. Los ficheros que pueden emplearse como 
 *  origen se han creado con los programas descritos en los proble- mas 11 y 12 y 
 *  por ese motivo se emplara el fichero de control creado por esos programas.
 *
 ******************************************************************************/

#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void reconstruir(ofstream & entrada, char *nombreFichero);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ofstream fileSalida;

    // Debemos comprobar todos los ficheros pasados
    if (argc != 2) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <fichero>" << endl;
        exit(1); // Salimos con error
    } 

    fileSalida.open (argv[1], ios::binary);
    if (!fileSalida) {
        cerr << "Error: no puedo crear "  << argv[1] << endl;
        exit(1); // Salimos con error
    }

    // Buscamos en el fichero actual
    reconstruir(fileSalida, argv[1]);

    fileSalida.close();

    // Terminamos la ejecución del programa
    return (0);

}
/************************************************/
// Parte un fichero en varios
void reconstruir(ofstream & salida, char *nombreFichero) {

    // Atributos
    ifstream fileControl;
    const int BUFF_SIZE = 512;
    char buffer[BUFF_SIZE];

    string nomFicheroCtrl = "." + string(nombreFichero) + ".ctrl";


    // Leemos el fichero de control
    fileControl.open (nomFicheroCtrl);
    if (!fileControl) {
        cerr << "Error: no puedo abrir el fichero de control" << endl;
        exit(1); // Salimos con error
    }

    fileControl.getline(buffer, BUFF_SIZE); // Leemos la primera linea (descartada)
    fileControl.getline(buffer, BUFF_SIZE); // Leemos la segunda
    int num_ficheros = atoi(buffer); // La convertimos a int

    // Cerramos el fichero de control
    fileControl.close();


    // Recorremos tantos ficheros como indica el fichero de control
    for (int i=1; i<=num_ficheros; i++) {

        // Abrimso el fichero
        ifstream entrada;
        string nomFichero = string(nombreFichero) + "_" + to_string(i) ;
        entrada.open (nomFichero, ios::binary);
        if (!entrada) {
            cerr << "Error: no puedo abrir el fichero " << nomFichero << endl;
            exit(1); // Salimos con error
        }

        // Leemos su contenido y lo escribimos
        while (!entrada.eof()) {

            entrada.read(reinterpret_cast<char*>(&buffer), BUFF_SIZE);
            int leidos = entrada.gcount();

            salida.write(reinterpret_cast<char*>(&buffer), leidos);


        }

        entrada.close(); // Cerramos el archivo


    }

}
/************************************************/
