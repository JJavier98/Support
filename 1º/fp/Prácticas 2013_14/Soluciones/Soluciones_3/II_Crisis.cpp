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
// EJERCICIO 6
/* 
	Medidas contra la crisis.

   * Bajar un 3% la retenci�n fiscal a los aut�nomos
   * Para las rentas de trabajo:
      - Se sube un 1% la retenci�n fiscal a todos los pensionistas.
      - Al resto de trabajadores se le sube un 2% la retenci�n fiscal. 
		Una vez hecha esta subida lineal del 2 %, se le aplica 
		(sobre el resultado anterior) las siguientes subidas adicionales, 
		dependiendo de su estado civil y niveles de ingresos:
         1) Subir un 6% la retenci�n fiscal a las rentas de trabajo 
			inferiores a 20.000 euros
         2) Subir un 8% la retenci�n fiscal a los casados con rentas 
			de trabajo superiores a 20.000 euros
         3) Subir un 10% la retenci�n fiscal a los solteros con 
			rentas de trabajo superiores a 20.000 euros

	C�mputo de porcentajes de incremento (Matem�ticas de tercero de la ESO).

		Supongamos un producto cuyo precio es P.
		1)	Un incremento del 3%, por ejemplo, se traduce en que el precio 
			final del producto ser� P * (1 + 0.03) = 1.03 * P
		2)	Una rebaja del 3%, por ejemplo, se traduce en que el precio final 
			del producto ser� P * (1 - 0.03) = 0.97 * P 
		3)	La aplicaci�n sucesiva de incrementos supone ir multiplicando 
			sucesivamente los incrementos porcentuales.
		P.e. Si subimos un 3% y al resultado le aplicamos otra subida del 
		5%, el precio final es P * 1.03 * 1.05
*/
/*********************************************************************/

#include <iostream>
#include <iomanip> // Recursos para dar formato a la presentaci�n de datos 
using namespace std;

int main()
{
	const double PORCENTAJE_INCR_PENSIONISTA = 1.01;
	const double PORCENTAJE_INCR_AUTONOMO = 0.97;    
	const double PORCENTAJE_INCR_SALARIO_BAJO = 1.06;
	const double PORCENTAJE_INCR_SALARIO_NORMAL_SOLTERO = 1.1;
	const double PORCENTAJE_INCR_SALARIO_NORMAL_CASADO = 1.08;
	const double PORCENTAJE_INCR_LINEAL = 1.02;

	double	renta_bruta, renta_neta, 
			retencion_inicial, retencion_final, 
			porcentaje_modificacion;

	bool es_autonomo, es_soltero, es_pensionista;	


	// En este ejercicio no se pide realizar ninguna lectura de datos, 
	// sino que despues de declarar las variables necesarias 
	// les asignaremos los valores directamente dentro del c�digo
	
	es_autonomo = false;
	retencion_inicial = 23.2;
	renta_bruta = 25000;
	es_soltero = true;
	es_pensionista = false;


	if (es_autonomo)   
		porcentaje_modificacion = PORCENTAJE_INCR_AUTONOMO;   

	else if (es_pensionista)
		porcentaje_modificacion = PORCENTAJE_INCR_PENSIONISTA;

	else { 

      porcentaje_modificacion = PORCENTAJE_INCR_LINEAL;

      if (renta_bruta < 20000)
         porcentaje_modificacion = porcentaje_modificacion * 
								   PORCENTAJE_INCR_SALARIO_BAJO;
      else if (es_soltero)
         porcentaje_modificacion = porcentaje_modificacion * 
								   PORCENTAJE_INCR_SALARIO_NORMAL_SOLTERO;
      else  
         porcentaje_modificacion = porcentaje_modificacion * 
								   PORCENTAJE_INCR_SALARIO_NORMAL_CASADO;
   }

	retencion_final = porcentaje_modificacion * retencion_inicial;
	renta_neta = renta_bruta * (1 - retencion_final /100.0);

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << "Autonomo = ";
	if (es_autonomo) 
		cout << "SI\n";
	else  
		cout << "NO\n";

	cout << "Pensionista = ";
	if (es_pensionista) 
		cout << "SI\n";
	else  
		cout << "NO\n";

	cout << "Soltero = ";
	if (es_soltero) 
		cout << "SI\n";
	else  
		cout << "NO\n";

	cout << endl;

	cout << "Retenci�n inicial = " << setw(6) << setprecision(2) 
						           << retencion_inicial << endl;
	cout << "Retenci�n final =   " << setw(6) << setprecision(2) 
						           << retencion_final << endl;
	cout << "Renta bruta = " << setw(10) << setprecision(2) 
		                     << renta_bruta << endl;
	cout << "Renta final = " << setw(10) << setprecision(2) 
						     << renta_neta;
	cout << "\n\n";

	system("pause");
}

