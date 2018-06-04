/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 4
// EJERCICIO 12
//
/*
	Programa que gestiona permutaciones de enteros: colecciones de enteros 
	sin elementos repetidos que coniene TODOS los n�meros entre el m�nimo 
	y el m�ximo de dichos valores.
	Por ejemplo, (2,3,6,5,4) es una permutaci�n correcta, pero no lo es 
	(7,7,6,5) -> el 7 est� repetido, ni tampoco (7,6,4)-> falta el 5.

	La resoluci�n de este programa se realiza usando la clase "Permutacion":

	1) Representaci�n: Usa un vector de la STL como dato miembro privado. 

	2) Ofrece los m�todos:  

	* Permutacion (vector <int> una_permutacion);

	Constructor con argumentos. 
	Recibe un vector de la STL con los valores que forman la permutaci�n.
	PRE: Supondremos que el vector es una permutaci�n correcta. 

	* int Maximo();
	* int Minimo();

	Devuelve el m�ximo / m�nimo de la permutaci�n. 
	PRE: al menos hay un elemento 


	* int NumeroLecturas (void);

	Calcula el n�mero de lecturas de la permutaci�n. 
	Por ejemplo, una permutaci�n de un conjunto de enteros, C = {1,2,...,n} 
	tiene k lecturas, si para leer sus elementos en orden creciente (de 
	izquierda a derecha) tenemos que recorrer la permutaci�n k veces. 
	Por ejemplo, la siguiente permutaci�n del conjunto {0,1,...,8}: 

		4 0 8 1 2 5 3 6 7

	necesita 3 lecturas: en la primera obtendr�amos 0, 1, 2 y 3; en la 
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
	// la permutaci�n (vector de la STL)

	vector <int> vector_privado;

public: 


	/*****************************************************************/
	// Constructor con argumentos
	// PRE: Supondremos que el vector "una_permutacion" es una 
	// permutaci�n correcta. 

	Permutacion (vector <int> una_permutacion) 
	{
		vector_privado = una_permutacion;
	}

	/*****************************************************************/
	// Devuelve el n�mero de elementos de la permutaci�n. 

	int NumElementos()
	{
		return (vector_privado.size());
	}

	/*****************************************************************/
	// Devuelve el m�nimo de la permutaci�n. 
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
	// Devuelve el m�ximo de la permutaci�n. 
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
	// PRE: la posici�n dada por "indice" es correcta.

	int Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Calcula el n�mero de lecturas de la permutaci�n

	int NumeroLecturas (void)
	{	
		int num_elementos = NumElementos();
		int contador = 1; 
		int pos = 0; 


		// Usaremos un ciclo for porque sabemos exactamente los n�meros 
		// que deben buscarse: Minimo(), Minimo()+1,Minimo()+2,...,Maximo()

		for (int n=Minimo(); n<=Maximo(); n++) {

			bool encontrado = false;

			while (!encontrado) {

				if (vector_privado[pos] == n) 
					encontrado = true; 

				else {
					if (pos==num_elementos-1)	// se ha examinado el �ltimo->
						contador++;				// empieza otra lectura.

					pos = (pos+1)%num_elementos; // Incremento de "pos"

					// CLAVE: La operaci�n "% num_elementos" permite que el 
					// siguiente al �ltimo (posici�n = "num_elementos"-1) 
					// sea el primero (posici�n = 0)			
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

	const int MAX_LINE = 10; // Mostrar MAX_LINE n�meros por l�nea 


	// Creaci�n y relleno del vector que formar� la permutaci�n

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

	// Crear una permutaci�n a partir de v --> Constructor 

	Permutacion perm (v);


	// Consultar cu�ntos elementos tiene la permutaci�n

	int tope = perm.NumElementos();
	
	cout << "La permutaci�n tiene " << tope << " elementos." << endl;
	cout << "Rango: " << perm.Minimo() << " - " << perm.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutaci�n

	for (int i=0; i<tope; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm.Elemento(i) << separador;
	}

	cout << endl << endl;


	// Calcular el n�mero de lecturas 

	cout << "La permutaci�n tiene " << perm.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;


	// Segundo ejemplo: una permutaci�n ordenada 

	vector <int> v_ordenado;

	v_ordenado.push_back (3);
	v_ordenado.push_back (4);
	v_ordenado.push_back (5);
	v_ordenado.push_back (6);

	// Crear una permutaci�n a partir de v --> Constructor 

	Permutacion perm_ordenada (v_ordenado);


	// Consultar cu�ntos elementos tiene la permutaci�n

	int tope_ordenada = perm_ordenada.NumElementos();
	
	cout << "La permutaci�n tiene " << tope_ordenada << " elementos.\n";
	cout << "Rango: " << perm_ordenada.Minimo() 
		 << " - " << perm_ordenada.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutaci�n

	for (int i=0; i<tope_ordenada; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_ordenada.Elemento(i) << separador;
	}

	cout << endl << endl;


	// Calcular el n�mero de lecturas 

	cout << "La permutaci�n tiene " << perm_ordenada.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;


	// Tercer ejemplo: una permutaci�n en orden decreciente

	vector <int> v_decreciente;

	v_decreciente.push_back (8);
	v_decreciente.push_back (7);
	v_decreciente.push_back (6);
	v_decreciente.push_back (5);

	// Crear una permutaci�n a partir de v_decreciente --> Constructor 

	Permutacion perm_decreciente (v_decreciente);


	// Consultar cu�ntos elementos tiene la permutaci�n

	int tope_decreciente = perm_decreciente.NumElementos();
	
	cout << "La permutaci�n tiene " << tope_decreciente << " elementos.\n";
	cout << "Rango: " << perm_decreciente.Minimo() 
		 << " - " << perm_decreciente.Maximo() << endl;
	cout << endl;


	// Mostrar los elementos de la permutaci�n

	for (int i=0; i<tope_decreciente; i++) {

		char separador;

		if ((i+1)%MAX_LINE == 0) 
			separador = '\n';
		else 
			separador = ' ';
		cout << setw(4) << perm_decreciente.Elemento(i) << separador;
	}

	cout << endl << endl;


	// Calcular el n�mero de lecturas 


	cout << "La permutaci�n tiene " << perm_decreciente.NumeroLecturas() 
		 << " lecturas." << endl;
	cout << endl << endl;

	cout << "\n\n";
	system ("pause");
}