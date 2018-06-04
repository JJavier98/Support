/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 4
// EJERCICIO 12
//
/*
	Programa que gestiona permutaciones de enteros: colecciones de enteros 
	sin elementos repetidos que coniene TODOS los números entre el mínimo 
	y el máximo de dichos valores.
	Por ejemplo, (2,3,6,5,4) es una permutación correcta, pero no lo es 
	(7,7,6,5) -> el 7 está repetido, ni tampoco (7,6,4)-> falta el 5.

	La resolución de este programa se realiza usando la clase "Permutacion":

	1) Representación: Usa un vector de la STL como dato miembro privado. 

	2) Ofrece los métodos:  

	* Permutacion (vector <int> una_permutacion);

	Constructor con argumentos. 
	Recibe un vector de la STL con los valores que forman la permutación.
	PRE: Supondremos que el vector es una permutación correcta. 

	* int Maximo();
	* int Minimo();

	Devuelve el máximo / mínimo de la permutación. 
	PRE: al menos hay un elemento 


	* int NumeroLecturas (void);

	Calcula el número de lecturas de la permutación. 
	Por ejemplo, una permutación de un conjunto de enteros, C = {1,2,...,n} 
	tiene k lecturas, si para leer sus elementos en orden creciente (de 
	izquierda a derecha) tenemos que recorrer la permutación k veces. 
	Por ejemplo, la siguiente permutación del conjunto {0,1,...,8}: 

		4 0 8 1 2 5 3 6 7

	necesita 3 lecturas: en la primera obtendríamos 0, 1, 2 y 3; en la 
	segunda 4, 5, 6 y 7; finalmente, en la tercera, 8.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>

#include <vector>	// Para la almacenar los valores calculados

using namespace std;

///////////////////////////////////////////////////////////////////////

class Permutacion
{

private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// la permutación (vector de la STL)

	vector <int> vector_privado;

public: 


	/*****************************************************************/
	// Constructor con argumentos
	// PRE: Supondremos que el vector "una_permutacion" es una 
	// permutación correcta. 

	Permutacion (vector <int> una_permutacion) 
	{
		vector_privado = una_permutacion;
	}

	/*****************************************************************/
	// Devuelve el número de elementos de la permutación. 

	int NumElementos()
	{
		return (vector_privado.size());
	}

	/*****************************************************************/
	// Devuelve el mínimo de la permutación. 
	// PRE: al menos hay un elemento 

	int Minimo()
	{
		int min = vector_privado[0];
		int tope = vector_privado.size();

		for (int i=1; i<tope; i++) 
			if (vector_privado[i] < min) 
				min = vector_privado[i];

		return (min);
	}

	/*****************************************************************/
	// Devuelve el máximo de la permutación. 
	// PRE: al menos hay un elemento 

	int Maximo()
	{
		int max = vector_privado[0];
		int tope = vector_privado.size();

		for (int i=1; i<tope; i++) 
			if (vector_privado[i] > max) 
				max = vector_privado[i];

		return (max);
	}

	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.

	int Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Calcula el número de lecturas de la permutación

	int NumeroLecturas (void)
	{	
		int num_elementos = NumElementos();
		int contador = 1; 
		int pos = 0; 


		// Usaremos un ciclo for porque sabemos exactamente los números 
		// que deben buscarse: Minimo(), Minimo()+1,Minimo()+2,...,Maximo()

		for (int n=Minimo(); n<=Maximo(); n++) {

			bool encontrado = false;

			while (!encontrado) {

				if (vector_privado[pos] == n) 
					encontrado = true; 

				else {
					if (pos==num_elementos-1)	// se ha examinado el último->
						contador++;				// empieza otra lectura.

					pos = (pos+1)%num_elementos; // Incremento de "pos"

					// CLAVE: La operación "% num_elementos" permite que el 
					// siguiente al último (posición = "num_elementos"-1) 
					// sea el primero (posición = 0)			
				}

			} //while (!encontrado)

		} // for (int n=Minimo(); n<=Maximo(); n++) 

		return (contador); 
	}
	
	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

int main()
{

	const int MAX_LINE = 10; // Mostrar MAX_LINE números por línea 


	// Creación y relleno del vector que formará la permutación

	vector <int> v;

	v.push_back (4);
	v.push_back (0);
	v.push_back (8);
	v.push_back (1);
	v.push_back (2);
	v.push_back (5);
	v.push_back (3);
	v.push_back (6);
	v.push_back (7);

	// Crear una permutación a partir de v --> Constructor 

	Permutacion perm (v);


	// Consultar cuántos elementos tiene la permutación

	int tope = perm.NumElementos();
	
	cout << "La permutación tiene " << tope << " elementos." << endl;
	cout << "Rango: " << perm.Minimo() << " - " << perm.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutación

	for (int i=0; i<tope; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm.Elemento(i) << separador;
	}

	cout << endl << endl;


	// Calcular el número de lecturas 

	cout << "La permutación tiene " << perm.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;


	// Segundo ejemplo: una permutación ordenada 

	vector <int> v_ordenado;

	v_ordenado.push_back (3);
	v_ordenado.push_back (4);
	v_ordenado.push_back (5);
	v_ordenado.push_back (6);

	// Crear una permutación a partir de v --> Constructor 

	Permutacion perm_ordenada (v_ordenado);


	// Consultar cuántos elementos tiene la permutación

	int tope_ordenada = perm_ordenada.NumElementos();
	
	cout << "La permutación tiene " << tope_ordenada << " elementos.\n";
	cout << "Rango: " << perm_ordenada.Minimo() 
		 << " - " << perm_ordenada.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutación

	for (int i=0; i<tope_ordenada; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_ordenada.Elemento(i) << separador;
	}

	cout << endl << endl;


	// Calcular el número de lecturas 

	cout << "La permutación tiene " << perm_ordenada.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;


	// Tercer ejemplo: una permutación en orden decreciente

	vector <int> v_decreciente;

	v_decreciente.push_back (8);
	v_decreciente.push_back (7);
	v_decreciente.push_back (6);
	v_decreciente.push_back (5);

	// Crear una permutación a partir de v_decreciente --> Constructor 

	Permutacion perm_decreciente (v_decreciente);


	// Consultar cuántos elementos tiene la permutación

	int tope_decreciente = perm_decreciente.NumElementos();
	
	cout << "La permutación tiene " << tope_decreciente << " elementos.\n";
	cout << "Rango: " << perm_decreciente.Minimo() 
		 << " - " << perm_decreciente.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutación

	for (int i=0; i<tope_decreciente; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_decreciente.Elemento(i) << separador;
	}

	cout << endl << endl;


	// Calcular el número de lecturas 


	cout << "La permutación tiene " << perm_decreciente.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;

	cout << "\n\n";
	system ("pause");
}