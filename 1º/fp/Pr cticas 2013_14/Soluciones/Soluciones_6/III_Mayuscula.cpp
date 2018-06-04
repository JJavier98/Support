/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// EJERCICIO 5
//
/*	
	Programa que usa las funciones: 
	a)	"EsMinuscula()": comprueba si un carácter es una minúscula.
	b)	"Convierte_a_Mayuscula()": comprueba si un carácter pasado como 
		parámetro es minúscula (usa la función anterior) y en cuyo caso 
		lo transforma a mayúscula. Si no es minúscula no lo cambia. 

	Entradas: Un carácter. 
	Salidas:  El carácter transformado (si procede).
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
	// 'a' tiene código ASCII 97 y 'A' tiene código ASCII 65 

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

		cout << "\nEl carácter " << letra 
			 << " una vez convertido es: " << mayuscula << "\n";

		cout << "\nIntroduzca una letra (* para terminar) --> ";
		cin >> letra;
	}

	cout << "\n\n";   
	system("pause");
}