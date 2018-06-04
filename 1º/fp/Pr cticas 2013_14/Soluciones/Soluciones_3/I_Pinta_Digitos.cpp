/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) FRANCISCO JOSÉ CORTIJO BON
// (C) JUAN CARLOS CUBERO TALAVERA
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
// EJERCICIO 22
/*	
   Programa que lee un enteroi de tres dígitos y los muestra individualmente, 
   separándolos por tres espacios. 
   
   Entradas: un entero
   Salidas:  Los dígitos del entero leido.
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numero_3dig;	// Dato de entrada: un entero de tres dígitos
	int numero_2dig;
	int numero_1dig;

	// Entrada

	cout << "Introduce un entero de tres dígitos: "; 
	cin >> numero_3dig; 


	// Cálculos

	numero_2dig = numero_3dig % 100; // Las dos cifras menos significativas
	numero_1dig = numero_2dig % 10;  // La cifra menos significativa

	cout << (numero_3dig / 100) << "   " // el digito de las centenas
		 << (numero_2dig / 10) << "   "  // el digito de las decenas
		 << numero_1dig;			     // el digito de las unidades 			  
	cout << endl;

	system ("pause");
}
