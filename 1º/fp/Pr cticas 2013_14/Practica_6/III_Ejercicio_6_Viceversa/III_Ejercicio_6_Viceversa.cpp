/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Programa que convierte un caracter a mayuscula y
	viceversa utilizando funciones.
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

//Nos definimos la diferencia en una constante global
const int AMPLITUD = 'a' - 'A';

//Funcion que comprueba si una letra es minuscula
bool EsMinuscula (char una_letra){

	bool resultado = true;

	//Comprobamos si esta fuera del rango a-z
	if ((una_letra < 'a') || (una_letra > 'z')) {
		resultado = false;
	}

	//Devolvemos el valor
	return resultado;
}

//Funcion que comprueba si una letra es minuscula
bool EsMayuscula (char una_letra){

	bool resultado = true;

	//Comprobamos si esta fuera del rango a-z
	if ((una_letra < 'A') || (una_letra > 'Z')) {
		resultado = false;
	}

	//Devolvemos el valor
	return resultado;
}


//Funcion que convierte una letra a mayúscula
char Convierte_a_Mayuscula (char caracter){

	//Comprobamos si es minúscula
	if (EsMinuscula(caracter))
		caracter -= AMPLITUD; 

	//Devolvemos el valor
	return caracter;
}

//Funcion que convierte una letra a minuscula o minuscula
char Transforma(char caracter){

	char resultado;

	//Hacemos los calculos
	if (EsMinuscula(caracter)) {
		//En este caso llamamos a la funcion previa, ya que ya está hecha
		//y así no hay codigo duplicado
		resultado = Convierte_a_Mayuscula(caracter);
	}else if (EsMayuscula(caracter)) {
		//Como aqui no se pide funcion hacemos los calculos aqui
		//quizá estaría mejor si se creara una funcion Convierte_a_Minuscula
		resultado = caracter + AMPLITUD;
	} else {
		resultado = caracter;
	}

	//Devolvemos el valor
	return resultado;
}

//Programa Principal
int main(){                    

	//Declaramos variables donde almacenar los datos
	char caracter = 'B';

	//Obtenemos los datos necesarios
	caracter = Transforma(caracter);

	//Pintamos los valores en la consola
	cout << "El caracter convertido es " << caracter << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
