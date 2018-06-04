/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 26
//
/*	
	Programa que muestra las siguientes salidas:

	1 2 3 4 5 6
	2 3 4 5 6
	3 4 5 6
	4 5 6
	5 6
	6

	1 2 3 4 5 6
	2 3 4 5 6 7
	3 4 5 6 7 8
	4 5 6 7 8 9
	5 6 7 8 9 10
	6 7 8 9 10 11

	Entradas: valores inicial ("inicial") y final ("final")
	Salidas:  La indicada anteriormente.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{

	int inicial, final;

	cout << "Introduzca valor inicial: ";
	cin >> inicial; 
	cout << "Introduzca valor final: ";
	cin >> final; 

	int num_filas = final-inicial+1;
	cout << "num_filas = " << num_filas << endl;


	int primero, valor;

	for (primero=inicial; primero <=inicial+num_filas-1; primero++) {
		for (valor=primero; valor<=final; valor++) // el último de cada fila
			cout << setw (4) << valor;			// siempre es el mismo
		cout << endl;
	}
	cout << "\n\n";


	// En el cuadrado, el valor del último de cada fila cambia, 
	// aunque todas las fials tienen el mismo número de elementos

	for (primero=inicial; primero <=inicial+num_filas-1; primero++) {
		for (valor=primero; valor<=primero+num_filas-1; valor++)  
			cout << setw (4) << valor;	
		cout << endl;
	}
	cout << "\n\n";

	system("pause");
}