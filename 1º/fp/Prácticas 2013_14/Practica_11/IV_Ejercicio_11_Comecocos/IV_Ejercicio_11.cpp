/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - FP
	------------------------------
	Construid una clase CaminoComeCocos para representar el camino seguido por 
	el usuario en el juego del ComeCocos (Pac-Man). Internamente debe usar un 
	string como dato miembro privado. Tendrá métodos para subir, bajar, ir a la 
	izquierda e ir a la derecha. Dichos métodos únicamente añadirán el carácter 
	correspondiente ’s’, ’b’, ’i’, ’d’ a la cadena privada.

	Añadir a la clase un método PosicionMovimientosConsecutivos() que calcule 
	la posición donde se encuentre la primera secuencia de al menos n 
	movimientos consecutivos iguales a uno dado (que pasaremos como parámetro 
	al método).

	Por ejemplo, en el camino de abajo, si n = 3, y el movimiento buscado es 
	’s’, entonces dicha posición es la 6. 
	{’b’,’b’,’i’,’s’,’s’,’b’,’s’,’s’,’s’,’s’,’i’,’i’,’d’}

	Resolved este problema usando las siguientes aproximaciones:
		
		a) Definiendo una cadena local a_buscar con la cadena formada por la 
		secuencia de movimientos a buscar y llamando al método find() de la 
		clase string. 

		b) Sin usar find(), accediendo directamente a las componentes de la 
		cadena.

******************************************************************************/
#include <iostream>	// Inclusión de los recursos de E/S
#include <string>	//Inclusión de las funciones para manejo de cadenas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class CaminoComeCocos {
private:
    string cadena_privada;
public:

	/*********************************************************/
	//Este método agrega "s" a la cadena_privada
    void Subir() {
        cadena_privada.append("s");
    }
	/*********************************************************/
	//Este método agrega "b" a la cadena_privada
    void Bajar() {
        cadena_privada.append("b");
    }
	/*********************************************************/
	//Este método agrega "i" a la cadena_privada
    void Izquierda() {
        cadena_privada.append("i");
    }
	/*********************************************************/
	//Este método agrega "d" a la cadena_privada
    void Derecha() {
        cadena_privada.append("d");
    }
	/*********************************************************/
	//Esta función busca los movimientos consecutivos usando la funcion find 
	//de la clase string, para ello hay que pasarle el movimiento y el numero
	//de apariciones consecutivas
	int PosicionMovimientosConsecutivosA(string caracter_movimiento, int n_consecutivos) {
	
		//Declara variables para guardar los datos   
		int posicion;
		string a_buscar;

		//Creamos la cadena a_buscar agregando tantos elementos como se pidan
		for (int i = 0; i < n_consecutivos; i++) {
			a_buscar.append(caracter_movimiento);
		}

		//Buscamos la cadena usando el método find de la clase string
		//Si no lo encuentra devolvera -1
		posicion = cadena_privada.find(a_buscar);

		//Devolvemos el valor
		return posicion;
	}
	/*********************************************************/
	//Esta función busca los movimientos consecutivos sin hacer uso del find 
	//de la clase string, para ello hay que pasarle el movimiento y el numero
	//de apariciones consecutivas
	int PosicionMovimientosConsecutivosB(char caracter_movimiento, int n_consecutivos) {
	
		//Declara variables para guardar los datos   
		int posicion = -1; //si no lo encuentra devolverá -1
		bool encontrada = false; //Bandera para optimizar la salida de los bucles

		//Si se pide una repeticion mayor que el tamaño de la cadena es erroneo
		if (n_consecutivos < (int)cadena_privada.size()) {

			//Recorremos la cadena 
			//(si se encuentra la subcadena se saldrá) 
			//esto es un while con forma de for
			for (int i = 0; !encontrada && (i < (int)cadena_privada.size()); i++) {

				//Comprobamos el numero de consecutivo a partir de donde estamos no es superior
				//a la cadena, y si coincide la letra actual con la que vamos a buscar
				if ((i + n_consecutivos < (int)cadena_privada.size()) && (cadena_privada[i] == caracter_movimiento)) {

					//Nos guardamos un contador de consecutivos encontrados
					//empieza de 1 porque el primero ya se ha encontrado
					int caracteres_consecutivos_encontrados = 1;

					//Recorremos los caracteres siguientes a la aparición 
					//(si se encuentra la subcadena se saldrá) 
					//esto es un while con forma de for
					for (int j = i + 1; !encontrada && j < i + n_consecutivos; j++) {

						//Si el caracter coincide incrementamos el contador
						if (caracter_movimiento == cadena_privada[j]) {
		
							caracteres_consecutivos_encontrados++;
						}

					}

					if (caracteres_consecutivos_encontrados == n_consecutivos) {
						//Establecemos la bandera a true, asi salimos de 
						//los bucles mas eficientemente
						encontrada = true; 

						//Asignamos la posicion para devolverla
						posicion = i;	
					}

				}
			}

		}

		//Devolvemos el valor
		return posicion; 

	}

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los datos   
	CaminoComeCocos ccc;
	int posicion_a;
	int posicion_b;
	
	//Vamos moviendo el comecocos (y agregando letras a la cadena)
	ccc.Subir();
	ccc.Subir();
	ccc.Subir();
	ccc.Izquierda();	
	ccc.Bajar();
	ccc.Bajar();
	ccc.Subir();
	ccc.Subir();
	ccc.Bajar();
	ccc.Bajar();
	ccc.Bajar();
	ccc.Bajar();
	ccc.Izquierda();
	ccc.Izquierda();
	ccc.Izquierda();


	//Buscamos un par de movimentos consecutivos utilizando
	//los dos distintos métodos A y B
	posicion_a = ccc.PosicionMovimientosConsecutivosA("i", 2);
	posicion_b = ccc.PosicionMovimientosConsecutivosB('b', 4);


	//Pintamos los valores en la consola
	cout << "Posicion de i repetido 2 veces mediante el metodo A: ";
	cout << posicion_a << "\n\n";
	cout << "Posicion de b repetido 4 veces mediante el metodo B: ";
	cout << posicion_b << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}