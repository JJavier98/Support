/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Se pide crear la clase Palabra que permita almacenar un conjunto de 
	caracteres que representarán una palabra. Definid un método EsIgual al que 
	se le pase como parámetro otra palabra y determine si son iguales atendiendo 
	al siguiente criterio: La primera letra de ambas palabras es igual, la 
	última letra de ambas palabras también es igual y el resto de las letras son 
	las mismas pero no están necesariamente en las mismas posiciones.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <string> //Libreria para cadenas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase Palabra
class Palabra {

private:
	//Definicion de atributos
    string palabra_privada;

public:
	//Constructor
	Palabra(string palabra) {

		palabra_privada = palabra;
	
	}

	/*********************************************************/
	//Esta función devuelve el tamaño de la palabra
	int Tamanio() {
	
		return palabra_privada.size();
	
	}

	/*********************************************************/
	//Esta función devuelve un elemento de la palabra
	char Elemento(int indice) {
	
		return palabra_privada.at(indice);
	
	}

	/*********************************************************/
	//Esta función comprueba si el vector pasado es igual
	bool EsIgual(Palabra palabra) {

		bool es_igual = false;

		//Comprobamos si las dos palabras tienen el mismo tamaño
		if (Tamanio() == palabra.Tamanio()) {
		
			//Comprobamos si la dos palabras empiezan por la misma letra
			if (Elemento(0) == palabra.Elemento(0)) {
		
				//Obtenemos la posicion de la ultima letra
				int posicion_ultima = Tamanio() -1;

				//Comprobamos si la dos palabras terminan por la misma letra
				if (palabra.Elemento(posicion_ultima) == Elemento(posicion_ultima)) {
				
					//Nos guardamos el numero de letras que debemos de buscar
					//para ir decrementandolas luego
					int contador_letras_a_buscar = posicion_ultima - 1;

					//Recorremos las letras desde la 2ª a la penultima
					for (int i = 1; i < posicion_ultima; i++) {

						//Establecemos una bandera por si la encontramos
						bool letra_encontrada = false;

						//Recorremos las letras de la palabra pasada
						for (int h = 1; !letra_encontrada && h < posicion_ultima; h++) {

							//Si coincide establecemos la bandera y decrementamos el contador
							if (Elemento(i) == palabra.Elemento(h)) {
							
								letra_encontrada = true;
								contador_letras_a_buscar--;
							
							}

						}

					}

					//Si el contador ha llegado a 0 es porque ha encontrado todo
					//NOTA: Esto puede dar lugar a errores, puesto que si hubieran letras
					//repetidas podrian haber errores, se debería de optimizar
					if (contador_letras_a_buscar == 0) {

						es_igual = true;

					}

				
				}
	
			}
		
		}

		//Devolvemos el resultado
		return es_igual;
	}

	/*********************************************************/
	//Este método pinta la palabra en la salida estándar
	void PintarPalabra() {
	
		cout << palabra_privada;
	}

};

/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos   
	Palabra palabra1("mundo");
	Palabra palabra2("mdnuo");
	Palabra palabra3("munda");
	
	//Pintamos los valores en la consola  sus elementos
	palabra1.PintarPalabra();
	cout << "\n----\n";
	palabra2.PintarPalabra();
	cout << "\n¿Es igual (0=No|1=Si)" <<  palabra1.EsIgual(palabra2) << "\n";
	palabra3.PintarPalabra();
	cout << "\n¿Es igual (0=No|1=Si)" <<  palabra1.EsIgual(palabra3) << "\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}