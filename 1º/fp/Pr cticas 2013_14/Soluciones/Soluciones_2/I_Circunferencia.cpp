/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
// EJERCICIO 4
/*	
   Programa que pide el radio y calcula e imprime
   en pantalla el área correspondiente y la longitud de la circunferencia.
   Entradas: El radio de la circunferencia
   Salidas:  El área del círculo calculada mediante: 
				area = PI * radio^2
             La longitud de la circunferencia calculada mediante: 
				longitud = 2 * PI * radio
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main() 
{
	const double PI = 3.1415927;
	
	double radio;			// Dato de entrada
	double area, longitud;	// Datos de salida

	cout << "Introduzca el valor del radio: ";
	cin >> radio;

	area = PI * radio * radio;
	longitud = 2 * PI  * radio;

	cout << "\n\nEl área del círculo vale " << area;
	cout << "\n\nLa longitud de la circunferencia vale " << longitud;
	cout << "\n\n";

	system("pause");
}
