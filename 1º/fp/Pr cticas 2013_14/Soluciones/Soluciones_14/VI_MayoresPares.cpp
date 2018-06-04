/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS VI
// EJERCICIO 13 
//
/*	
	Programa que emplea una función recursiva que muestra en la salida 
	estándar los m mayores números pares que sean menores o iguales que 
	un número n. Esta tarea la realiza la función recursiva:

		void MayoresPares(int m, int n);

	Ejemplos:
		MayoresPares(3,6) : imprimirá en pantalla 6, 4, 2
		MayoresPares(4,3) : imprimirá en pantalla 2, 0, -2, -4
		MayoresPares(0,8) : no imprimirá nada en pantalla
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************************/
/*********************************************************************/

void MayoresPares (int m, int n)
{
	if (m > 0) {

		if (n%2 == 0) {
			
			cout << setw (4) << n;

			MayoresPares (m-1, n-1);	// m-1 porque se ha encontrado un par
		}								// n-1 para comprobar el anterior
		else 
			MayoresPares (m, n-1);		// m no cambia -> no es par 
										// n-1 para comprobar el anterior
	}
}

/*********************************************************************/
/*********************************************************************/

int main (void)
{
	cout << "\nSe van a calcular los m mayores pares menores (o igual)";
	cout << " que un valor dado.\n\n";

	int m, n;

	cout << "Valor: ";
	cin >> n;

	cout << "Numero de pares: ";
	cin >> m;

	MayoresPares (m, n);

	cout << endl << endl; 
	system ("pause");

	return (0); 
}
/*********************************************************************/
/*********************************************************************/