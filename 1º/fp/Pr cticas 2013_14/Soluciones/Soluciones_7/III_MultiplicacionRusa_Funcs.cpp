/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 11
//
/*	
	El algoritmo de la multiplicaci�n rusa es una forma distinta de calcular 
	la multiplicaci�n de dos n�meros enteros n * m. Para ello este algoritmo 
	va multiplicando por 2 el multiplicador m y dividiendo (sin decimales) por 
	dos el multiplicando n hasta que n tome el valor 1 y suma todos aquellos 
	multiplicadores cuyos multiplicandos sean impares
	
	Entradas: multiplicando (multiplicando > 0) 
	          multiplicador (multiplicador > 0) 
	
	Salidas:  El valor de multiplicando*multiplicador
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************************/
// C�lculo de la multiplicaci�n usando el m�todo de la mltiplicaci�n rusa
// Argumentos: multiplicando y multiplicador
// Devuelve: multiplicando*multiplicador

int MultiplicacionRusa (int multiplicando, int multiplicador) 
{
	int multiplicacion = 0; 

	while (multiplicando != 1) {
		
		if (multiplicando%2 != 0) 
			multiplicacion += multiplicador; // Solo sumamos los impares

		multiplicando = multiplicando / 2; 
		multiplicador = multiplicador * 2;

	}

	multiplicacion += multiplicador; // Es importante no olvidar el �ltimo
	
	return (multiplicacion);
}

/*********************************************************************/

int main()
{
	int multiplicando, multiplicador;
	int multiplicacion;

	// Lectura anticipada

	cout << "Multiplicando (negativo para salir): "; 
	cin >> multiplicando;

	while (multiplicando > 0) { 

		do {
			cout << "Multiplicador : "; 
			cin >> multiplicador;
		} while ( multiplicador < 0);  


		multiplicacion = MultiplicacionRusa (multiplicando, multiplicador); 

		cout << endl << multiplicando << " * " <<  multiplicador << " = " 
			 << multiplicacion  << endl << endl; 

		// Lectura anticipada

		cout << "Multiplicando (negativo para salir): "; 
		cin >> multiplicando;

	} // while (multiplicando > 0) 

	cout << "\n\n";
	system("pause");
}