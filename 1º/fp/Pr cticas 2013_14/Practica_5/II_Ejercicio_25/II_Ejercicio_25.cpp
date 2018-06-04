/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que pinta un cuadrado en pantalla.

	Devuelve: Un cuadrado numerico.
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal

	//Hacemos los cálculos

	for (int i = 0; i < 6; i++){

		//Anidamos otro for donde el iterador comenzara en i+1
		//y terminará en i + 7
		for (int h = i + 1; h < (i + 7); h++) {

			/*	
				NOTA: Lo correcto seria no escribir aqui el resultado, si no
				almacenarlo en una variable temporal stringstream y luego pintarla 
			*/
		
			//Pintamos los valores en la consola
			cout << h << " ";

		}

		//Pintamos un salto de linea
		cout << "\n";

	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	//system("pause");
}
