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
// EJERCICIO 2
//
/*	
	Programa que calcula el m�ximo de tres n�meros le�dos del teclado, 
	modularizando la operaci�n del c�lculo del m�ximo.

	Se implementa la funci�n: 
	      double Max(double primero, double segundo, double tercero);
	
	Entradas: Tres n�meros double. 
	Salidas:  El m�ximo de los tres n�meros. 
*/
/*********************************************************************/

#include <iostream>
#include <cctype>
using namespace std;

/*********************************************************************/

// Calcula y devuelve el m�ximo entre tres valores

double Max(double primero, double segundo, double tercero)
{
	double max;

	if (primero >= segundo)
		max = primero;
	else
		max = segundo;

	if (tercero >= max)
		max = tercero;

	return max;
}
/*********************************************************************/

int main()
{
	double uno, dos, tres, maximo_de_los_tres;
	char respuesta;

	do {
		cout << "\nIntroduzca el primer valor = "; 
		cin >> uno;
		cout << "Introduzca el segundo valor = "; 
		cin >> dos;
		cout << "Introduzca el tercer valor = "; 
		cin >> tres;

		maximo_de_los_tres = Max(uno, dos, tres);
	
		cout << "\nEl m�ximo es " << maximo_de_los_tres << endl;
  
		cout << "\n�Continuar(s)? ";
		cin >> respuesta;
		
	} while (toupper(respuesta) == 'S');

	cout << "\n\n";
	system("pause");
}