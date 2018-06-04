/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 2
// EJERCICIO 21
//
/*	
	Considerar la sucesi�n:

              (-1)^i * (i^2  - 1)
        a_i = -------------------
                   2*i

	Este programa calcula la suma de sus 100 primeros t�rminos.
	
	RESTRICCI�N: No se usa la funci�n pow. En cada iteraci�n se calcula 
	(-1)^i a partir del calculado en la iteraci�n anterior: (-1)^{i-1}
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
	Una primera soluci�n pasar�a por hacer  lo siguiente.
	Para calcular en cada iteraci�n (-1)^i, lo hago
	con un bucle similar al usado para calcular una base
	cualquiera elevado a un exponente entero, sustituyendo
	la base por -1 y el exponente por i, es decir:
     
	potencia = 1;
	for (j = 1 ; j <= i ; j++)
		potencia = potencia*(-1);    
   
	Por tanto, el recorrido de los t�rminos de la serie quedar�a as�:
      
	suma=0;

	for (i = 1 ; i <= n ; i++){

		potencia = 1;
		for (j = 1 ; j <= i ; j++)
			potencia = potencia*(-1);
   
		termino = (i*i-1)/(2.0*i);
		suma = suma + potencia*termino;
	}
   
	Pero SIEMPRE nos debemos preguntar si en cada iteraci�n de un bucle,
	podemos aprovechar los c�lculos realizados en la iteraci�n anterior.
	En este caso es as�. 
   
	Si en la iteraci�n i-1 he calculado (-1)^(i-1), y lo he almacenado 
	en una variable "potencia", entonces, para calcular la potencia de 
	(-1)^i, basta multiplicar (en la siguiente iteraci�n) "potencia" 
	por -1, o lo que es lo mismo, cambiarlo de signo.
	De esa forma sustituimos todo el bucle for j por una �nica l�nea:
		potencia = -potencia;
*/

int main()
{
	int i, tope, potencia;
	double suma_serie, termino;   
   
   	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	cout << "\nIntroduzca el l�mite de la serie: ";
	cin >> tope;
   
	suma_serie = 0;

	potencia = 1; 
   
	for (i = 1 ; i <= tope ; i++){

		potencia = -potencia;	// cambio de signo ->
								// para i=1, (-1)^i debe ser -1,  
								// para i=2, (-1)^i debe ser +1,... 
		termino = (i*i - 1) / (2.0 * i); // t�rmino i

		suma_serie = suma_serie + (potencia * termino);
	}
   
	cout << "\nSuma de la serie = " 
		 << setw(10) << setprecision(2) << suma_serie;      
	cout << "\n";
   
	system("pause");
}
