/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Construir un programa que divida un fichero de cualquier tipo en diferentes 
 *  ficheros, indicando como argumentos el nombre del fichero original y el 
 *  maximo numero de bytes que contendra cada fichero resultante.
 *
 ******************************************************************************/

#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void partir(istream & entrada, char *nombreFichero, int lineas);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ifstream fileEntrada;
    int lineas;

    // Debemos comprobar todos los ficheros pasados
    if (argc != 3) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <fichero1> <num bytes>" << endl;
        exit(1); // Salimos con error
    } 

    lineas = atoi(argv[2]);

    fileEntrada.open (argv[1], ios::binary);
    if (!fileEntrada) {
        cerr << "Error: no puedo abrir "  << argv[1] << endl;
        exit(1); // Salimos con error
    }

    // Buscamos en el fichero actual
    partir(fileEntrada, argv[1], lineas);

    fileEntrada.close();

    // Terminamos la ejecución del programa
    return (0);

}
/************************************************/
// Parte un fichero en varios
void partir(istream & entrada, char *nombreFichero, int maximoarchivo) {

    // Atributos
    ofstream fileSalida;
    ofstream fileControl;

    string nomFicheroCtrl = "." + string(nombreFichero) + ".ctrl";

    int num_ficheros = 0;
    int leidos;
    
    const int BUFF_SIZE = 500;
    char linea[BUFF_SIZE];

    // Recorremos las lineas
    while (!entrada.eof()) {

        entrada.read(reinterpret_cast<char*>(&linea), BUFF_SIZE);

        // Incrementamos el contador
        leidos = entrada.gcount();
        // Si hemos sobrepasado los bytes maximos...
        if (leidos >= maximoarchivo) {
            num_ficheros++;
            fileSalida.close(); // Cerramos el archivo
            string nomFichero = string(nombreFichero) + "_" + to_string(num_ficheros) ;

            // Abrimos otro archivo
            fileSalida.open (nomFichero, ios::binary);
            if (!fileSalida) {
                cerr << "Error: no puedo crear el fichero " << nomFichero << endl;
                exit(1); // Salimos con error
            }


        }
        
        // Escribimos lo leido
        fileSalida.write(reinterpret_cast<char*>(&linea), leidos);


    }

    // Cerramos el archivo
    fileSalida.close();
    

    // Creamos el fichero de control, lo escribimos y lo cerramos
    fileControl.open (nomFicheroCtrl);
    if (!fileControl) {
        cerr << "Error: no puedo crear el fichero de control" << endl;
        exit(1); // Salimos con error
    }
    fileControl << nombreFichero << endl;
    fileControl << num_ficheros << endl;

    fileControl.close();

}
/************************************************/
