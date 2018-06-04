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
// EJERCICIO 10
/*	
	Un n�mero es triangular si se puede poner como la suma de los 
	primeros m valores enteros, para alg�n valor de m. 
	Por ejemplo, 6 es triangular ya que 6 = 1+2+3. 
	
	Este programa obtiene todos los n�meros triangulares que hay menores 
	que un entero k introducido desde teclado.

	Entradas: Un n�mero entero, k
	Salidas:  Lista de todos los n�meros triangulares menores que k
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************************/

bool EsTriangular (int n)
{
	bool es_triangular; 

	int suma=1;	// Estas inicializaciones equivalen a hacer 
	int i=2;	//		int suma=0;
				//		int i=1
				// pero ahorramos una iteraci�n.
	
	while (suma < n) { // Si suma sobrepasa n, no es triangular
		suma += i;
		i++;
	}

	if (suma == n) // Condici�n para ser triangular
		es_triangular = true;
	else 
		es_triangular = false;

	return (es_triangular);
}

/*********************************************************************/

int main()
{

	int	k; 

	cout << "\nIntroduzca un entero: ";
	cin >> k;
   
	for (int i=1; i<=k; i++)	// Comprobamos todos los n�meros menores 
								// que k (�ste incluido)
		if (EsTriangular (i))
			cout << setw (4) << i << " es triangular.\n";

	cout << "\n\n";	
	system("pause");
}
