/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 * Considere dos secuencias de datos ordenadas almacenadas en sendas listas. 
 * Implemente una funcion para mezclar ordenadamente las dos secuencias en una 
 * nueva, de forma que las dos listas originales se queden vacias tras realizar 
 * la mezcla y la lista resultante contenga todos los datos.
 *
 * Observe se trata de una variante del algoritmo mergesort. Ahora se exige la 
 * modificacion de las secuencias originales: en esta version los datos se 
 * "mueven" hacia la lista resultante en lugar de copiarlos.
 *
 * Nota: No es preciso (ni se permite) realizar ninguna operacion de reserva 
 * ni liberacion de memoria.
 *
 * He intentado implementar el algoritmo merge sort tal y como lo indica la
 * wikipedia: http://es.wikipedia.org/wiki/Ordenamiento_por_mezcla pero no
 * lo he conseguido
 *
 ******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std;

/*************************************************************/
//Esta función pinta el contenido de la estructura enlazada
void Merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;

    while((h<=pivot)&&(j<=high)) {
        if(a[h]<=a[j]) {
            b[i]=a[h];
            h++;
        } else {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot) {
        for(k=j; k<=high; k++) {
            b[i]=a[k];
            i++;
        }
    } else {
        for(k=h; k<=pivot; k++) {
            b[i]=a[k];
            i++;
        }
    } for(k=low; k<=high; k++) 
    	a[k]=b[k];
}

/*************************************************************/
//Esta función pinta el contenido de la estructura enlazada
void MergeSort(int *a, int*b, int low, int high) {
    int pivot;
    if(low<high) {

        pivot=(low+high)/2;
        MergeSort(a,b,low,pivot);
        MergeSort(a,b,pivot+1,high);
        Merge(a,b,low,pivot,high);
    
    }
}

/*****************************************************************************/
//Programa Principal
int main(){

	//Declaracion de variables
    int a[] = {2, 8, 7, 4};
    //int b[] = {1, 3, 5};
    

    int num;
	
    num = sizeof(a)/sizeof(int);
	
    int b[num];


    //Llamamos a la funcion
    MergeSort(a,b,0,num - 1);

	//Pintamos los valores en la consola
    for (int i = 0; i < num; i++) {
    	cout << a[i] << " ";
    }
    cout << endl;

    //Finalizamos el programa
    return 0;
	
}