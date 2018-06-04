/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 5
// EJERCICIOS 9 y 10 
//
/*	
	En este ejercico se amplía funcionalidad ofrecida por la clase <básica> 
	MiVectorEnteros con las clases: 
	
	*	ImpresorVectorEnteros: para imprimir los datos de un objeto de 
		la clase MiVectorEnteros.

	*	LectorVectorEnteros: para leer los datos de un objeto de la clase 
		MiVectorEnteros.

*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////

class MiVectorEnteros 
{

private:

	static const int TAMANIO = 50;
	int vector_privado[TAMANIO];
	int total_utilizados;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	MiVectorEnteros() 
	{
		total_utilizados = 0;
	}

	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	int TotalUtilizados()
	{
		return total_utilizados;
	}

	int Capacidad()
	{
		return TAMANIO;
	}

	/*****************************************************************/
	// Añade un elemento al vector
	// PRE: hay espacio para el nuevo elemento.
	// Si no lo hay, no hace nada.
	
	void Aniade(int nuevo)
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

	int Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
};

///////////////////////////////////////////////////////////////////////

class ImpresorVectorEnteros
{
private:

	const int MAX_LINE; // Mostrar MAX_LINE números por línea 

public:

	/*****************************************************************/
	// Constructor sin argumentos: fija el valor 10 como valor por defecto 
	// para la constante MAX_LINE

	ImpresorVectorEnteros (void) : MAX_LINE (10)
	{
	}

	/*****************************************************************/
	// Constructor con argumentos: fija el valor de la constante MAX_LINE

	ImpresorVectorEnteros (int datos_por_linea): MAX_LINE (datos_por_linea)
	{
	}

	/*****************************************************************/
	
	void Imprime(string mensaje, MiVectorEnteros un_vector) 
	{
		int tope = un_vector.TotalUtilizados();
		char separador;

		cout << mensaje << endl;

		for (int i=0; i<tope; i++) {

			if ((i+1)%MAX_LINE == 0) 
				separador = '\n';
			else 
				separador = ' ';

			cout << setw(4) << un_vector.Elemento(i) << separador;
		}

		cout << endl << endl;

	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

class LectorVectorEnteros
{ 

private: 

	const int TERMINADOR; // Valor que actúa como "terminador" en la lectura

public:

	/*****************************************************************/
	// Constructor con argumentos. 
	// Fija el valor de la constante TERMINADOR.

	LectorVectorEnteros (int terminador_datos) : TERMINADOR(terminador_datos)
	{
	}

	/*****************************************************************/
	// Devuelve el valor de la constante TERMINADOR.

	int GetTerminador (void)
	{
		return (TERMINADOR);
	}


	/*****************************************************************/
	// Método general de lectura, controladop por el terminador 
	// especificado en la constante TERMINADOR. 
	// NOTA: No hay filtro en la lectura de los datos del vector. 
	// Si se quisiera un filtro, debería escribirse un método específico 
	// adaptado a los valores buscados.  

	MiVectorEnteros LeeVector()
	{
		MiVectorEnteros vector_leido;
		int entero_leido;

		cin >> entero_leido; 

		while (entero_leido != TERMINADOR){

			vector_leido.Aniade(entero_leido);
			cin >> entero_leido; 
		}

		return vector_leido;
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////


/*********************************************************************/

int main()
{

	// Vector pensado para elementos positivos (o cero). 
	// Termina la lectura al introducir "-1". 
	// CUIDADO: Se usa el método genérico de lectura, por lo que no hay 
	// filtro, lo que significa que puede leer y aceptar cualquier valor. 

	MiVectorEnteros			edades; 
	LectorVectorEnteros		lector_edades (-1); 
	ImpresorVectorEnteros	impresor_edades; 

	cout << "Introduzca edades (terminar con " 
		 << lector_edades.GetTerminador() << ") "<< endl; 

	edades = lector_edades.LeeVector();
	impresor_edades.Imprime("Vector de edades", edades);


	// Vector pensado para elementos comprendidos en [-10, 10]. 
	// Termina la lectura al introducir "99". 
	// CUIDADO: Se usa el método genérico de lectura, por lo que no hay 
	// filtro, lo que significa que puede leer y aceptar cualquier valor. 

	MiVectorEnteros			en_rango; 
	LectorVectorEnteros		lector_en_rango (99); 
	ImpresorVectorEnteros	impresor_en_rango; 

	cout << "Introduzca valores entre -20 y 20 (terminar con " 
		 << lector_en_rango.GetTerminador() << ") "<< endl; 

	en_rango = lector_en_rango.LeeVector();
	impresor_en_rango.Imprime("Vector con valores entre -20 y 20", en_rango);

	cout << "\n\n";
	system ("pause");

	return (0);
}