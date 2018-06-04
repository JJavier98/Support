/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 17-a
//
/*	
	El ejercicio 9 calculaba todos los divisores de un n�mero. 
	En este programa se modifica la soluci�n para que el filtro de 
	entrada usado para leer la variable tope se haga con un bucle 
	pre-test (while).
*/
/*********************************************************************/

#include <iostream>
using namespace std;  

int main()
{
	int tope, divisor;
	bool es_negativo;

	/*
	Ten�amos un filtro de entrada de la forma:
	
	do {
		cout << "Introduce un numero entero positivo mayor que 0: ";
		cin >> tope;
	} while (top

	Se pide que lo hagamos con un bucle pre-test (while).
	Para ello, hemos introducido una variable adicional es_negativo
	La inicializamos a true para que SIEMPRE entre una vez
	ya que SIEMPRE queremos leer un primer valor, al menos.

	El uso del bucle pre-test no complica excesivamente el c�digo, pero 
	si siempre vamos a ejecutar una primera vez el bucle (como en 
	cualquier filtro), es preferible la versi�n anterior (ejercicio 9) 
	con el ciclo post-test (do-while).

	En definitiva, en la mayor parte de los algoritmos usaremos
	bucles pre-test pues siempre habr� situaciones en las que
	no querremos entrar ni una sola vez a ejecutar el cuerpo del bucle.
	La excepci�n son los filtros de entrada de datos, en los que,
	normalmente, usaremos un post-test (do-while)
	*/

	es_negativo = true;

	while (es_negativo){
		cout << "Introduce un numero entero positivo mayor que 0: ";
		cin >> tope;
		es_negativo = (tope <= 0);
	}

	divisor = 2;

	while (divisor < tope) {

		if (tope % divisor == 0)
			cout << divisor << " es un divisor de " << tope << endl;
		
		divisor++;
	}

	cout << "\n\n";
	system("pause");
}