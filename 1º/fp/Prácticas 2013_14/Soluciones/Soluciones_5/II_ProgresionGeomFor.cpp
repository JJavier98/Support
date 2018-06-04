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
// EJERCICIO 19 (con ciclo for)
//
/*	

	Progresión geométrica: 
	Supongamos una serie numérica cuyo término general es:
                        
					  i-1
		a_i =  a_1 * r 

	Dado "a_1" (el primer término), y "r" (la razón) se calcula cualquier  
	término "a_i" de la serie 

	El programa lee r, a1 y un índice k y calcula la suma de los primeros 
	k valores de la serie, es decir: 
	
		  i=k
		  __
		<
		 >    a_i	
		< __   
		
		  i=1

	Entradas:	El primer término de la progresión (termino_primero)
				La razón de la progresión (razon)
				Indice del último término para la suma (tope)

	Salidas:	La suma (desde 1 a "tope") de los términos de la progresión. 
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

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "Primer término de la progresión: ";
	cin >> termino_primero;
	cout << "Razón de la progresión: ";
	cin >> razon;

	do {
		cout << "Indice (debe ser >=1) del último término a sumar: ";
		cin >> tope;
	} while (tope < 1);

	suma_total = termino_primero;
	
	// No se inicia a 1 porque la asignación anterior 
	// hace, implícitamente, la suma desde i=1 hasta 1

	for (n=2; n <= tope; n++) { 
		suma_total = suma_total + (termino_primero * pow(razon, n-1));		
	}

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_total;
	cout << "\n\n";
	

	/*
	En vez de hacer la operación pow, que es costosa, bastaría multiplicar
	en cada iteración, el valor de a_{n-1} por la razón, y ya tengo a_n
	Observad que en Matemáticas decimos:
		a_i = a_{i-1} * r
	Mientras que en un algoritmo debemos poner:
		termino = termino * r
	*/


	termino_n = termino_primero;
	suma_total = termino_n; 
	
	// No se inicia a 1 porque la asignación anterior 
	// hace, implícitamente, la suma desde i=1 hasta 1

	for (n=2; n <= tope; n++) { 
		termino_n = termino_n * razon;
		suma_total = suma_total +  termino_n;		
	}

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_total;
	cout << "\n\n";

	system("pause");
}
