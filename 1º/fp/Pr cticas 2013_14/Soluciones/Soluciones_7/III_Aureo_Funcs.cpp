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
// EJERCICIO 25
/*	
	El número aúreo se conoce desde la Antigüedad griega y aparece en muchos 
	temas de la geometría clásica. La forma más sencilla de definirlo es 
	como el único número positivo  que cumple que Phi^2 - Phi = 1 y por 
	consiguiente su valor es
	                ___
               1 + V 5
		Phi = ---------- = 1,6180339887...
                  2
	Se pueden construir aproximaciones al número aúreo mediante la fórmula

		      fib(n + 1)
	   a_n = -----------
                fib(n)

	siendo fib(n) el término n-ésimo de la sucesión de fibonacci, definida:
		fib(0) = 0
		fib(1) = 1
		fib(n) = fib(n-2) + fib(n-1) para n>=2

	A medida que n aumenta, a_n oscila, y es alternativamente menor y mayor 
	que la razón áurea (Para más información, véase, por ejemplo 
	http://es.wikipedia.org/wiki/Número_áureo) 

	Este programa calcula el menor valor de n que hace que la aproximación
	dada por a_n difiere en menos de Delta del número Phi, sabiendo que n>=1. 
	
	Entradas: Un número real, Delta, que estabalece la precisión. 
	Salidas:  El valor de n
*/	
/*********************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*********************************************************************/
// Función que calcula el término n-ésimo de Fibonacci, definida como: 
//		fib(0) = 0
//		fib(1) = 1
//		fib(n) = fib(n-2) + fib(n-1) para n>=2
//
// Existe una versión recursiva para esta función que estudiaremos en
// el tema 6. De hecho, es uno de los ejemplos característicos de 
// recursividad

int Fib (int n)
{
	int resultado; 

	switch (n) {

		case (0):	resultado = 0;
					break;

		case (1):	resultado = 1;
					break; 

		default:	int ant1 = 1; // Fib(1)
					int ant2 = 0; // Fib(0) 

					for (int i=2 ; i<=n; i++) {
						resultado = ant1 + ant2; // Fib (i)
						ant2 = ant1;		// Preparamos la siguiente 
						ant1 = resultado;	// iteracion
					}
					break;
	}
	
	return (resultado);
}

/*********************************************************************/
// Función que calcula el término n-ésimo de la serie dada por   
//		      fib(n + 1)
//	   a_n = -----------
//              fib(n)

double Termino (int n) 
{
	return ((Fib(n+1)*1.0) / Fib(n)); // ¡¡Cuidado con la división entera!! 
}

/*********************************************************************/

int main()
{

	const double Phi = (1 + sqrt(5.0)) / 2.0; // 1,6180339887...

	double Delta;	// Precisión de la aproximación 
	int n;			// Resultado: índice del término buscado 

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "\nCalculando la aproximación al número Aureo = " 
		 << setw(15) << setprecision(13) << Phi << endl << endl;

	cout << "\nIntroduzca la precisión deseada para la aproximación: ";
	cin >> Delta;


	double	a_n;		// Término n-ésimo
	double	diferencia; // |a_n - Phi|

	n=1;
	bool sigo = true; 

	while (sigo) {

		a_n = Termino(n); 
		diferencia = fabs(a_n-Phi);	// |a_n - Phi|

		cout << "a_" << setw(3) << n << " = " <<setw(15)<<setprecision(13)<< a_n;
		cout << " (Dif = " <<setw(15)<<setprecision(13)<< diferencia << ")\n";
		
		if (diferencia <= Delta)
			sigo = false;
		else 
			n++;
	}

	cout << endl;
	cout << "Menor valor de n = " << setw(3) << n << endl; 
	cout << "Diferencia = " << setw(15) << setprecision(8) << diferencia << "\n";

	cout << "\n\n";
	system("pause");
}