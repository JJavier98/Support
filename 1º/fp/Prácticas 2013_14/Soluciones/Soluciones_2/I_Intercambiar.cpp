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
// EJERCICIO 3
/*	
   Programa que pide los valores de dos datos y los intercambia.
   Entradas: los valores de los dos datos: edad_Pedro y edad_Juan
   Auxiliares: una variable para realizar el intercambio, que actúa 
			como almacén temporal. 
   Salidas: los datos de entrada (sus valores deben ser diferentes)
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int edad_Pedro, edad_Juan;  // Datos de entrada/salida
	int intermedia;				// Dato auxiliar

	// Entrada de datos
	cout << "\nIntroduzca la edad de Pedro: ";
	cin >> edad_Pedro;
	cout << "Introduzca la edad de Juan: ";
	cin >> edad_Juan;

	// Cómputos --> intercambio de valores empleando una variable auxiliar
	intermedia = edad_Juan;
	edad_Juan  = edad_Pedro;
	edad_Pedro = intermedia;

	// Salida
	cout << "\nNueva edad de Pedro: " << edad_Pedro;
	cout << "\nNueva edad de Juan: " << edad_Juan;
	
	cout << "\n\n";	

	system("pause");
}