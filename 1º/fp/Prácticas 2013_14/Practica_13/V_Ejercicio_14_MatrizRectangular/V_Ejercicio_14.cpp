/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Cread la clase MiMatrizRectangularCaracteres para obligar a que todas las 
	filas tengan el mismo número de columnas, es decir, que sea una matriz 
	rectangular. 
	
	Usad como dato miembro privado una matriz clásica en la forma:
      char matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];

	Definid métodos para:

	a) Obtener el número de filas y columnas utilizadas.
	b) Obtener el carácter que haya en una fila y columna.
	c) Devolver una fila completa como un vector de la STL. 
	d) Añadir una fila entera. La fila será un vector de la STL. 
	e) Encontrar un carácter.
	f) Comprobar si es igual a otra matriz rectangular.
	g) (Examen Febrero 2011) Obtener la traspuesta de la matriz.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <vector> //Libreria para vectores de la STL

using namespace std; 

/*****************************************************************************/
//Definicion de la clase MiMatrizRectangularCaracteres
class MiMatrizRectangularCaracteres {

private:
	//Definicion de atributos
    static const int MAXIMO_FILAS = 40;
	static const int MAXIMO_COLUMNAS = 10;
    char matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];
    int filas_utilizadas;

public:
	MiMatrizRectangularCaracteres() : filas_utilizadas(0) {}

	//Esta función devuelve el número de filas utilizadas
	int FilasUtilizadas() {
		return filas_utilizadas;
	}

	/*********************************************************/
	//Esta función devuelve el número de columnas utilizadas
	int ColumnasUtilizadas() {
		//Como siempre tienen que haber el mismo numero de columnas
		//devolvemos el numero maximo de columnas
		return MAXIMO_COLUMNAS;
	}

	/*********************************************************/
	//Esta función obtiene el carácter que hay en una fila y columna
	//si la posicion proporcionada (fila,columna) fuera incorrecta 
	//devolvería -1
	char Elemento(int fila, int columna) {

		//Declaracion de variables
		char elemento;

		//Comprobamos si la posicion proporcionada es correcta
		if (fila > filas_utilizadas || columna > MAXIMO_COLUMNAS ) {
		
			//La posición es incorrecta, así que asignamos el elemento como -1
			elemento = -1;

		} else {
		
			//Obtenemos el elemento
			elemento = matriz_privada[fila][columna];

		}

		//Devolvemos el elemento
		return elemento;
	}

	/*********************************************************/
	//Esta función devuelve una fila completa como un vector de la STL. 
	vector<char> Fila(int indice_fila) {

		//Declaramos un nuevo objeto del tipo vector
		vector<char> fila;
		
		//Recorremos la matriz
		for (int i = 0; i < MAXIMO_COLUMNAS; i++) {
			//Agregamos cada elemento como una columna del vector
			fila.push_back(matriz_privada[indice_fila][i]);
		}
		//Devolvemos el vector
		return fila;
	}

	/*********************************************************/
	//Este método añade una fila entera. La fila será un vector de la STL.
	void Aniade(vector<char> nueva_fila) {

		//Comprobamos que no vayamos a agregar mas filas del maximo
		if (filas_utilizadas < MAXIMO_FILAS){

			//Recorremos las columnas
			for (int i = 0; i < MAXIMO_COLUMNAS; i++) {

				//Comprobamos que no tenga mas columnas de las soportadas
				if (i < (int)nueva_fila.size() ) {
					//Asignamos cada elemento de la fila pasada a la matriz_privada
					matriz_privada[filas_utilizadas][i] = nueva_fila.at(i);		
					
				} else {
					//En caso de que tenga menos elementos que el maximo de columnas le 
					//ponemos un espacio en blanco, en caso de que tenga mas se omitirá
					//Así será rectangular
					matriz_privada[filas_utilizadas][i] = ' ';

				}

			}

			//Incrementamos el contador de filas utilizadas
			filas_utilizadas++;
		} 
	}

	/*********************************************************/
	//Esta funcion busca un caracter, devuelve true si lo encuentra, false si no
	bool BuscarCaracter(char caracter) {

		//Asignamos una bandera como false
		bool encontrado = false;

		//Bucle while en forma de for, recorremos la matriz hasta el final o hasta que cambie la bandera
		for (int i = 0; !encontrado && i < filas_utilizadas; i++) { 

			//Bucle while en forma de for, recorremos la matriz hasta el final o hasta que cambie la bandera
			for (int h = 0; !encontrado && h < MAXIMO_COLUMNAS; h++) {
			
				//Si el caracter existe cambiamos la bandera, así que saldra de los bucles
				if (matriz_privada[i][h] == caracter ) {
				
					//Encontrado!!
					encontrado = true;
				
				}
	
			}
		
		}

		//Devolvemos si se ha encontrado
		return encontrado;
	}

	/*********************************************************/
	//Esta funcion comprueba si la matriz es igual a la que se le pasa como parámetro
	//como un objeto de la clase MiMatrizRectangularCaracteres
	bool EsIgual(MiMatrizRectangularCaracteres matriz_a_comparar) {

		//Declaracion de bandera
		bool es_igual = true;
		
		//Recorremos las filas
		for (int i = 0; es_igual && i < filas_utilizadas; i++) { 
		
			//Recorremos las columnas
			for (int h = 0; es_igual && h < MAXIMO_COLUMNAS; h++) {
			
				//Comprobamos si son iguales los elementos
				if (matriz_privada[i][h] != matriz_a_comparar.Elemento(i,h)) {
				
					//Cambiamos la bandera (se saldra de los bucles)
					es_igual = false;
				
				}

			}

		}

		//Devolvemos la bandera
		return es_igual;
	}

	/*********************************************************/
	//Esta función obtiene la traspuesta de la matriz como un nuevo
	//objeto del timpo MiMatrizCaracteres
	MiMatrizRectangularCaracteres ObtenerTraspuesta() {
	
		//Definimos un nuevo objeto
		MiMatrizRectangularCaracteres traspuesta;

		//Recorremos las columnas
		for (int i = 0; i < MAXIMO_COLUMNAS; i++) {
		
			//Definimos un nuevo vector
			vector<char> fila;

			//Recorremos las filas por cada columnas
			for (int h = 0; h < filas_utilizadas; h++) {
			
				//Agregamos el elemento al vector
				fila.push_back(matriz_privada[h][i]);
			
			}

			//Agregamos la fila a la nueva matriz
			traspuesta.Aniade(fila);
		
		}

		//Devolvemos la matriz traspuesta
		return traspuesta;
	}

	/*********************************************************/
	//Este método imprime la matriz en la salida estándar
	void ImprimirMatriz() {

		//Recorremos el vector
		for (int i = 0; i < filas_utilizadas; i++) {

			for (int h = 0; h < MAXIMO_COLUMNAS; h++) {

				//Imprime el elemento actual en la salida estándar
				cout << matriz_privada[i][h] << ", ";

			}	
			
			//Pintamos un salto de linea
			cout << "\n";

		}

	}

};

/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos   
	//Creamos un vector
	vector<char> fila1;
	fila1.push_back('H');
	fila1.push_back('o');
	fila1.push_back('l');
	fila1.push_back('a');

	//Creamos un vector
	vector<char> fila2;
	fila2.push_back('m');
	fila2.push_back('u');
	fila2.push_back('n');
	fila2.push_back('d');
	fila2.push_back('o');

	//Creamos un vector
	vector<char> fila3;
	fila3.push_back('m');
	fila3.push_back('u');
	fila3.push_back('n');
	fila3.push_back('d');
	fila3.push_back('i');
	fila3.push_back('a');
	fila3.push_back('l');

	//Agregamos las filas a la matriz
	MiMatrizRectangularCaracteres matriz;
	matriz.Aniade(fila1);
	matriz.Aniade(fila2);
	matriz.Aniade(fila3);

	//Pintamos los valores en la consola recorriendo sus elementos
	cout << "Imprimiendo matriz:\n";
	matriz.ImprimirMatriz();


	//Sacamos la traspuesta y la pintamos en la consola
	MiMatrizRectangularCaracteres matriz_traspuesta = matriz.ObtenerTraspuesta();
	cout << "Imprimiendo matriz traspuesta:\n";
	matriz_traspuesta.ImprimirMatriz();

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}