/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------

	El resultado de multiplicar 37 y 12 sería la suma de los multiplicadores 
	correspondien- tes a los multiplicandos impares (en negrita), es decir 
	12+48+384=444
	Cread un programa que lea dos enteros y calcule su producto con este 
	algoritmo.

*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

//Función para calcular si el número suministrado es perfecto o no  
int MultiplicarRusamente(int numero1, int numero2){

	//Declaramos variables
	int resultado=0;

	while (numero1 != 0) {  

		if (numero1 % 2 != 0)   
			resultado += numero2; 

		numero1 = numero1 / 2;  //El primer numero lo dividimos entre 2
		numero2 = numero2 * 2;  //El segundo numero lo multiplicamos por 2
	}

	return resultado;   

}  

int main(){                    // Programa Principal 

	// Declara variables para guardar los datos
	int numero1, numero2, resultado;   
      
	//Obtenemos los datos
	do {
		cout << "Introduzca un número positivo (1): ";
		cin >> numero1;  
	} while (numero1 < 0);

	do {
		cout << "Introduzca un número positivo (2): ";
		cin >> numero2;  
	} while (numero2 < 0);


	//Hacemos los cálculos
	resultado = MultiplicarRusamente(numero1, numero2);
      
	//Pintamos los valores en la consola
    cout << "El resultado es " << resultado << "\n\n";  
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}