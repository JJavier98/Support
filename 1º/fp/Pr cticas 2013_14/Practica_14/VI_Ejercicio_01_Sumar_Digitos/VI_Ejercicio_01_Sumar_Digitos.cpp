/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Definir una función recursiva para sumar los dígitos de un entero positivo.
	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std; 

/*************************************************************/
//Esta función suma los dígitos de un número entero positivo
//utilizando la recursividad
int SumarDigitos(int numero, int suma) {    
    
	if (numero == 0)  {
		//Cuando llegue a 0, hemos terminado, podemos devolver la suma
        return suma;
    } else {
		//Si no, le vamos sumando el resto de dividir el numero entre diez (el digito de la derecha)
        suma = suma + (numero % 10); 
		
		//En numero vamos poniendo lo que nos quede de la izquierda (la parte entera de la division)
        numero = numero / 10;

		//Volvemos a llamar a la función para el siguiente dígito
        return SumarDigitos(numero, suma);
    }
}

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	int numero, resultado;

	//Solicita datos al usuario
	cout << "Introduzca un número entero positivo: " << endl;
	cin >> numero;


	//Hace los calculos, le hace falta el número, y como en suma se irá acumulando, y no hemos
	//visto las variables por referencia, le podemos pasar 0 sin problemas
	resultado = SumarDigitos(numero, 0);

	//Pintamos el resultado en la consola
	cout << "El resultado es: " << resultado << endl;


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}