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
// EJERCICIO 15
//
/*	
	Un paso más en la resolución de este problema, planteado en: 
	* ejercicio 19 de la Relación de Problemas 2 
	* ejercicio  9 de la Relación de Problemas 3 
	No describiremos los detalles, ya que deben ser conocidos. 

	Se construirá una clase "ProgresionGeometrica" que incorpore la 
	funcionalidad necesaria para resolver los problemas planteados.

	Un objeto de la clase "ProgresionGeometrica" queda completamente 
	determinado por el primer término y la razón. 

	Los métodos ofertados por la clase serán los conocidos: 
	- Sumar hasta un tope todos los términos de la progresión
	- Obtener el término n-ésimo de la progresión
	- Multiplicar hasta un tope todos los términos de la progresión
	- Suma hasta el infinito todos los términos de la progresión

	En el diseño de esta clase se ha decidido que, una vez creado 
	el objeto, no se pueda cambiar ni el primer término ni la razón 
	de la progresión. En caso contrario, habría que añadir los 
	métodos correspondientes:  
		SetRazon()
		SetPrimerTermino()
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

///////////////////////////////////////////////////////////////////////

class ProgresionGeometrica
{
private:

	double primer_termino;	// Una progresión geométrica queda completamente
	double razon;			// especificada por estos dos valores

public:

	/*****************************************************************/
	// Constructor con argumentos

	ProgresionGeometrica (double primer_termino_progresion, 
						  double razon_progresion)
	{
		primer_termino = primer_termino_progresion;
		razon = razon_progresion;
	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 
	
	double PrimerTermino()
	{
		return primer_termino;
	}

	double Razon()
	{
		return razon;
	}

	/*****************************************************************/
	// Cálculo del término n-ésimo
	//				   n-1
	//	a_n =  a_1 * r 
	//

	double Termino (int n) 
	{
		return (primer_termino * pow (razon, n-1));
	}

	/*****************************************************************/
	// Cálculo de la sumatoria por la expresión simple:
	//
	// 		  i=k 		    
	//		  __                    k
	//		<		               r  - 1
	//		 >    a_i	= 	a_1 * --------
	//		< __   		            r - 1
	//		  i=1		     
	//

	double SumaHasta (int tope) 
	{
		return (primer_termino * ((pow(razon,tope) - 1) / (razon-1)));
	}

	/*****************************************************************/
	// Cálculo de la sumatoria hasta infinito:
	//
	//		 i=OO
	//		  __
	//		<              a_1
	//		 >    a_i  = -------	siempre que |r| < 1
	//		< __          1 - r
	//		  i=1
	//
	// PRECONDICION: |r| < 1

	double SumaHastaInfinito () 
	{
		return (primer_termino / (1 - razon));
	}

	/*****************************************************************/
	// Cálculo del producto de los primeros k valores de la serie: 
	//
	//        i=k         i=k
	//		  __          __ 
	//		 |  |        |  |                 ________________
	//		 |  |  		 |	|         i-1    /            k
	//		 |  |  a_i = |  |  a_1 * r    = V  (a_1 * a_k)
	//		  i=1         i=1
	//
	//

	double MultiplicaHasta (int tope) 
	{
		return (sqrt (pow (primer_termino * Termino (tope), tope)));
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	double primero, razon;
	int tope;

	double suma_hasta_tope,		// Para guardar los 
		   suma_hasta_inf,		// resultados de los 
		   producto_hasta;		// cálculos


	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "Primer término de la progresión: ";
	cin >> primero;
	cout << "Razón de la progresión: ";
	cin >> razon;
	cout << endl;


	// Creación de la progresión (constructor)

	ProgresionGeometrica prog (primero, razon);


	// Petición del índice que actúa como tope en sumatoria y producto

	cout << endl;
	do {
		cout << "Indice (debe ser >=1) del último término a sumar: ";
		cin >> tope;
	} while (tope < 1);


	cout << "\nCalculos sobre la progresión:\n";
	cout << "\tPrimer término: = " << setw(10) << setprecision (6) 
		 << prog.PrimerTermino() << endl;
	cout << "\tRazón: = " << setw(10) << setprecision (6) 
		 << prog.Razon() << endl;


	// Cálculo de la suma

	suma_hasta_tope = prog.SumaHasta (tope);

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(20) << setprecision (10) << suma_hasta_tope;
	cout << endl;
	

	// Cálculo de la suma hasta infinito

	if (abs(prog.Razon()) < 1) {

		suma_hasta_inf = prog.SumaHastaInfinito ();

		cout << "\nSuma hasta infinito = " 
			 << setw(20) << setprecision (10) << suma_hasta_inf;
	}
	else 
		cout << "\nNo puede calcularse suma hasta infinito " 
			 << "porque |" << setprecision (6) << prog.Razon() << "| >= 1";
	cout << endl;


	// Cálculo del producto 

	producto_hasta = prog.MultiplicaHasta (tope);

	cout << "\nProducto hasta " << setw(3) << tope 
		 << " = " << setw(20) << setprecision (10) << producto_hasta;
	cout << endl;

	cout << "\n\n";
	system("pause");
}