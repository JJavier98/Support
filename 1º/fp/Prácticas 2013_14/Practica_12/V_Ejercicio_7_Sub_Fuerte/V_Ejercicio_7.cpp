/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Sobre la clase MiVectorCaracteres (la que usa un vector “clásico” como dato 
	privado) definid el método Contiene para ver si contiene a otro vector de 
	caracteres. Los caracteres tienen que estar consecutivos y en el mismo 
	orden. Por ejemplo, el vector {’t’,’t’,’b’,’i’,’d’,’d’} no contiene al 
	vector {’t’,’i’} pero sí contiene al vector {’t’,’b’,’i’} (a partir de 
	la posición 1).

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S

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
	void PintarVector() {

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
	/*********************************************************/
	//Esta funcion busca una cadena de caracteres dada como argumento
	//dentro del vector de caracteres sin utilizar los metodos de la
	//clase string (find).
	//Si lo encuentra devuelve el valor de la primera posicion en la
	//que aparece el vector a buscar, si no devuelve el valor -1.
	int Contiene(MiVectorCaracteres vector_busqueda){

		//Declaracion de variables
		int pos_elemento_encontrado = -1;
		bool encontrado = false;
		bool igual=true;

		//Recorre el vector buscando la primera componente del vector a buscar
		for (int i = 0; !encontrado && i <= (total_utilizados - vector_busqueda.TotalUtilizados()); i ++) {

			//Si encuentra la primera componente, busca que este el resto del vector a buscar:
			if (vector_privado[i] == vector_busqueda.Elemento(0)){

				//Establece el valor de pos_elemento_encontrado el valor de la primera componente encontrada:
				pos_elemento_encontrado = i; 

				//Aumenta en uno el valor del i para no volver a comparar la misma componente:
				i++;

				//Compara los siguientes caracteres con los caracteres a buscar:
				for (int j = 1; igual && j < vector_busqueda.TotalUtilizados(); j ++, i++){

					//Si coinciden, la condicion igual se mantiene:
					if (vector_privado[i] == vector_busqueda.Elemento(j)) {

						igual = true;
					
					//Si no coinciden, la condicion igual se vuelve falsa, se finaliza el ultimo ciclo, 
					// se devuelve el valor de i para seguir buscando la primera componente 
					// y pos_elemento_encontrado vuelve a ser -1 (no encontrado):
					} else {

						igual = false;

						i = pos_elemento_encontrado;
						
						pos_elemento_encontrado = -1;
					}
				}

				//En el caso de que el ciclo anterior termine e igual sea siendo true, significa 
				// que se ha encontrado el vector, por lo que se deja de buscar (encontrado = true):

				if (igual) {

					encontrado = true;
				}
			}

		}

		return pos_elemento_encontrado;
	}
};
/*****************************************************************************/
//Programa Principal 
int main() {

	//Declara variables para guardar los datos   
	int resultado;
	MiVectorCaracteres vector_principal; 
	MiVectorCaracteres vector_busqueda;
	
	//Definimos el vectro principal
	vector_principal.Aniade('H');
	vector_principal.Aniade('o');
	vector_principal.Aniade('l');
	vector_principal.Aniade('a');
	vector_principal.Aniade(' ');
	vector_principal.Aniade('q');
	vector_principal.Aniade('u');
	vector_principal.Aniade('e');
	vector_principal.Aniade(' ');
	vector_principal.Aniade('t');
	vector_principal.Aniade('a');
	vector_principal.Aniade('l');


	//Definimos el vector a buscar
	vector_busqueda.Aniade('t');
	vector_busqueda.Aniade('a');
	vector_busqueda.Aniade('l');

	//Vemos si un vector contiene al otro
	resultado = vector_principal.Contiene(vector_busqueda);

	//Pintamos el resultado en la consola
	cout << "Vamos a buscar el vector:\n";
	vector_busqueda.PintarVector();

	cout << "\nDentro del vector:\n";
	vector_principal.PintarVector();

	if (resultado > -1) {
		cout << "\nEl vector buscado esta en la posicion: " << resultado << "\n\n";

	} else {
		cout << "\nNo se ha encontrado el vector.\n\n";
	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
