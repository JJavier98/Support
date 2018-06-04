/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 3
// EJERCICIO 8 
/*	
	Considerar la sucesi�n:

              (-1)^i * (i^2  - 1)
        a_i = -------------------
                   2*i

	Este programa calcula la suma de sus n primeros t�rminos.
	
	Implementaci�n con funciones del ejercicio 21 de la Relaci�n II
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************************/
// En esta implementaci�n se calcula directamente (-1)^i
// que ser� +1 � -1 dependiendo de si i es par o impar, respectivamente

double Elemento (int i)
{
	int potencia; 

	if (i%2 == 0) potencia = 1;
	else		  potencia = -1;

	return ((potencia * (i*i - 1)) / (2.0 * i)); // T�rmino i-esimo
}

/*********************************************************************/
// Implementaci�n de la sumatoria desde 1 hasta tope de Elemento(i)

double SumaHasta (int tope)
{
	double suma = 0.0;

	// Cuando i=1, suma=0.0 (evitamos una iteraci�n innecesaria)
	for (int i = 2 ; i <= tope ; i++)
		suma = suma + Elemento (i);
   
	return (suma);
}
/*********************************************************************/

int main()
{
	int	tope;
 
   	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "\nIntroduzca el �ndice del mayor elemento de la serie: ";
	cin >> tope;
   
	cout << "\nSuma de la serie = " 
		 << setw(10) << setprecision(4) << SumaHasta (tope);      

	cout << "\n\n";   
	system("pause");
}