/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 3
// EJERCICIO 8 
/*	
	Considerar la sucesión:

              (-1)^i * (i^2  - 1)
        a_i = -------------------
                   2*i

	Este programa calcula la suma de sus n primeros términos.
	
	Implementación con funciones del ejercicio 21 de la Relación II
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************************/
// En esta implementación se calcula directamente (-1)^i
// que será +1 ó -1 dependiendo de si i es par o impar, respectivamente

double Elemento (int i)
{
	int potencia; 

	if (i%2 == 0) potencia = 1;
	else		  potencia = -1;

	return ((potencia * (i*i - 1)) / (2.0 * i)); // Término i-esimo
}

/*********************************************************************/
// Implementación de la sumatoria desde 1 hasta tope de Elemento(i)

double SumaHasta (int tope)
{
	double suma = 0.0;

	// Cuando i=1, suma=0.0 (evitamos una iteración innecesaria)
	for (int i = 2 ; i <= tope ; i++)
		suma = suma + Elemento (i);
   
	return (suma);
}
/*********************************************************************/

int main()
{
	int	tope;
 
   	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "\nIntroduzca el índice del mayor elemento de la serie: ";
	cin >> tope;
   
	cout << "\nSuma de la serie = " 
		 << setw(10) << setprecision(4) << SumaHasta (tope);      

	cout << "\n\n";   
	system("pause");
}