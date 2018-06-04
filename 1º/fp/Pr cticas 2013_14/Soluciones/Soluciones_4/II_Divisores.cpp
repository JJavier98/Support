/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 9
//
/*	
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


int main()
{
	int n, divisor;

	// Lectura (con filtro) del numero del que queremos calcular 
	// todos sus divisores. Solo admitimos números positivos.  

	do {
		cout << "Introduce un numero entero positivo mayor que 0: ";
		cin >> n;
	} while (n <= 0);

	divisor = 2;

	while (divisor < n) {

		if (n % divisor == 0)
			cout << divisor << " es un divisor de " << n << endl;
		
		divisor++;
	}

	cout << "\n\n";

	// Mejora: no es preciso comprobar si los números mayores 
	// que sqrt(tope) son divisores. 

	divisor = 2;

	int ultimo = floor (sqrt(n*1.0)); // Tomamos la parte entera de 
										 // la raiz cuadrada de tope
	while (divisor < ultimo) {

		if (n % divisor == 0) {
			cout << divisor << " es un divisor de " << n << endl;
			cout << n/divisor << " es un divisor de " << n << endl;		
		}
		divisor++;
	}

	if (n % ultimo == 0)
		cout << ultimo << " es un divisor de " << n << endl;

	// CUIDADO: El valor "ultimo" se comprueba fuera del ciclo 
	// Sin duda, podría haberse planteado el ciclo anterior así: 
	//	while (divisor <= ultimo) 
	// pero preferimos esta solución. Encuentre una justificación.

	system("pause");
}