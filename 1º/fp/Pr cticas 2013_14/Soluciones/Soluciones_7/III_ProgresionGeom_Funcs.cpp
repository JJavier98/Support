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
// EJERCICIO 9 
//
// Ampliaci�n del ejercicio 19 de la Relaci�n II
/*	
	Progresi�n geom�trica: 
	Supongamos una serie num�rica cuyo t�rmino general es:

					  i-1        
		a_i =  a_1 * r    = a_{i-1} * r

	donde "a_1" es el primer t�rmino de la serie, y "r" es la raz�n

	El programa lee r, a_1 y un �ndice k y calcula:  

	a) la suma de los primeros k valores de la serie, es decir: 
	
		  i=k        i=k
		  __         __
		<           <           i-1
		 >    a_i =  >   a_1 * r   
		< __   		< __
		  i=1         i=1

		Recordar que a_i = a_{i-1} * r   para i=2,3,... lo que hace 
		posible escribir otra versi�n de  esta sumatoria.
	
   		  i=k 	     i=k                 i=k
 		  __         __                  __   
 		<		    <            i-1    <
 		 >    a_i =  >   a_1 * r 	=    >   a_{i-1} * r
        < __   		< __   		        < __
 		  i=1		  i=1                 i=2
 
	b) 	b) la suma anterior pero sustituyendo la sumatoria por

			    k
		       r  - 1
		a_1 * --------
		       r - 1

	c) la suma "hasta infinito" de la serie, es decir: 
	
		  i=OO
		  __
		<              a_1
		 >    a_i  = -------	siempre que |r| < 1
		< __          1 - r
		  i=1
	
	d) el producto de los primeros k valores de la serie, es decir: 
	
          i=k         i=k
		  __          __ 
		 |  |        |  |                 _____________________
		 |  |  		 |	|         i-1    /            k
		 |  |  a_i = |  |  a_1 * r    = V  (a_1 * a_k)
		  i=1         i=1

	Entradas:	El primer t�rmino de la progresi�n (termino_primero)
				La raz�n de la progresi�n (razon)
				Indice del �ltimo t�rmino para la suma (tope)
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*****************************************************************/
// C�lculo del t�rmino i-�simo
//				   i-1
//	a_i =  a_1 * r 

double Termino (int i, double termino_primero, double razon) 
{
	return (termino_primero * pow (razon, i-1));
}

/*****************************************************************/
// C�lculo de la sumatoria, usando la expresi�n directa de a_i:
//
// 		  i=k 		     i=k
//		  __             __        
//		<		       <            i-1
//		 >    a_i	=   >    a_1 * r 	
//		< __   		   < __         
//		  i=1		     i=1
//

double SumaHasta_ver1 (double termino_primero, double razon, int tope) 
{
	double suma_total = termino_primero;
	
	// El ciclo for no se inicia a 1 porque la asignaci�n anterior 
	// hace, impl�citamente, la suma desde i=1 hasta 1

	for (int i=2; i <= tope; i++) { 
		suma_total += Termino(i, termino_primero, razon);		
	}

	return (suma_total);
}

/*****************************************************************/
// C�lculo de la sumatoria, usando en cada iteraci�n el valor del 
/// t�rmino calculado en la iteraci�n anterior.
//
// 		  i=k 		     i=k                 i=k
//		  __             __                  __   
//		<		       <            i-1     <
//		 >    a_i	=   >    a_1 * r 	=    >   a_{i-1} * r
//		< __   		   < __   		        < __
//		  i=1		     i=1                  i=1
//

double SumaHasta_ver2 (double termino_primero, double razon, int tope) 
{
	double suma_total  = termino_primero;
	double termino_ant = termino_primero;

	double termino_act;

	// El ciclo for no se inicia a 1 porque las asignaciones anteriores 
	// hacen, impl�citamente, la suma desde i=1 hasta 1

	for (int i=2; i <= tope; i++) { 
		termino_act = termino_ant * razon;
		suma_total += termino_act;		
		termino_ant = termino_act;
	}

	return (suma_total);
}
/*****************************************************************/
// C�lculo de la sumatoria por la expresi�n directa:
//
// 		  i=k 		    
//		  __                    k
//		<		               r  - 1
//		 >    a_i	= 	a_1 * --------
//		< __   		            r - 1
//		  i=1		     
//

double SumaHasta_ver3 (double termino_primero, double razon, int tope) 
{
	return (termino_primero * ((pow(razon,tope) - 1) / (razon-1)));
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

double SumaHastaInfinito (double termino_primero, double razon) 
{
	return (termino_primero / (1 - razon));
}

/*****************************************************************/
// C�lculo del producto de los primeros k valores de la serie: 
//
//        i=k         i=k
//		  __          __ 
//		 |  |        |  |                 
//		 |  |  		 |	|         i-1 
//		 |  |  a_i = |  |  a_1 * r    
//		  i=1         i=1
//
//

double MultiplicaHasta_ver1 (double termino_primero, double razon, int tope) 
{
	int producto_total = termino_primero;

	// El ciclo for no se inicia a 1 porque la asignaci�n anterior 
	// hace, impl�citamente, el producto desde i=1 hasta 1

	for (int i=2; i <= tope; i++) { 
		producto_total *= termino_primero * pow (razon, i-1);		
	}

	return (producto_total);
}

/*****************************************************************/
// C�lculo (directo) del producto de los primeros k valores de la serie: 
//
//        i=k         i=k
//		  __          __ 
//		 |  |        |  |                 ________________
//		 |  |  		 |	|         i-1    /            k
//		 |  |  a_i = |  |  a_1 * r    = V  (a_1 * a_k)
//		  i=1         i=1
//
//

double MultiplicaHasta_ver2 (double termino_primero, double razon, int tope) 
{
	return (sqrt (pow (termino_primero * 
		               Termino (tope, termino_primero, razon), tope)));
}

/*****************************************************************/
int main()
{
	double termino_primero, razon; // Par�metros de la serie

	int tope; // M�ximo �ndice para la suma

	// Resultados 
	double suma_total_ver1, suma_total_ver2, suma_total_ver3; 
	double suma_total_inf;
	double producto_total_ver1, producto_total_ver2;


	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Lecutra de los par�metros que definen la serie

	cout << "Primer t�rmino de la progresi�n: ";
	cin >> termino_primero;
	cout << "Raz�n de la progresi�n: ";
	cin >> razon;

	// Lectura del m�ximo �ndice para la suma
	do {
		cout << "Indice (debe ser >=1) del �ltimo t�rmino a sumar: ";
		cin >> tope;
	} while (tope < 1);


	// C�lculos y resultados de la sumatoria hasta "tope"

	suma_total_ver1 = SumaHasta_ver1 (termino_primero, razon, tope);
	suma_total_ver2 = SumaHasta_ver2 (termino_primero, razon, tope);
	suma_total_ver3 = SumaHasta_ver3 (termino_primero, razon, tope);

	cout << "\nVersi�n 1: Suma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_total_ver1 << "\n\n";
	cout << "\nVersi�n 2: Suma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_total_ver2 << "\n\n";
	cout << "\nVersi�n 3: Suma hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << suma_total_ver3 << "\n\n";
		
	// C�lculo y resultado de la sumatoria hasta "infinito"

	if (abs(razon) < 1) {
		suma_total_inf = SumaHastaInfinito (termino_primero, razon);
		cout << "\nSuma hasta infinito = " 
			 << setw(10) << setprecision (2) << suma_total_inf << "\n\n";
	}
	else 
		cout << "\n No puede calcularse suma hasta infinito " 
			 << "porque |" << setprecision (2) << razon << "| >= 1";
		
	cout << "\n\n";

	// Lectura del m�ximo �ndice para el producto
	do {
		cout << "Indice (debe ser >=1) del �ltimo t�rmino a multiplicar: ";
		cin >> tope;
	} while (tope < 1);

	// C�lculos y resultados del producto hasta "tope"

	producto_total_ver1 = MultiplicaHasta_ver1 (termino_primero, razon, tope);
	producto_total_ver2 = MultiplicaHasta_ver2 (termino_primero, razon, tope);

	cout << "\nVersi�n 1: Producto hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << producto_total_ver1 << "\n\n";
	cout << "\nVersi�n 2: Producto hasta " << setw(3) << tope 
		 << " = " << setw(10) << setprecision (2) << producto_total_ver2 << "\n\n";

	system("pause");
}