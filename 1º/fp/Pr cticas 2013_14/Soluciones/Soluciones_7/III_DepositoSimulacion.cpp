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
// EJERCICIO 14 
//
/*	
	La clase "DepositoSimulacion" se emplea para simular préstamos, 
	ofreciendo la funcionalidad descrita en los ejercicios 11 
	(reinvierte capital e interés un número de años) y 12 (reinvierte 
	capital e interés hasta obtener el doble de la cantidad inicial) 
	de la Relación de Problemas II. 
*/
/*********************************************************************/


#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////

class DepositoSimulacion
{
	/*
	Parece lógico permitir cambiar el capital y el interés una vez creado
	el objeto, para así poder hacer simulaciones con distintos valores.
	Además, lo lógico es cambiarlos independientemente, por lo que
	definiremos los métodos SetCapital() y SetInteres()
	*/

private:

   double capital;
   double interes;

public:

	/*****************************************************************/
	// Constructor con argumentos

	DepositoSimulacion (double capital_deposito, double interes_deposito)
	{
		SetCapital(capital_deposito);
		SetInteres(interes_deposito);
	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 
	
	double GetCapital()
	{
		return capital;
	}

	double GetInteres()
	{
		return interes;
	}

	/*****************************************************************/
	// Métodos de escritura (Set) de los datos individuales 

	void SetCapital(double capital_prestamo)
	{
		if (capital_prestamo > 0)
			capital = capital_prestamo;
		else
			capital = 0;
	}

	void SetInteres(double interes_prestamo){
		if ((0 < interes_prestamo) && (interes_prestamo < 100))
			interes = interes_prestamo;
		else
			interes = 0;
	}

	/*****************************************************************/
	// Calculo del capital obtenido por una inversión

	double TotalObtenidoDespues_de (int anios_totales)
	{
		double total;

		total = capital; 
      
		for(int anio = 1; anio <= anios_totales; anio++)
			total = total + (total * (interes/100.0));  
               
		return total;
	}

	/*****************************************************************/
	// Calculo del número de años que deben transcurrir hasta 
	// conseguir un capital dado
	
	int NumeroAniosHastaObtener (double cantidad_objetivo)
	{
		double total;
		int numero_anios;

		total = capital;
		numero_anios = 0;

		while (total < cantidad_objetivo){
			numero_anios = numero_anios+1;           
			total = total + (total * (interes/100.0));  
		}
      
		return numero_anios;
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
   
	double capital_deposito, interes_deposito, capital_a_obtener;
	int anios;

	cout << "Introduzca capital inicial --> ";
	cin >> capital_deposito;
	cout << "Introduzca interés (como un %) --> ";
	cin >> interes_deposito;   
	cout << "Número de años que mantendrá el depósito --> ";
	cin >> anios;

	// Construcción del objeto "deposito"
	DepositoSimulacion deposito(capital_deposito, interes_deposito);

	cout << "\n\nAl término de " << anios << " años, habrá obtenido "; 
	cout << deposito.TotalObtenidoDespues_de(anios) << " euros";   
  	cout << endl << endl << endl; 

	cout << "Cantidad objetivo --> ";
	cin >> capital_a_obtener;

	cout << "Para obtener " << capital_a_obtener << " euros, han de pasar ";
	cout << deposito.NumeroAniosHastaObtener(capital_a_obtener) << " años.";    
  	cout << endl << endl; 


	// Calcular cuánto tiempo debe pasar para doblar el capital inicial
	// Recordemos que el capital inicial no se ha cambiado desde la creación 
	// del objeto "deposito"

	double capital_doble = 2.0 * deposito.GetCapital(); 
	int anios_capital_doble = deposito.NumeroAniosHastaObtener(capital_doble);

	cout << "Para doblar el capital inicial han de pasar "
	     << anios_capital_doble << " años.\n"; 
	cout << "Pasados " << anios_capital_doble<< " años, obtendrá exactamente " 
	     << deposito.TotalObtenidoDespues_de(anios_capital_doble) <<endl<<endl;

	cout << "\n\n";
	system("pause");
}
