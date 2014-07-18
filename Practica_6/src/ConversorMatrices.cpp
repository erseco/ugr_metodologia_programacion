/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include "ConversorMatrices.h"

/*****************************************************************************/
//Crea una matriz 2D 1 en base a una matriz 2D 2
Matriz2D_1 InvierteMatriz2D_2_a_1 (Matriz2D_2 matriz, int fils, int cols) { 

	//Declaramos una nueva matriz
	Matriz2D_1 matriznueva = CreaMatriz2D_1 (fils, cols);

	//Recorremos filas y columnas
	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++) {

			//Asignamos los valores de la matriz a la matriznueva
			matriznueva[f][c] = matriz[f][c];

		}

	}

	//Devolvemos el resultado
	return matriznueva;

}

/*****************************************************************************/
//Crea una matriz 2D 1 en base a una matriz 2D 2
Matriz2D_2 InvierteMatriz2D_1_a_2 (Matriz2D_1 matriz, int fils, int cols) { 

	//Declaramos una nueva matriz
	Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);

	//Recorremos filas y columnas
	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++) {

			//Asignamos los valores de la matriz a la matriznueva
			matriznueva[f][c] = matriz[f][c];

		}

	}

	//Devolvemos el resultado
	return matriznueva;

}