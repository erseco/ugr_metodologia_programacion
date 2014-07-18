/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef MATRIZ2D_1
#define MATRIZ2D_1

typedef int ** Matriz2D_1;

Matriz2D_1 CreaMatriz2D_1   (int fils, int cols);
void       LiberaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols);
void       PintaMatriz2D_1  (Matriz2D_1 matriz, int fils, int cols); //Ejercicio 8.b

//Funciones creadas segun el enunciado del ejercicio
Matriz2D_1 LlenarMatriz2D_1(Matriz2D_1 matriz, int fils, int cols); //Ejercicio 8.a
Matriz2D_1 CopiaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols); //Ejercicio 8.c
Matriz2D_1 SubMatriz2D_1 (Matriz2D_1 matriz, int fil_desde, int col_desde, int fil_hasta, int col_hasta); //Ejercicio 8.d

Matriz2D_1 EliminaFilaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols, int filaborrar);		//Ejercicio 8.e
Matriz2D_1 EliminaColumnaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols, int columnaborrar);	//Ejercicio 8.f
Matriz2D_1 TraspuestaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols); 		//Ejercicio 8.g
Matriz2D_1 InvierteMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols); 		//Ejercicio 8.h

#endif