/*	
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que calcula el área de una funcion gaussiana
	para comprobarla he usado la calculadora de
	http://www.danielsoper.com/statcalc3/calc.aspx?id=53
	porque la pagina indicada en el ejercicio no funcionaba
*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>   // Inclusión de las funciones matemáticas

using namespace std; 



//Funcion que calcula la abscisa de una funcion gaussiana
double Gaussiana(double x, double esperanza, double desviacion){

	const double PI = 3.1416;   // Declara las constantes

	/*
	Nota: Esta funcion admite tres parámetros, podría almacenar 
			la esperanza y la desviacion en dos variables globales
			y solo requerir x
	*/

	//Hacemos los calculos
	double y = exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / (desviacion * sqrt(2*PI));

	//Devolvemos el valor
	return y;
}

//Programa Principal
int main(){        
	//Declara variables para guardar los valores
	const double B0 = 0.2316419;
	const double B1 = 0.319381530;
	const double B2 = -0.356563782;
	const double B3 = 1.781477937;
	const double B4 = -1.821255978;
	const double B5 = 1.330274429;

	double esperanza;				
	double desviacion;
	double x;
	double y; //Salida 
	double t;

	//Obtenemos los datos necesarios
	cout << "Introduzca la esperanza (μ): ";
	cin >> esperanza;
	cout << "Introduzca la desviación típica (σ): ";
	cin >> desviacion;
	cout << "Introduzca la abscisa (x): ";
	cin >> x;

	//Calculamos t tal y como indica el ejercicio
	t = 1.0/(1.0 + B0*x);
	

	y = 1.0 - Gaussiana(x, esperanza, desviacion) * ((B1*t) + (B2*t) + (B3*t) + (B4*t) + (B5*t));

	//Pintamos los valores en la consola
	cout << "\n\nEl CDF de la función en " << x << " es " << y << "\n\n";

	//Pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
