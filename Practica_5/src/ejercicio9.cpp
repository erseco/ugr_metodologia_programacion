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
 * a) Reescribir todos los modulos propuestos en el ejercicio 8 usando esta nueva 
 *    representacion.
 * b) Construir un modulo que dada una matriz bidimensional dinamica Matriz2D-1 
 *    realice una copia de la misma en una matriz bidimensional dinamica Matriz2D-2 
 *    y la devuelva.
 * c) Desarrollar un modulo que realice el paso inverso, convertir de Matriz2D-2 
 *    a Matriz2D-1 y devolverla.
 *
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include <iomanip>
#include "Matriz2D_2.h"
#include "Matriz2D_1.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main(){

    Matriz2D_2 m2; // "m2" matriz dinamicas 2D.
    int filas, cols;
    
    // Leer num. de filas y columnas
    cout << "Numero de filas : ";
    cin >> filas;
    cout << "Numero de columnas : ";
    cin >> cols;
    
    // Crear matrices dinamicas
    cout << "Creando Matriz ("<< filas << "X"<< cols << ")" << endl;
    m2 = CreaMatriz2D_2 (filas, cols);
    
    //Llena la matriz y muestra su contenido
    m2 = LlenarMatriz2D_2(m2, filas, cols);
    cout << endl << "Matriz Original:" << endl;
    PintaMatriz2D_2 (m2, filas, cols);


    //Copia la matriz y muestra su contenido
    Matriz2D_2 copia_m2 = CopiaMatriz2D_2(m2, filas, cols);
    cout << endl << "Copia Matriz:" << endl;
    PintaMatriz2D_2 (copia_m2, filas, cols);
    LiberaMatriz2D_2 (copia_m2, filas, cols);

    int desde = 0, hasta = 2;
    if (filas >= hasta && cols >= hasta) {
        //Crea una submatriz y muestra su contenido
        Matriz2D_2 sub_m2 = SubMatriz2D_2(m2, desde, desde, hasta, hasta);
        cout << endl << "Sub Matriz:" << endl;
        PintaMatriz2D_2 (sub_m2, hasta - desde, hasta - desde);
        LiberaMatriz2D_2 (sub_m2, hasta - desde, hasta - desde);
    }

    //Elimina una fila de la matriz y muestra su contenido
    Matriz2D_2 delf_m2 = EliminaFilaMatriz2D_2(m2, filas, cols, 0);
    cout << endl << "Matriz con fila eliminada:" << endl;
    PintaMatriz2D_2 (delf_m2, filas - 1, cols);
    LiberaMatriz2D_2 (delf_m2, filas - 1, cols);


    //Elimina una columna de la matriz y muestra su contenido
    Matriz2D_2 delc_m2 = EliminaColumnaMatriz2D_2(m2, filas, cols, 0);
    cout << endl << "Matriz con columna eliminada:" << endl;
    PintaMatriz2D_2 (delc_m2, filas, cols - 1);
    LiberaMatriz2D_2 (delc_m2, filas, cols - 1);


    //Obtiene la traspuesta de la matriz y muestra su contenido
    Matriz2D_2 tras_m2 = TraspuestaMatriz2D_2(m2, filas, cols);
    cout << endl << "Traspuesta Matriz:" << endl;
    PintaMatriz2D_2 (tras_m2, cols, filas);
    LiberaMatriz2D_2 (tras_m2, cols, filas);

    //Obtiene la inversa de la matriz y muestra su contenido
    Matriz2D_2 inv_m2 = InvierteMatriz2D_2(m2, filas, cols);
    cout << endl << "Matriz invertida:" << endl;
    PintaMatriz2D_2 (inv_m2, filas, cols);
    LiberaMatriz2D_2 (inv_m2, filas, cols);


    /*** Inicio llamada a opcionales ***/
    Matriz2D_1 m1 = InvierteMatriz2D_2_a_1(m2, filas, cols);
    cout << endl << "Matriz2D_1:" << endl;
    PintaMatriz2D_1 (m1, filas, cols);

    Matriz2D_2 m2aux = InvierteMatriz2D_2_a_1(m1, filas, cols);
    cout << endl << "Matriz2D_2:" << endl;
    PintaMatriz2D_2 (m2aux, filas, cols);

    LiberaMatriz2D_2 (m2aux, filas, cols);
    LiberaMatriz2D_1 (m1, filas, cols);
    /*** Fin llamada a opcionales ***/
    
    // Liberar la memoria ocupada
    cout << endl << "Liberando matriz" << endl;
    LiberaMatriz2D_2 (m2, filas, cols);

    return (0);

}