/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2012-2013
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
// EJERCICIO 9
/*	
   Programa que calcula d�as, horas, minutos y segundos en el rango correcto, 
   dados un n�mero de horas, minutos y segundos arbitrarios. 
   
   Entradas: horas, minutos y segundos
   Salidas:  dias (0-...), horas (0-23), minutos (0-59) y segundos (0-59)  
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int segundos, minutos, horas, dias;
	int segundos_enteros, minutos_enteros, horas_enteras, dias_enteros;  

	cout << "\nIntroduzca segundos --> ";
	cin >> segundos;
	cout << "\nIntroduzca minutos --> ";
	cin >> minutos;
	cout << "\nIntroduzca horas --> ";
	cin >> horas;
           
	/* 
	La siguiente soluci�n repite muchos c�mputos.
	Repetir c�digo tiene los siguientes problemas:
	1. Es ineficiente: Se pierde tiempo en evaluar expresiones repetidas
	2. Mucho peor: Es propenso a errores ya que hay que teclear varias veces
	   una misma expresi�n y debe ser igual siempre
	3. Es dif�cil de modificar: Cada cambio habr� que hacerlo
	   en cada una de las expresiones repetidas.
	
	segundos_enteros =     segundos % 60; 
	minutos_enteros	 =   ((segundos / 60) + minutos) % 60;
	horas_enteras	 = ((((segundos / 60) + minutos) / 60) + horas ) % 24;
	dias_enteros	 = ((((segundos / 60) + minutos) / 60) + horas ) / 24;
	*/

	/* 
	El siguiente c�digo no repite c�mputos.
	En cualquier caso, estamos modificando las variables originales
	segundos, minutos, horas y no es recomendable.
	
	segundos_enteros  =  segundos % 60;

	minutos			  = (segundos / 60) + minutos;
	minutos_enteros   =  minutos % 60;
   
	horas			  = (minutos / 60) + horas;
	horas_enteras     =  horas % 24;
   
	dias			  =  horas / 24;

	*/

	/*
	El siguiente algoritmo no repite c�digo, y no modifica las variables
	originales. Hemos usado tres variables adicionales con los totales
	de los minutos, horas, etc. 
	*/
	
	int minutos_totales, horas_totales, dias_totales;

	segundos_enteros =  segundos % 60;
	minutos_totales  = (segundos / 60) + minutos;
	horas_totales    = (minutos_totales / 60) + horas;
	dias_totales     = (horas_totales / 24);  // + dias en su caso

	minutos_enteros   = minutos_totales % 60;
	horas_enteras     = horas_totales % 24;   
	dias_enteros      = dias_totales; // dias_totales%365 si consideramos a�os
		
	cout << "\nD�as: " << dias_enteros;
	cout << "\nHoras: " << horas_enteras;   
	cout << "\nMinutos: " << minutos_enteros;
	cout << "\nSegundos: " << segundos_enteros;
	cout << "\n\n";

	system("pause");

	/*
	***********************************************************************************
	***********************************************************************************
	M�ximas en programaci�n:

	- No seremos r�canos en el uso de variables intermedias
	- No debemos modificar los valores de las variables de entrada, salvo que se 
	   diga expresamente

	***********************************************************************************
	***********************************************************************************
	*/


	/*
	Por �ltimo, observad que las variables totales podr�an sustituirse
	por las propias variables enteras, ya que su valor se modifica al principio,
	se usa para calcular las divisiones enteras y no se vuelve a usar hasta 
	asignarles el valor definitivo.
	Por tanto, el anterior c�digo podr�a quedar como sigue:

	segundos_enteros  = segundos%60;
	minutos_enteros = segundos/60 + minutos;
	horas_enteras   = minutos_enteros/60 + horas;
	dias_enteros    = horas_enteras/24;  // + dias en su caso

	minutos_enteros   = minutos_enteros % 60;
	horas_enteras     = horas_enteras % 24;   

	En cualquier caso, puede que sea m�s dif�cil de entender, por lo que
	ser�a recomendable seguir usando las variables totales
	*/


}
