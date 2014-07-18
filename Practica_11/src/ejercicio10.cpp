/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que lea una serie indefinida de numeros enteros de la 
 *  entrada estandar y los copie, en el mismo orden, en la salida estandar.
 *  
 *  En la secuencia de entrada, dos numeros consecutivos estan separados por el caracter *. 
 *  En la secuencia de salida se separan dos enteros consecutivos con un salto de linea.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>

using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copiar (istream & entrada);

/************************************************/
// Programa Principal
int main (int argc, char **argv) {

    // Copiamos de cin
    copiar(cin);

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Copia los numeros entrada en la salida (separador *)
void copiar (istream & entrada) {

    int i;
    char c;

    // NOTA: cin >> (int)c convierte lo de cin a entero, y omite el resto,
    // asi que tomará como separador el asterisco sin problemas

    // Vamos obteniendo palabras y conviertiendolas a int
    //OJO!! igual interesa un getline() con tercer argumento "*" VER SOLUCIONES
    while (cin >> i >> c) {

        // Pintamos el numero en la salida estandar con un salto de linea
        cout << i << endl; 
    
    }

}
/************************************************/
