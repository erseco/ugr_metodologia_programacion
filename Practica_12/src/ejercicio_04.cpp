/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 * ------------------------------
 *
 *  Escribir un programa que permita encriptar y desencriptar el contenido de un 
 *	fichero de texto. Para encriptar sustituiremos cada letra (mayusculas y 
 *	minusculas) por la letra que esta p posiciones mas adelante en el alfabeto 
 *	(para las ultimas letras ciclamos el alfabeto). Los caracteres que no sean 
 *	letras se quedaran igual.
 *
 ******************************************************************************/
#include <iostream> // Inclusión de los recursos de E/S

#include <fstream>
#include <cstdlib>


using namespace std;

// Declaramos la funcion, para no tener que escribirla al principio
void codifica(istream & entrada, ostream & salida, int posiciones, bool encripta);
int encripta_char(int letra, int posiciones);

int desencripta_char(int letra, int posiciones);

/************************************************/
// Programa Principal
int main (int argc, char *argv[]) {

    ifstream fileEntrada;
    ofstream fileSalida;
    int posiciones;

    if (argc != 5) {
        cerr << "Error: Num. de params. erroneo" << endl;
        cerr << "Uso: " <<argv[0] << " <ficheroE> <ficheroS> <p> <tipo>" << endl;
        exit(1); // Salimos con error
    } else if (strcmp(argv[4], "enc") != 0 && strcmp(argv[4], "desenc") != 0) {
        cerr << "Error: El tipo debe ser 'enc' o 'desenc'" << endl;
        cerr << "Uso: " <<argv[0] << " <ficheroE> <ficheroS> <p> <tipo>" << endl;
        exit(1); // Salimos con error
    } 

    fileEntrada.open (argv[1]);
    if (!fileEntrada) {
        cerr << "Error: no puedo abrir "  << argv[1] << endl;
        exit(1); // Salimos con error
    }

    fileSalida.open (argv[2]);
    if (!fileSalida) {
        cerr << "Error: no puedo crear "  << argv[2] << endl;
        exit(1); // Salimos con error
    }

    // Obtenemos las posiciones
    posiciones = atoi(argv[3]);

    // Solo debemos hacerlo en caso de desenc, ya que por defecto hace enc
    if (strcmp(argv[4], "desenc") == 0) {

    	// encriptamos el archivo
	    codifica(fileEntrada, fileSalida, posiciones, false);

    } else {

    	// desencriptamos el archivo
	    codifica(fileEntrada, fileSalida, posiciones, true);
    }




    fileEntrada.close();
    fileSalida.close();

    // Terminamos la ejecución del programa
    return (0);
}
/************************************************/
// Codifica el fichero (encripta o desencripta)
void codifica(istream & entrada, ostream & salida, int posiciones, bool encripta) {

	int c;

	// Obtenemos un valor
	c = entrada.get();

	// Encripta o desencripta el caracter, dependiendo de la variable
	if (encripta)
		c = encripta_char(c, posiciones);
	else
		c = desencripta_char(c, posiciones);

	while (!entrada.eof()) {
			
		// Escribimos el caracter al archivo
		salida.put(c); 

		// Vamos leyendo caracteres hasta el fin del fichero
		c = entrada.get();

		// Encripta o desencripta el caracter, dependiendo de la variable
		if (encripta)
			c = encripta_char(c, posiciones);
		else
			c = desencripta_char(c, posiciones);
	} 

	// Escribimos el caracter al archivo
	salida.put(c); 

}
/************************************************/
// Codifica los números el numero de posiciones indicado
int encripta_char(int letra, int posiciones) {

	int resultado;

	const int A = 'A';
	const int Z = 'Z';
	const int a = 'a';
	const int z = 'z';

	if (letra >= A && letra <= Z) { // Es una mayuscula

		if ((letra + posiciones) > Z) {
			// Si pasa de la Z hay que ciclar el alfabeto
			resultado = (Z-(letra-A) + posiciones ) -1;

		} else {

			resultado = char(letra+posiciones);

		}

	} else if (letra >= a && letra <= z) { // Es una minuscula

		if ((letra + posiciones) > z) {
			// Si pasa de la Z hay que ciclar el alfabeto
			resultado = (z-(letra -a) + posiciones ) -1;

		} else {

			resultado = (letra+posiciones);

		}

	} else {

		// No es una letra, la dejamos igual
		resultado = letra;
		
		 
	}

	return resultado;

}

/************************************************/
// Codifica los números el numero de posiciones indicado
int desencripta_char(int letra, int posiciones) {

	int resultado;

	const int A = 'A';
	const int Z = 'Z';
	const int a = 'a';
	const int z = 'z';

	if (letra >= A && letra <= Z) { // Es una mayuscula

		if ((letra - posiciones) < A) {
			// Si es menor de la A hay que ciclar el alfabeto
			resultado = (A-(letra-Z) + posiciones ) -1;


		} else {

			resultado = char(letra-posiciones);

		}


	} else if (letra >= a && letra <= z) { // Es una minuscula

		if ((letra - posiciones) < a) {
			// Si es menor de la A hay que ciclar el alfabeto
			resultado = (a-(letra-z) + posiciones ) -1;

		} else {

			resultado = (letra-posiciones);

		}

	} else {

		// No es una letra, la dejamos igual
		resultado = letra;
		
		 
	}

	return resultado;

}
/************************************************/
