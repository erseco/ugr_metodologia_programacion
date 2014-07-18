/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

#include "Matriz2D_1.h"

using namespace std;

/*****************************************************************************/
// Constructor sin argumentos, que crea una matriz vacia.
Matriz2D_1::Matriz2D_1(void) {

	ReservarMemoria(0, 0);

}

/*****************************************************************************/
// Constructor con un argumento, que crea una matriz cuadrada con el numero de filas y columnas indicado en el argumento.
Matriz2D_1::Matriz2D_1(int n) {

	ReservarMemoria(n, n);

}

/*****************************************************************************/
// Constructor con dos argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo.
Matriz2D_1::Matriz2D_1(int f, int c) {

	ReservarMemoria(f, c);

}

/*****************************************************************************/
// Constructor con tres argumentos, que crea una matriz con el numero de filas indicado en el primer argumento y con el numero de columnas indicado en el segundo argumento. Ademas inicia todas las casillas de la matriz al valor especificado con el tercer argumento.
Matriz2D_1::Matriz2D_1(int f, int c, TipoBase value) {

	ReservarMemoria(f, c);

	Inicializar(value);

}

/*****************************************************************************/
// Constructor que llena una matriz a partir de un fichero
Matriz2D_1::Matriz2D_1(char * nombrefichero) {

	ifstream fileEntrada;
	fileEntrada.open (nombrefichero);
	if (!fileEntrada) {
		cerr << "Error: no puedo abrir "  << nombrefichero << endl;
		exit(1); // Salimos con error
	}

	bool columnascalculadas = false;
	int cols;
	int numero;

    const int BUFF_SIZE = 500;
    char linea[BUFF_SIZE];

    // Recorremos las lineas
    while (fileEntrada.getline(linea, BUFF_SIZE)) {

    	// Comprobamos que la linea no esté vacia
    	if (strlen(linea) > 0) {

    		// La primera vez que accede debe calcular el numero de columnas
    		if (!columnascalculadas) {
    			columnascalculadas = true; // Marca la bandera para que no vuelva a entrar
    			cols = CalculaColumnas(linea);

    			// Reserva la memoria e inicializa la matriz
    			ReservarMemoria(0, cols);
    			Inicializar(0);
    		}

    		istringstream iss;  // Flujo de string a partir de la linea
    		iss.str (linea); 


    		// Agregamos una nueva fila a la matriz
			AgregarFila();

    		int i = 0; // Sumatorio de columna
    		string valor;
    		while (iss >> valor) {  // Recorremos un flujo de un string
    							 	// ya que es la forma mas sencilla de 
    								//obtener palabras desde una linea

    			// Asignamos los valores a la nueva fila de la matriz
    			vector[filas -1][i] = atoi(valor.c_str());
    			i++; // incrementamos el iterador de columna

    		}

    	}


    }

	// Cerramos el fichero
	fileEntrada.close();


}


/*****************************************************************************/
// Esta funcion calcula el numero de columnas del fichero
int Matriz2D_1::CalculaColumnas(char * linea) {

	// Hacemos uso de un flujo de string para obtener las palabras (cada palabra es una columna)
	istringstream iss;  // Objeto istringstream	
	int cols = 0;
	iss.str (linea); 

	string valor;
	while (iss >> valor) {
			cols++; // incrementamos el contador de columnas

	}

	return cols;

}

/*****************************************************************************/
// Constructor de copia
Matriz2D_1::Matriz2D_1(const Matriz2D_1 & otro) {

	// Reserva de memoria para el vector
	ReservarMemoria(otro.filas, otro.columnas);

	// Copia de los valores del vector
	// y de los campos privados
	CopiarDatos(otro);

}

/*****************************************************************************/
// Destructor
Matriz2D_1::~Matriz2D_1() {

	// Liberamos la memoria usada
	LiberarMemoria();

}


/*****************************************************************************/
// Crea una matriz de las dimensiones pasadas como parámetro
void Matriz2D_1::ReservarMemoria (int f, int c) {

	filas = f;
	columnas = c;

	// Declaramos una nueva matriz
	vector = new TipoBase*[filas];

	for (int f=0; f<filas; f++) {
		vector[f] = new TipoBase[columnas]; 
	}                              
   


}

/*****************************************************************************/
// Agrega una fila a la matriz
void Matriz2D_1::AgregarFila() {

	Matriz2D_1 otro = *this;

	ReservarMemoria(filas+1, columnas);
	 
	// Copia los valores del vector (omitiendo la ultima fila)
	for (int f=0; f<filas-1; f++){
		for (int c=0; c<columnas; c++) {
			vector[f][c] = otro.vector[f][c];
		}
	}



}

/*****************************************************************************/
void Matriz2D_1::Inicializar(TipoBase value) {

	for (int i=0; i<filas; i++) {
		for (int h=0; h<columnas; h++) {

			vector[i][h] = value;
		}

	}

}

/*****************************************************************************/
// Metodo (valor devuelto: bool) que consulta si la matriz esta vacia.
bool Matriz2D_1::EstaVacia() {

	for (int i=0; i<filas; i++) {
		for (int h=0; h<columnas; h++) {

			if (vector[i][h] != 0) {
				return false;
			} 
		}

	}

	return true;

}


/*****************************************************************************/
// Pedir memoria para alojar 
void Matriz2D_1::LiberarMemoria() {

	for (int i=0; i<filas; i++)
		delete [] vector[i];    //  Libera una fila

	delete [] vector;     //  Libera el vector de punteros
}

/*******************************************************/
// Copiar campos privados y los coeficientes
void Matriz2D_1::CopiarDatos (const Matriz2D_1 & otro) {

	// Copia los campos privados
	filas = otro.filas;
	columnas = otro.columnas;

	// Copia los valores del vector
	for (int f=0; f<filas; f++){
		for (int c=0; c<columnas; c++) {
			vector[f][c] = otro.vector[f][c];
		}
	}
}

/*****************************************************************************/
// Operador de asignación
Matriz2D_1 & Matriz2D_1::operator = (const Matriz2D_1 & otro){

	if (this != &otro) { // Evitar autoasignacion

		// Libera la memoria ocupada
		LiberarMemoria();
		// Reserva de memoria para los coeficientes
		ReservarMemoria (otro.filas, otro.columnas);
		// Copia los campos privados y los coeficientes
		CopiarDatos(otro);

	}

	return (*this);  // Objeto implicito: parte
					 // izquierda de la asignacion

}

/*****************************************************************************/
// Operador de asignación sobrecargado para asignar a todos los elementos 
// un valor por defecto
Matriz2D_1 & Matriz2D_1::operator = (const TipoBase & defaultvalue){

	Inicializar(defaultvalue);

	return (*this);  // Objeto implicito: parte
				 // izquierda de la asignacion


}

/*****************************************************************************/
// Sobrecarga del operador []
TipoBase & Matriz2D_1::operator () (const int fila, const int columna){

	return  vector[fila][columna];

}

/*****************************************************************************/
 // Operador unario +
Matriz2D_1 Matriz2D_1:: operator + (void){
	return (*this);
}

/*****************************************************************************/
// Operador unario -
Matriz2D_1 Matriz2D_1:: operator - (void){
	return (*this);
}


/*****************************************************************************/
// Sobrecarga del operador +
Matriz2D_1 Matriz2D_1::operator + (const Matriz2D_1 & otro){

	Matriz2D_1 tmp;

	// Comprobamos que tengan el mismo tamaño
	if (filas == otro.filas && columnas == otro.columnas) {

		tmp.ReservarMemoria(filas, columnas);

		for (int f=0; f<filas; f++){
			for (int c=0; c<columnas; c++) {

				tmp.vector[f][c] = (vector[f][c] + otro.vector[f][c]);
			}
		}

	}

	return  SonIguales(otro);


}

/*****************************************************************************/
// Sobrecarga del operador -
Matriz2D_1 Matriz2D_1::operator - (const Matriz2D_1 & otro){

	Matriz2D_1 tmp;

	// Comprobamos que tengan el mismo tamaño
	if (filas == otro.filas && columnas == otro.columnas) {

		tmp.ReservarMemoria(filas, columnas);

		for (int f=0; f<filas; f++){
			for (int c=0; c<columnas; c++) {

				tmp.vector[f][c] = (vector[f][c] - otro.vector[f][c]);
			}
		}

	}

	return  SonIguales(otro);


}

/*****************************************************************************/
// Sobrecarga del operador +=
Matriz2D_1 & Matriz2D_1::operator += (const TipoBase valor){

	  (*this) = (*this) + valor;   // operador binario +
		return (*this);

}

/*****************************************************************************/
// Sobrecarga del operador -=
Matriz2D_1 & Matriz2D_1::operator -= (const TipoBase valor){

	(*this) = (*this) - valor;   // Operador binario -
	return (*this);

}

/*****************************************************************************/
// Sobrecarga del operador *=
Matriz2D_1 & Matriz2D_1::operator *= (const TipoBase valor){

	  //(*this) = (*this) * valor;   // operador binario *
		return (*this);

}

/*****************************************************************************/
// Sobrecarga del operador /=
Matriz2D_1 & Matriz2D_1::operator /= (const TipoBase valor){

	//(*this) = (*this) / valor;   // Operador binario /
	return (*this);

}

/*****************************************************************************/
// Sobrecarga del operador ==
bool Matriz2D_1::operator == (const Matriz2D_1 & otro){

	return  SonIguales(otro);

}

/*****************************************************************************/
// Sobrecarga del operador !=
bool Matriz2D_1::operator != (const Matriz2D_1 & otro){

	return  !SonIguales(otro);

}

/*****************************************************************************/
// Esta funcion comprueba que dos vectores dinamicos sean iguales
bool Matriz2D_1::SonIguales(const Matriz2D_1 & otro) {

	// NOTA: Sé que está desaconsejado tener mas de un return en la misma función
	// pero en este caso quedaría mucho mas sencillo de entender el código, aun 
	// así lo he realizado como se aconseja.

	bool resultado = true;

	// Comprobamos que tengan el mismo tamaño
	if (filas != otro.filas || columnas != otro.columnas) {

		// Difieren
		resultado = false;

	} else {

		// Recorremos los elementos del vector para compararlos con el proporcionado como parametro
		// usamos un bucle while en forma de for
		for (int f=0; resultado && f<filas; f++){
			for (int c=0; resultado && c<columnas; c++) {

				if (vector[f][c] != otro.vector[f][c]) {

					// Difieren
					resultado = false;
				}
			}
		}

	}

	// Devolvemos el resultado
	return resultado;

}

/*****************************************************************************/
// Imprime los valores en la salida estándar
void Matriz2D_1::PrintValues() {

	for (int f=0; f<filas; f++) {
		for (int c=0; c<columnas; c++)
		  cout << setw(4) << vector[f][c]; //  acceso a un elemento
	  cout << endl; //  cada fila se muestra en una linea diferente
	} 

}


