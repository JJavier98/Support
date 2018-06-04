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
// EJERCICIO 6
/*	
   Programa que calcula el reparto de beneficios entre cuatro destinatarios, 
   siendo las proporciones diferentes: el destinatario 1 (dise�ador) recibe 
   el doble que los otros tres (fabricantes).

   Entradas: beneficio a repartir 
   Salidas:  ganancia del dise�ador y ganancia de los fabricantes   
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{

	double beneficio; 	// Dato de entrada

	cout << "\nIntroduzca beneficio obtenido: ";
	cin >> beneficio;


/*
	En esta primera soluci�n se ofrece la salida pedida, 
	pero tiene dos inconvenientes:
	1.	Repetimos el c�lculo beneficio/5 dos veces.
		Repetir c�digo es propenso a errores
	2.	En la misma sentencia de salida de resultados realizamos los c�mputos. 
		Debemos separar las entradas de datos de los c�mputos y de las 
		salidas de resultados 
*/
	 
	cout << "\nGanancia de cada fabricante: " << beneficio/5;   // :-(
	cout << "\nGanancia del dise�ador: " << 2 * beneficio/5;   // :-(
	cout << "\n\n";

	// Lo arreglamos a�adiendo dos variables y realizando los calculos 
	// antes de miostrar los resultados:

	double ganancia_diseniador, ganancia_fabricante; // Datos de salida

	ganancia_fabricante = beneficio/5;
	ganancia_diseniador= 2 * ganancia_fabricante;

	cout << "\nGanancia de cada fabricante: " <<  ganancia_fabricante;  // :-)
	cout << "\nGanancia del dise�ador: " << ganancia_diseniador;       // :-)
	cout << "\n\n";
	
	system("pause");
}
