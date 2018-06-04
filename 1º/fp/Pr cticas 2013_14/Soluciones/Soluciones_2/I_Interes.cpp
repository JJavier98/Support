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
// EJERCICIO 2
/*	
   Programa que calcula el dinero que se obtiene al realizar una 
   inversi�n a plazo fijo (en un a�o). 
   Entradas: capital a invertir (capital) e inter�s a aplicar (interes).
   Salidas:  dinero total (capital + ganancia obtenida) calculado por: 
				total = capital + (capital * interes/100)
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double interes;	// Entrada: inter�s a aplicar
	double capital; // Entrada: capital solicitado
	double total;	// Salida: cantidad ganada en un a�o
   
	cout << "Introduzca capital inicial --> ";
	cin >> capital;
	cout << "\nIntroduzca inter�s --> ";
	cin >> interes;   
   
	total = capital + capital * interes/100; 
	// idem: 
	// total = capital + (capital * (interes/100)); 

	cout << "\nA�o 1 --> Capital + Ganancia obtenida = " << total;
	cout << "\n\n";

/*	
	// Mejora propuesta: total en el segundo a�o, invirtiendo todo 
	// lo conseguido el primer a�o

	capital = total; 
	total = capital + capital * interes/100;

	cout << "\nA�o 2 --> Capital + Ganancia obtenida = " << total;
	cout << "\n\n";
*/
	system("pause");
}

