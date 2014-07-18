/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef POLIGONO
#define POLIGONO

#include <vector>

struct Punto2D {
	double x;
	double y;
};

struct Nodo {
	Punto2D punto;
	Nodo * next;

};

typedef Nodo * Poligono;

//Funciones requeridas por el ejercicio, tienen su descripción en el archivo donde se implementan
Poligono LlenarPoligono(std::vector<Punto2D> puntos, int tamanio); 	//Ejercicio 10.a
void LiberaPoligono (Poligono poligono);				//Ejercicio 10.b
int NumeroLados (Poligono poligono);								//Ejercicio 10.c
void PintaRecta (Punto2D p1, Punto2D p2);
void PintarPoligono (Poligono poligono); 				//Ejercicio 10.d
std::vector<Poligono> ObtenerTriangulosDesdeCuadrado(Poligono poligono); 		//Ejercicio 10.e
Poligono ObtenerTrianguloInterno(Poligono poligono); 					//Ejercicio 10.f
Poligono ObtenerPoligonoInscritoCircunferencia(int lados, int radio, Punto2D centro); 	//Ejercicio 10.g


//Estas funciones las he definido personalmente para poder pintar el poligono en la salida estándar
//no son requeridas por el ejercicoi y se pueden obviar
void PintarInformacionPoligono(Poligono p);
bool ExistePunto(Poligono poligono, int tamanio, int x, int y);
void PintarGrafica(Poligono poligono);

#endif