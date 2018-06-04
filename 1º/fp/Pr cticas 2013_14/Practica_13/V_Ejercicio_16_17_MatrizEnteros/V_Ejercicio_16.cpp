/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Definid la clase MiMatrizRectangularEnteros de forma análoga a la clase
	MiMatrizRectangularCaracteres (ejercicio 14 de esta relación de problemas). 
	Ampliar el conjunto de métodos básicos con otros que nos permitan realizar 
	las siguientes operaciones:

	b) Calcular la posición de aquel elemento que sea el mayor de entre los 
		mínimos de cada fila. 

	c) Ver si existe un valor MaxiMin, es decir, que sea a la vez, máximo de su ç
		fila y mínimo de su columna.

	AmpliarlaclaseMiMatrizRectangularEnterosconunmétodoquebusquelafila de la 
	matriz que más se parezca a un vector de enteros (clase MiVectorEnteros) al 
	que llamaremos referencia. El método devolverá el número de la fila.


******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <vector> //Libreria para vectores de la STL

using namespace std; 
/*****************************************************************************/
//Definicion de la clase Punto2DyValor
//Esta clase almacena un punto2D y un valor
class Punto2DyValor {
private:
   int abscisa;
   int ordenada;
   int valor;
public:
   Punto2DyValor(int pAbscisa, int pOrdenada, int pValor) {
      abscisa = pAbscisa;
      ordenada = pOrdenada;
	  valor = pValor;
   }
   int GetAbscisa() {
      return abscisa;
   }
   int GetOrdenada() {
      return ordenada;
   }
   int GetValor() {
      return valor;
   }
};
/*****************************************************************************/
//Definicion de la clase MiMatrizRectangularEnteros
class MiMatrizRectangularEnteros {

private:
	//Definicion de atributos
    static const int MAXIMO_FILAS = 40;
	static const int MAXIMO_COLUMNAS = 10;
    int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];
    int filas_utilizadas;

public:
	MiMatrizRectangularEnteros() : filas_utilizadas(0) {}

	/*********************************************************/
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
	//Esta función obtiene el entero que hay en una fila y columna
	//si la posicion proporcionada (fila,columna) fuera incorrecta 
	//devolvería -1
	int Elemento(int fila, int columna) {

		//Declaracion de variables
		int elemento;

		//Comprobamos si la posicion proporcionada es correcta
		if (fila > filas_utilizadas || columna > MAXIMO_COLUMNAS ) {
		
			//La posición es incorrecta, así que asignamos el elemento como 0
			elemento = 0;

		} else {
		
			//Obtenemos el elemento
			elemento = matriz_privada[fila][columna];

		}

		//Devolvemos el elemento
		return elemento;
	}

/*********************************************************/
	//Este método establece el elemento indicado en la posicion
	//indicada de la matriz
	void SetElemento(int fila, int columna, int valor) {

		//Establecemos el valor
		matriz_privada[fila][columna] = valor;
		
	}

	/*********************************************************/
	//Esta función devuelve una fila completa como un vector de la STL. 
	vector<int> Fila(int indice_fila) {

		//Declaramos un nuevo objeto del tipo vector
		vector<int> fila;
		
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
	void Aniade(vector<int> nueva_fila) {

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
					//ponemos un 0, en caso de que tenga mas se omitirá
					//Así será rectangular
					matriz_privada[filas_utilizadas][i] = 0;

				}

			}

			//Incrementamos el contador de filas utilizadas
			filas_utilizadas++;
		} 
	}

	/*********************************************************/
	//Esta funcion busca un caracter, devuelve true si lo encuentra, false si no
	bool BuscarEntero(int numero) {

		//Asignamos una bandera como false
		bool encontrado = false;

		//Bucle while en forma de for, recorremos la matriz hasta el final o hasta que cambie la bandera
		for (int i = 0; !encontrado && i < filas_utilizadas; i++) { 

			//Bucle while en forma de for, recorremos la matriz hasta el final o hasta que cambie la bandera
			for (int h = 0; !encontrado && h < MAXIMO_COLUMNAS; h++) {
			
				//Si el numero existe cambiamos la bandera, así que saldra de los bucles
				if (matriz_privada[i][h] == numero ) {
				
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
	//como un objeto de la clase MiMatrizRectangularEnteros
	bool EsIgual(MiMatrizRectangularEnteros matriz_a_comparar) {

		bool distinta = false;
		
		for (int i = 0; !distinta && i < filas_utilizadas; i++) { 

			for (int h = 0; !distinta && h < MAXIMO_COLUMNAS; h++) {
			
				if (matriz_privada[i][h] != matriz_a_comparar.Elemento(i,h)) {
				
					distinta = true;
				
				}
	
			}
		
		}

		return !distinta;
	}

	/*********************************************************/
	//Esta función obtiene la traspuesta de la matriz como un nuevo
	//objeto del timpo MiMatrizCaracteres
	MiMatrizRectangularEnteros ObtenerTraspuesta() {
	
		//Definimos un nuevo objeto
		MiMatrizRectangularEnteros traspuesta;

		//Recorremos las columnas
		for (int i = 0; i < MAXIMO_COLUMNAS; i++) {
		
			//Definimos un nuevo vector
			vector<int> fila;

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
	//Esta función comprueba si la matriz es simetrica haciendo uso
	//de las funiciones definidas previamente
	bool EsSimetrica() {

		//Obtenemos la traspuesta
		MiMatrizRectangularEnteros traspuesta = ObtenerTraspuesta();

		//La comprobamos con la funcion predefinida
		bool es_simetrica = EsIgual(traspuesta);

		//Devolvemos el resultado
		return es_simetrica;

	}

	/*********************************************************/
	//Calcular la posición de aquel elemento que sea el mayor de 
	//entre los mínimos de cada fila (EJERCICIO B)
	//La posicion (x,y) la devolveremos como un objeto Punto2D
	Punto2DyValor DevolverMayorEntreMinimos() { 
	
		int i, h;
		Punto2DyValor resultado(0,0,0);
		vector<Punto2DyValor> minimos;

		for (i = 0; i < filas_utilizadas; i++) {
		
			int minimo = -1;

			for (h = 0; h < MAXIMO_COLUMNAS; h++) {
			
				if (minimo == -1 || minimo > matriz_privada[i][h]) {
				
					minimo = matriz_privada[i][h];
				
				}

			}

			minimos.push_back(Punto2DyValor(i,h,minimo));		
		
		}

			
		int maximo = -1;
		for (i = 0; i < (int)minimos.size(); i++) {
		
				if (maximo == -1 || maximo < minimos[i].GetValor()) {
				
					resultado = minimos[i];
				
				}

		
		}

		return resultado;
	
	}



	/*********************************************************/
	//Esta funcion devuelve una matriz indicando que valores de la matriz son maximin
	//el 0 es no y el 1 es si
	MiMatrizRectangularEnteros MatrizMaxiMin() {
	
		//Declaramos un nuevo objeto del tipo MiMatrizRectangularEnteros
		MiMatrizRectangularEnteros matriz_maximin;


		//Recorremos sus filas
		for (int i = 0; i < filas_utilizadas; i++) {

			//Declaramos un nuevo vector (fila)
			vector<int> fila;

			//Recorremos las columnas
			for (int h = 0; h < MAXIMO_COLUMNAS; h++) {

				//Vamos agregando valores a la fila (si es maximin)
				fila.push_back(EsMaxiMin(i,h));
			
			}

			//Agregamos la fila a la matriz
			matriz_maximin.Aniade(fila);
		
		}
	
		//Devolvemos el valor
		return matriz_maximin;
	
	}

	/*********************************************************/
	//Ver si existe un valor MaxiMin, es decir, que sea a la vez, máximo de su 
	//fila y mínimo de su columna. (EJERCICIO C)
	bool EsMaxiMin(int fila, int columna) {
	
		//Declaracion de variables
		bool maximo_fila = true;
		bool minimo_columna = true;

		int valor = matriz_privada[fila][columna];

		//Recorremos las filas
		for (int i = 0; maximo_fila && i < filas_utilizadas; i++) {
		
			//Todas excepto la pasada
			if (i != fila) {
			
				if (matriz_privada[i][columna] > valor) {
				
					//Es la maxima
					maximo_fila = false;
				
				}
			
			}

		}

		//Recorremos las columnas
		for (int i = 0; minimo_columna && i < MAXIMO_COLUMNAS; i++) {
		
			//Todas excepto la pasada
			if (i != columna) {
			
				if (matriz_privada[fila][i] < valor) {
					
					//Es la maxima
					minimo_columna = false;
				
				}
			
			}

		}
	
		//Devolvemos si es la maximin
		return maximo_fila & minimo_columna;

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
	vector<int> fila1;
	fila1.push_back(1);
	fila1.push_back(2);
	fila1.push_back(2);
	fila1.push_back(3);

	//Creamos un vector
	vector<int> fila2;
	fila2.push_back(1);
	fila2.push_back(7);
	fila2.push_back(3);
	fila2.push_back(3);
	fila2.push_back(1);

	//Creamos un vector
	vector<int> fila3;
	fila3.push_back(1);
	fila3.push_back(2);
	fila3.push_back(1);
	fila3.push_back(3);
	fila3.push_back(5);
	fila3.push_back(7);
	fila3.push_back(3);

	//Agregamos las filas a la matriz
	MiMatrizRectangularEnteros matriz;
	matriz.Aniade(fila1);
	matriz.Aniade(fila2);
	matriz.Aniade(fila3);

	//Pintamos los valores en la consola recorriendo sus elementos
	cout << "Imprimiendo matriz:\n";
	matriz.ImprimirMatriz();


	//Obtenemos el mayor entre minimos
	Punto2DyValor punto = matriz.DevolverMayorEntreMinimos();
	int x = punto.GetAbscisa();
	int y = punto.GetOrdenada();
	int valor = punto.GetValor();
	cout << "El mayor entre minimos es: " << valor << " y está en la posicion (" << x << "," << y << ")\n";


	//Obtenemos el MaxiMin
	MiMatrizRectangularEnteros matriz_maximin = matriz.MatrizMaxiMin();

	//Pinta un vector de 0 y 1 dependiendo de si el valor de la matriz es maximin
	cout << "Tiene MaxiMin (0=No|1=Si)?\n";
	matriz_maximin.ImprimirMatriz();

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}