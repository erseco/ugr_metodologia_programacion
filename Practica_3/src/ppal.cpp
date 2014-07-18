//*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2012-2013
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// ppal.cpp
//
/*********************************************************************/

#include <iostream>
// Para generar "ppal_1lib_1mod" (makefile_1lib_1mod.mak) usar: 
// #include "opers_1mod.h"
//
// Para generar "ppal_1lib_2mod" (makefile_1lib_2mod.mak) usar: 
 #include "opers_2mod.h"
//
// Para generar "ppal_1lib_4mod" (makefile_1lib_4mod.mak) usar: 
// #include "opers_4mod.h"
//
// Para generar "ppal_2lib_2mod" (makefile_2lib_2mod.mak) usar: 
// #include "adic_2mod.h"
// #include "producto_2mod.h"
using namespace std;

/*********************************************************************/

int main (void)
{
   int num1, num2; 

   cout << "Introduce un numero: "; 
   cin >> num1; 
   cout << "Introduce otro numero: "; 
   cin >> num2; 

   cout << "La suma es = " << suma (num1, num2) << "\n"; 
   cout << "La resta es = " << resta (num1, num2) << "\n"; 
   cout << "La multiplicación es = " << multiplica (num1, num2) << "\n"; 
   cout << "La división es = " << divide (num1, num2) << "\n"; 

   return (0);
}

/*********************************************************************/
 
