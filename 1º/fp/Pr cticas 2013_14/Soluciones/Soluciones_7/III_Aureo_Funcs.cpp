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
// EJERCICIO 25
/*	
	El n�mero a�reo se conoce desde la Antig�edad griega y aparece en muchos 
	temas de la geometr�a cl�sica. La forma m�s sencilla de definirlo es 
	como el �nico n�mero positivo  que cumple que Phi^2 - Phi = 1 y por 
	consiguiente su valor es
	                ___
               1 + V 5
		Phi = ---------- = 1,6180339887...
                  2
	Se pueden construir aproximaciones al n�mero a�reo mediante la f�rmula

		      fib(n + 1)
	   a_n = -----------
                fib(n)

	siendo fib(n) el t�rmino n-�simo de la sucesi�n de fibonacci, definida:
		fib(0) = 0
		fib(1) = 1
		fib(n) = fib(n-2) + fib(n-1) para n>=2

	A medida que n aumenta, a_n oscila, y es alternativamente menor y mayor 
	que la raz�n �urea (Para m�s informaci�n, v�ase, por ejemplo 
	http://es.wikipedia.org/wiki/N�mero_�ureo) 

	Este programa calcula el menor valor de n que hace que la aproximaci�n
	dada por a_n difiere en menos de Delta del n�mero Phi, sabiendo que n>=1. 
	
	Entradas: Un n�mero real, Delta, que estabalece la precisi�n. 
	Salidas:  El valor de n
*/	
/*********************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*********************************************************************/
// Funci�n que calcula el t�rmino n-�simo de Fibonacci, definida como: 
//		fib(0) = 0
//		fib(1) = 1
//		fib(n) = fib(n-2) + fib(n-1) para n>=2
//
// Existe una versi�n recursiva para esta funci�n que estudiaremos en
// el tema 6. De hecho, es uno de los ejemplos caracter�sticos de 
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
// Funci�n que calcula el t�rmino n-�simo de la serie dada por   
//		      fib(n + 1)
//	   a_n = -----------
//              fib(n)

double Termino (int n) 
{
	return ((Fib(n+1)*1.0) / Fib(n)); // ��Cuidado con la divisi�n entera!! 
}

/*********************************************************************/

int main()
{

	const double Phi = (1 + sqrt(5.0)) / 2.0; // 1,6180339887...

	double Delta;	// Precisi�n de la aproximaci�n 
	int n;			// Resultado: �ndice del t�rmino buscado 

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "\nCalculando la aproximaci�n al n�mero Aureo = " 
		 << setw(15) << setprecision(13) << Phi << endl << endl;

	cout << "\nIntroduzca la precisi�n deseada para la aproximaci�n: ";
	cin >> Delta;


	double	a_n;		// T�rmino n-�simo
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