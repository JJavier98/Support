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
// EJERCICIO 10
/*	
	Calcular cu�ntos datos reales se han introducido y cual es el m�nimo 
	de dichos valores (pueden ser positivos o negativos). 
	La lectura finaliza cuando se introduce el valor 0. 
   
	Entradas:	Una serie datos reales distintos de cero.
				Si se introduce el cero finaliza la lectura
	Salidas:	Se muestra el m�nimo de los valores leidos y 
				el n�mero de datos procesados.

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
	Algo que NUNCA haremos ser� inicializar min a un literal:
	min = 32768;
	La raz�n es 32768 puede que sea el m�nimo entero en un compilador 
	que use 16 bits para su representaci�n, PERO en otro compilador que 
	use 32 bits, el m�nimo entero es mucho m�s peque�o.
	Si todos los valores le�dos desde teclado est�n por encima de la 
	constante anterior, el programa ya no funcionar� correctamente, ya 
	que dar� como salida 32768
	*/

   min = dato;					// Inicializamos min al primer valor le�do
   validos_introducidos = 0;	// Si el primero es cero, consideramos que no 
								// es v�lido y no se considera.
     
   while (dato != 0) { 

      validos_introducidos++;   // Actualizar el contador, ya que se ha leido 
								// un dato v�lido previamente.
      if (dato < min)	// La primera vez, dato es igual a min => false
         min = dato;
         
      cout << MENSAJE;
      cin >> dato;	//  Lectura anticipada

   }
   
   if (validos_introducidos > 0){
      cout << "\nN�mero de valores introducidos = " << validos_introducidos;
      cout << "\nM�nimo = " << min;
   }
   else
      cout << "\nNo se introdujo ning�n valor v�lido";
      
   cout << "\n\n";
   system("pause");
}
