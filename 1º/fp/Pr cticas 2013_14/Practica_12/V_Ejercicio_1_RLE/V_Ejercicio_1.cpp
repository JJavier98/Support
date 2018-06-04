/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Cread la clase RLE para codificar/descodificar una secuencia según indica 
	el ejercicio 22 de la Relación de Problemas II de Estructuras de Control. 
	Los métodos a implementar tendrán las siguientes cabeceras:

     MiVectorEnteros Codifica    (MiVectorEnteros
                                  secuencia_descodificada)
     MiVectorEnteros Descodifica (MiVectorEnteros
                                  secuencia_codificada)

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std; 
/*****************************************************************************/
//Definicion de la clase MiVectorEnteros
class MiVectorEnteros {

private:

	static const int TAMANIO = 50;
	int vector_privado[TAMANIO];
	int total_utilizados;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorEnteros() 
	{
		total_utilizados = 0;
	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 
	int TotalUtilizados() {
		return total_utilizados;
	}

	int Capacidad() {
		return TAMANIO;
	}

	/*****************************************************************/
	// Añade un elemento al vector
	// PRE: hay espacio para el nuevo elemento.
	// Si no lo hay, no hace nada.
	void Aniade(int nuevo) {
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.
	int Elemento(int indice) {
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Sustituye la componente con índice "indice_componente" por el 
	// valor nuevo.
	// PRE: la posición dada por "indice_componente" es correcta.
	// Si no es correcta, no hace nada.
	void Modifica (int indice_componente, int nuevo) {
		if ((indice_componente >= 0)  &&  (indice_componente < total_utilizados))

			vector_privado[indice_componente] = nuevo;
	}		

	/*****************************************************************/
	//Esta función comprueba si el objeto pasado como parámetro es igual
	//al propio objeto
	bool EsIgualA (MiVectorEnteros otro) {

		//Por defecto decimos que es igual
		bool es_igual = true;

		//Si el tamaño de los vectores difiere...
		if (otro.TotalUtilizados() != TotalUtilizados()) {
		
			//...los objetos no son iguales
			es_igual = false;

		} else { //Si son iguales
			
			//Recorremos sus elementos comparándolos (esto es un while con
			//forma de for, en el momeno que no sea igual (es_igual == false) 
			//se saldría
			for (int i = 0; es_igual && i < TotalUtilizados(); i++) {
			
				//Si los dos elementos difieren...
				if (Elemento(i) != otro.Elemento(i)) {
				
					//..los objetos no son iguales
					es_igual = false;
				}
			
			}
		
		}

		//Devolvemos el resultado de la comparación
		return es_igual;
	}		

	/*****************************************************************/

};
/*****************************************************************************/
//Definicion de la clase RLE
class RLE {

public:

	/*********************************************************/
	//Esta función codifica un objeto MiVectorEnteros usando la técnica RLE.
	MiVectorEnteros Codifica(MiVectorEnteros secuencia_descodificada) {

		//Declaracion de variables
		MiVectorEnteros secuencia_codificada;
		//Aqui vamos guardando el anterior, la primera vez ponemos -1
		int entero_anterior = -1; 

		//Recorremos el vector descodificado
		for (int i = 0; i < secuencia_descodificada.TotalUtilizados(); i++) {
		
			//Nos guardamos el entero actual (por comodidad)
			int entero_actual = secuencia_descodificada.Elemento(i);

			//Si el actual es igual que el anterior...
			if (entero_actual == entero_anterior) {

				//Obtenemos la posicion del contador de repeticiones y su valor
				int posicion_repeticiones = secuencia_codificada.TotalUtilizados() -2;
				int valor_repeticiones = secuencia_codificada.Elemento(posicion_repeticiones);
				
				//Incrementamos el numero de repeticiones
				secuencia_codificada.Modifica(posicion_repeticiones, valor_repeticiones+1);

			} else { //Si es distinto...
			
				//...agregamos 2 elementos al vector (numero de repeticiones y valor)
				secuencia_codificada.Aniade(1); //La primera repeticion es 1
				secuencia_codificada.Aniade(entero_actual);
			
			}

			//Nos guardamos el valor actual para la siguiente iteración
			entero_anterior = entero_actual;

		}

		//Devolvemos el vector codificado
		return secuencia_codificada;
	}
	/*********************************************************/
	//Esta función descodifica un objeto MiVectorEnteros usando la técnica RLE.
	MiVectorEnteros Descodifica(MiVectorEnteros secuencia_codificada) {

		//Declaracion de variables
		MiVectorEnteros secuencia_descodificada;
		
		//Recorremos el vector codificado de dos en dos (esto es porque RLE utiliza
		//el primer valor de cada dos enteros para guardar el numero de repeticiones
		for (int i = 0; i < secuencia_codificada.TotalUtilizados(); i +=2) {
			
			//Obtenemos los valores para mayor comidad al trabajar
			int repeticiones = secuencia_codificada.Elemento(i);
			int valor = secuencia_codificada.Elemento(i+1);
			
			//Agregamos un nuevo valor por cada repetición
			for (int j = 0; j < repeticiones; j++) {
			
				secuencia_descodificada.Aniade(valor);
			
			}

		}

		//Devolvemos el vector descodificado
		return secuencia_descodificada;
	}
};
/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos   
	MiVectorEnteros vector_introducido;
	MiVectorEnteros vector_auxiliar;
	int entrada;
	RLE rle; //Objeto de la clase RLE
	bool son_iguales = false;

	
	do {	

		//Obtenemos los datos necesarios
		cout << "Introduzca un número entero (-1 para finalizar):";
		cin >> entrada;

		//Vamos añadiendo los enteros al vector
		if (entrada > -1) {
			vector_introducido.Aniade(entrada);
		}

	} while (entrada != -1); //Comprobamos que el número sea distindo de -1



	//Codificamos
	vector_auxiliar = rle.Codifica(vector_introducido);

	//Decodificamos (reutilizamos vector_auxiliar)
	vector_auxiliar = rle.Descodifica(vector_auxiliar);

	//Comprobamos si son iguales
	son_iguales = vector_introducido.EsIgualA(vector_auxiliar);

	//Pintamos los valores en la consola
	cout << "¿Los vectores son iguales (0 = No | 1 = Si?: " << son_iguales << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}
