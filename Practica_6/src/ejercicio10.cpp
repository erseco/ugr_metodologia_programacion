/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Se desea desarrollar una estructura de datos que permita representar de 
 * forma general diversas figuras po- ligonales. Cada figura poligonal se puede 
 * representar como un conjunto de puntos en el plano unidos por segmentos de 
 * rectas entre cada dos puntos adyacentes. 
 * 
 * Por esta razon se propone la representacion mostra- da en la figura 6.
 * Asi, un poligono se representa como una secuencia circular y ordenada de 
 * nodos enlazados.
 *
 * Teniendo en cuenta esta representacion, responder a las siguientes cuestiones: 
 *  a) Implementar un modulo que permita iniciar y “rellenar” una variable de 
 *      tipo Poligono proporcionandole un vector de datos de tipo Punto2D y el 
 *      numero de puntos que debe emplear para iniciar el poligono.
 *  b) Desarrollar un modulo que permita liberar la memoria reservada por una 
 *      variable Poligono.
 *  c) Construir un modulo que determine el numero de lados que contiene la 
 *      figura almacenada en una variable de tipo Poligono.
 *  d) Suponiendo que existe una funcion llamada 
 *      PintaRecta (Punto2D pl, Punto2D p2) 
 *      que pinta una recta entre los dos puntos que se le pasan como argumentos, 
 *      construir un modulo que permita pintar la figura que representa una 
 *      determinada variable Poligono.
 *  e) Sabiendo que una variable Poligono almacena un cuadrado, implementar un 
 *      modulo que devuelva los dos triangulos que resultan de unir mediante 
 *      una recta la esquina inferior izquierda del cuadrado con su esquina 
 *      superior derecha (figura 7.A).
 *  f) Construir un modulo que a partir de una variable Poligono que representa 
 *      a un triangulo devuelva el triangulo formado por los puntos medios de 
 *      las rectas del triangulo original (figura 7.B).
 *  g) Desarrollar un modulo que permita construir un poligono regular de n lados 
 *      inscrito en una circunferencia de radio r y centro (x,y) (figura 7.C).
 *
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include <iomanip>
#include <vector>
#include "Poligono.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main(){

    //Definimos un poligono
    Poligono poligono; 
    vector<Punto2D> puntos; //En este vector almacenaremos los 
                            //puntos con los que crearemos el poligono

    //Creamos un nuevo punto (lo reutilizaremos)
    Punto2D punto;

    // //AQUI PEDIMOS DATOS AL USUARIO (descomentar el bloque deseado)
    // int x, y; //En estas variables almacenamos los puntos introducidos por teclado
    // //Vamos pidiendo datos al usuario
    // do {
    //     cout << "Introduzca un valor para X (-1 para salir): ";
    //     cin >> x;
    //     if (x > -1) { //Si el numero es > -1 el punto es válido
    //         cout << "Introuzca un valor para Y:";
    //         cin >> y;
    //         //Asignamos los valores del punto 
    //         punto.x = x;
    //         punto.y = y;
    //         //Lo agregamos al vector de puntos
    //         puntos.push_back(punto);
    //     }
    // } while (x > -1);


    // //AQUI DEFINIMOS UN TRIANGULO DE FORMA FIJA (descomentar el bloque deseado)
    // puntos.clear();
    // punto.x = 2; punto.y = 0;
    // puntos.push_back(punto);
    // punto.x = 4; punto.y = 0;
    // puntos.push_back(punto);
    // punto.x = 3; punto.y = 1;
    // puntos.push_back(punto);

    //AQUI DEFINIMOS UN CUADRADO DE FORMA FIJA (descomentar el bloque deseado)
    puntos.clear();
    punto.x = 2; punto.y = 1;
    puntos.push_back(punto);
    punto.x = 5; punto.y = 1;
    puntos.push_back(punto);
    punto.x = 5; punto.y = 4;
    puntos.push_back(punto);
    punto.x = 2; punto.y = 4;
    puntos.push_back(punto);


    //Creamos un polígono a partir del vector y pintamos su información
    cout << "Creando Poligono" << endl;
    poligono = LlenarPoligono(puntos, puntos.size());
    PintarInformacionPoligono(poligono);

    //Pintamos el número de lados del polígono (para probar la función NumeroLados)
    cout << "Numero de lados: " << NumeroLados(poligono) << endl;

    //Pintamos el polígono (para probar la función PintarPoligono)
    PintarPoligono(poligono);


    //Obtenemos dos triangulos a partir de un cuadrado y pintamos su información
    vector<Poligono> triangulos = ObtenerTriangulosDesdeCuadrado(poligono);
    PintarInformacionPoligono(triangulos.at(0));
    PintarInformacionPoligono(triangulos.at(1));

    //Obtenemos un sub-triangulo a partir del primero de los dos triangualos anteriores
    //y pintamos su información
    Poligono triangulo = ObtenerTrianguloInterno(triangulos.at(0));
    PintarInformacionPoligono(triangulo);

    //Declaramos los datos de la circunferencia, obtenemos el poligono 
    //inscrito en ella y pintamos los datos (no graficamente, ya que no nos valdría)
    Punto2D centro;
    centro.x = 5;
    centro.y = 5;
    Poligono pol = ObtenerPoligonoInscritoCircunferencia(8, 6, centro);
    PintarInformacionPoligono(pol);

    // Liberar la memoria ocupada

    cout << endl << "Liberando poligonos" << endl;
    LiberaPoligono (poligono);
    LiberaPoligono(triangulos.at(0));
    LiberaPoligono(triangulos.at(1));
    LiberaPoligono(triangulo);
    LiberaPoligono(pol);

    return (0);

}