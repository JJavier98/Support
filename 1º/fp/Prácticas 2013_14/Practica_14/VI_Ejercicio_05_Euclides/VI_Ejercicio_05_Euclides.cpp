/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Definid una función recursiva con prototipo

     int MCD(int un_entero, int otro_entero)
	
	para que calcule el máximo común divisor entre dos enteros, aplicando el 
	algoritmo de Euclides, que nos dice lo siguiente:

     MCD (a, 0) = a
     MCD (a, b) = MCD (b, a % b)
	
	dónde a % b es el resto de la división entera entre a y b. Implementad el 
	algoritmo suponiendo que a es mayor que b. A continuación, comprobad que 
	también funciona en el caso contrario. ¿Por qué?

	RESPUESTA: Porque el orden de los factores es indiferente

	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std; 

/*************************************************************/
//Esta función calcula el máximo común divisor entre dos enteros, 
//aplicando el algoritmo de Euclides
int MCD(int un_entero, int otro_entero) {

	//Esta funcion simplemente hace uso del algoritmo de euclides
	//
    // MCD (a, 0) = a
    // MCD (a, b) = MCD (b, a % b)

	//Por ejemplo, para 42 y 16, el MCD es 14

	if (otro_entero == 0) {
	
		return un_entero;

	} else {
		
		return MCD(otro_entero, un_entero % otro_entero);
	
	}

}

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	int n1, n2, resultado;

	//Solicita datos al usuario
	cout << "Introduzca un numero (n1): ";
	cin >> n1;
	cout << "Introduzca un numero (n2): "; 
	cin >> n2;


	//Hacemos los calculos
	resultado = MCD(n1, n2);

	//Pintamos el resultado en la consola
	cout << "El máximo comun divisor es: " << resultado << endl;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}