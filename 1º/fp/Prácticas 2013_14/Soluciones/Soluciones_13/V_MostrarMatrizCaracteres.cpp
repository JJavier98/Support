/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 5
// EJERCICIOS 11 y 12
//
/*	

	En este programa se resumen las actividades propuestas en los ejercicios 
	11 y 12 de la Relaci�n de Problemas V. Basicamente se trata de imprimir 
	el contenido de una matriz. 
	
	En el ejercicio 11 se pide que se haga recuperando cada fila de la matriz 
	empleando el m�todo Fila(), y mostrando su contenido de dos formas 
	alternativas:
	1)	Con un bucle que vaya recorriendo los caracteres de dicha fila a 
		trav�s del m�todo Elemento().
	2)	Usando la clase ImpresorVectorCaracteres.


	En el ejercicio 12 se pide la clase ImpresorMatricesCaracteres. 
	En la definici�n de �sta se emplea la clase ImpresorVectorCaracteres.

	AMPLIACI�N ADICIONAL: Se ha a�adido la clase LectorVectorCaracteres 
	para que la lectura de cada l�nea de la matriz sea m�s c�moda.

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

	MiVectorCaracteres() 	{
		total_utilizados = 0;
	}

	/*****************************************************************/
	// M�todos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return total_utilizados;
	}

	int Capacidad()
	{
		return TAMANIO;
	}

	/*****************************************************************/
	// A�ade un elemento al vector
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
	// PRE: la posici�n dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no est� definido.

	char Elemento(int indice)
	{
		return vector_privado[indice];
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

    // El n�mero de columnas empleadas por cada fila, as� como las
    // propiedades y los datos de cada fila se est�n disponibles
    // por los m�todos de la clase MiVectorCaracteres

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiMatrizCaracteres() :  filas_utilizadas(0)
	{ }

	/*****************************************************************/

	int FilasUtilizadas() {
		return filas_utilizadas;
	}

	/*****************************************************************/

	char Elemento(int fila, int columna) {
		return (matriz_privada[fila].Elemento(columna));
	}

	/*****************************************************************/

	MiVectorCaracteres Fila(int indice_fila)
	{
		return matriz_privada[indice_fila];
	}

	/*****************************************************************/

	void Aniade(MiVectorCaracteres nueva_fila)
	{
		if (filas_utilizadas < MAXIMO_FILAS){
			matriz_privada[filas_utilizadas] = nueva_fila;
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
	{
	}

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

	/*********************************************************************/

	LectorVectorCaracteres(char caracter_terminador)
		:terminador(caracter_terminador)
	{
	}

	/*********************************************************************/

	char GetTerminador ()
	{
		return (terminador); 
	}

	/*********************************************************************/

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

	/*********************************************************************/

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

	LectorVectorCaracteres		lector_fila ('.');
	ImpresorVectorCaracteres	impresor_fila ("{","}","-");
	ImpresorMatrizCaracteres	impresor_matriz (impresor_fila);

	MiVectorCaracteres una_fila, otra_fila, ultima_fila;   
	MiMatrizCaracteres matriz;   

	cout << "Introduzca una cadena (terminar con " 
		 << lector_fila.GetTerminador() << " )--> ";

	una_fila = lector_fila.Lee();


	cout << "Introduzca otra cadena (terminar con " 
		 << lector_fila.GetTerminador() << " )--> ";

	otra_fila = lector_fila.Lee();


	matriz.Aniade(una_fila);
	matriz.Aniade(otra_fila);

	/*****************************************************************/
	// Impresi�n de una matriz (sin usar ninguna clase)

	cout << "\n------------------------------------------------";
	cout << "\n\nImpresi�n sin clases.\n\n";

	for (int fila=0; fila<matriz.FilasUtilizadas(); fila++){

		// Copiar cada fila en "vector_fila"
		
		MiVectorCaracteres vector_fila = matriz.Fila(fila);

		cout << "\tFila -> ";
		cout << "|";
			
		int tope_columnas =  vector_fila.TotalUtilizados();

		for (int col=0; col < tope_columnas; col++)
			cout << vector_fila.Elemento(col);
      
		cout << "|";
		cout << endl;
	}
   

	/*****************************************************************/
	// Usamos la clase ImpresorVectorCaracteres para mostrar cada fila

	cout << "\n------------------------------------------------";
	cout << "\n\nImpresi�n con ImpresorVectorCaracteres.\n\n";

	for(int fila=0; fila<matriz.FilasUtilizadas(); fila++){

		// Copiar cada fila en "vector_fila"
		
		MiVectorCaracteres vector_fila = matriz.Fila(fila);

		impresor_fila.Imprime("\tUna fila de la matriz --> ", vector_fila);
   }


	/*****************************************************************/
	// Impresi�n usando la clase ImpresionMatrizCaracteres

	cout << "\n------------------------------------------------";
	cout << "\n\nImpresi�n con ImpresionMatrizCaracteres.\n\n";

	impresor_matriz.Imprime("Matriz antes de insertar:", "\t", matriz);
	cout << endl;

	cout << "Introduzca la �ltima cadena (terminar con " 
		 << lector_fila.GetTerminador() << " )--> ";

	ultima_fila = lector_fila.Lee();

	matriz.Aniade(ultima_fila);

	cout << endl;
	impresor_matriz.Imprime("Matriz despu�s de insertar:", "\t", matriz);
	cout << endl;

	/*****************************************************************/

	cout << "\n\n";
	system ("pause");

	return (0);
}