/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que calcula si un numero es feliz.

	Necesita: n y k.

	Devuelve: Si el numero es feliz.
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal

	//Declaramos variables donde almacenar los datos
	int n, k;

	//Obtenemos los datos necesarios
	cout << "Introduzca un numero (n): ";
	cin >> n;
	cout << "Introduzca un grado (k): ";
	cin >> k;

	//Hacemos los cálculos

	//Nos guardamos el numero actual en una variable temporal para hacerle cambios
	int numero_temporal = n;

	for (int i = 1; i <= k; i++) {

		//Si el numero temporal es 1 es que el numero es feliz en menos iteracciones
		if (numero_temporal > 1) {

			int suma = 0;
			int digito;

			//Hacemos el bucle hasta dejar la variable temporal a 0
			while (numero_temporal > 0) {

				//Vamos extrayendo el resto de dividir el valor entre 10, ese sera el digito
				digito = numero_temporal % 10;  

				//En la variable temporal vamos dividiendo entre 10, 
				//que al redondear nos quitará el número final
				numero_temporal /= 10;

				//Hacemos los calculos ya sobre el dígito 
				suma += digito * digito;
			}

			//Asignamos el resultado del calculo de los digitos como nuevo número temporal
			numero_temporal = suma;

		}

	} 

	//Pintamos los valores en la consola
	if (numero_temporal == 1) {
		cout << "Es feliz\n\n";
	}else {
		cout << "No es feliz\n\n";
	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
