/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIO 13
//
/*	
	En este ejercico se amplía funcionalidad ofrecida por la clase 
	MiMatrizCaracteres con el método: 
	
		void Inserta (MiVectorCaracteres nueva_fila, int pos_nueva_fila);

	que inserta una fila completa "nueva_fila" en una posición (de fila) 
	determinada por "pos_nueva_fila".
*/
/*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiVectorCaracteres 
{
private:

	static const int TAMANIO = 50;
	char vector_privado[TAMANIO];
	int total_utilizados;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorCaracteres() : total_utilizados	(0) {}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return (total_utilizados);
	}

	int Capacidad()
	{
		return (TAMANIO);
	}

	/*****************************************************************/
	// Añade un elemento al vector
	// PRE: hay espacio para el nuevo elemento.
	// Si no lo hay, no hace nada.
	
	void Aniade(char nuevo)
	{
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.

	char Elemento(int indice)
	{
		return (vector_privado[indice]);
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

class MiMatrizCaracteres
{
private:

    static const int MAXIMO_FILAS = 40;
    MiVectorCaracteres matriz_privada[MAXIMO_FILAS];
    int filas_utilizadas;

    // El número de columnas empleadas por cada fila, así como las
    // propiedades y los datos de cada fila se están disponibles
    // por los métodos de la clase MiVectorCaracteres

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiMatrizCaracteres() :  filas_utilizadas(0)	{}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	int FilasUtilizadas() {
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// Devuelve el carácter de la casilla ("fila", "columna").
	// PRE: la posición dada por la pareja  ("fila", "columna") es 
	// correcta. Si no, el comportamiento no está definido.

	char Elemento(int fila, int columna) {
		return ((matriz_privada[fila]).Elemento(columna));
	}

	/*****************************************************************/
	// Devuelve una fila completa, la dada por el índice "fila"
	// PRE: la posición dada por "fila" es correcta. 
	// Si no, el comportamiento no está definido.

	MiVectorCaracteres Fila (int indice_fila)
	{
		return (matriz_privada[indice_fila]);
	}

	/*****************************************************************/
	// Añade una fila completa a la matriz. 
	// La nueva fila pasa a ser la última de la matriz.
	// Si no hay espacio, no hace nada. 
	
	void Aniade (MiVectorCaracteres nueva_fila)
	{
		if (filas_utilizadas < MAXIMO_FILAS){
			matriz_privada[filas_utilizadas] = nueva_fila;
			filas_utilizadas++;
		}
	}

	/*****************************************************************/
	// Inserta una fila completa a la matriz. 
	// La nueva fila (dada por "nueva_fila") se coloca en la posición 
	// (indicada por "pos_fila") y la inserción provoca un desplazamiento 
	// de una posición de las filas superiores (incluida la que estaba en 
	// "pos_fila", por supuesto).
	// Si no hay espacio, no hace nada. 

	void Inserta (MiVectorCaracteres nueva_fila, int pos_fila)
	{
		bool hay_sitio = (filas_utilizadas < MAXIMO_FILAS);

		if (pos_fila >= filas_utilizadas) // Si "pos_fila" es demasiado grande 
			pos_fila = filas_utilizadas;  // se considera una adición

		if ((hay_sitio) && (pos_fila>=0)) {

			// "Desplazamiento" de las filas completas
			for (int nueva=filas_utilizadas;nueva>pos_fila; nueva--)
				matriz_privada[nueva] = matriz_privada[nueva-1];

			matriz_privada[pos_fila] = nueva_fila;  // "Inserción"

			filas_utilizadas++;
		}
	}
	/*****************************************************************/
};
///////////////////////////////////////////////////////////////////////

class ImpresorVectorCaracteres
{
private:
	string inicio, final, intermedio;

public:

	ImpresorVectorCaracteres(string cadena_inicio, string cadena_final, 
							 string cadena_intermedio)
		: inicio(cadena_inicio), 
		  final(cadena_final), 
		  intermedio(cadena_intermedio)
	{}

	void Imprime(string mensaje_inicial, MiVectorCaracteres un_vector)
	{		
		int tope = un_vector.TotalUtilizados() - 1;

		cout << mensaje_inicial;
		cout << inicio;

		for (int i=0; i<tope; i++)
			cout << un_vector.Elemento(i) << intermedio;

		cout << un_vector.Elemento(tope) << final << endl;
	}
};
///////////////////////////////////////////////////////////////////////

class LectorVectorCaracteres
{
private:
	char terminador;

public:

	LectorVectorCaracteres(char caracter_terminador) :
	  terminador(caracter_terminador)
	{ }

	MiVectorCaracteres Lee()
	{
		MiVectorCaracteres a_leer;
		char caracter;

		cin >> caracter;
		while (caracter != terminador){
			a_leer.Aniade(caracter);
			cin >> caracter;
		}		
		return a_leer;
	}
};
///////////////////////////////////////////////////////////////////////

class ImpresorMatrizCaracteres
{
private: 

	ImpresorVectorCaracteres output_vector;

public:

	ImpresorMatrizCaracteres(ImpresorVectorCaracteres output_vector_caracteres)
		:output_vector(output_vector_caracteres)
	{
	}

	void Imprime(string mensaje_general, string mensaje_por_fila, 
		         MiMatrizCaracteres una_matriz)
	{	
		cout << mensaje_general << endl;
            
		for (int i=0; i<una_matriz.FilasUtilizadas(); i++){         
			output_vector.Imprime(mensaje_por_fila, una_matriz.Fila(i));
		}
	}

};
///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{
	MiMatrizCaracteres matriz; 
	MiVectorCaracteres una_fila;

	LectorVectorCaracteres		lector_fila ('.');
	ImpresorVectorCaracteres	impresor_fila ("|","|","-");
	ImpresorMatrizCaracteres	impresor_matriz (impresor_fila);

	int num_fila; 

	cout << "Introduzca una cadena --> "; 
	una_fila = lector_fila.Lee();

	while (una_fila.TotalUtilizados() > 0) {
		
		impresor_fila.Imprime ("\nFila: ", una_fila);  
		cout << endl << endl; 

		do{
			cout << "Num, fila donde insertar: ";
			cin >> num_fila; 
		} while (num_fila < 0);

		matriz.Inserta (una_fila, num_fila);
		
		impresor_matriz.Imprime("\nMatriz actual", "\t", matriz);
		cout << endl << endl; 

		cout << "Introduzca una cadena --> "; 
		una_fila = lector_fila.Lee();
	}

	cout << "\n\n";
	system ("pause");

	return (0);
}