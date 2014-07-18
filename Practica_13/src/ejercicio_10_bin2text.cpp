/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escriba dos programas para transformar ficheros con datos correspondientes a 
 *	una serie de grupos de valores reales (como estan descritos en el problema 6), 
 *	para transformar entre formato binario y texto
 *	
 *	Este es el que convierte de binario a texto
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
		cerr << "Uso: " <<argv[0] << " <fichero texto> <fichero binario>" << endl;
		exit(1); // Salimos con error
	} 

	fileEntrada.open(argv[1], ios::binary);
	if (!fileEntrada) {
		cerr << "Error: no puedo abrir "  << argv[1] << endl;
		exit(1); // Salimos con error
	}

	fileSalida.open(argv[2]);
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
// Convierte el fichero de binario a texto
void copia(istream & entrada, ostream & salida) {

	const int TAM_BUFFER = 512; // Num. de bytes del buffer de lectura
	char buffer [TAM_BUFFER];    // Buffer de lectura


	int leidos; // Contador

	// Vamos leyendo las lineas	
	while (!entrada.eof()) {

		// Leemos en bloques de TAM_BUFFER
		entrada.read(buffer, TAM_BUFFER);

		// Obtenemos el numero de caracteres leidos
		leidos = entrada.gcount();
		salida.write(reinterpret_cast<char*>(&buffer), leidos); // Escribimos lo que haya leido

		// NOTA, Si en lugar de hacer write utilizao el operador << solo
		// escribe la primera línea, investigar
		//salida << buffer;


	}

}
/************************************************/
