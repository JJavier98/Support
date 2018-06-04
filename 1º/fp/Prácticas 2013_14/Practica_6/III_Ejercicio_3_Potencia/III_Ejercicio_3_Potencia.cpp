/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que utiliza funciones para calcular el factorial
	y la potencia de un numero
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

//Funcion que calcula el factorial de un numero
int Factorial (int n){

	//Asignamos el valor por defecto a 1
	int resultado = 1;
	
	//Hacemos los calculos
	for (int i = 2; i <= n; i++)
		resultado *= i;

	//Devolvemos el valor
	return resultado;
}

//Funcion que calcula la potencia de un numero
int Potencia (int n, int elevado){

	//Asignamos el valor por defecto a 1
	int resultado = 1;
	
	//Hacemos los calculos
	for (int i = 1; i <= elevado; i++)
		resultado *= n;

	//Devolvemos el valor
	return resultado;
}

//Programa Principal
int main(){                    

	//Declaramos variables donde almacenar los datos
	int numero = 3;
	int elevado = 2;
	int potencia;
	int factorial;

	//Obtenemos los datos necesarios
	factorial = Factorial(numero);
	potencia = Potencia(numero,elevado);

	//Pintamos los valores en la consola
	cout << "Dado el numero " << numero << " da el factorial: " << factorial << 
		" y su potencia de " << elevado << " es " << potencia << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
