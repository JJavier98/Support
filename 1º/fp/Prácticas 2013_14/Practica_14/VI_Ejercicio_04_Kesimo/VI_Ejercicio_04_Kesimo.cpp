/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Definir una función recursiva a la que se le pasen dos valores enteros n y 
	k y devuelva como resultado el valor k-ésimo comenzando por la derecha del 
	número n. 
	Por ejemplo para n = 427 y k = 3 el resultado sería 4.

	Si k es mayor que el número de dígitos de n la función devolverá el valor 0. 
	Por ejemplo, para n = 23 y k = 5 el resultado es 0.

	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std; 

/*************************************************************/
//Esta función calcula el valor k-esimo de los valores indicados
//usando recursividad
int CalcularKesimo(int n, int k) {    



	if (n == 0)  {
		//Cuando n llegue a 0, es que k es superior al numero de digitos
        return 0;
    } else if (k == 1 && n > 0) {

		//Cuando k valga 1 hemos llegado al punto clave
		return n;

	} else {

		//En n vamos poniendo lo que nos quede de la izquierda (la parte entera de la division)
        n = n / 10;
		//Le restamos -1 a k
		k = k - 1;

		//Volvemos a llamar a la función para el siguiente dígito
        return CalcularKesimo(n, k);
    }

}

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	int n, k, resultado;

	//Solicita datos al usuario
	cout << "Introduzca el numero n: ";
	cin >> n;
	cout << "Introduzca el numero k: "; 
	cin >> k;


	//Hacemos los calculos
	resultado = CalcularKesimo(n, k);

	//Pintamos el resultado en la consola
	cout << "El resultado k-esimo es: " << resultado << endl;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}