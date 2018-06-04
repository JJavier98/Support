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
// EJERCICIO 10
/*	
	Un número es triangular si se puede poner como la suma de los 
	primeros m valores enteros, para algún valor de m. 
	Por ejemplo, 6 es triangular ya que 6 = 1+2+3. 
	
	Este programa obtiene todos los números triangulares que hay menores 
	que un entero k introducido desde teclado.

	Entradas: Un número entero, k
	Salidas:  Lista de todos los números triangulares menores que k
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
				// pero ahorramos una iteración.
	
	while (suma < n) { // Si suma sobrepasa n, no es triangular
		suma += i;
		i++;
	}

	if (suma == n) // Condición para ser triangular
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
   
	for (int i=1; i<=k; i++)	// Comprobamos todos los números menores 
								// que k (éste incluido)
		if (EsTriangular (i))
			cout << setw (4) << i << " es triangular.\n";

	cout << "\n\n";	
	system("pause");
}
