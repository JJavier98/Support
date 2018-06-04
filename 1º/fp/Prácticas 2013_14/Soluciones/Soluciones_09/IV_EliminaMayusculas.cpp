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
// EJERCICIOS 5 y 6
//
/*	
	En este ejercico se ampl�a la clase MiVectorCaracteres con el m�todo:
	
		void EliminaMayusculas (void) 
		
	para eliminar todas las may�sculas del vector. 

	Se presentan dos versiones de este m�todo, 
	
	1) Ineficiente 
		Se realiza un borrado f�sico de cada may�scula detectada empleando 
		el m�todo Elimina(). Cada borrado supone el desplazamiento de los 
		elementos situados en posiciones superiores. 

	2) Eficiente 
		Realiza un borrado f�sico, aunque ahora se emplean dos variables que 
		act�an como apuntadores, para indicar la posici�n de lectura y la 
		posici�n de escritura, respectivamente.

*/
/*********************************************************************/

#include <iostream>
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

	MiVectorCaracteres() 
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
	// Eliminar el car�cter que se encuentre en la posici�n dada por 
	// "indice_componente".
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n).
	// PRE: la posici�n dada por "posicion" es correcta.
	// Si no es correcta, no hace nada.

	void Elimina (int posicion) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posici�n a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((posicion >= 0) && (posicion < total_utilizados)) {

			int tope = total_utilizados-1; // posici�n del �ltimo 
    
			for (int i = posicion ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}

		// Nota:
		// La asignaci�n
		//    vector_privado[i] = vector_privado[i+1];
		// podr�a cambiarse por:
		//    Modifica(i, Elemento(i+1));
		// Hemos preferido acceder directamente a las componentes con la 
		// notaci�n en corchete para aumentar la eficiencia del m�todo 
		// Elimina() evitando usar m�todos lo que conllevar�a a una 
		// sobrecarga de procesamiento: llamada, paso de argumentos, 
		// gesti�n de los entornos en la pila, retorno,...
	}

	/*****************************************************************/
	// Eliminar los caracteres may�scula del vector.
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n) usando 
	// el m�todo Elimina().
	// Versi�n ineficiente

	void EliminaMayusculasIneficiente()
	{
 		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual es may�scula
					Elimirla (llamar al m�todo Elimina())
				en otro caso
					Pasar a la siguiente componente

			Actualizar el n�mero de componentes utilizadas
		*/

		int i = 0;

		while (i < total_utilizados){
			if (isupper(vector_privado[i]))
				Elimina(i);
			else
				i++;
		}

		/*
			Hay que prestar atenci�n y no cometer el error mostrado a 
			continuaci�n, muy frecuente entre los proncipiantes: 
			El siguiente bucle es incorrecto porque cuando ha borrado 
			una may�scula, NO debe avanzar i

			for (int i=0; i<total_utilizados; i++)
				if (isupper(vector_privado[i]))
					Elimina(i);
		*/
	}

	/*****************************************************************/
	// Eliminar los caracteres may�scula del vector.
	// Realiza un borrado f�sico usando dos apuntadores para indicar la 
	// posici�n de lectura y la posici�n de escritura, respectivamente.
	// Versi�n eficiente

	void EliminaMayusculas()
	{
		int pos_escritura,  // posici�n donde escribir 
			pos_lectura;	// posici�n d�nde leer 

		/* Algoritmo: 

			Recorrer todas las componentes que hay en el vector
				Si la componente actual no es may�scula
					ponedla d�nde indique pos_escritura
				Avanzar pos_lectura

			Actualizar el n�mero de componentes utilizadas
		*/

		pos_escritura = 0;		
		
		for (pos_lectura = 0; pos_lectura < total_utilizados; pos_lectura++){

			if (islower(vector_privado[pos_lectura])) {

				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				pos_escritura++;					

			}	// OJO: "pos_lectura" SIEMPRE avanza (for), mientras que
				// "pos_escritura" solo lo hace cuando encuentra min�sculas.
		}

		total_utilizados = pos_escritura;
	}

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/


int main()
{

	MiVectorCaracteres vector;
	int tope;


	// A�adir datos al vector

	vector.Aniade('h');   
	vector.Aniade('E');
	vector.Aniade('L');
	vector.Aniade('o');
	vector.Aniade('l');
	vector.Aniade('L');
	vector.Aniade('O');
	vector.Aniade('a');


	cout  << "Vector original: \n";	

	// Mostrar el contenido del vector

	tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	
	cout << endl; 


	// Eliminar las may�sculas
	cout << endl; 
	cout  << "Eliminando may�sculas\n";	

	vector.EliminaMayusculas();

	// Probad con: 
	//		vector.EliminaMayusculasIneficiente();
	// (deber�a dar el mismo resultado)

	cout << endl; 
	cout  << "Vector modificado: \n";	

	tope = vector.TotalUtilizados();  	// Es OBLIGADO recalcular "tope"
										// ya que el n�mero de componentes 
										// utilizadas puede cambiar
    for (int i=0; i<tope; i++)
      cout  << vector.Elemento(i) << " ";
	cout << endl; 


	cout << "\n\n";
	system ("pause");

	return (0);
}