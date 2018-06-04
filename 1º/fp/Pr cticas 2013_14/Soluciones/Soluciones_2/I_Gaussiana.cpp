/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
// EJERCICIO 5
/*	
   Programa que calcula e imprime el valor de una gaussiana, dados 
   sus par�metros (desviaci�n t�pica y esperanza)   
   Entradas: par�metros de la gaussiana (desviacion, esperanza) y 
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
#include <cmath>
using namespace std;

int main()
{
	const double PI = 3.141592; 

	double esperanza, desviacion, x; // Entrada
	double y;	// Salida
   
	cout << "\nIntroduzca el valor del par�metro 'esperanza' : ";
	cin >> esperanza;
	cout << "\nIntroduzca el valor del par�metro 'desviacion' : ";
	cin >> desviacion;
	cout << "\nIntroduzca el valor de la abscisa: ";
	cin >> x;
   
	y = exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
		(desviacion * sqrt(2*PI));
   
	cout << "\n\nEl valor de la funci�n gaussiana en " << x << " es " << y;
	cout << "\n\n";
	
	system("pause");
}
