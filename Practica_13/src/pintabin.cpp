/**************************************************************/
// Fichero: pinta_aleat.cpp
//
// Muestra el contenido de un fichero que contiene números
// enteros, almacenados en formsto binario.
//
// Uso:  pinta_aleat <fichE>
//
//  <fichE> es el nombre del fichero que contiene los números
//          enteros guardados en formato binario.
/**************************************************************/
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
/**************************************************************/
bool ExisteFichero (char *nombre);
int  tamanio (char *nombre);
/**************************************************************/
int main (int argc, char **argv) {

	const int MAX_LINE=8;
	int tam;
	int num;
	int n;
	// Num. de enteros por línea
	// Tamaño el fichero (en bytes)
	// Núm de enteros que hay en el fichero
	// Para recuperar cada número del fichero
	 ifstream fi; // Flujo de entrada
	   // Comprobar el número de argumentos
	 if (argc != 2) {
	 	cerr << "Error: Num. de params. erroneo\n";
	 	cerr << "Uso: " << argv[0]<< " <fichE>\n";
	 	exit (1);
	 }
	   // Comprobar si existe el fichero
	 if (!ExisteFichero(argv[1])) {
	 	cerr << "Error: no puedo abrir " << argv[1] << endl;
	 	exit (1);
	 }
	   // Calcular y mostrar el tamaño del fichero (en bytes)
	 tam = tamanio (argv[1]);
	 cout << "Fichero: " << argv[1] << " (";
	 	cout << tam << " bytes).\n";
	   // Calcular y mostrar el número de enteros que hay en el fichero
		num = tam / sizeof(int);
		cout << "Contiene : " << num << " enteros." << endl;

	   fi.open (argv[1], ios::binary);  // Apertura (para lectura)
	                                    // en modo binario
	   // En cada iteración se lee del fichero un número entero
	   // (realmente se leen "sizeof(int)" bytes consecutivos y
	   // se copian en "n", al cual se leen, a nivel de bit.
	   for (int i=1; i<=num; i++) {
	      // Escribir en "n" tantos bytes como tenga un "int"
	      // La copia es exacta (a nivel de bit)
	   	fi.read (reinterpret_cast<char*>(&n), sizeof (int));
	      // Adicionalmente se muestra en la consola el valor leído.
	      // Se muestran MAX_LINE números en cada línea.
	   	cout << setw (6) << n;
	   	if (i%MAX_LINE==0)  cout << endl;
	   }
	   fi.close(); // Cerrar el fichero asociado a "fi"
	   return (0); 

}
/**************************************************************/
// Devuelve TRUE si existe el fichero llamado "nombre" y si los
// permisos son los correctos para lectura.
bool ExisteFichero (char *nombre)
{
   ifstream fichero;
   bool problema;
   fichero.open (nombre);
   problema = fichero.fail();
   if (!problema) fichero.close();
   return ((problema) ? false : true);
}
/**************************************************************/


/**************************************************************/
// Devuelve el tamaño del fichero llamado "nombre" (en bytes)
// Este código ha ha sido explicado anteriormente, aunque ahora
// aparece encapsulado en forma de función.
int tamanio (char *nombre)
{
   const int TAM_BUFFER = 1024;
   char buffer [TAM_BUFFER];
   ifstream fi;
   int sum = 0;
   fi.open (nombre, ios::binary);
   while (fi.read(reinterpret_cast<char*> (buffer), TAM_BUFFER))
      sum += TAM_BUFFER;
   sum += fi.gcount();
   fi.close();
   return (sum);
}
/**************************************************************/