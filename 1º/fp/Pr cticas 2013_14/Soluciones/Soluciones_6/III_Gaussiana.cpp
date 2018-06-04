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
// EJERCICIO 7
/*	
	Programa que calcula e imprime el valor de una gaussiana, 
	dados sus parámetros (desviación típica y esperanza) 
	modularizando con funciones.
	
	Ampliación del ejercicio 5 de la Relación de Problemas 1

	Entradas: parámetros de la gaussiana (desviacion, esperanza) y 
			  la abscisa (x)
	Salidas:  El valor de la ordenada (y), calculada mediante: 

	                                            {        (x-esperanza)^2 }
							                    { -0.5 * (-----------)   }
	                        1                   {        (desviacion )   }
				y = ----------------------  * e^                  
	                               ______
				     desviacion * V 2*PI     
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

int main()
{
	double esperanza, desviacion, x; // Entrada
	double y;						 // Salida
   
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "Esperanza = ";
	cin >> esperanza;
	cout << "Desviación típica = ";
	cin >> desviacion;

	cout << "\nValor de la abscisa: ";
	cin >> x;
   
	y = Gauss (x, esperanza, desviacion);

	cout << "\n\nEl valor de la función gaussiana en " 
		 << setw(10) << setprecision(7) << x << " es " 
		 << setw(10) << setprecision(7) << y;
	cout << "\n\n";
	
	system("pause");
}