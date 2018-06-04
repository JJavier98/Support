/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2013-2014
// (C) JUAN CARLOS CUBERO TALAVERA
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS V
// EJERCICIO 4 
//
/*	

	En este programa se reescribe la soluci�n al ejercicio 4 de la relaci�n 
	de problemas V (generador de permutaciones aleatorias) usando como dato 
	miembro de la clase Permutacion un objeto de la clase MiVectorEnteros, 
	en vez de un vector de la STL. 
	Al constructor le seguimos pasando un vector de la STL.

	........................................................................
	RECORDATORIO DEL EJERCICIO V-3:

		Se presenta la clase GeneradorPermutaciones para generar 
		permutaciones aleatorias de un conjunto de enteros entre un valor 
		m�nimo y un valor m�ximo. 
		
		La clase tiene un �nico m�todo: 
		
			Permutacion Genera(int primero, int ultimo)

		d�nde la clase Permutacion es la vista en el problema 12 de la 
		Relaci�n de Ejercicios IV --> La estructura de datos que soporta 
		la permutaci�n es un vector de la STL.
		
		Por ejemplo, si m�nimo = 1 y m�ximo = 6, una permutaci�n v�lida ser�a 
		{3,1,6,4,5,2,3}. Como puede observarse, no pueden aparecer elementos 
		repetidos y deben estar todos los valores entre 1 y 6.

		Evidentemente, se requiere un sistema para generar valore aleatorios. 
		Para ello se dispone de la clase MyRandom (leer explicaciones 
		detalladas en el Gui�n de Pr�cticas)
	........................................................................

	La interfaz p�blica de las clases no cambia:

	MyRandom
		+ MyRandom(int minimo, int maximo)
		+ int Next()
		+ int Min()
		+ int Max()

	Permutacion
		+ Permutacion(vector <int> una_permutacion)
		+ int NumElementos()
		+ int NumeroLecturas()
		+ int Elemento(int indice)
		+ int Minimo()
		+ int Maximo()	

	GeneradorPermutacionesAleatorias
		+ Permutacion Genera(int primero, int ultimo)


*/
/*********************************************************************/


#include <iostream>
#include <iomanip>

#include <cstdlib>	// para "MyRandom"
#include <ctime>

#include <vector>	// para "Permutacion"

using namespace std;


///////////////////////////////////////////////////////////////////////

class MyRandom
{
private:
    int minVal;
    int maxVal;

    void InitMyRandom (void)
    {
        time_t t;
        srand ((int) time(&t));     // Inicializa el generador
                                    // con el reloj del sistema
    }
public:
    MyRandom (int el_minimo, int el_maximo) :
        minVal(el_minimo), maxVal(el_maximo)
    {
        InitMyRandom();

        int no_lo_uso = Next(); // desecho el primero
    }

    int Next() {
        int rango = (maxVal - minVal)+1;
        int v1 = rango * (rand() / (RAND_MAX*1.0));
        int v2 = minVal + (v1 % rango);

        return v2;
    }

    int Min() {
        return minVal;
    }
    int Max() {
        return maxVal;
    }
};

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
	// Devuelve la posicion del m�nimo elemento del vector. 

	int PosicionMinimo()
	{
		int posicion_minimo;

		if (total_utilizados > 0){
			posicion_minimo = 0;
			int minimo = vector_privado[0];

			for (int i=1; i<total_utilizados ; i++)
				if (vector_privado[i] < minimo){
					minimo = vector_privado[i];
					posicion_minimo = i;
				}
		}
		else
			posicion_minimo = -1; 

		return posicion_minimo;
	}

	/*****************************************************************/
	// Devuelve la posicion del m�ximo elemento del vector. 

	int PosicionMaximo()
	{
		int posicion_maximo;

		if (total_utilizados > 0) {
			posicion_maximo = 0;
			int maximo = vector_privado[0];

			for (int i=1; i<total_utilizados ; i++)
				if (vector_privado[i] > maximo){
					maximo = vector_privado[i];
					posicion_maximo = i;
				}
		}
		else
			posicion_maximo = -1; 

		return posicion_maximo;
	}

	/*****************************************************************/
	// Busca el valor "buscado" desde "pos_inicial" y devuelve su 
	// posici�n, o -1 si no lo encuentra. 

    int PosEncontrado(int buscado, int pos_inicial)
	{
        bool encontrado = false;
        int pos_encontrado = -1;
        int tope = total_utilizados;

		int i = pos_inicial; 

        while ((i<tope) && (!encontrado)) {

            if (vector_privado[i] == buscado) {
                pos_encontrado = i;
                encontrado = true;
            }
			else 
				i++;
        }
        return pos_encontrado;
    }

	/*****************************************************************/

};



///////////////////////////////////////////////////////////////////////

class Permutacion
{
	// La clase Permutacion representa una permutaci�n de enteros, 
	// es decir, el conjunto de todos los enteros entre un m�nimo 
	// y un m�ximo sin repetidos y no necesariamente ordenado. 

private:

	// La clase Permutacion tiene un dato miembro de la clase MiVectorEnteros

	MiVectorEnteros permutacion;

	// Los m�todos PosMin(), PosMax(), etc que hab�a privados han desaparecido
	// ya que la responsabilidad de calcular el m�nimo y m�ximo recae en la 
	// clase MiVectorEnteros


public: 

	/*****************************************************************/
	// Constructor con argumentos
	// PRE: Supondremos que el vector "una_permutacion" es una 
	// permutaci�n correcta. 

	Permutacion (vector <int> una_permutacion) 
	{
		int tope = una_permutacion.size();

		for (int i=0; i<tope; i++)
			permutacion.Aniade(una_permutacion[i]);

	}


	/*****************************************************************/
	// Devuelve el n�mero de elementos de la permutaci�n. 

	int NumElementos()
	{
		return permutacion.TotalUtilizados();
	}

	/*****************************************************************/
	// Devuelve el elemento de la posici�n "indice". 
	// PRE: la posici�n dada por "indice" es correcta.

	int Elemento(int indice)
	{
		return permutacion.Elemento(indice);
    }

	/*****************************************************************/
	// Devuelve el m�nimo de la permutaci�n. 

    int Minimo()
	{
        return permutacion.Elemento(permutacion.PosicionMinimo());
    }

	/*****************************************************************/
	// Devuelve el m�ximo de la permutaci�n.

    int Maximo()
	{
        return permutacion.Elemento(permutacion.PosicionMaximo());
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

				if (permutacion.Elemento(pos) == n) 
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


class GeneradorPermutacionesAleatorias 
{

public: 

	/*****************************************************************/

	Permutacion Genera(int primero, int ultimo)
	{
        /*

		Algoritmo:

		* Ir generando todos los enteros entre primero y ultimo 
		  con el generador_aleatorio
		* A�adir a permutados el entero generado, siempre y cuando 
		  no se haya a�adido anteriormente.

		El generador puede generar el mismo n�mero varias veces, 
		por lo que necesitamos llevar la cuenta de cu�les son los 
		que ya se han generado.
		
			Por ejemplo, si primero = 3 y ultimo = 5, necesitaremos 
			el siguiente vector:
				ya_generados = {false, false, false}

			Cuando genere el 5:
				ya_generados = {false, false, true}

			Termino cuando haya generado todos los enteros entre 3 y 5.
            
		En vez de recorrer cada vez que se genera un entero completamente 
		el vector "ya_generados" en busca de alg�n false (indica alg�n hueco), 
		basta con contar cu�ntos enteros distintos llevo generados en cada 
		momento --> total_generados_distintos

            Si, por ejemplo, el primer entero generado es el 4, nos queda:
            permutados = {4, ? , ?}
        */


		int total_generados_distintos = 0;  
		int totales_a_generar = ultimo - primero + 1;
		int generado, indice_generado;

		vector <int> permutados;	// Contendr� el resultado (la permutaci�n)
		vector <bool> ya_generado;	// Vector auxiliar de control      

		// Iniciar el vector de control a false (no se ha registrado 
		// ning�n valor de la permutaci�n)

		for (int i = primero; i <= ultimo; i++)
			ya_generado.push_back(false);


		MyRandom aleatorio(primero, ultimo); // Iniciar el generador aleatorio

		while (total_generados_distintos < totales_a_generar) {

			generado = aleatorio.Next(); // Obtener un nuevo valor aleatorio 
										 // entre "primero" y "ultimo"

			indice_generado = generado - primero;
			// El �ndice de "primero" es 0, el de "primero"+1 es 1, ...
			// Sirve para consultar el vector de control

			// Si no ha sido generado, a�adirlo al vector resultado 
			// Si ha sido generado, no hacer nada: en la siguiente iteraci�n 
			// se generar� otro valor aleatorio.

			if (!ya_generado[indice_generado]){

				total_generados_distintos++;
				ya_generado[indice_generado] = true;
				permutados.push_back(generado);
			}

		} // while (total_generados_distintos < totales_a_generar)
      
		// Crear la permutaci�n con el vector de enteros y devolverla

		Permutacion permutacion(permutados);
		return permutacion;
   }
};

///////////////////////////////////////////////////////////////////////

int main()
{
	const int MAX_LINE = 10; // Mostrar MAX_LINE n�meros por l�nea 

	// Pedir los valores extremos de la permutaci�n

	int minimo, maximo; 

	cout << "Introduzca los dos valores extremos de la permutaci�n: ";
	cin >> minimo >> maximo; 

	if (maximo < minimo) {
		int tmp = maximo; 
		maximo = minimo; 
		minimo = tmp;
	}

	// Crear el objeto generador de permutaciones 
    GeneradorPermutacionesAleatorias gen_permutaciones;


	bool sigo = true; 

	while (sigo) {

		// Observar c�mo act�a el constructor de copia de la clase Permutacion
		Permutacion permutacion(gen_permutaciones.Genera(minimo,maximo));


		// Consultar cu�ntos elementos tiene la permutaci�n

		int tope = permutacion.NumElementos();
	
		cout << "La permutaci�n tiene " << tope << " elementos." << endl;
		cout << "Rango: " << permutacion.Minimo() 
			 << " - " << permutacion.Maximo() << endl;
		cout << endl;


		// Mostrar los elementos de la permutaci�n

		for (int i=0; i<tope; i++) {

			char separador;

			if ((i+1)%MAX_LINE == 0) 
				separador = '\n';
			else 
				separador = ' ';
			cout << setw(4) << permutacion.Elemento(i) << separador;
		}

		cout << endl << endl;
	
		// Pedir otra permutaci�n

		char respuesta;
		cout << "�Generar otra permutaci�n (s)? ";
		cin >> respuesta; 

		if (toupper(respuesta)!='S') 
			sigo = false; 
	}

    cout << "\n\n";

    system("pause");

	return (0);
}