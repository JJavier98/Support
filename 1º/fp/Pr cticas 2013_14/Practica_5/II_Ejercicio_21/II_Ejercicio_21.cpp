/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa para calcular la suma de los 100 primeros términos de una sucesión.

	Devuelve:  Los terminos de la sucesion.
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double total = 0;               // Declara variables para guardar los datos

	//Hacemos los cálculos
	for (int i = 1; i < 100; i++){

	

		total = total + ((1 * i * (i * 2)-1) / (2 * i));

		//Pintamos los valores en la consola
		cout << "Para el numero " << i << " tiene el valor: " << total << "\n";

	}


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
