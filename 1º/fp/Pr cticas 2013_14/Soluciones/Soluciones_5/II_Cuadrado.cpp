/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 25
//
/*	
	Programa que muestra la siguiente salida:
	
	1 2 3 4 5 6
	2 3 4 5 6 7
	3 4 5 6 7 8
	4 5 6 7 8 9
	5 6 7 8 9 10
	6 7 8 9 10 11

	Entradas: Ninguna 
	Salidas:  La indicada anteriormente.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int fila, valor;

	for (fila=1; fila <=6; fila++) {
		for (valor=fila; valor<=fila+5; valor++) 
			cout << setw (4) << valor; 
		cout << endl;
	}

	cout << "\n\n";
	
	system("pause");
}

