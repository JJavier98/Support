/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 1
// EJERCICIO 2
/*	
   Programa que calcula el dinero que se obtiene al realizar una 
   inversión a plazo fijo (en un año). 
   Entradas: capital a invertir (capital) e interés a aplicar (interes).
   Salidas:  dinero total (capital + ganancia obtenida) calculado por: 
				total = capital + (capital * interes/100)
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double interes;	// Entrada: interés a aplicar
	double capital; // Entrada: capital solicitado
	double total;	// Salida: cantidad ganada en un año
   
	cout << "Introduzca capital inicial --> ";
	cin >> capital;
	cout << "\nIntroduzca interés --> ";
	cin >> interes;   
   
	total = capital + capital * interes/100; 
	// idem: 
	// total = capital + (capital * (interes/100)); 

	cout << "\nAño 1 --> Capital + Ganancia obtenida = " << total;
	cout << "\n\n";

/*	
	// Mejora propuesta: total en el segundo año, invirtiendo todo 
	// lo conseguido el primer año

	capital = total; 
	total = capital + capital * interes/100;

	cout << "\nAño 2 --> Capital + Ganancia obtenida = " << total;
	cout << "\n\n";
*/
	system("pause");
}

