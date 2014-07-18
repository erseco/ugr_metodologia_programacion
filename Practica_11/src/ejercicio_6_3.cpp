/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que reciba como parametros tres nombres de ficheros de 
 *  texto. Los dos primeros ficheros contienen numeros reales y estan ordenados. 
 *  El programa tomara los datos de esos ficheros y los ira copiando ordenadamente 
 *  en el tercer fichero, de forma que al finalizar este tambien ordenado.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Lista.h"

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (istream & entrada1, istream & entrada2, ostream & salida);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ifstream fileEntrada1;
    ifstream fileEntrada2;
    ofstream fileSalida;

    if (argc != 4) {
        cerr << "Error: Num. de params. erroneo\n";
        cerr << "Uso: " <<argv[0] << " ficheroEntrada1 ficheroEntrada2 ficheroSalida\n";
        exit(1); // Salimos con error
    } 

    
    fileEntrada1.open (argv[1]);
    if (!fileEntrada1) {
        cerr << "Error: no puedo abrir "  << argv[1] << endl;
        exit(1); // Salimos con error
    }

    fileEntrada2.open (argv[2]);
    if (!fileEntrada2) {
        cerr << "Error: no puedo abrir "  << argv[2] << endl;
        exit(1); // Salimos con error
    }

    fileSalida.open (argv[3]);
    if (!fileSalida) {
        cerr << "Error: no puedo crear "  << argv[3] << endl;
        exit(1); // Salimos con error
    }

    copiar(fileEntrada1, fileEntrada2, fileSalida);

    fileEntrada1.close();
    fileEntrada2.close();
    fileSalida.close();

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Suma los numeros de entrada en la salida
void copiar(istream & entrada1, istream & entrada2, ostream & salida) {

    int n;
 
    Lista lista;

    // Agregamos los numeros del fichero 1 (no haria falta llamar a 
    // AniadirOrdenado, porque se supone que estan ordenados ya)
    while (entrada1 >> n) {

        lista.AniadirOrdenado(n);

    }

    // Agregamos los numeros del fichero 2
    while (entrada2 >> n) {

        lista.AniadirOrdenado(n);

    }

    // Vamos recorriendo la lista hasta que esté vacia
    while (!lista.EstaVacia()) {

        // Obtenemos el primero valor y lo borramos, así hasta que se vacíe
        cout << lista.ObtenerValor(0) << endl;
        lista.Borrar(0);

    }


}
/************************************************/
