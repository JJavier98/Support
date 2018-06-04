/*	
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa para calcular el resultado de una función matemática
	Necesita: coeficientes reales μ, σ y un valor de abscisa (x)
	Calcula: El resultado de la función según la fórmula, se 
	podrá comprobar el resultado aquí: http://www.danielsoper.com/statcalc/calc54.aspx
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
	double esperanza;				
	double desviacion;
	double x;
	double y; //Salida 

	//Obtenemos los datos necesarios
	cout << "Introduzca la esperanza (μ): ";
	cin >> esperanza;
	cout << "Introduzca la desviación típica (σ): ";
	cin >> desviacion;
	cout << "Introduzca la abscisa (x): ";
	cin >> x;

	y = Gaussiana(x, esperanza, desviacion);

	//Pintamos los valores en la consola
	cout << "\n\nEl valor de la función gaussiana en " << x << " es " << y << "\n\n";

	//Pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
