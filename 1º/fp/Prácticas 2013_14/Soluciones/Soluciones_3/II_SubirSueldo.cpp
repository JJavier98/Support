/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 2
/*	

	Programa que calcule si es aplicable la subida de ingresos a 
	partir de la edad e ingresos, de acuerdo con la regla:  
		"Se subirá el sueldo si es jubilado con ingresos inferiores a 300 euros" 
	Entradas: edad (double) e ingresos (double) 
	Salidas: el nuevo sueldo ó el mensaje "No es aplicable la subida"


*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int edad;
	double ingresos;

	cout << "\nIntroduce la edad de la persona: ";
	cin >> edad;
	cout << "\nIntroduce los ingresos: ";
	cin >> ingresos;


	/*
	// En el siguiente código realizamos los cómputos en el mismo bloque
	// en el que realizamos la salida de datos por pantalla:
	
	if ((edad > 65) && (ingresos < 300))
		ingresos = ingresos + ingresos * 1.05;
	else
		cout << "\nNo es aplicable la subida";

	cout << "\nSalario Final: " << ingresos;
	*/


	// Para resolverlo, usaremos variables lógicas que nos digan lo que 
	// ha ocurrido en el código anterior
	
	bool es_jubilado;			// VERDAD si edad > 65
	bool tiene_ingresos_bajos;	// VERDAD si ingresos < 300
	bool es_aplicable_subida;	// VERDAD si son ciertas LAS DOS anteriores

	// CÓMPUTOS:

	es_jubilado = edad > 65;
	tiene_ingresos_bajos = ingresos < 300;
	es_aplicable_subida = es_jubilado && tiene_ingresos_bajos;

	if (es_aplicable_subida)
		ingresos = ingresos * 1.05;

	// SALIDA RESULTADOS:

	if (! es_aplicable_subida)
		cout << "\nNo es aplicable la subida";	
	
	cout << "\nSalario Final: " << ingresos;

	/*
	En el anterior código usamos dos estructuras equivalentes:
		if (es_aplicable_subida)
		if (! es_aplicable_subida)
	pero logramos independizar los cómputos de la salida de datos,
	lo cual es muy importante.
	*/

	cout << "\n\n";
	system("pause");
}
