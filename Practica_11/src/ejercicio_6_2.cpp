/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa similar a diff para comparar dos ficheros de texto. 
 *  El programa imprimira el numero de la primera linea en la que difieren y el 
 *  contenido de estas.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>
#include <iomanip>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (char nombre_1[], istream & entrada1, char nombre_2[], istream & entrada2);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ifstream fileEntrada1;
    ifstream fileEntrada2;

    if (argc != 3) {
        cerr << "Error: Num. de params. erroneo\n";
        cerr << "Uso: " <<argv[0] << " ficheroEntrada ficheroAComparar\n";
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

    // Copiamos de cin
    copiar(argv[1], fileEntrada1, argv[2], fileEntrada2);

    fileEntrada1.close();
    fileEntrada2.close();

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Suma los numeros de entrada en la salida
void copiar (char nombre_1[], istream & entrada1, char nombre_2[], istream & entrada2) {

    int num_linea = 1;
    const int BUFF_SIZE = 256;
    char c1[BUFF_SIZE];
    char c2[BUFF_SIZE];

   entrada1.getline(c1, BUFF_SIZE);
   entrada2.getline(c2, BUFF_SIZE);


   while (!entrada1.eof()) {

        if (strcmp(c1, c2) != 0) {

            cout << "(" << setw(4) << num_linea << ") ";
            cout << nombre_1 << ": " << c1 << endl;
            cout << setfill(' ') << setw(7) << "" << nombre_2 << ": " << c2 << endl;

        }

        entrada1.getline(c1, BUFF_SIZE);
        entrada2.getline(c2, BUFF_SIZE);

        num_linea++;
    }

    if (strcmp(c1, c2) != 0) {

        cout << "(" << setw(4) << num_linea << ") ";
        cout << nombre_1 << ": " << c1 << endl;
        cout << setfill(' ') << setw(7) << "" << nombre_2 << ": " << c2 << endl;

    }
}
/************************************************/
