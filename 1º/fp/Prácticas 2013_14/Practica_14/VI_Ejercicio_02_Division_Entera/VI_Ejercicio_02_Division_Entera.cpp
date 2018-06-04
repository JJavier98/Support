/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Cread sendas funciones recursivas para:

	a) Calcular la división entera entre dos números enteros positivos.
	b) Calcular el resto de la división entera de dos números enteros positivos.

	Pasad como parámetros a cada función los dos enteros, y suponed que en la 
	llamada siempre pasarán números positivos (es la precondición de la función)

	En la definición de las funciones no pueden utilizarse los operadores de 
	división, multiplicación ni módulo.

	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std; 

/*************************************************************/
//Esta función calcula una division entera sin hacer uso de los operadores
//de multiplicacion, division o resto utilizando la recursividad
int CalcularDivisionEntera(int dividendo, int divisor) {    

	//Le restamos el divisor al dividendo
	int cociente = dividendo - divisor;

	//Si el resultado es menor, es que ya no se puede dividir mas
	if (cociente < divisor) {

		//Devolvemos 1
		return 1;
	
	} else {
	
		//Si no, le sumamos uno y bajamos la cifra siguente, como en el colegio!
		return 1 + CalcularDivisionEntera(cociente, divisor);
	
	}

}

/*************************************************************/
//Esta función calcula el resto de una division entera sin hacer 
//uso de los operadores de multiplicacion, division o resto 
//utilizando la recursividad
int CalcularRestoDivisionEntera(int dividendo, int divisor) {    

	//Le restamos el divisor al dividendo
	int cociente = dividendo - divisor;

	//Si el resultado es menor, es que ya no se puede dividir mas
	if (cociente < divisor) {

		//devolvemos el resto
		return cociente;
	
	} else {
	
		//Si no, seguimos restando
		return CalcularRestoDivisionEntera(cociente, divisor);
	
	}

}

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	int dividendo, divisor, resultado;

	//Solicita datos al usuario
	cout << "Introduzca un número entero positivo (dividendo): " << endl;
	cin >> dividendo;
	cout << "Introduzca un número entero positivo (divisor): " << endl;
	cin >> divisor;


	//Calculamos la division
	resultado = CalcularDivisionEntera(dividendo, divisor);

	//Pintamos el resultado en la consola
	cout << "El resultado de la division es: " << resultado << endl;

	//Calculamos el resto division
	resultado = CalcularRestoDivisionEntera(dividendo, divisor);

	//Pintamos el resultado en la consola
	cout << "El resto de la division es: " << resultado << endl;


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}