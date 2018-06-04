/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
// EJERCICIO 14
/*	

	Programa que lee un caracter (debe ser entre '0' y '9') y obtenga el correspondiente valor 
	int y lo imprima.
	   
	Entradas: un char ('0' y '9')
	Salidas:  un int (0..9)

	Los caracteres num�ricos est�n ordenados en la tabla ASCII '0'<'1'<...<'9'
*/	
/*********************************************************************/

#include <iostream>
using namespace std;


int main()
{

	char caracter;
	int caracter_a_entero;
   
	cout << "\nIntroduzca un car�cter num�rico  --> ";
	cin >> caracter;
   
	caracter_a_entero = caracter - '0'; 
	// N�mero de caracteres entre ambos. Observe que '0'-'0'=0, '1'-'0'=1, ...
   
	cout << "\nEl entero correspondiente es " << caracter_a_entero;
	cout << "\n\n";

	system("pause");
}

