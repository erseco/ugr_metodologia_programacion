/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Supongamos que ahora decidimos utilizar una forma diferente para representar 
 * las matrices bidimensionales dinamicas a la que se propone en el ejercicio 8. 
 * Usaremos una estructura semejante a la que aparece en la figura 5 (tipo Matriz2D-2). 
 * En los apuntes de clase se detalla como crear y liberar esta estructura.
 * 
 * Nota: Recuerde que los modulos que procesan estructuras de este tipo necesitan 
 * recibir como parametros el numero de filas y columnas de la matriz.
 * 
 * b) Construir un modulo que dada una matriz bidimensional dinamica Matriz2D-1 
 *    realice una copia de la misma en una matriz bidimensional dinamica Matriz2D-2 
 *    y la devuelva.
 * c) Desarrollar un modulo que realice el paso inverso, convertir de Matriz2D-2 
 *    a Matriz2D-1 y devolverla.
 *
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include <iomanip>
#include "ConversorMatrices.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main(){

    Matriz2D_2 m2; // "m2" matriz dinamicas 2D.
    int filas, cols;
    
    //Leer num. de filas y columnas
    cout << "Numero de filas : ";
    cin >> filas;
    cout << "Numero de columnas : ";
    cin >> cols;
    
    //Crear matriz dinamica
    cout << "Creando Matriz ("<< filas << "X"<< cols << ")" << endl;
    m2 = CreaMatriz2D_2 (filas, cols);
    
    //Llena la matriz y muestra su contenido
    m2 = LlenarMatriz2D_2(m2, filas, cols);
    cout << endl << "Matriz Original:" << endl;
    PintaMatriz2D_2 (m2, filas, cols);



    //Crea un objeto Matriz2D_1 a partir de un objeto Matriz2D_2
    Matriz2D_1 m1 = InvierteMatriz2D_2_a_1(m2, filas, cols);
    cout << endl << "Matriz2D_1:" << endl;
    PintaMatriz2D_1 (m1, filas, cols);

    //Crea un objeto Matriz2D_2 a partir de un objeto Matriz2D_1
    Matriz2D_2 m2aux = InvierteMatriz2D_2_a_1(m1, filas, cols);
    cout << endl << "Matriz2D_2:" << endl;
    PintaMatriz2D_2 (m2aux, filas, cols);

    //Liberamos la memoria de las matrices convertidas
    LiberaMatriz2D_2 (m2aux, filas, cols);
    LiberaMatriz2D_1 (m1, filas, cols);
    
    // Liberar la memoria ocupada por la matriz original
    cout << endl << "Liberando matriz" << endl;
    LiberaMatriz2D_2 (m2, filas, cols);

    //Terminamos la ejecución del programa
    return (0);

}