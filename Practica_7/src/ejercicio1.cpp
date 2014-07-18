/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Implementar modularmente la clase MiMiVectorDinamico para trabajar con vectores 
 * de datos de tipo TipoBase. Los vectores dinamicos tendran un tamaño arbitrario, 
 * y no definido a priori. Proponer una representacion para la clase e implementar 
 * los siguientes metodos:
 *
 *  a) Constructor sin argumentos, que crea un vector dinamico con un numero de casillas predeterminado.
 *  b) Constructor con un argumento, que crea un vector dinamico con un numero de casillas indicado en el argumento.
 *  c) Constructor con dos argumentos, que crea un vector dinamico con un numero de casillas indicado en el primer argumento. Inicia todas la casillas al valor indicado en el segundo argumento. Por defecto tomara el valor 0.
 *  d) Destructor.
 *  e) Metodos para consultar el numero de casillas ocupadas/reservadas. 
 *  f) Metodo para añadir un valor (siempre al final).
 *  g) Metodo para devolver el valor que ocupa una posicion dada. 
 *  h) Metodo para establecer/consultar el tipo de redimensionamiento.
 *  i) Escribir una funcion main() que permita probar la clase.
 *
 ******************************************************************************/
#include <iostream> //Inclusión de los recursos de E/S
#include "MiVectorDinamico.h"

using namespace std;

/*****************************************************************************/
//Programa Principal
int main() {

    //Declaramos un nuevo vector dinamico
    MiVectorDinamico vector1 = MiVectorDinamico();
    
    //Agregamos datos
    vector1.AddValue(1);
    vector1.AddValue(2);
    vector1.AddValue(3);
    vector1.AddValue(4);


    //Declaramos un nuevo vector dinamico y ponemos los datos
    MiVectorDinamico vector2 = MiVectorDinamico(3);
    
    //Imprimimos los valores
    cout << "Vector vacio:" << endl;
    vector2.PrintValues();

    //Agregamos datos
    vector2.AddValue(1);
    vector2.AddValue(2);
    vector2.AddValue(3);
    vector2.AddValue(4);
    vector2.AddValue(5);
    vector2.AddValue(6);
    vector2.AddValue(7);

    //Imprimimos los valores
    cout << "Vector con valores:" << endl;
    vector2.PrintValues();


    //Declaramos un nuevo vector dinamico y ponemos los datos
    MiVectorDinamico vector3 = MiVectorDinamico(5,-1);
    
    //Imprimimos los valores
    cout << "Vector a -1:" << endl;
    vector3.PrintValues();

    //Agregamos datos
    vector3.AddValue(1);
    vector3.AddValue(2);

    //Imprimimos los valores
    cout << "Vector a -1 con dos valores agregados:" << endl;
    vector3.PrintValues();

    //Obtenemos el tamaño del vector
    cout << "Tamaño: " << vector3.GetSize() << endl;

    //Obtenemos el tamaño de los utilizados
    cout << "Usados: " << vector3.GetUsed() << endl;


    //Obtenemos un valor
    int pos = 1;
    cout << "Obtenemos el valor de la posicion " << pos << ": " << vector3.GetValue(pos) << endl;


    //Obtenemos el tipo de redimensionamiento
    cout << "Tipo redimensionamiento (0=1, 1=Doble): " << vector3.GetRedimensionType() << endl;

    //Terminamos la ejecución del programa
    return (0);

}