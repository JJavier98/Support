/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que, dado un número entero positivo, nos indique si el número es o no narcisista.

	Necesita: Un numero entero.

	Devuelve: Si el numero es narcisista.
*/
#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>   // Inclusión de las funciones matemáticas

using namespace std; 

int main(){                    // Programa Principal

	//Declaramos variables donde almacenar los datos
	int numero;

	//Obtenemos los datos necesarios
	cout << "Introduzca un numero: ";
	cin >> numero;

	//Hacemos los cálculos
	int numero_temporal;
	int suma = 0;
	int digito;
	int numero_digitos = 0;

	//Nos guardamos el numero actual en una variable temporal para hacerle cambios
	numero_temporal = numero;

	while(numero_temporal > 0)
	{
		//En la variable temporal vamos dividiendo entre 10, 
		//que al redondear nos quitará el número final
	   numero_temporal /= 10;

	   //Vamos almacenando en un contador el numero de digitos
	   numero_digitos++;
	}

	//Nos guardamos el numero actual en una variable temporal para hacerle cambios
	numero_temporal = numero;

	//Hacemos el bucle hasta dejar la variable temporal a 0
	while (numero_temporal > 0) {

		//Vamos extrayendo el resto de dividir el valor entre 10, ese sera el digito
	    digito = numero_temporal % 10;  

		//En la variable temporal vamos dividiendo entre 10, 
		//que al redondear nos quitará el número final
		numero_temporal /= 10;

		//Hacemos los calculos ya sobre el dígito (multiplicamos por 1.0 para que sea double)
		suma += pow(digito, numero_digitos * 1.0);
	}

	//Pintamos los valores en la consola
	if (suma == numero) {
		cout << "Es narcisista\n\n";
	}else {
		cout << "No es narcisista\n\n";
	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
