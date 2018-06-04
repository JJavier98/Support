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
// EJERCICIO 19 (con ciclo for)
//
/*	

	Progresi�n geom�trica: 
	Supongamos una serie num�rica cuyo t�rmino general es:
                        
					  i-1
		a_i =  a_1 * r 

	Dado "a_1" (el primer t�rmino), y "r" (la raz�n) se calcula cualquier  
	t�rmino "a_i" de la serie 

	El programa lee r, a1 y un �ndice k y calcula la suma de los primeros 
	k valores de la serie, es decir: 
	
		  i=k
		  __
		<
		 >    a_i	
		< __   
		
		  i=1

	Entradas:	El primer t�rmino de la progresi�n (termino_primero)
				La raz�n de la progresi�n (razon)
				Indice del �ltimo t�rmino para la suma (tope)

	Salidas:	La suma (desde 1 a "tope") de los t�rminos de la progresi�n. 
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double termino_primero, razon;
	int n, tope;

	double suma_total; // variable acumuladora
	double termino_n;

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "Primer t�rmino de la progresi�n: ";
	cin >> termino_primero;
	cout << "Raz�n de la progresi�n: ";
	cin >> razon;

	do {
		cout << "Indice (debe ser >=1) del �ltimo t�rmino a sumar: ";
		cin >> tope;
	} while (tope < 1);

	suma_total = termino_primero;
	
	// No se inicia a 1 porque la asignaci�n anterior 
	// hace, impl�citamente, la suma desde i=1 hasta 1

	for (n=2; n <= tope; n++) { 
		suma_total = suma_total + (termino_primero * pow(razon, n-1));		
	}

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_total;
	cout << "\n\n";
	

	/*
	En vez de hacer la operaci�n pow, que es costosa, bastar�a multiplicar
	en cada iteraci�n, el valor de a_{n-1} por la raz�n, y ya tengo a_n
	Observad que en Matem�ticas decimos:
		a_i = a_{i-1} * r
	Mientras que en un algoritmo debemos poner:
		termino = termino * r
	*/


	termino_n = termino_primero;
	suma_total = termino_n; 
	
	// No se inicia a 1 porque la asignaci�n anterior 
	// hace, impl�citamente, la suma desde i=1 hasta 1

	for (n=2; n <= tope; n++) { 
		termino_n = termino_n * razon;
		suma_total = suma_total +  termino_n;		
	}

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_total;
	cout << "\n\n";

	system("pause");
}
