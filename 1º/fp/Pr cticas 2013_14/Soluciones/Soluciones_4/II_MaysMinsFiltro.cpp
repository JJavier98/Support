/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// EJERCICIO 13
/*	
   Pasar un carácter de mayúscula a minúscula, pero leyendo el carácter
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
		Lee una letra, HASTA que sea una mayúscula,
		es decir, hasta que (letra >= 'A') && (letra <= 'Z')

	Equivale a:
         
		Lee una letra, MIENTRAS que NO sea una mayúscula
      
		es decir, mientras que !((letra >= 'A') && (letra <= 'Z'))
		es decir, mientras que !(letra >= 'A') || !(letra <= 'Z')
			(hemos aplicado las leyes de Morgan)
		es decir, mientras que (letra < 'A') || (letra > 'Z')
   
			do{
				cout << "\nIntroduzca una letra mayúscula  --> ";
				cin >> letra_mayuscula;
			} while ((letra < 'A') || (letra > 'Z'));
   
	*/


	bool es_mayuscula; 

	// Filtro para permitir SOLO mayúsculas

	do {

		cout << "Introduzca una letra mayúscula  --> ";
		cin >> letra;

		es_mayuscula = (letra >= 'A') && (letra <= 'Z');

	} while (! es_mayuscula);
   

	// En este punto estamos seguros de que "letra" contiene 
	// una mayúscula, por lo que podemos transformarla con seguridad 

	letra_minuscula = letra + DISTANCIA_MAY_MIN ;
   
	cout << "\nEl carácter " << letra  
		 << " pasado a minúscula es: " << letra_minuscula;
   
	cout << "\n\n";   
	system("pause");
}