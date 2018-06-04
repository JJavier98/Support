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
// EJERCICIO 5
//
/*	
	Se presenta la clase "ConjuntoOrdenado", que permite almacenar una 
	secuencia ordenada de n�meros enteros sin repeticiones. 
	
	Ofrece m�todos para realizar las operacionne t�picas sobre conjuntos: 
	
		*	A�adir un entero (de forma ordenada y sin almacenar repetidos).
		*	Calcular la uni�n con otro conjunto. 
			En la uni�n se deben incluir los elementos que est�n en 
			cualquiera de ellos.
		*	Calcular la intersecci�n con otro conjunto. 
			En la intersecci�n se deben incluir los elementos que sean 
			comunes a ambos conjuntos.
*/
/*********************************************************************/


#include <iostream>
#include <iomanip>

#include <vector>	// para "ConjuntoOrdenado"
#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////////


class ConjuntoOrdenado 
{
	// La clase ConjuntoOrdenado representa una colecci�n ordenada 
	// de enteros sin repetidos. 

private:

	// La estructura de datos empleada para guardar la colecci�n  
	// es un vector de la STL

	vector <int> vector_privado;

public: 

	/*****************************************************************/
	// Constructores 
	
	// Constructor sin argumentos: crea un conjunto vac�o

	ConjuntoOrdenado (void) {}

	// Constructor a partir de un vector de la STL
	// PRE: Supondremos que el vector "coleccion" contiene una colecci�n 
	//		v�lida (ordenada y sin elementos repetidos). 

	ConjuntoOrdenado (vector <int> coleccion) 
	{
		vector_privado = coleccion;
	}

	/*****************************************************************/
	// Consulta el estado (vac�o/con datos) de un conjunto 

	bool EstaVacio (void)
	{
		return (vector_privado.empty()); 
	}

	/*****************************************************************/
	// Devuelve el tama�o de un conjunto 

	int Tamanio (void)
	{
		return (vector_privado.size()); 
	}

	/*****************************************************************/
	// Consulta si el cojunto contiene un valor dado 	

	bool Contiene (int dato)
	{
		int posicion = Busca (dato);
		return (posicion != -1);
	}

	/*****************************************************************/
	// A�ade "valor" al conjunto 
	// Si "valor" existe, no hace nada.

	void Aniade (int nuevo_valor)
	{
		int total_utilizados = vector_privado.size(); // Num. elementos
 
		bool sigo = true;
		bool encontrado = false; 
		bool insertado  = false; 

		int pos = 0; // posicion  a explorar

		while ((pos < total_utilizados) && (sigo)) {

			if (vector_privado[pos] < nuevo_valor) // Seguir buscando
				
				pos++;

			else {				
				// Si el valor de "pos" es mayor o igual que "nuevo_valor" se 
				// termina la b�squeda: 
				// * Si es igual, el conjunto contiene a "dato"--> no insertar
				// * Si es mayor, no lo contiene (no puede esar en posiciones
				//		m�s altas porque los datos est�n ordenados)-->insertar
				
				sigo = false;	

				if (vector_privado[pos] > nuevo_valor) {
					
					vector_privado.push_back(0); // valor fict�cio
					total_utilizados++;

					// Desplazar hacia la derecha los valores mayores 
					// que el que se va a insertar

					for (int i=total_utilizados-1; i>pos; i--)
						vector_privado[i]=vector_privado[i-1];

					vector_privado[pos] = nuevo_valor; // copiar en su lugar

					insertado = true; 
				}
				else 
					encontrado = true; 

			} // else 

		} // while 

		if (!encontrado && !insertado) {

			if (total_utilizados == 0) // El conjunto estaba vac�o
				vector_privado.push_back (nuevo_valor);

			else // El nuevo valor es mayor que el �ltimo del vector
				vector_privado.push_back (nuevo_valor);

		} // if (!encontrado)

	}

	/*****************************************************************/
	// Consulta si el conjunto contiene un valor dado 	

	void Pinta (string mensaje)
	{
		int tope = vector_privado.size(); // Num. elementos

		cout << endl << endl; 
		cout << mensaje << endl;   
		for (int i=0; i < tope; i++) {
			cout << setw (4) << vector_privado[i] << ","; 
		}
		cout << endl << endl; 
	}

	/*****************************************************************/
	// Union de Conjuntos

	ConjuntoOrdenado Union (ConjuntoOrdenado otro)
	{
		ConjuntoOrdenado tmp; 

		// Inicialmente contendr� lo mismo que el objeto impl�cito
		tmp.vector_privado = vector_privado;


		// Recorrer el conjunto "otro" 

		int num_elementos_en_otro = otro.vector_privado.size();

		for (int pos=0; pos<num_elementos_en_otro; pos++) {
			
			int elemento_en_otro = (otro.vector_privado)[pos];

			if (!Contiene(elemento_en_otro))	// Si no est�, se a�ade
				tmp.Aniade (elemento_en_otro);
		}

		return (tmp);
	}

	/*****************************************************************/
	// Intersecci�n de Conjuntos

	ConjuntoOrdenado Interseccion (ConjuntoOrdenado otro)
	{
		ConjuntoOrdenado tmp; // Inicialmente estar� vac�o

		// Recorrer el objeto impl�cito 

		int num_elementos = vector_privado.size();

		for (int pos=0; pos<num_elementos; pos++) {
			
			int elemento = vector_privado[pos];

			if (otro.Contiene(elemento))	// Si est�, se a�ade
				tmp.Aniade (elemento);
		}

		return (tmp);
	}

	/*****************************************************************/

private: 

	/*****************************************************************/
	// Consulta si el cojunto contiene un valor dado 	
	// Devuelve la posici�n del dato, y si no est� devuelve -1

	int Busca (int dato)
	{
		int tope = vector_privado.size(); // Num. elementos

		bool sigo = true;
		bool encontrado = false; 

		int pos = 0; // posicion  a explorar

		while ((pos < tope) && (sigo)) {

			if (vector_privado[pos] < dato) // Seguir buscando
				
				pos++;

			else {				
				// Si el valor de "pos" es mayor o igual que "valor" se 
				// termina la b�squeda: 
				// * Si es igual, el conjunto contiene a "dato".
				// * Si es mayor, no lo contiene (no puede esar en posiciones
				//		m�s altas porque los datos est�n ordenados).
				
				sigo = false;	

				if (vector_privado[pos] == dato) 
					encontrado = true;

			} // else 

		} // while 

		if (encontrado)
			return (pos);
		else 
			return (-1);

	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

int main()
{
	// Crear ConjuntoOrdenado y hacer m�ltiples adiciones 
	
	ConjuntoOrdenado c1; 

	if (c1.EstaVacio())
		cout << "c1 esta vacio. " << endl; 
	else 
		cout << "c1 NO esta vacio. " << endl; 

	c1.Aniade (2);
	c1.Aniade (4);
	c1.Aniade (7);
	c1.Aniade (6);
	c1.Aniade (1);
	c1.Aniade (3);
	c1.Pinta("Conjunto c1 tras aniadir 2, 4, 7, 6, 1 y 3");


	// Crear ConjuntoOrdenado desde un vector de la STL

	vector <int> v;
	v.push_back (1);
	v.push_back (3);
	v.push_back (5);
	v.push_back (7);   

	ConjuntoOrdenado c2 (v); 
	c2.Pinta("Conjunto c2 creado desde un vector con 1, 3, 5 y 7");


	// Prueba de la uni�n de conjuntos 
	
	ConjuntoOrdenado c3 = c1.Union (c2);
	c3.Pinta("Conjunto c3 tras c1 UNION c2");


	// Prueba de la intersecci�n de conjuntos 
	
	ConjuntoOrdenado c4 = c1.Interseccion (c2);
	c4.Pinta("Conjunto c4 tras c1 INTERSECCION c2");

    system("pause");

	return (0);
}