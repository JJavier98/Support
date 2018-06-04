/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Escribir un programa que calcule el menor valor de n que hace que la 
	aproximación dada por an difiera en menos de δ del número φ, sabiendo 
	que n ≥ 1. La entrada del programa será el valor de δ y la salida el 
	valor de n. Por ejemplo, para un valor de δ = 0,1 el valor de salida 
	es n = 3

*/
#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>

using namespace std; 

//Función para calcular el numero aureo  
double CalcularNumeroAureo( double valor ) {

	//Supongo que la fórmula será así
	double n = ((1.0 + sqrt(5.0)) / 2.0) * valor;

	return n;

}

int main(){  // Programa Principal 

	// Declara variables para guardar los datos
	double valor, aureo;   
      
	//Obtenemos los datos
	do {
		cout << "Introduzca un número positivo: ";
			cin >> valor;  
	} while (valor < 0);
	
	//Hacemos los cálculos
	aureo = CalcularNumeroAureo(valor);
      
	//Pintamos los valores en la consola
    cout << "El numero aureo de " << valor << " es " << aureo << "\n\n";  
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}