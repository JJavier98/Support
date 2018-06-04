/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Añadir el método Elimina() para eliminar el carácter que se encuentre en 
	una determinada posición, de forma que si el vector contenía, por ejemplo,
	los caracteres {’h’,’o’,’l’,’a’}, después de eliminar la componente con 
	índice 2 (la tercera) se quedará con {’h’,’o’,’a’}.

	¿Qué debería hacer el método si el índice no es correcto?

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
				break; //Salimos del bucle para optimizar
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
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	MiVectorCaracteres vc1;

	vc1.Aniade('h');
	vc1.Aniade('o');
	vc1.Aniade('l');
	vc1.Aniade('a');	

	cout << "Eliminar:\n";

	for (int i = 0; i < vc1.TotalUtilizados();i++){
		cout << vc1.Elemento(i);
	}
	cout << '\n';

	//Eliminamos el valor
	vc1.Elimina(2);

	for (int i = 0; i < vc1.TotalUtilizados();i++){
		cout << vc1.Elemento(i);
	}
	cout << '\n' << '\n';



	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}