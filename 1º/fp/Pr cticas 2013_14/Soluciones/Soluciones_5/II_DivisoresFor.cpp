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
// EJERCICIO 20 (1)
//
/*	
	Versión con un ciclo for del ejercicio 9:

	Programa que calcula todos los divisores de un número. 
   
	Entradas:	El número ("n") del que se quieren calcular sus divisores
				Se exige que sea positivo para poder hacer el cálculo.
	Salidas:	Los divisores de ese número (obviando 1 y él mismo) 
				(se muestran en pantalla)
		NOTA:	Somos conscientes de que mezclamos C/S pero por 
				ahora no tenemos herramientas (serán los vectores) 
				para separarlos.
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;  

const double MARGEN = 0.000001;

int main()
{
	int n, divisor;

	// Lectura (con filtro) del numero del que queremos calcular 
	// todos sus divisores. Solo admitimos números positivos.  

	do {
		cout << "Introduce un numero entero positivo mayor que 0: ";
		cin >> n;
	} while (n <= 0);

	for (divisor = 2; divisor < n; divisor++)

		if (n % divisor == 0)
			cout << divisor << " es un divisor de " << n << endl;
		

	cout << "\n\n";

	// Mejora: no es preciso comprobar si los números mayores 
	// que sqrt(tope) son divisores. 

	int ultimo = floor (sqrt(n*1.0));	// Tomamos la parte entera de 
										// la raiz cuadrada de "n"
	for (divisor = 2; divisor < ultimo; divisor++)

		if (n % divisor == 0) {
			cout << divisor << " es un divisor de " << n << endl;
			cout << n/divisor << " es un divisor de " << n << endl;		
		}

	if (n % ultimo == 0) {

		// Si "n" es un cuadrado (4, 9, 16, 25, ...) su raiz cuadrada 
		// es exacta

		bool es_n_un_cuadrado = (sqrt(n*1.0) - ultimo < MARGEN);

		if (es_n_un_cuadrado) 
			cout << ultimo << " es un divisor de " << n << endl;
		else {
			cout << ultimo << " es un divisor de " << n << endl;
			cout << n/ultimo << " es un divisor de " << n << endl;	
		}

	}

	// CUIDADO: El valor "ultimo" se comprueba fuera del ciclo 
	// Sin duda, podría haberse planteado el ciclo anterior así: 
	//	while (divisor <= ultimo) 
	// pero preferimos esta solución. Encuentre una justificación.

	system("pause");
}