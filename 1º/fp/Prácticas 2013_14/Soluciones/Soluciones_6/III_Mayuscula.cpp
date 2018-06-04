/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 5
//
/*	
	Programa que usa las funciones: 
	a)	"EsMinuscula()": comprueba si un car�cter es una min�scula.
	b)	"Convierte_a_Mayuscula()": comprueba si un car�cter pasado como 
		par�metro es min�scula (usa la funci�n anterior) y en cuyo caso 
		lo transforma a may�scula. Si no es min�scula no lo cambia. 

	Entradas: Un car�cter. 
	Salidas:  El car�cter transformado (si procede).
*/
/*********************************************************************/

#include <iostream>
using namespace std;

/*********************************************************************/

bool EsMinuscula (char una_letra)
{
	return ((una_letra >= 'a') && (una_letra <= 'z'));
}

/*********************************************************************/

char Convierte_a_Mayuscula (char caracter)
{      
	// 'a' tiene c�digo ASCII 97 y 'A' tiene c�digo ASCII 65 

	const int AMPLITUD = 'a'-'A';             
	char caracter_convertido;

	if (EsMinuscula(caracter))
		caracter_convertido = caracter - AMPLITUD;
	else
		caracter_convertido = caracter;

	return (caracter_convertido);
}

/*********************************************************************/

int main()
{
	char letra, mayuscula;

	cout << "\nIntroduzca una letra (* para terminar) --> ";
	cin >> letra;

	while (letra != '*') { 
   
		mayuscula = Convierte_a_Mayuscula (letra);

		cout << "\nEl car�cter " << letra 
			 << " una vez convertido es: " << mayuscula << "\n";

		cout << "\nIntroduzca una letra (* para terminar) --> ";
		cin >> letra;
	}

	cout << "\n\n";   
	system("pause");
}