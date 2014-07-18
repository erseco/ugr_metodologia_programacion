/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa con las mismas caracteristicas que las descritas en el 
 *  problema 7 pero que escriba en el fichero de salida bloques de 512 bytes.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void copia(istream & entrada, ostream & salida);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

	ifstream fileEntrada;
	ofstream fileSalida;

	if (argc != 3) {
		cerr << "Error: Num. de params. erroneo" << endl;
		cerr << "Uso: " <<argv[0] << " <ficheroE> <ficheroS>" << endl;
		exit(1); // Salimos con error
	} 

	fileEntrada.open(argv[1]);
	if (!fileEntrada) {
		cerr << "Error: no puedo abrir "  << argv[1] << endl;
		exit(1); // Salimos con error
	}

	fileSalida.open(argv[2], ios::binary);
	if (!fileSalida) {
		cerr << "Error: no puedo crear "  << argv[2] << endl;
		exit(1); // Salimos con error
	}

	copia(fileEntrada, fileSalida);
   

	fileEntrada.close();
	fileSalida.close();

	// Terminamos la ejecución del programa
	return (0);
}
/************************************************/
// Copia los numeros del fichero de entrada en el de salida
void copia(istream & entrada, ostream & salida) {

	const int TAM_BUFFER = 512; // Num. de bytes del buffer de lectura
	unsigned int buffer [TAM_BUFFER];    // Buffer de lectura

	//int *p;

	//le metemos a *p el valor de buffer siendo byte
	// aritmetica de punteros

	// p++ sería el siguiente int

	int n = 255;

	unsigned char *p = reinterpret_cast<char*>(&n);

	for (int i=0; i<sizeof(n); i++, p++) {

		cout << (int)(*p) << endl;
	}




	unsigned int num;
	int i = 0; // Contador

	// Vamos obteniendo numeros
	while (entrada >> num) {

		// Controlamos que cuando se llene el buffer debemos escribir
		if (i == TAM_BUFFER) {
			salida.write(reinterpret_cast<char*>(&buffer), TAM_BUFFER); // Escribimos 512Bytes enteros
			i = 0; // Reseteamos el contador
		}

		// Guardamos el número en el buffer
		buffer[i] = num;
		i++;           

	}

	// Escribimos el restante (lo que quede en el buffer)
   for(int j=0; j<i; j++) 
      salida.write (reinterpret_cast<char*>(&buffer[j]), sizeof (int)); 

}
/************************************************/
