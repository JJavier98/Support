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
// EJERCICIO 4
//
/*	
	En este ejercico se amplía la clase MiVectorCaracteres con el método:
	
		void Elimina(int posicion) 
		
	para eliminar el carácter que se encuentre en la posición dada por 
	"posicion". En el caso de que la componente no esté dentro 	del rango 
	correcto, el método no modificará nada.


	NOTAS DE DISEÑO: 

	Se distinguen dos tipos de borrado:

    1)	Lógico
	
		Usar un valor "especial" para marcar la componente que se quiere 
		borrar con dicho valor. Por ejemplo, en un vector: 
			de edades -> usar como valor especial el -1
			de caracteres alfabéticos -> usar como valor especial '@'
        Ventajas: Muy rápido
        Inconvenientes: Cualquier procesado posterior del vector debe 
		tratar las componentes marcadas de una forma especial, ya 
		que "no existen"

	2) Físico

		Implica desplazar una posición a la izquierda, todas las 
		componentes que hay a la derecha de la que queremos borrar.
        Tiene justo las ventajas e incovenientes contrarias que el método 
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
	
	void Aniade(char nuevo)
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

	char Elemento(int indice)
	{
		return vector_privado[indice];
	}

	/*****************************************************************/
	// Eliminar el carácter que se encuentre en la posición dada por 
	// "indice_componente".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	// PRE: la posición dada por "posicion" es correcta.
	// Si no es correcta, no hace nada.

	void Elimina (int posicion) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posición a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((posicion >= 0) && (posicion < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último 
    
			for (int i = posicion ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}

		// Nota:
		// La asignación
		//    vector_privado[i] = vector_privado[i+1];
		// podría cambiarse por:
		//    Modifica(i, Elemento(i+1));
		// Hemos preferido acceder directamente a las componentes con la 
		// notación en corchete para aumentar la eficiencia del método 
		// Elimina() evitando usar métodos lo que conllevaría a una 
		// sobrecarga de procesamiento: llamada, paso de argumentos, 
		// gestión de los entornos en la pila, retorno,...
	}

};

///////////////////////////////////////////////////////////////////////

/*********************************************************************/


int main()
{

	MiVectorCaracteres vector;
	int tope;


	// Añadir datos al vector

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


	// Eliminar el elemento de la posición 3 y mostrar el vector resultante

	cout << endl; 
	cout  << "Eliminando la componente 3\n";	

	vector.Elimina(3);


	cout << endl; 
	cout  << "Vector modificado: \n";	

	tope = vector.TotalUtilizados();  	// Es OBLIGADO recalcular "tope"
										// ya que el número de componentes 
										// utilizadas puede cambiar
    for (int i=0; i<tope; i++)
      cout  << vector.Elemento(i) << " ";
	cout << endl; 


	// Eliminar el elemento de la posición 10 y mostrar el vector resultante

	cout << endl; 
	cout  << "Eliminando la componente 10\n";	

	vector.Elimina(10);


	cout << endl; 
	cout  << "Vector modificado: \n";	

	tope = vector.TotalUtilizados();  	// Es OBLIGADO recalcular "tope"
										// ya que el número de componentes 
										// utilizadas puede cambiar
    for (int i=0; i<tope; i++)
      cout  << vector.Elemento(i) << " ";
	cout << endl; 

	cout << "\n\n";
	system ("pause");

	return (0);
}