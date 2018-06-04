/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) FRANCISCO JOS� CORTIJO BON
// (C) JUAN CARLOS CUBERO TALAVERA
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
// EJERCICIO 22
/*	
   Programa que lee un enteroi de tres d�gitos y los muestra individualmente, 
   separ�ndolos por tres espacios. 
   
   Entradas: un entero
   Salidas:  Los d�gitos del entero leido.
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numero_3dig;	// Dato de entrada: un entero de tres d�gitos
	int numero_2dig;
	int numero_1dig;

	// Entrada

	cout << "Introduce un entero de tres d�gitos: "; 
	cin >> numero_3dig; 


	// C�lculos

	numero_2dig = numero_3dig % 100; // Las dos cifras menos significativas
	numero_1dig = numero_2dig % 10;  // La cifra menos significativa

	cout << (numero_3dig / 100) << "   " // el digito de las centenas
		 << (numero_2dig / 10) << "   "  // el digito de las decenas
		 << numero_1dig;			     // el digito de las unidades 			  
	cout << endl;

	system ("pause");
}
