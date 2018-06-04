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
// EJERCICIO 4
//
/*	
	En este ejercico se ampl�a la clase MiVectorCaracteres con el m�todo:
	
		void Elimina(int posicion) 
		
	para eliminar el car�cter que se encuentre en la posici�n dada por 
	"posicion". En el caso de que la componente no est� dentro 	del rango 
	correcto, el m�todo no modificar� nada.


	NOTAS DE DISE�O: 

	Se distinguen dos tipos de borrado:

    1)	L�gico
	
		Usar un valor "especial" para marcar la componente que se quiere 
		borrar con dicho valor. Por ejemplo, en un vector: 
			de edades -> usar como valor especial el -1
			de caracteres alfab�ticos -> usar como valor especial '@'
        Ventajas: Muy r�pido
        Inconvenientes: Cualquier procesado posterior del vector debe 
		tratar las componentes marcadas de una forma especial, ya 
		que "no existen"

	2) F�sico

		Implica desplazar una posici�n a la izquierda, todas las 
		componentes que hay a la derecha de la que queremos borrar.
        Tiene justo las ventajas e incovenientes contrarias que el m�todo 
		anterior.

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

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/


int main()
{

	MiVectorCaracteres vector;
	int tope;


	// A�adir datos al vector

	vector.Aniade('H');   
	vector.Aniade('o');
	vector.Aniade('l');
	vector.Aniade('l');
	vector.Aniade('a');
	

	cout  << "Vector original: \n";	

	// Mostrar el contenido del vector

	tope = vector.TotalUtilizados();
	for (int i=0; i<tope; i++)
		cout  << vector.Elemento(i) << " ";	
	cout << endl; 


	// Eliminar el elemento de la posici�n 3 y mostrar el vector resultante

	cout << endl; 
	cout  << "Eliminando la componente 3\n";	

	vector.Elimina(3);


	cout << endl; 
	cout  << "Vector modificado: \n";	

	tope = vector.TotalUtilizados();  	// Es OBLIGADO recalcular "tope"
										// ya que el n�mero de componentes 
										// utilizadas puede cambiar
    for (int i=0; i<tope; i++)
      cout  << vector.Elemento(i) << " ";
	cout << endl; 


	// Eliminar el elemento de la posici�n 10 y mostrar el vector resultante

	cout << endl; 
	cout  << "Eliminando la componente 10\n";	

	vector.Elimina(10);


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