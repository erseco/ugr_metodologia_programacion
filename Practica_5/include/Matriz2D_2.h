/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef MATRIZ2D_2
#define MATRIZ2D_2

#include "Matriz2D_1.h"

typedef int ** Matriz2D_2;

Matriz2D_2 CreaMatriz2D_2   (int fils, int cols);
void       LiberaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
void       PintaMatriz2D_2  (Matriz2D_2 matriz, int fils, int cols);

//Funciones creadas segun el enunciado del ejercicio
Matriz2D_2 LlenarMatriz2D_2(Matriz2D_2 matriz, int fils, int cols); //Ejercicio 9.a
Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols); //Ejercicio 9.a
Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz, int fil_desde, int col_desde, int fil_hasta, int col_hasta); //Ejercicio 9.a

Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int filaborrar);		//Ejercicio 9.a
Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columnaborrar);	//Ejercicio 9.a
Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols); 		//Ejercicio 9.a
Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols); 		//Ejercicio 9.a

//Ejercicios opcionales
Matriz2D_1 InvierteMatriz2D_2_a_1 (Matriz2D_2 matriz, int fils, int cols); 		//Ejercicio 9.b
Matriz2D_2 InvierteMatriz2D_1_a_2 (Matriz2D_1 matriz, int fils, int cols); 		//Ejercicio 9.c


#endif