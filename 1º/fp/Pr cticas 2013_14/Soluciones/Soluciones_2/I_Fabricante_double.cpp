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
// EJERCICIO 6
/*	
   Programa que calcula el reparto de beneficios entre cuatro destinatarios, 
   siendo las proporciones diferentes: el destinatario 1 (diseñador) recibe 
   el doble que los otros tres (fabricantes).

   Entradas: beneficio a repartir 
   Salidas:  ganancia del diseñador y ganancia de los fabricantes   
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
	En esta primera solución se ofrece la salida pedida, 
	pero tiene dos inconvenientes:
	1.	Repetimos el cálculo beneficio/5 dos veces.
		Repetir código es propenso a errores
	2.	En la misma sentencia de salida de resultados realizamos los cómputos. 
		Debemos separar las entradas de datos de los cómputos y de las 
		salidas de resultados 
*/
	 
	cout << "\nGanancia de cada fabricante: " << beneficio/5;   // :-(
	cout << "\nGanancia del diseñador: " << 2 * beneficio/5;   // :-(
	cout << "\n\n";

	// Lo arreglamos añadiendo dos variables y realizando los calculos 
	// antes de miostrar los resultados:

	double ganancia_diseniador, ganancia_fabricante; // Datos de salida

	ganancia_fabricante = beneficio/5;
	ganancia_diseniador= 2 * ganancia_fabricante;

	cout << "\nGanancia de cada fabricante: " <<  ganancia_fabricante;  // :-)
	cout << "\nGanancia del diseñador: " << ganancia_diseniador;       // :-)
	cout << "\n\n";
	
	system("pause");
}
