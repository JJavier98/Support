/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Añadir un método EliminaExcesoBlancos() para eliminar el exceso de 
	caracteres en blanco, es decir, que sustituya todas las secuencias de 
	espacios en blanco por un sólo espacio. Por ejemplo, si el vector original 
	es (’ ’,’a’,’h’,’ ’,’ ’,’ ’,’c’), que contiene una secuencia de tres 
	espacios consecutivos, el vector resultante debe ser (’ ’,’a’,’h’,’ ’,’c’).

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S
#include <string>   // Inclusión de los recursos de cadenas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class MiVectorCaracteres {
private:
    static const int TAMANIO = 50;
    char vector_privado[TAMANIO];
    int total_utilizados;
public:
    MiVectorCaracteres() : total_utilizados(0){
	}
    int TotalUtilizados() {
        return total_utilizados;
    }
    int Capacidad() {
        return TAMANIO;
    }
    void Aniade(char  nuevo) {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
		} 
	}
    char Elemento(int indice) {
        return vector_privado[indice];
    }
	/*********************************************************/
	//Esta funcion comprueba si el vector es palíndromo
	bool EsPalindromo() {

		//Por defecto asignamos el resultado como true
		bool es_palindromo = true;

		//Recorremos el vector, pero nos definimos i y j para tener iteradores en
		//los dos sentidos (ascendente y decreciente) asi queda mas resultón
		//que hacer la resta al indicar el indice a acceder
		for (int i = 0, j = total_utilizados-1; i < total_utilizados-1; i++,j--) {
		
			//Vamos comprobando cada vector con su inverso
			if (vector_privado[i] != vector_privado[j]) {
				es_palindromo = false;
			}

		}

		return es_palindromo;
	}
	/*********************************************************/
	//Esta funcion modifica un indice del vector
	void Modifica(int indice_componente, char nuevo) {
	
		//Comprobamos si ese índice está usado en el vector
		if (total_utilizados > indice_componente) {
		
			//Sustituimos el valor
			vector_privado[indice_componente] = nuevo;

		}

	}
	/*********************************************************/
	//Esta funcion intercambia dos valores
	void IntercambiaComponentes(int indice1, int indice2) {
	
		//Comprobamos si ese índice está usado en el vector
		if (total_utilizados > indice1 && total_utilizados > indice2) {
		
			//Nos guardamos la variable temporal
			char tmp = vector_privado[indice1];
			//Sustituimos el valor
			vector_privado[indice1] = vector_privado[indice2];
			vector_privado[indice2] = tmp;

		}

	}
	/*********************************************************/
	//Esta funcion invierte un vector
	void Invierte() {

		//Recorremos el vector, pero nos definimos i y j para tener iteradores en
		//los dos sentidos (ascendente y decreciente) asi queda mas resultón
		//que hacer la resta al indicar el indice a acceder
		//NOTA: Dividimos entre 2 porque solo hay que recorrer hasta la mitad
		for (int i = 0, j = total_utilizados-1; i < ((total_utilizados-1) / 2); i++,j--) {
		
			//Invertimos los valores
			IntercambiaComponentes(i,j);

		}

	}
	/*********************************************************/
	//Esta funcion elimina un indice de un vector
	void Elimina(int indice_componente) {

		//Comprobamos que el indice exista en la matriz
		if (total_utilizados > indice_componente) {

			//Recorremos el vector desde el superior al indice pasado
			for (int i = indice_componente+1; i < total_utilizados; i++) {

				//NOTA: Esto se resuelve así porque no se pueden eliminar
				//elementos de un vector en c++ (de momento)

				//Vamos desplazando todos los valores un lugar a la izquierda
				vector_privado[i-1] = vector_privado[i];
			}
			
			//Decrementamos el contador de utilizados
			total_utilizados--;

		}
	}
	/*********************************************************/
	//Esta funcion elimina un indice de un vector eficientemente
	//NOTA: Con recursividad se podría optimizar esta funcion
	//pero con lo que sabemos hasta ahora no se me ocurre
	//como optimizarla sin hacerla demasiado compleja
	void EliminaEficiente(int indice_componente) {

		//Comprobamos que el indice exista en la matriz
		if (total_utilizados > indice_componente) {

			//Recorremos el vector desde el superior al indice pasado
			for (int i = indice_componente+1; i < total_utilizados; i++) {

				//NOTA: Esto se resuelve así porque no se pueden eliminar
				//elementos de un vector en c++ (de momento)

				//Vamos desplazando todos los valores un lugar a la izquierda
				vector_privado[i-1] = vector_privado[i];
			}
			
			//Decrementamos el contador de utilizados
			total_utilizados--;

		}
	}
	/*********************************************************/
	//Esta funcion elimina un indice de un vector
	void EliminaMayusculas() {

		//Recorremos el vector
		for (int i = 0; i < total_utilizados; i++) {
		
			//Comprobamos si el elemento actual esta en minúsculas
			if ((vector_privado[i] >= 'A') && (vector_privado[i] <= 'Z')){

				//Lo eliminamos
				EliminaEficiente(i);

			}

		}
		
	}
	/*********************************************************/
	//Esta funcion pinta el array en la salida estandar
	void PintarVector(string mensaje = "") {

		//Solo pintamos el mensaje si le pasamos algo
		if (mensaje.length()  > 0) 
			cout << mensaje << ":\n";

		for (int i = 0; i < total_utilizados; i++){
			cout << vector_privado[i];
		}
		cout << '\n';
		
	}
	/*********************************************************/
	//Esta funcion elimina los elementos repetidos usando un vector local
	void EliminaRepetidosA() {

		//Declaracion de variables
		char vector_unicos[TAMANIO];
		int unicos_utilizados = 0;
		bool existe; //Bandera para cuando exista previamente
		int j = 0;

		for (int i = 0; i < total_utilizados; i++) {
		
			//Establecemos el valor inicial de las variables
			existe = false;
			j = 0;

			while (!existe && j < unicos_utilizados) {//ademas del valor del iterador comprobamos existe, 
													 //para optimizar en caso de encontrarse
				if (vector_privado[i] == vector_unicos[j]) {
					existe = true;
				}
				j++; //Incrementamos el iterador
			}

			if (!existe) {
				//Agregamos un nuevo elemento al array de unicos
				vector_unicos[unicos_utilizados] = vector_privado[i];
				unicos_utilizados++;
			}

		
		}

		//Copiamos el vector_unicos en el vector_privado
		for (int i = 0; i < unicos_utilizados; i++) {
			vector_privado[i] = vector_unicos[i]; 
		}
		//Reajustamos el contador de utilizados
		total_utilizados = unicos_utilizados;

	}
	/*********************************************************/
	//Esta funcion elimina los elementos repetidos desplazando
	void EliminaRepetidosB() {

		//Declaracion de variables
		int i = 0;
		int j = 0;
		bool existe; //Bandera para cuando exista previamente

		//Usamos un while, porque solo incrementamos la posicion cuando
		//el caracter es distinto
		while (i < total_utilizados) {
		
			//Establecemos el valor inicial de las variables
			existe = false; 
			j = 0;

			//Recorremos los caracteres previos...
			while ((!existe) && (j < i)) { //ademas del valor del iterador comprobamos existe, 
										   //para optimizar en caso de encontrarse
				//...para ver si existe
				if (vector_privado[i] == vector_privado[j]) {
					existe = true;
				}
				j++; //Incrementamos el iterador
			
			}

			//Si existe desplazamos los componentes y decrementamos los utilizados
			if (existe) {
				for (int h = i; h < total_utilizados; h++) {
					vector_privado[h] = vector_privado[h+1]; 
				}
				total_utilizados--;
			} else {
				i++; //Incrementamos el iterador
			}
			
		}

	}
	/*********************************************************/
	//Esta funcion elimina los elementos repetidos
	void EliminaRepetidosC() {

		//Declaracion de variables
		int i = 0;
		int j;
		int numero_iguales_adyacentes;
		bool existe; //Bandera para cuando exista previamente
		int k;
		bool caracter_es_distinto;
		
		//Usamos un while, porque solo incrementamos la posicion cuando
		//el caracter es distinto
		while (i < total_utilizados) {
		
			//Asignamos el valor inicial de las variables
			existe = false;
			j = 0;
			numero_iguales_adyacentes = 0;

			//Recorremos los caracteres previos...
			while ((!existe) && (j < i)) {
			
				//...para ver si existe
				if (vector_privado[i] == vector_privado[j]) {
				
					//Establecemos el valor inicial de las variables
					numero_iguales_adyacentes = 0; //Establecemos la variable a 0
					k = i + 1; //Tiene que tener el valor siguiente a i
					caracter_es_distinto = false;

					//Recorremos hacia adelante para ver si hay adyacentes, asi
					//nos ahorramos un cacho
					while ((!caracter_es_distinto) && (k < total_utilizados -1)) {
						if (vector_privado[i] == vector_privado[k]) {
							numero_iguales_adyacentes++;
						} else {
							//Si es diferente asignamos la bandera
							caracter_es_distinto = true;
						}
						k++; //Incrementamos el iterador
					}
					existe = true;

				}

				j++; //Incrementamos el iterador
			
			}

			//Si existe desplazamos los componentes y decrementamos los utilizados
			if (existe) {
				for (int h = i; h < total_utilizados; h++) {
					vector_privado[h] = vector_privado[h+1 + numero_iguales_adyacentes]; 
				}
				total_utilizados -= numero_iguales_adyacentes + 1;
			} else {
				//Incrementamos el iterador
				i++;
			}
			
		}

	}
	/*********************************************************/
	//Esta funcion elimina los elementos whitespace repetidos
	void EliminaExcesoBlancos() {

		int i = 0;
		bool anterior_es_espacio = false;
		//Usamos un while, porque solo incrementamos la posicion cuando
		//el caracter es distinto
		while (i < total_utilizados) {

			if (vector_privado[i] == ' ') {

				if (anterior_es_espacio) { 
				
					//Desplazamos
					for (int h = i; h < total_utilizados; h++) {
						vector_privado[h] = vector_privado[h+1]; 
					}
					total_utilizados--;

				} 

				anterior_es_espacio = true;
	
			} else {
				anterior_es_espacio = false;
				
			}
			//Incrementamos el iterador
			i++;
		}

	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	MiVectorCaracteres vc1;

	vc1.Aniade(' ');
	vc1.Aniade('a');
	vc1.Aniade(' ');
	vc1.Aniade('h');	
	vc1.Aniade(' ');
	vc1.Aniade(' ');
	vc1.Aniade(' ');
	vc1.Aniade(' ');
	vc1.Aniade('c');


	vc1.PintarVector("Eliminar repetidos");

	//Eliminamos los repetidos
	vc1.EliminaExcesoBlancos();

	vc1.PintarVector();

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}