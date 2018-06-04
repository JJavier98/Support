/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Sobre la clase MiVectorCaracteres, definir un método recursivo que nos diga 
	si es un palíndromo, es decir, que se lee igual de izquierda a derecha que 
	de derecha a izquierda. Por ejemplo, {’a’,’b’,’b’,’a’} sería un palíndromo.

	Pasad al método como parámetros las posiciones izquierda y derecha sobre 
	las que trabajará.
	
******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S

using namespace std; 

/*****************************************************************************/
//Definicion de la clase MiVectorCaracteres
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

	/*************************************************************/
	//Esta función comprueba si un objeto MiVectorCaracteres es
	//palíndromo haciendo uso de la recursividad.
	//NOTA: Lo he realizado con varios return porque se permite.
	bool EsPalindromo(int posicionIzquierda, int posicionDerecha) {
	

		//Comprobamos si ya hemos llegado al centro del vector, es decir, si la
		//posicion izquierda es mayor o igual a la derecha
		if (posicionIzquierda >= posicionDerecha) {
		
			//Ha terminado y no ha encontrado diferencias
			return true;

		} else {

			//Obtenemos los caracteres de izquierda y derecha y los asignamos
			//a sendas variables para hacer el codigo mas legible
			char caracter_izquierda = vector_privado[posicionIzquierda];
			char caracter_derecha = vector_privado[posicionDerecha];
		
			//Comprobamos si los caracteres son distintos
			if (caracter_izquierda != caracter_derecha) {
		
				//Si son distintos no es palindromo, asi que false
				return false;
		
			} else {
		
				//Si son iguales pasamos a comprobar los siguentes, incrementamos izquierda
				//y decrementamos derecha
				return EsPalindromo(posicionIzquierda + 1, posicionDerecha - 1);
		
			} 

		}
	
	}

};

/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	MiVectorCaracteres palabra;
	palabra.Aniade('a');
	palabra.Aniade('b');
	palabra.Aniade('c'); 
	palabra.Aniade('b');
	palabra.Aniade('a');

	//Hacemos las operaciones
	bool resultado = palabra.EsPalindromo(0, palabra.TotalUtilizados() -1);

	//Pintamos el resultado en la consola
	cout << "Es palíndromo (0=No|1=Si): " <<  resultado << endl;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}