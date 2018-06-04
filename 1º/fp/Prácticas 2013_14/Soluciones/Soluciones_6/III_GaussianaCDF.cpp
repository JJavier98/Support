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
// EJERCICIO 24
/*	
	Programa que calcula e imprime:
	a) el valor de una gaussiana, dados sus parámetros (desviación típica 
	   y esperanza) modularizando con funciones.
	b) el valor aprovimado de la CDF(x)
	
	Ampliación del ejercicio 5 de la Relación de Problemas 1

	Entradas: parámetros de la gaussiana (desviacion, esperanza) y 
			  la abscisa (x)
	Salidas:  a) El valor de la ordenada (y), calculada mediante: 

	                                            {        (x-esperanza)^2 }
							                    { -0.5 * (-----------)   }
	                        1                   {        (desviacion )   }
				y = ----------------------  * e^                  
	                               ______
				     desviacion * V 2*PI     

				b) El valor de la CDF(x) calculado por la aproximación: 

					1 - Gauss(x)(b1*t + b2*t^2 + b3*t^3 + b4*t^4)

				dónde:
				        1 
				t = --------
				    1 + b0*x
				b0 = 0.2316419		b1 = 0.319381530	b2 = -0.356563782
				b3 = 1.781477937	b4 = -1.821255978	b5 = 1.330274429

*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*********************************************************************/
// Calcula el valor de g(x) donde g -> N (esperanza, desviacion)

double Gauss (double x, double esperanza, double desviacion)
{
	const double PI = 3.141592; 

	return (exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
		        (desviacion * sqrt(2*PI)));
}
 
/*********************************************************************/

// Calcula CDF (x) = Integral_{-infty}^{x} {g(x) d(x)}
// donde g -> N (esperanza, desviacion)

double CDF (double x, double esperanza, double desviacion)
{
	const double b0 = 0.2316419;
	const double b1 = 0.319381530;
	const double b2 = -0.356563782;
	const double b3 = 1.781477937;
	const double b4 = -1.821255978;
	const double b5 = 1.330274429;

	double t = 1.0 / (1 + b0*x);
	double gauss_x =  Gauss(x, esperanza, desviacion);

	return (1 - gauss_x * (b1*t + b2*t*t + b3*t*t*t + b4*t*t*t*t));

}
 
/*********************************************************************/

int main()
{
	double esperanza, desviacion, x; // Entrada
	double y;	// Salida
	double cdf;	// Salida
   
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "Esperanza = ";
	cin >> esperanza;
	cout << "Desviación típica = ";
	cin >> desviacion;

	cout << "\nValor de la abscisa: ";
	cin >> x;
   
	y = Gauss (x, esperanza, desviacion);
	cdf = CDF(x, esperanza, desviacion);

	cout << "\n\nEl valor de la función gaussiana en " 
		 << setw(10) << setprecision(7) << x << " es " 
		 << setw(10) << setprecision(7) << y;
	cout << "\n\nEl valor de CDF(" << setw(10) << setprecision(7) << x << ") es " 
		 << setw(10) << setprecision(7) << cdf;
	cout << "\n\n";
	
	system("pause");
}