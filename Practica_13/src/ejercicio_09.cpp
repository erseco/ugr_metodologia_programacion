/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea un fichero binario como los generados en los 
 *  problemas 7 y 8 y que muestre en la salida estandar la suma de todos esos 
 *  numeros. Para la lectura se empleara un buffer de 512 bytes.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void suma(istream & entrada);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ifstream fileEntrada;

    if (argc != 2) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <ficheroE>" << endl;
        exit(1); // Salimos con error
    } 

    fileEntrada.open(argv[1], ios::binary);
    if (!fileEntrada) {
        cerr << "Error: no puedo abrir "  << argv[1] << endl;
        exit(1); // Salimos con error
    }

	suma(fileEntrada);
   
    fileEntrada.close();

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Suma los numeros del fichero de entrada
void suma(istream & entrada) {

    const int TAM_BUFFER = 512; // Num. de bytes del buffer de lectura
    char buffer [TAM_BUFFER];    // Buffer de lectura

	int sum = 0;
    int leido = 0;

    while (!entrada.eof()) {
        
        // Leemos del fichero
        entrada.read(reinterpret_cast<char*>(&buffer), TAM_BUFFER);

        leido = entrada.gcount();

        // Recorremos el buffer sumando sus valores
        for (int i=0; i<leido; i++) {
            sum += buffer[i];
        }

    }

    
    // Mostramos la suma en la salida
    cout << "La suma de los números es: " << sum << endl;

}
/************************************************/
