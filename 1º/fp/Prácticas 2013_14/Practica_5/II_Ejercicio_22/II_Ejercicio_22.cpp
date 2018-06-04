/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que lee una secuencia de números naturales 
	terminada con un número negativo y la codifique mediante el método RLE.

	Necesita: Un fichero de entrada con numeros terminada en -1.

	Devuelve:  Esa serie de numeros codificada con RLE.
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int entrada;               // Declara variables para guardar los datos
	int contador_iguales = 0;	
	int entrada_anterior = -1; //Le asignamos -1 para controlar la primera vez que entra

	do {	

		//Obtenemos los datos necesarios
		cin >> entrada;

		//Hacemos los cálculos
		if ((entrada_anterior == -1) || (entrada == entrada_anterior)) {

			//Aquí entrará siempre la primera vez (-1) y cuando entrada sea igual que la anterior

			//Incrementamos el contador de iguales
			contador_iguales++;
		}else {

			//Si ya no es igual pintaremos el valor y resetearemos el contador

			/*	
				NOTA: Lo correcto seria no escribir aqui el resultado, si no
				almacenarlo en una variable temporal y luego pintarla 
			*/

			//Pintamos los valores en la consola
			cout << contador_iguales << entrada_anterior;
			
			//Reseteamos el contador de iguales
			contador_iguales = 1;
		}

		//La entrada actual pasará a ser la anterior y vuelta a empezar
		entrada_anterior = entrada;

	} while (entrada != -1); //Comprobamos que el número sea distindo de -1

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
