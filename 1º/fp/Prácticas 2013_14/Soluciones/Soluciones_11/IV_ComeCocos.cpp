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
// EJERCICIO 11
//
/*	
	Se presenta la clase "CaminoComeCocos" para representar el camino 
	seguido por el usuario en el juego del ComeCocos (Pac-Man). 
	
	Usa un string como dato miembro privado. 
	
	Como funcionalidad, ofrece m�todos para subir, bajar, ir a la 
	izquierda e ir a la derecha. Estos m�todos �nicamente a�aden  
	el car�cter correspondiente �s�, �b�, �i�, �d� a la cadena privada.

	La clase ofrece tamb�n el m�todo 
	
		int PosicionMovimientosConsecutivos(char c, int n) 

	que calcula la posici�n donde se encuentre la primera secuencia de 
	al menos "n" caracteres consecutivos e iguales a "c".
	Si no la hay, devuelve -1
	
	Por ejemplo, en el camino de abajo, si n = 3, y el movimiento 
	buscado es �s�, entonces dicha posici�n es la 6.
		{�b�,�b�,�i�,�s�,�s�,�b�,�s�,�s�,�s�,�s�,�i�,�i�,�d�}

	Se presentan dos soluciones: 
	
	a) Definiendo una cadena local "a_buscar" con la cadena formada por 
	la secuencia de movimientos a buscar y llamando al m�todo find() de 
	la clase string.

	b) Sin usar find(), accediendo directamente a las componentes de 
	la cadena.
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////

class CaminoComeCocos 
{

private:

	string camino;

public:
	
	/*****************************************************************/
	// Constructor sin argumentos

	CaminoComeCocos() 	{
		camino.clear();
	}

	/*****************************************************************/
	// M�todos de lectura (Get) de los datos individuales 

	int TotalMovimientos()
	{
		return camino.length();
	}

	/*****************************************************************/
	// M�todos de escritura
	
	void AniadirSubir()
	{
		camino.append("s");
	}

	void AniadirBajar()
	{
		camino.append("b");
	}

	void AniadirMoverIzquierda()
	{
		camino.append("i");
	}

	void AniadirMoverDerecha()
	{
		camino.append("d");
	}

	/*****************************************************************/
	// Devuelve el movimiento de la casilla "indice" 
	// PRE: la posici�n dada por "indice" es correcta.

	char GetMovimiento(int indice)
	{
		return camino[indice];
	}

	/*****************************************************************/
	// Calcula y devuelve la posici�n donde se encuentre la primera 
	// secuencia de al menos "n" caracteres consecutivos e iguales a "c".
	// Si no la hay, devuelve -1

	int PosicionMovimientosConsecutivos_Find (char c, int n) 
	{
		string subcadena = "";
		for (int i=1; i<=n;i++) 
			subcadena.append(1,c);

		return (camino.find(subcadena));
	}

	/*****************************************************************/
	// Calcula y devuelve la posici�n donde se encuentre la primera 
	// secuencia de al menos "n" caracteres consecutivos e iguales a "c".
	// Si no la hay, devuelve -1

	int PosicionMovimientosConsecutivos (char c, int n) 
	{

		// la manera m�s sencilla de resolver este problema es mediante un 
		// ciclo que recorra "vector_privado" y en el que cada iteraci�n se 
		// analiza un car�cter. Eso s�, es preciso "recordar" el estado de la 
		// iteraci�n anterior: 
		//
		// Si el car�cter leido en la iteraci�n actual es el dado por "c" 
		//		�fu� el car�cter leido ANTES el dado por "c"?
		//			SI: Seguimos en la secuencia
		//				�Tiene la longitud buscada?
		//					SI: Terminar
		//					NO: Seguimos 
		//			NO: empieza una secuencia
		// Si no,
		//		�fu� el car�ter leido antes el dado por "c"?
		//			SI: ha terminado una secuencia, que no es la soluci�n
		//			NO: Continuar la b�squeda


		// Es posible que el proceso de b�squeda termine antes de recorrer 
		// completamente el vector, por lo que empleamos una variable bool  
		// que se har� TRUE cuando encontremos lo buscado: en este caso, una  
		// secuencia de longitud "n" del car�cter "c"

		bool encontrada_secuencia_n = false; 


		// Es importante establecer los valores iniciales correctamente, y 
		// para eso se trata el primer car�cter de manera especial: 
		//
		// Si es el buscado, empieza una secuencia:
		//		"en_secuencia" ser� TRUE
		//		"init_act"	ser� 0, indicando la posici�n donde empieza la 
		//					secuencia actual. Un valor -1 indica que no se 
		//					est� en una secuencia y que ninguna anterior ha 
		//					verificado la condici�n exigida (longitud >= "n")
		
		bool en_secuencia;
		int	 init_act;

		if (camino[0] == c) {
			
			if (n==1) 
				encontrada_secuencia_n = true; // Caso trivial: para terminar 
			else 
				en_secuencia = true; // empieza una secuencia 
			
			init_act = 0; // posici�n de inicio de la secuencia (0)
		}

		else  {
	
			en_secuencia = false;	// no es est� en una secuencia 
			init_act = -1;
		}



		int pos_lectura = 1;	// Posici�n de lectura (empieza en la posici�n 
								//		1 porque la 0 ya se ha procesado)
		char leido; // caracter leido en cada iteraci�n del ciclo que recorre 
					// el vector --> ser�  "vector_privado[pos_lectura]"


		// La consecuencia de que la b�squeda pueda terminar antes de 
		// recorrer todo el vector (�xito), pero que sea posible tener que 
		// hacer un recorrido completo (fracaso) es que el ciclo est� 
		// controlado por DOS condiciones:
		//
		//	1) Hayan caracteres que leer:	   pos_lectura < total_utilizados
		//	2) No se haya encontrado soluci�n:	      !encontrada_secuencia_n
		//
		// Mientras se satisfagan las dos condiciones debe continuar.
		// 
		// IMPORTANTE: en el momento en el que se encuentra la soluci�n se 
		// termina, no se espera a terminar de procesar la secuencia.


		int total_utilizados = TotalMovimientos();

		while ((pos_lectura<total_utilizados) && (!encontrada_secuencia_n)) {
	
			leido = camino[pos_lectura];

			if (leido == c) 

				if (en_secuencia) { // ((leido == c) && (en_secuencia))
									// Seguimos en la secuencia

					// Comprobar si se puede terminar ya 

					int long_sec_act = pos_lectura - init_act + 1; 

					if (long_sec_act >= n) 
						encontrada_secuencia_n = true; // Para terminar 
					else 
						pos_lectura++;	// seguir leyendo
									
				}

				else {	// ((leido == c) && (!en_secuencia)) 
						// Empieza una nueva secuencia 

					init_act = pos_lectura;	// guardar inicio de secuencia


					// Comprobar si se trata del caso trivial (longitud 1) 

					if (n==1) 
						encontrada_secuencia_n = true; // Para terminar 

					else {	
						en_secuencia = true;	// empieza una secuencia 
						pos_lectura++;
					}

				}

			else // Ahora: leido != c

				if (en_secuencia) { // ((leido != c) && (en_secuencia))
									// Termin� la secuencia
							
					en_secuencia = false;	// termina la secuencia

					init_act = -1;	// No hay (hasta ahora) soluci�n  
					pos_lectura++;	// seguir leyendo... vuelta a empezar

				} 

				else { // ((leido != c) && (!en_secuencia))

					pos_lectura++;	 // avanzar	
				}

		} // while (pos_lectura < total_utilizados)
 

		// Antes de devolver "init_act" es preciso comprobar si se encontr� la
		// secuencia buscada. Considere el caso de buscar una secuencia del 
		// �ltimo car�cter del vector con una longitud mayor que la que hay 
		// realmente. P.e. en "abbbass" la b�squeda de una secuencia con 
		// c='s' y n=3 deber�a dar -1 (no hay tal secuencia). 
		// Si no se comprueba "encontrada_secuencia_n", como al terminar el 
		// ciclo se est� en la secuencia, "init_act" != -1 y devuelve un valor 
		// err�neo. As�, la comprobaci�n siguiente es NECESARIA:  

		if (encontrada_secuencia_n) 
			return (init_act);
		else 
			return (-1); 

	}

	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/

int main()
{

	CaminoComeCocos un_juego;

	// A�adir los movimientos realizados 
	// Objetivo: {�b�,�b�,�i�,�s�,�s�,�b�,�s�,�s�,�s�,�s�,�i�,�i�,�d�}

	un_juego.AniadirBajar();   
	un_juego.AniadirBajar();  
	un_juego.AniadirMoverIzquierda();
	un_juego.AniadirSubir();
	un_juego.AniadirSubir();  
	un_juego.AniadirBajar();  
	un_juego.AniadirSubir();
	un_juego.AniadirSubir();
	un_juego.AniadirSubir();  
	un_juego.AniadirSubir();
	un_juego.AniadirMoverIzquierda();
	un_juego.AniadirMoverIzquierda();
	un_juego.AniadirMoverDerecha();

	cout  << "Secuencia de : \n";	

	// Mostrar los movimientos registrados

	int tope = un_juego.TotalMovimientos();

	for (int i=0; i<tope; i++)
		cout  << setw(4) << i;	
	cout << endl; 

	for (int i=0; i<tope; i++)
		cout  << setw(4) << un_juego.GetMovimiento(i);	
	cout << endl; 


	// Prueba exhaustiva de PosicionMovimientosConsecutivos()

	cout << endl;

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos ('s', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos ('s', n) 
			  << endl;  
	cout << endl; 

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos ('b', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos ('b', n) 
			  << endl;  
	cout << endl; 

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos ('i', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos ('i', n) 
			  << endl;  
	cout << endl; 

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos ('d', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos ('d', n) 
			  << endl;  
	cout << endl; 


	// Prueba exhaustiva de PosicionMovimientosConsecutivos_Find()

	cout << endl;

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos_Find ('s', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos_Find ('s', n) 
			  << endl;  
	cout << endl; 

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos_Find ('b', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos_Find ('b', n) 
			  << endl;  
	cout << endl; 

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos_Find ('i', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos_Find ('i', n) 
			  << endl;  
	cout << endl; 

	for (int n=1; n<=5; n++) 
		cout  << "PosicionMovimientosConsecutivos_Find ('d', " << n << ") = " 
		      <<setw(3)<< un_juego.PosicionMovimientosConsecutivos_Find ('d', n) 
			  << endl;  
	cout << endl; 


	cout << "\n\n";
	system ("pause");
}