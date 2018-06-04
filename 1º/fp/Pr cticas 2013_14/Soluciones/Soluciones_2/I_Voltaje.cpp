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
// EJERCICIO 1
/*	
   Programa que pide la intensidad de la corriente y la resistencia para 
			calcular e imprimir en pantalla el voltaje
   Entradas: Intensidad de la corriente (intensidad) y 
			 la resistencia (resistencia)
   Salidas:  El voltaje, calculado mediante la ley de Ohm: 
				voltaje = intensidad * resistencia
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double intensidad;  // Entrada: intensidad de corriente
	double resistencia;	// Entrada: resistencia 
	double voltaje;		// Salida: voltaje 

	// Entrada de datos
	cout << "\nIntroduzca el valor de intensidad: ";
	cin >> intensidad;
	cout << "\nIntroduzca el valor de resistencia: ";
	cin >> resistencia;

	// C�mputos
	voltaje = intensidad * resistencia;

	// Salida
	cout << "\nEl valor de voltaje es: " << voltaje << "\n\n";

	system("pause");
}