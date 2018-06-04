/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Definid la clase ConjuntoOrdenado para que permita almacenar una secuencia 
	ordenada de números enteros sin repetidos. Definid mé- todos para:

	• Añadir un entero (de forma ordenada y sin almacenar repetidos).
	• Calcular la unión con otro conjunto. En la unión se deben incluir los 
	elementos que estén en cualquiera de ellos.
	• Calcular la intersección con otro conjunto. En la intersección se deben 
	incluir los elementos que sean comunes a ambos conjuntos.

******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include <vector>	//Inclusión de las funciones para manejo de cadenas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase ConjuntoOrdenado
class ConjuntoOrdenado {
private:
    vector <int> vector_privado;
public:

	/*********************************************************/
	//Este método agrega un elemento a la cadena_privada a la cadena_privada
	//si el valor ya existiera se devolvería -1, si el valor se inserta
	//correctamente devolverá la posicion en que se inserta
    int Aniadir(int valor) {
		
		//El resultado por defecto es -1 (no se ha insertado)
		int resultado = -1;
		
		//El primer elemento del vector siempre se añadira
		if (vector_privado.size() == 0) {
			
			resultado = 0; //El primer elemento tendrá posicion 0
			vector_privado.push_back(valor); //Lo agregamos

		} else { //Los siguientes elementos ya tienen que comprobar lo previo

			//Bandera para ver si existe el valor en el vector
			bool encontrado = false;

			//Recorremos el vector para ver si existe el valor
			for (int i= 0; !encontrado && i < (int)vector_privado.size(); i++) {
		
				//Si existe...
				if (vector_privado.at(i) == valor) {
					//...activamos la bandera, así que nos saldremos devolviendo -1
					encontrado = true;
				}
		
			} 
			
			//Pero si no se ha encontrado habra que añadirlo
			if (!encontrado) {

				//Bandera para detectar que hemos encontrado un numero mayor (el vector esta ordenado)
				bool mayor_encontrado = false;
				
				//Recorremos el vector hasta que encontramos el inmediatamente mayor
				for (int i = 0; !mayor_encontrado && i < (int)vector_privado.size(); i++) {
			
					//Si lo encontramos...
					if (vector_privado.at(i) > valor) {

						//Activamos la bandera de que hemos encontrado un valor mayor
						mayor_encontrado = true;

						//la posicion será el actual (porque vamos a insertar ahi)
						resultado = i;

						//Insertamos el valor en el vector haciendo uso de la funcion insert
						vector_privado.insert(vector_privado.begin() + resultado, valor);

					}

				}

				//Si hemos recorrido todo el vector y no hemos encontrado un valor mayor
				if (!mayor_encontrado) {
					//Entonces el resultado sera el tamaño del vector
					resultado = vector_privado.size();
					//Porque vamos a agregarle el valor al final
					vector_privado.push_back(valor);
				}
		 
			}

		}
		
		//Devolvemos la posicion
		return resultado;

    }
	/*********************************************************/
	//Este método devuelve un nuevo ConjuntoOrdenado juntando los elementos de 
	//los dos vectores de forma ordenada y eliminando duplicados
    ConjuntoOrdenado CalcularUnion(vector<int> vector_entrada) {

		//Declaramos el conjunto de salida
		ConjuntoOrdenado conjunto_salida;

		//Recorremos el vector_privado
		for (int i = 0; i < (int)vector_privado.size(); i++) {
			
			//Agregamos los valores en el conjunto de salida usando nuestra funcion
			conjunto_salida.Aniadir(vector_privado.at(i));
		}
        
		//Recorremos el vector_entrada
		for (int i = 0; i < (int)vector_entrada.size(); i++) {

			//Agregamos los valores en el conjunto de salida usando nuestra funcion
			conjunto_salida.Aniadir(vector_entrada.at(i));
		}
        
		//Devolvemos el nuevo conjunto
		return conjunto_salida;
    }
	/*********************************************************/
	//Este método devuelve un nuevo ConjuntoOrdenado con los elementos que 
	//coinciden en el vector_privado y en el vector_entrada de forma ordenada 
	//y eliminando duplicados
    ConjuntoOrdenado CalcularInterseccion(vector<int> vector_entrada) {

		//Declaramos el conjunto de salida
		ConjuntoOrdenado conjunto_salida;

		//Recorremos el vector_privado
		for (int i = 0; i < (int)vector_privado.size(); i++) {
		
			//Recorremos el vector_entrada
			for (int j = 0; j < (int)vector_entrada.size(); j++) {
			
				//Comprobamos si el elemento está en los dos vectores
				if (vector_privado.at(i) == vector_entrada.at(j)) {
				
					//Agregamos los valores en el conjunto de salida usando nuestra funcion
					conjunto_salida.Aniadir(vector_privado.at(i));

				}


			}

		}

		//Devolvemos el nuevo conjunto
		return conjunto_salida;

    }
	/*****************************************************************/
	//Pinta el vector concatenado en la salida estandar. 
	void PintarVector() {
		
		//Recorremos el vector y lo vamos pintanto en la salida
		for (int i = 0; i < (int)vector_privado.size(); i++) {
		
			cout << vector_privado.at(i) << ",";

		}

		//Salto de linea
		cout << "\n";

	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	ConjuntoOrdenado conjunto;
	ConjuntoOrdenado conjuntoUnion;
	ConjuntoOrdenado conjuntoInterseccion;
	vector <int> vector_union;
	vector <int> vector_interseccion;

	//Añadimos valores al conjunto
	conjunto.Aniadir(2);
	conjunto.Aniadir(3);
	conjunto.Aniadir(1);
	conjunto.Aniadir(8);
	conjunto.Aniadir(1);
	conjunto.Aniadir(2);
	conjunto.Aniadir(4);

	//Añadimos valores a los conjuntos de union e interseccion
	vector_union.push_back(2);
	vector_union.push_back(3);
	vector_union.push_back(7);

	vector_interseccion.push_back(2);
	vector_interseccion.push_back(4);
	vector_interseccion.push_back(7);

	//Calculamos la union
	conjuntoUnion = conjunto.CalcularUnion(vector_union);

	//Calculamos la interseccion
	conjuntoInterseccion = conjunto.CalcularInterseccion(vector_interseccion);

	//Pintamos los valores en la consola
	cout << "Tenemos el vector:\n";
	conjunto.PintarVector();

	cout << "La union seria:\n";
	conjuntoUnion.PintarVector();

	cout << "La interseccion seria:\n";
	conjuntoInterseccion.PintarVector();

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}