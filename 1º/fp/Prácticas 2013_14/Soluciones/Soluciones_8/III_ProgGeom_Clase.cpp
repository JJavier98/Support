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
// EJERCICIO 15
//
/*	
	Un paso m�s en la resoluci�n de este problema, planteado en: 
	* ejercicio 19 de la Relaci�n de Problemas 2 
	* ejercicio  9 de la Relaci�n de Problemas 3 
	No describiremos los detalles, ya que deben ser conocidos. 

	Se construir� una clase "ProgresionGeometrica" que incorpore la 
	funcionalidad necesaria para resolver los problemas planteados.

	Un objeto de la clase "ProgresionGeometrica" queda completamente 
	determinado por el primer t�rmino y la raz�n. 

	Los m�todos ofertados por la clase ser�n los conocidos: 
	- Sumar hasta un tope todos los t�rminos de la progresi�n
	- Obtener el t�rmino n-�simo de la progresi�n
	- Multiplicar hasta un tope todos los t�rminos de la progresi�n
	- Suma hasta el infinito todos los t�rminos de la progresi�n

	En el dise�o de esta clase se ha decidido que, una vez creado 
	el objeto, no se pueda cambiar ni el primer t�rmino ni la raz�n 
	de la progresi�n. En caso contrario, habr�a que a�adir los 
	m�todos correspondientes:  
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

	double primer_termino;	// Una progresi�n geom�trica queda completamente
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
	// M�todos de lectura (Get) de los datos individuales 
	
	double PrimerTermino()
	{
		return primer_termino;
	}

	double Razon()
	{
		return razon;
	}

	/*****************************************************************/
	// C�lculo del t�rmino n-�simo
	//				   n-1
	//	a_n =  a_1 * r 
	//

	double Termino (int n) 
	{
		return (primer_termino * pow (razon, n-1));
	}

	/*****************************************************************/
	// C�lculo de la sumatoria por la expresi�n simple:
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
	// C�lculo de la sumatoria hasta infinito:
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
	// C�lculo del producto de los primeros k valores de la serie: 
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
		   producto_hasta;		// c�lculos


	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "Primer t�rmino de la progresi�n: ";
	cin >> primero;
	cout << "Raz�n de la progresi�n: ";
	cin >> razon;
	cout << endl;


	// Creaci�n de la progresi�n (constructor)

	ProgresionGeometrica prog (primero, razon);


	// Petici�n del �ndice que act�a como tope en sumatoria y producto

	cout << endl;
	do {
		cout << "Indice (debe ser >=1) del �ltimo t�rmino a sumar: ";
		cin >> tope;
	} while (tope < 1);


	cout << "\nCalculos sobre la progresi�n:\n";
	cout << "\tPrimer t�rmino: = " << setw(10) << setprecision (6) 
		 << prog.PrimerTermino() << endl;
	cout << "\tRaz�n: = " << setw(10) << setprecision (6) 
		 << prog.Razon() << endl;


	// C�lculo de la suma

	suma_hasta_tope = prog.SumaHasta (tope);

	cout << "\nSuma hasta " << setw(3) << tope 
		 << " = " << setw(20) << setprecision (10) << suma_hasta_tope;
	cout << endl;
	

	// C�lculo de la suma hasta infinito

	if (abs(prog.Razon()) < 1) {

		suma_hasta_inf = prog.SumaHastaInfinito ();

		cout << "\nSuma hasta infinito = " 
			 << setw(20) << setprecision (10) << suma_hasta_inf;
	}
	else 
		cout << "\nNo puede calcularse suma hasta infinito " 
			 << "porque |" << setprecision (6) << prog.Razon() << "| >= 1";
	cout << endl;


	// C�lculo del producto 

	producto_hasta = prog.MultiplicaHasta (tope);

	cout << "\nProducto hasta " << setw(3) << tope 
		 << " = " << setw(20) << setprecision (10) << producto_hasta;
	cout << endl;

	cout << "\n\n";
	system("pause");
}