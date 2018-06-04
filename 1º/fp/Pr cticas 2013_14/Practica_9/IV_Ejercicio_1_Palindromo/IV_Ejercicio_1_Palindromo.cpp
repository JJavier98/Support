/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Añadir un método con la cabecera:
     bool EsPalindromo (void)
	que nos diga si el vector es un palíndromo, es decir, que se lee igual de 
	izquierda a derecha que de derecha a izquierda. 
	
	Por ejemplo, {’a’,’b’,’b’,’a’} sería un palíndromo.

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

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	MiVectorCaracteres vc;

	vc.Aniade('a');
	vc.Aniade('b');
	vc.Aniade('b');
	vc.Aniade('a');
	vc.Aniade('a');
	vc.Aniade('b');
	vc.Aniade('b');
	vc.Aniade('a');

	cout << "Es palindromo? " << vc.EsPalindromo() << "\n\n";  
      
	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}