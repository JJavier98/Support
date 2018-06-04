/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Construir una función recursiva que muestre en la salida estándar los m 
	mayores números pares que sean menores o iguales que un número n. 
	El prototipo sería el siguiente:
       void MayoresPares(int m, int n);
	Por ejemplo:
	• MayoresPares(3,6): imprimirá en pantalla 6, 4, 2
	• MayoresPares(4,3) : imprimirá en pantalla 2, 0, -2, -4 
	• MayoresPares(0,8) : no imprimirá nada en pantalla
	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <string> //Inclusión de las funciones de cadenas

using namespace std; 

/*************************************************************/
//Este método muestra en la salida estándar los m mayores números 
//pares que sean menores o iguales que un número n
void MayoresPares(int m, int n) {

	//Solo debe hacerse mientras m sea mayor que 0
	if (m > 0) {
	
		//Comprobamos si es par
		if (n % 2 == 0) {
		
			//Pintamos el numero en la salida estandar
			cout << n << ",";

			//Decrementamos m (pares)
			m--;
		}
	
		//Decrementamos el número en 1
		n--;
		
		//Volvemos a llamar a la funcion con los nuevos valores
		MayoresPares(m,n);

	} else {

		//En la última iteración pintamos un salto de línea
		cout << endl;
	
	}


	
}

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Pintamos el resultado en la consola
	MayoresPares(3,6); // imprimirá en pantalla 6, 4, 2
	MayoresPares(4,3); // imprimirá en pantalla 2, 0, -2, -4 
	MayoresPares(0,8); // no imprimirá nada en pantalla

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}