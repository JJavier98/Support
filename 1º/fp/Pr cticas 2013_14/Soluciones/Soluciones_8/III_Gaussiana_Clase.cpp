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
// EJERCICIO 29 
//
/*	
	Un paso más en la resolución de este problema, planteado en: 
	* ejercicio 5 de la Relación de Problemas 1
	* ejercicio 7 de la Relación de Problemas 3 
	* ejercicio 24 de la Relación de Problemas 3 
	No describiremos los detalles, ya que deben ser conocidos. 

	Se construye la clase "Gausssiana" que incorpore la 
	funcionalidad necesaria para resolver los problemas planteados.

	Un objeto de la clase "Gaussiana" queda completamente 
	determinado por la esperanza y la desviación típica. 

	Los métodos ofertados por la clase serán los conocidos: 
	- Calcular el valor de una gaussiana para un valor x dado.
	- el valor aproximado de la CDF(x)

	En el diseño de esta clase se ha decidido que, una vez creado el  
	objeto no se pueda cambiar ni la esperanza ni la desviación típica. 
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Por el momento tendremos que aceptar el uso de una constante global
// No obstante, observe que no pueden producirse efectos colaterales 
// al no poder modificar este valor (es una constante)
// No obstante, avanzamos que podría emplearse una constante a nivel 
// de clase para PI (compartida por todos los objetos de la clase): 
// constante estatica

const double PI = 3.1415927;

///////////////////////////////////////////////////////////////////////

class Gaussiana
{

private:

	double esperanza;	// Esperanza
	double desviacion;	// Desviación típica

public:

	// Para este problema no permitimos el constructor sin argumentos, 
	// porque no tiene sentido la existencia de un objeto de la clase 
	// con valores por defecto. 

	/*****************************************************************/
	// Constructor con argumentos

	Gaussiana (double esp, double desv)
	{
		esperanza = esp;
		desviacion = desv;
	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 
	
	double GetEsperanza()
	{
		return esperanza;
	}

	double GetDesviacion()
	{
		return desviacion;
	}

	/*****************************************************************/
	// Calculo de Gauss(x)

	double Evalua (double x)
	{
		return (exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
		                        (desviacion * sqrt(2*PI)));
	}

	/*****************************************************************/
	// Calculo de CDF(x)

	double CDF (double x)
	{
		const double b0 = 0.2316419;
		const double b1 = 0.319381530;
		const double b2 = -0.356563782;
		const double b3 = 1.781477937;
		const double b4 = -1.821255978;
		const double b5 = 1.330274429;

		double t = 1 / (1 + b0*x);

		return (1 - Evalua (x) * (b1*t + b2*t*t + b3*t*t*t + b4*t*t*t*t));

	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/


int main()
{

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Peticion de los parámmetros de la gaussiana

	double esperanza, desviacion;

	cout << "Esperanza = ";
	cin >> esperanza;
	cout << "Desviación típica = ";
	cin >> desviacion;
	cout << endl;

	// Creación de la gaussiana (constructor)

	Gaussiana g (esperanza, desviacion);

	
	cout << "\nCálculos sobre la gausssiana:\n";
	cout << "\tEsperanza =   " << setw(10) << setprecision (6) 
		 << g.GetEsperanza() << endl;
	cout << "\tDesv.Típica = " << setw(10) << setprecision (6) 
		<< g.GetDesviacion() << endl;


	// Petición del valor de abscisa, x, para calcular:  
	// Gauss(x) y CDF(x)

	double x; 

	cout << "\nIntroduzca el valor de la abscisa: ";
	cin >> x;
   
	cout << "\n\nEl valor de Gauss(" << x << ") es " 
		 << setw(10) << setprecision (6) << g.Evalua (x);
	cout << "\n\nEl valor de CDF(" << x << ") es " 
		 << setw(10) << setprecision (6) << g.CDF(x);
	cout << endl;

	cout << "\n\n";

	system("pause");

	return (0);
}