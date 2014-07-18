/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Construir un programa que divida un fichero de texto en diferentes ficheros 
 *  indicando como argumentos el nombre del fichero original y el maximo numero 
 *  de lineas que contendra cada fichero resultante.
 *
 *  Se creara un fichero de control que contendra con los datos necesario para 
 *  la reconstruccion del fichero original.
 *
 *  Por ejemplo, si Fichero contiene 1600 lineas, la ejecucion de 
 *
 *      parte_lineas Fichero 500 
 *
 *  genera como resultado los ficheros Fichero_1, Fichero_2, Fichero_3 y 
 *  Fichero_4. Los tres primeros contienen 500 lineas de Fichero y el ultimo, 
 *  las 100 restantes. Se creara un fichero oculto llamado .Fichero.ctrl que 
 *  contendra (formato texto, en dos lineas separadas): nombre del fichero 
 *  original y numero de ficheros resultan- tes de la particion.
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
        cerr << "Uso: " <<argv[0] << " <num lineas> <fichero1>" << endl;
        exit(1); // Salimos con error
    } 

    lineas = atoi(argv[2]);

    fileEntrada.open (argv[1]);
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
void partir(istream & entrada, char *nombreFichero, int lineas) {

    // Atributos
    ofstream fileSalida;
    ofstream fileControl;

    string nomFicheroCtrl = "." + string(nombreFichero) + ".ctrl";

    int num_ficheros = 0;
    int num_linea = 0;
    
    const int BUFF_SIZE = 500;
    char linea[BUFF_SIZE];

    // Recorremos las lineas
    while (entrada.getline(linea, BUFF_SIZE)) {

        // Incrementamos el contador
        num_linea++;

        // Si hemos sobrepasado las lineas maximas...
        if (num_linea >= lineas) {
            num_linea = 0; //Reseteamos el numero de lineas
            num_ficheros++;
            fileSalida.close(); // Cerramos el archivo
            string nomFichero = string(nombreFichero) + "_" + to_string(num_ficheros) ;

            // Abrimos otro archivo
            fileSalida.open (nomFichero);
            if (!fileSalida) {
                cerr << "Error: no puedo crear el fichero " << nomFichero << endl;
                exit(1); // Salimos con error
            }


        }

        // Escribimos la linea
        fileSalida << linea << endl;


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
