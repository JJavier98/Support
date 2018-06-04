/******************************************************************************
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Cread una clase llamada ParejaEnteros que represente una pareja de enteros 
	cualesquiera. Añadid un constructor y los métodos que se estimen oportunos 
	para asignarles valores a los enteros y para obtener el valor que éstos 
	tengan.
	Las operaciones que queremos realizar sobre una pareja son calcular el 
	mayor, el menor, comprobar si se dividen, ver quien es el dividendo y quien 
	el divisor, intercambiarlos y calcular el máximo común divisor. Cread un 
	main que llame a dichos métodos, para comprobar que están bien 
	implementados.
	
	
	NOTA: No le agregaría la funcion factorial porque no se especifica a que 
	numero aplicarla, aunque se podria agregar para ambos

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class ParejaEnteros {

private: 

	//Atributos
	int numero1;
	int numero2;

public:
/*****************************************************************************/
	//Constructor
	ParejaEnteros(int pNumero1, int pNumero2) {
		
		//Asignamos los atributos
		numero1 = pNumero1;
		numero2 = pNumero2;

	}
/*****************************************************************************/
	//Métodos
	int Mayor() {
		//Devuelve el mayor de los dos numero
		if (numero1 > numero2) {
			return numero1;
		}else{
			return numero2;
		}
	}
/*****************************************************************************/
	int Menor() {
		//Devuelve el menor de los dos numero
		if (numero1 < numero2) {
			return numero1;
		}else{
			return numero2;
		}
	}
	bool Dividen() {

		//Segun el ejercicio 3 de la relación, si el resto es 0 es que dividen
		return Dividendo() % Divisor() == 0;

	}
/*****************************************************************************/
	int Dividendo() {
		//El mayor será el dividendo
		return Mayor();
	}
/*****************************************************************************/
	int Divisor() {
		//El menor será el divisor
		return Menor();
	}
/*****************************************************************************/
	void Intercambiar() {
	
		//Intercambiamos el valor de las variables usando una variable temporal
		int tmp = numero1;
		numero1 = numero2;
		numero2 = tmp;
		
	}
/*****************************************************************************/
	//Funcion que calcula el maximo comun divisor
	int MCD() {
	
		int menor = Menor();
		int mayor = Mayor();

		while(mayor != menor){
			if(mayor > menor)
				mayor -= menor;
			else
				menor -= mayor;
		}
		return mayor;

	}


};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores
	int numero1;				
	int numero2;

	//Obtenemos los datos necesarios
	cout << "Introduzca un numero (1): ";
	cin >> numero1;
	cout << "Introduzca un numero (2): ";
	cin >> numero2;

	//Creamos un objeto de la clase ParejaEnteros
	ParejaEnteros pareja_enteros(numero1,numero2);

	//Pintamos los valores en la consola
	cout << "El mayor es: " << pareja_enteros.Mayor() << "\n";
	cout << "El menor es: " << pareja_enteros.Menor() << "\n";
	cout << "¿Se dividen? 0=No 1=Si: " << pareja_enteros.Dividen() << "\n";
	cout << "El Divisor es: " << pareja_enteros.Divisor() << "\n";
	cout << "El Dividendo es: " << pareja_enteros.Dividendo() << "\n";
	cout << "El MCD es: " << pareja_enteros.MCD() << "\n";
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}