/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Sobre el ejercicio 9, cread una clase específica Mayusculas que implemente 
	los métodos necesarios para realizar la cuenta de las mayúsculas. Lo que se 
	pretende es que la clase proporcione los métodos siguientes:

      void IncrementaCuenta (char mayuscula)
      int  CuantasHay (char mayuscula)

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S
#include <string>   // Inclusión de los recursos de cadenas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Mayusculas {
private:
    static const int TAMANIO = ('Z' - 'A') + 1;
    char vector_privado[TAMANIO];
    int total_utilizados;
public:
    Mayusculas() : total_utilizados(0){
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

	void Modifica(int indice_componente, char nuevo) {
	
		//Comprobamos si ese índice está usado en el vector
		if (total_utilizados > indice_componente) {
		
			//Sustituimos el valor
			vector_privado[indice_componente] = nuevo;

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
	void IncrementaCuenta(char mayuscula) {

		//Restamos la mayuscula para averiguar la posicion (A sera la posicion 0)
		int pos = mayuscula - 'A';

		//Incrementamos el valor
		vector_privado[pos]++;

	}
     
	int CuantasHay(char mayuscula) {

		//Restamos la mayuscula para averiguar la posicion (A sera la posicion 0)
		int pos = mayuscula - 'A';

		return vector_privado[pos];

	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	Mayusculas vc;
	Mayusculas vcLetras; //Esta es para pintar
	char caracter;

	for (char ch = 'A'; ch <= 'Z'; ch++) {
	
		//Agregamos 0 (como char para reutilizar miVectorCaracteresf)
		vc.Aniade('0');
		//En esta las letras
		vcLetras.Aniade(ch);
	}

	do {
		cout << "Introduzca un caracter: ";
		cin >> caracter;

		if ((caracter >= 'A') && (caracter <= 'Z')) {

			vc.IncrementaCuenta(caracter); 
		} 

	} while (caracter != '.');

	vcLetras.PintarVector("Contador Mayusculas");
	vc.PintarVector();

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}