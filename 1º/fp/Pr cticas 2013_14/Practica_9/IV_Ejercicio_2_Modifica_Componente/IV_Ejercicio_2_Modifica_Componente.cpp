/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Añadir un método con la cabecera:

		void Modifica (int indice_componente, char nuevo)
	
	para que sustituya la componente con índice indice_componente por el valor
	nuevo.
	
	Este método está pensado para modificar una componente ya existente, pero 
	no para añadir componentes nuevas. Por tanto, en el caso de que la 
	componente no esté dentro del rango correcto, el método no modificará nada.

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

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	MiVectorCaracteres vc;

	vc.Aniade('a');
	vc.Aniade('b');
	
	cout << "El valor del elemento 1 es: " << vc.Elemento(1) << "\n\n";  

	//Modificamos el valor
	vc.Modifica(1,'c');
	
	cout << "El nuevo valor del elemento 1 es: " << vc.Elemento(1) << "\n\n";  
	
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}