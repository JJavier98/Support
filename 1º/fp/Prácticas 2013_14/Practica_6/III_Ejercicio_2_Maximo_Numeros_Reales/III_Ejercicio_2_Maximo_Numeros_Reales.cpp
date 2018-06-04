/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que calcula el máximo de tres numeros usando una función
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

// Funcion que devuelve el máximo de los 3 valores pasados
double Maximo(double primero, double segundo, double tercero) {

	//Asignamos el primer valor al resultado
	double resultado = primero;

	//Si el segundo es mayor que el resultado, lo asignamos al resultado
	if (segundo > resultado) 
		 resultado = segundo;

	//Si el tercero es mayor que el resultado, lo asignamos al resultado
	if (tercero > resultado)
		resultado = tercero;

	//Devolvemos el resultado
	return resultado;
}

// Programa Principal
int main(){                    

	//Declaramos variables donde almacenar los datos
	double primero = 578.664;
	double segundo = 8.6;
	double tercero = 55.76;
	double maximo;

	//Obtenemos los datos necesarios
	maximo = Maximo(primero,segundo,tercero);

	//Pintamos los valores en la consola
	cout << "El máximo de " << primero << ", " << segundo << 
		" y " << tercero << " es: " << maximo << "\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
