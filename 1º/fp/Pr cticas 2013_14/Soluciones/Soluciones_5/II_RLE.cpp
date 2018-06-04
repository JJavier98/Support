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
// EJERCICIO 22
//
/*	
	El método RLE (Run Length Encoding) codifica una secuencia de datos 
	formada por series de valores idénticos consecutivos como una 
	secuencia de parejas de números(valor de la secuencia y número de 
	veces que se repite). 

	Este programa lee una secuencia de números naturales (terminada 
	con -1) y la codifica mediante el método RLE. 
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int actual, anterior, iguales_hasta_ahora;

	/*
		ALGORITMO: 
		Mientras que el actual no sea el terminador (-1)
			Avanzar actual y anterior

		Si son iguales
			incrementar la longitud de la secuencia actual
		si no
			Imprimir el actual junto con la longitud actual
				y resetear el contador de la longitud actual
   */

   cin >> actual;
   iguales_hasta_ahora = 1;

   while (actual != -1){

      anterior = actual;      
      cin >> actual;
      
      if (anterior == actual)
      
		  iguales_hasta_ahora++; // Continua la serie

		else{
			// Pintar pareja: num.veces - valor

			cout << iguales_hasta_ahora << " " << anterior << " ";      

			iguales_hasta_ahora = 1; // empezar una nueva serie
		}
	}   

	cout << "\n\n";

	system("pause");
}
