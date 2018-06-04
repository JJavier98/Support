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
// EJERCICIO 10
/*	
	Calcular cuántos datos reales se han introducido y cual es el mínimo 
	de dichos valores (pueden ser positivos o negativos). 
	La lectura finaliza cuando se introduce el valor 0. 
   
	Entradas:	Una serie datos reales distintos de cero.
				Si se introduce el cero finaliza la lectura
	Salidas:	Se muestra el mínimo de los valores leidos y 
				el número de datos procesados.

	NOTA: Un buen ejemplo de lectura anticipada.
*/
/*********************************************************************/

#include <iostream>
#include <string>
using namespace std;  

int main()
{
	const string MENSAJE = "\nIntroduzca un valor real (cero para terminar): ";

   double dato, min;
   int validos_introducidos;
   
   cout << MENSAJE;
   cin >> dato;               //  Lectura anticipada

	/*
	Algo que NUNCA haremos será inicializar min a un literal:
	min = 32768;
	La razón es 32768 puede que sea el mínimo entero en un compilador 
	que use 16 bits para su representación, PERO en otro compilador que 
	use 32 bits, el mínimo entero es mucho más pequeño.
	Si todos los valores leídos desde teclado están por encima de la 
	constante anterior, el programa ya no funcionará correctamente, ya 
	que dará como salida 32768
	*/

   min = dato;					// Inicializamos min al primer valor leído
   validos_introducidos = 0;	// Si el primero es cero, consideramos que no 
								// es válido y no se considera.
     
   while (dato != 0) { 

      validos_introducidos++;   // Actualizar el contador, ya que se ha leido 
								// un dato válido previamente.
      if (dato < min)	// La primera vez, dato es igual a min => false
         min = dato;
         
      cout << MENSAJE;
      cin >> dato;	//  Lectura anticipada

   }
   
   if (validos_introducidos > 0){
      cout << "\nNúmero de valores introducidos = " << validos_introducidos;
      cout << "\nMínimo = " << min;
   }
   else
      cout << "\nNo se introdujo ningún valor válido";
      
   cout << "\n\n";
   system("pause");
}
