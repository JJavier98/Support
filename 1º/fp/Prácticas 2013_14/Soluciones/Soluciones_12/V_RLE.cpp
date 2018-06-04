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
// EJERCICIO 1 
//
/*	
	Se presenta la clase RLE. Esta clase tiene como objetivo proporcionar 
	facilidades para codificar/descodificar una secuencia aplicando el 
	algoritmo RLE (ya se trabaj� sobre este algoritmo en el ejercicio 
	22 de la Relaci�n de Problemas II). 

		El m�todo RLE (Run Length Encoding) codifica una secuencia de datos 
		formada por series de valores id�nticos consecutivos como una 
		secuencia de parejas de n�meros(valor de la secuencia y n�mero de 
		veces que se repite). 

	Los m�todos a implementar tendr�n las siguientes cabeceras:

		MiVectorEnteros Codifica (MiVectorEnteros secuencia_descodificada); 

			Por ejemplo, la llamada al m�todo Codifica() pas�ndole como 
			par�metro el vector (1 1 1 2 2 2 2 2 3 3 3 3 3 3 5) debe 
			devolver el vector (3 1 5 2 6 3 1 5) 

		MiVectorEnteros Descodifica (MiVectorEnteros secuencia_codificada); 

			El m�todo Descodifica() hace justo lo contrario: la llamada al 
			m�todo Codifica() pas�ndole como par�metro el vector 
			(1 1 1 2 2 2 2 2 3 3 3 3 3 3 5) debe devolver (3 1 5 2 6 3 1 5) 

	Esta clase se prueba en un progama que lee una secuencia codificada, 
	la descodifica y la imprime en pantalla. 

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

	MiVectorEnteros() : total_utilizados(0) 
	{
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
	
	void Aniade(int nuevo)
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

	int Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Calcula si dos objetos son iguales: si contienen el mismo n�mero 
	// de elementos, son iguales y est�n en el mismo orden.

	bool EsIgualA (MiVectorEnteros otro)
	{
		bool son_iguales; 
		
		if (total_utilizados == otro.total_utilizados) {
			
			son_iguales = true; 

			int pos = 0; 
			bool sigo_comparando = true; 
			
			while ((pos < total_utilizados) && (sigo_comparando)) {

				if (vector_privado[pos] == otro.vector_privado[pos]) {
					pos++;
				}
				else {
					sigo_comparando = false; 
					son_iguales = false;
				}

			} // while (sigo_comparando)

		}
		else son_iguales = false; // tienen distinto tama�o

		return (son_iguales);
	}


};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class RLE
{ 

private: 

public:
	
	MiVectorEnteros Codifica (MiVectorEnteros secuencia_descodificada)
	{
		// Secuencia resultado de la codificaci�n
		MiVectorEnteros secuencia_codificada; 

		int tope, actual, anterior, iguales_hasta_ahora;

		// Registrar la longitud de la secuencia
		tope = secuencia_descodificada.TotalUtilizados();

		// Registrar el primer valor de la secuencia
		actual = secuencia_descodificada.Elemento(0);

		iguales_hasta_ahora = 1;

		for (int pos=1; pos<tope; pos++) {

			anterior = actual;
			actual = secuencia_descodificada.Elemento(pos);

			if (anterior == actual)

				iguales_hasta_ahora++; // Continua la serie

			else {

				// A�ade la pareja (valor, num.repeticiones)
				secuencia_codificada.Aniade(iguales_hasta_ahora);
				secuencia_codificada.Aniade(anterior);
				
				iguales_hasta_ahora = 1; // empezar una nueva serie				
			}
		} // for (int pos=1; pos<tope; pos++)

		// A�ade la �ltima pareja (valor, num.repeticiones)
		secuencia_codificada.Aniade(iguales_hasta_ahora);
		secuencia_codificada.Aniade(actual);

		return (secuencia_codificada); 
	}   

	/*****************************************************************/

	MiVectorEnteros Descodifica (MiVectorEnteros secuencia_codificada)
	{
		// Secuencia resultado de la descodificaci�n
		
		MiVectorEnteros secuencia_descodificada; 

		// Registrar el n�mero de elementos de la secuencia codificada. 

		int tope = secuencia_codificada.TotalUtilizados();

		// Ciclo que recorre la secuencia codificada. 
		// La longitud de la secuencia es par (est� formada por parejas) as� 
		// que el n�mero de parejas es justo la mitad del n�mero de elementos. 
		// Observad que el salto se realiza de 2 en 2 porque en cada iteraci�n 
		// se procesa una pareja. 

		for (int pos=0; pos<tope; pos+=2) {

			int num_repeticiones = secuencia_codificada.Elemento(pos);
			int valor = secuencia_codificada.Elemento(pos+1);
	
			// Cada pareja es (num_repeticiones, valor)

			for (int i=0; i<num_repeticiones; i++) 
				secuencia_descodificada.Aniade(valor);
		}
		
		return (secuencia_descodificada);
	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


/*********************************************************************/

int main()
{

	const int TERMINADOR = -1;  // Valor que act�a como "terminador" 
								// para la lectura de datos.
	const int MAX_LINE = 10;    // N�mero de datos por l�nea para 
								// mostrar el contenido de un vector.


	MiVectorEnteros	secuencia_original; // Vector a codificar 


	// Lectura del vector original 

	cout << "\n\nIntroduzca secuencia de enteros (terminar con -1): \n";

	int entero_leido;

	cin >> entero_leido; 

	while (entero_leido != TERMINADOR){

		secuencia_original.Aniade(entero_leido);
		cin >> entero_leido; 
	}
	cout << endl << endl;


	// Se muestra el vector original 

	cout << "\n\nSecuencia original: \n";

	int tope = secuencia_original.TotalUtilizados();
	char separador;

	for (int i=0; i<tope; i++) {
		if ((i+1)%MAX_LINE == 0)  separador = '\n';
		else  separador = ' ';
		cout << setw(4) << secuencia_original.Elemento(i) << separador;
	}
	cout << endl << endl;



	// Prueba de los m�todos Codifica() y Desodifica() 
	// 
	// Declararemos un objeto de la clase RLE al que llamaremos "gestor_RLE" 
	// que emplearemos para codificar/descodificar una secuencia.

	RLE gestor_RLE; // Objeto codificador/descodificador

	MiVectorEnteros secuencia_codificada;		// Serie codificada 
	MiVectorEnteros secuencia_descodificada;	// Serie descodificada

	// Codificaci�n--> gestor_RLE.Codifica() 
	secuencia_codificada = gestor_RLE.Codifica(secuencia_original);

	// Descodificaci�n--> gestor_RLE.Descodifica() 
	secuencia_descodificada = gestor_RLE.Descodifica(secuencia_codificada);


	// Presentaci�n de resultados

	// Secuencia codificada 

	cout << "\n\nSecuencia codificada: \n";

	tope = secuencia_codificada.TotalUtilizados();

	for (int i=0; i<tope; i++) {
		if ((i+1)%MAX_LINE == 0)  separador = '\n';
		else  separador = ' ';
		cout << setw(4) << secuencia_codificada.Elemento(i) << separador;
	}
	cout << endl << endl;


	// Secuencia descodificada 

	cout << "\n\nSecuencia descodificada: \n";

	tope = secuencia_descodificada.TotalUtilizados();

	for (int i=0; i<tope; i++) {
		if ((i+1)%MAX_LINE == 0)  separador = '\n';
		else  separador = ' ';
		cout << setw(4) << secuencia_descodificada.Elemento(i) << separador;
	}
	cout << endl << endl;


	// Prueba de EsIgualA()

	if (secuencia_original.EsIgualA (secuencia_descodificada))
		cout << "Codificaci�n/descodificaci�n CORRECTA\n";
	else
		cout << "Codificaci�n/descodificaci�n INCORRECTA\n";
	cout << endl;

	cout << endl << endl;

	system ("pause");

	return (0);
}