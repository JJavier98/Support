/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	La criba de Eratóstenes (Cirene, 276 a. C. Alejandría, 194 a. C.) es un 
	algoritmo que permite hallar todos los números primos menores que un número 
	natural dado n.

	El programa debe definir una clase llamada Eratostenes que tendrá tres 
	métodos: 
		• void CalculaHasta(int n) para que calcule los primos menores que n.
		• int TotalCalculados() que devuelva cuántos primos hay actualmente
		almacenados.
		• int Elemento(int indice) para que devuelva el indice-ésimo primo.

******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include <vector>	//Inclusión de las funciones para manejo de vectores

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Eratostenes {
private:
    vector <int> vector_primos;
public:

	/*********************************************************/
	//Esta método calcula los numeros primos menores que n usando el método manual
	//El procedimiento “manual” consiste en escribir todos los números naturales 
	//comprendidos entre 2 y n y tachar los números que no son primos de la 
	//siguiente manera: el primero (el 2) se declara primo y se tachan todos sus
	//múltiplos; se busca el siguiente número entero que no ha sido tachado, se 
	//declara primo y se procede a tachar todos sus múltiplos, y así sucesivamente. 
	//El proceso para cuando el cuadrado del número entero es mayor o igual que el valor de n.
	void CalculaHasta(int n) {

		//Creamos un vector de boolean de tamaño n
		//con todos sus elementos inicializados a false
		vector <bool> vector_tachados;
		for (int i = 0; i <= n; i++) {
			vector_tachados.push_back(false);
		}

		//Recorremos los numeros desde el 2 en adelante
		for (int i = 2;  (i <= n); i ++) {

			if (!vector_tachados.at(i)) { //No ha sido tachado
				
				//Lo agregamos a la lista de numeros primos
				vector_primos.push_back(i); 

				//Recorremos los siguientes numeros al actual
				//Pero paramos cuando el cuadrado del numero sea mayor o igual
				//a n para optimizar (esto es un while con forma de for)
				for (int j = i+1; ((i * i) < n) && (j <= n); j++) {
				
					//Si alguno de los numeros sigueintes es divisor del actual...
					if (j % i == 0) {
					
						//...lo tachamos
						vector_tachados.at(j) = true;

					}
				
				}
			
			}
		
		}

	} 
	/*********************************************************/
	//Esta función devuelve cuántos primos hay actualmente almacenados.
	int TotalCalculados() {
		//Devolvemos el tamaño de vector_privado
		return vector_primos.size();
	}
	/*********************************************************/
	//Esta función devuelve devuelva el indice enésimo primo..
	int Elemento(int indice) {
		//Devolvemos el valor en el indice, si el indice estuviera fuera
		//del rango se dispararia una excepción
		return vector_primos.at(indice);
	} 

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	Eratostenes primos;
	int n = 100; 
	int tope;
	
	//Hacemos los calculos
	primos.CalculaHasta(n);
	tope = primos.TotalCalculados();

	//Pintamos los valores en la consola
	cout << "Numeros primos desde el 1 al " << n << ": (" << tope << ")\n";
	for (int i=0; i<tope; i++)
		cout << primos.Elemento(i) << " ";

	cout << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}