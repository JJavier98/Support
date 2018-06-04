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
// EJERCICIO 13
/*	
   Pasar un car�cter de may�scula a min�scula, pero leyendo el car�cter
   con un filtro de entrada
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	const int DISTANCIA_MAY_MIN = 'a'-'A';             

	char letra;				// Entrada
	char letra_minuscula;	// Salida
   
	/*
	Algoritmo:
		Lee una letra, HASTA que sea una may�scula,
		es decir, hasta que (letra >= 'A') && (letra <= 'Z')

	Equivale a:
         
		Lee una letra, MIENTRAS que NO sea una may�scula
      
		es decir, mientras que !((letra >= 'A') && (letra <= 'Z'))
		es decir, mientras que !(letra >= 'A') || !(letra <= 'Z')
			(hemos aplicado las leyes de Morgan)
		es decir, mientras que (letra < 'A') || (letra > 'Z')
   
			do{
				cout << "\nIntroduzca una letra may�scula  --> ";
				cin >> letra_mayuscula;
			} while ((letra < 'A') || (letra > 'Z'));
   
	*/


	bool es_mayuscula; 

	// Filtro para permitir SOLO may�sculas

	do {

		cout << "Introduzca una letra may�scula  --> ";
		cin >> letra;

		es_mayuscula = (letra >= 'A') && (letra <= 'Z');

	} while (! es_mayuscula);
   

	// En este punto estamos seguros de que "letra" contiene 
	// una may�scula, por lo que podemos transformarla con seguridad 

	letra_minuscula = letra + DISTANCIA_MAY_MIN ;
   
	cout << "\nEl car�cter " << letra  
		 << " pasado a min�scula es: " << letra_minuscula;
   
	cout << "\n\n";   
	system("pause");
}