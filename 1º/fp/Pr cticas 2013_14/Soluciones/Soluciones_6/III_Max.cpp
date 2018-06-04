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
// EJERCICIO 2
//
/*	
	Programa que calcula el máximo de tres números leídos del teclado, 
	modularizando la operación del cálculo del máximo.

	Se implementa la función: 
	      double Max(double primero, double segundo, double tercero);
	
	Entradas: Tres números double. 
	Salidas:  El máximo de los tres números. 
*/
/*********************************************************************/

#include <iostream>
#include <cctype>
using namespace std;

/*********************************************************************/

// Calcula y devuelve el máximo entre tres valores

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
	
		cout << "\nEl máximo es " << maximo_de_los_tres << endl;
  
		cout << "\n¿Continuar(s)? ";
		cin >> respuesta;
		
	} while (toupper(respuesta) == 'S');

	cout << "\n\n";
	system("pause");
}