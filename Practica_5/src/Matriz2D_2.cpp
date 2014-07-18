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
#include "Matriz2D_2.h"

using namespace std;

/*****************************************************************************/
//Crea una matriz de las dimensiones pasadas como parámetro
Matriz2D_2 CreaMatriz2D_2 (int fils, int cols) {

	//Declaramos una nueva matriz
	Matriz2D_2 matriz = new  int * [fils];  // puntero local a un
											// vector de punteros
	matriz[0] = new  int [fils*cols];  	// vector de datos: todos
										// estan en una sola fila
	for(int f=1; f<fils ; f++)
		matriz[f] = matriz[f-1] + cols; // apuntar con "matriz[f]"
										// al inicio de la fila "f"
	//Devolvemos el resultado
	return (matriz);

}

void LiberaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {

	 delete [] matriz[0];  // Libera el vector de datos
	 delete [] matriz;     // Libera el vector de punteros

}

void PintaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {

	 for (int f=0; f<fils; f++) {
			for (int c=0; c<cols; c++)
					cout << setw(4) << matriz[f][c]; // acceso a un elemento
			cout << endl; // cada fila se muestra en una linea diferente
		}
		 
}

/*****************************************************************************/
//Solicita datos al usuario hasta llenar la matriz
Matriz2D_2 LlenarMatriz2D_2(Matriz2D_2 matriz, int fils, int cols) {

	double value;

		//Rellenarlas (observar el acceso por indices)
	cout << endl << "Rellenando matrices" << endl;

	//Recorremos las filas y las columnas de la matriz
	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++) {

			//Solicitamos los datos
			cout << "Introduzca un valor para la coordenada (" << f << ", " << c << "): ";
			cin >> value;

			//Los introducimos en la nueva matriz
			matriz[f][c] = value;

		}

	}
	
	//Devolvemos el resultado
	return matriz;

}

/*****************************************************************************/
//Copia el contenido de la matriz en una nueva
Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {

	//Declaramos una nueva matriz
	Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);

	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++) {

			matriznueva[f][c] = matriz[f][c];

		}

	}

	//Devolvemos el resultado
	return matriznueva;

}

/*****************************************************************************/
//Crea una submatriz a partir de la que se le pasa como parámetro
//NOTA: La comprobación de que desde y hasta sean inferiores al tamaño de la matriz
//se realiza fuera para no tener que pasarle las dimensiones a la matriz
Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz, int fil_desde, int col_desde, int fil_hasta, int col_hasta) {

	//Las dimensiones de la nueva matriz serán hasta - desde
	int fils = fil_hasta - fil_desde;
	int cols = col_hasta - col_desde;

	//Declaramos una nueva matriz
	Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);

	//Recorremos la matriz
	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++) {

			//Copiamos los datos de la vieja a la nueva
			matriznueva[f][c] = matriz[f + fil_desde][c + col_desde];
		}

	}

	//Devolvemos el resultado
	return matriznueva;

}

/*****************************************************************************/
//Elimina una fila de la matriz
Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int filaborrar) {

	//Declaramos una nueva matriz
	Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils - 1, cols);


	//Comprobación de que la fila a borrar no este fuera del limite
	if (filaborrar < fils) {

		//Recorremos las filas (menos 1, que es la que quitaremos)
		for (int f=0, f2=0; f<fils - 1; f++, f2++) {


			//Si estamos en la fila a borrar incrementamos el valor de f2 en 1, así nos la saltamos
			if (f == filaborrar) {
				f2++;
			}

			//Recorrelmos las columnas
			for (int c=0; c<cols; c++) {
							
				//Copiamos los valores (usamos f2 en el origen 
				//porque habrá un punto donde se incremente una linea)
				matriznueva[f][c] = matriz[f2][c];
			}


		}

	}

	//Devolvemos el resultado
	return matriznueva;

}

/*****************************************************************************/
//Elimina una columna de la matriz
Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columnaborrar) {

	//Declaramos una nueva matriz
	Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols - 1);

	//Comprobación de que la columna a borrar no este fuera del limite
	if (columnaborrar < cols) {

		//Recorremos las filas
		for (int f=0; f<fils; f++) {

			//Recorremos las columnas (menos 1, que es la que quitaremos)
			for (int c=0, c2=0; c<cols - 1; c++, c2++) {
				
				//Si estamos en la columna a borrar incrementamos el valor de c2 en 1, así nos la saltamos
				if (c == columnaborrar) {
					c2++;
				}

				//Copiamos los valores (usamos c2 en el origen 
				//porque habrá un punto donde se incremente una linea)
				matriznueva[f][c] = matriz[f][c2];
			}


		}

	}

	//Devolvemos el resultado
	return matriznueva;

}

/*****************************************************************************/
//Obtiene la traspuesta de la matriz
Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {

	//Declaramos una nueva matriz
	Matriz2D_2 matriznueva = CreaMatriz2D_2 (cols, fils);

	//Recorremos la matriz
	for (int f=0; f<cols; f++) {


		for (int c=0; c<fils; c++) {
		
			//Copiamos los datos trasponiendo la posicion
			matriznueva[f][c] = matriz[c][f];

		}


	}

	//Devolvemos el resultado
	return matriznueva;

}

/*****************************************************************************/
//Invierte las filas de la matriz
Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {

	//Declaramos una nueva matriz
	Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);

	//Recorremos las filas teniendo dos variables, desde el principio(f1) y desde el final(f2)
	for (int f1=0,f2=fils-1; f1<fils; f1++,f2--) {

		//Recorremos las columnas
		for (int c=0; c<cols; c++) {
			
			//Copiamos los datos invirtiendo las filas
			matriznueva[f1][c] = matriz[f2][c];

		}


	}

	//Devolvemos el resultado
	return matriznueva;

}

/*****************************************************************************/
//Crea una matriz 2D 1 en base a una matriz 2D 2
Matriz2D_1 InvierteMatriz2D_2_a_1 (Matriz2D_2 matriz, int fils, int cols) { 

	//Declaramos una nueva matriz
	Matriz2D_1 matriznueva = CreaMatriz2D_1 (fils, cols);

	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++) {

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

	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++) {

			matriznueva[f][c] = matriz[f][c];

		}

	}

	//Devolvemos el resultado
	return matriznueva;

}