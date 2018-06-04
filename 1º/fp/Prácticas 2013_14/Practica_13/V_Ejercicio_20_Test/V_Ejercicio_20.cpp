/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - FP
	------------------------------
	Se quiere desarrollar una aplicación para automatizar la realización de 
	exámenes tipo test. El software incluirá una clase Examen que debe almacenar:
	el nombre de la asignatura, la lista de enunciados de las preguntas (cada 
	enunciado es una cadena de caracteres de tipo string) y la lista de respuestas 
	correctas para cada pregunta (cada respuesta es un carácter). Para representar 
	una lista puede usar un vector de la STL. Implementa la clase junto con los 
	siguientes métodos:

		• Un constructor que inicialice un objeto de tipo Examen dando el nombre 
			de la asignatura y con la lista de preguntas vacía.
		• Un método NuevaPregunta que reciba un enunciado y la respuesta correcta 
			y que los añada a la lista de preguntas del examen. Cada nueva pregunta 
			siempre se añade al final de la lista.
		• Un método NumPreguntas que devuelva el número de preguntas de que consta 
			el examen.
		• Un método GetEnunciado que devuelva el enunciado de la pregunta i-ésima.
		• Un método GetRespuesta que devuelva la respuesta de la pregunta i-ésima.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <vector> //Libreria para vectores de la STL
#include <string> //Libreria para vectores de la STL

using namespace std; 
/*****************************************************************************/
//Definicion de la clase Examen
class Examen {

private:
	//Definicion de atributos
    string nombre_asignatura;
	vector<string> enunciados;
	vector<string> respuestas;

public:
	//Constructor
	Examen(string nombre) {

		nombre_asignatura = nombre;
	
	}

	/*********************************************************/
	//Esta función devuelve el nombre de la asignatura
	string Asignatura() {
	
		return nombre_asignatura;
	}

	/*********************************************************/
	//Este método agrega una nueva pregunta al examen (y su respuesta)
	void NuevaPregunta(string pregunta, string respuesta) {
	
		//Agregamos la pregunta y la respuesta a los vectores
		enunciados.push_back(pregunta);
		respuestas.push_back(respuesta);


	}

	/*********************************************************/
	//Esta función devuelve el numero de preguntas del examen
	int NumPreguntas() {
	
		return enunciados.size();
	
	}

	/*********************************************************/
	//Este método  devuelva el enunciado de la pregunta i-ésima.
	string GetEnunciado(int indice) {

		return enunciados.at(indice);
	}

	/*********************************************************/
	//Este método  devuelva la respuesta de la pregunta i-ésima.
	string GetRespuesta(int indice) {

		return respuestas.at(indice);
	}

};

/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos
	string asignatura;
	string pregunta;
	string respuesta;

	int numero_alumnos;


	//Obtiene los datos referentes al examen;
	cout << "Definicion de examen:\n";
	cout << "---------------------\n";
	cout << "Introduzca el nombre de la asignatura: ";

	//Uso la función getline(cin, <string>) para poder leer cadenas con espacios,
	//Esta función la he buscado en stackoverflow
	getline(cin, asignatura);

	Examen examen(asignatura);

	do {
		cout << "Introduzca una pregunta (en blanco para terminar): ";

		//Uso la función getline(cin, <string>) para poder leer cadenas con espacios,
		//Esta función la he buscado en stackoverflow
		getline(cin, pregunta);

		//Si la pregunta esta en blanco ya hemos terminado
		if (pregunta != "") {
			cout << "Introduzca una respuesta (s=si|n=no): ";

			//Uso la función getline(cin, <string>) para poder leer cadenas con espacios,
			//Esta función la he buscado en stackoverflow
			getline(cin, respuesta);

			//Agregamos la pregunta la objeto examen
			examen.NuevaPregunta(pregunta, respuesta);

		}

	} while (pregunta != "");

	//Mostramos el numero de preguntas
	cout << "\nEl examen contiene " << examen.NumPreguntas() << " preguntas.\n";

	//Pasamos a realizar los examenes
	cout << "\nExamen de " << examen.Asignatura() << "\n";
	cout << "-------------------------------\n";

	cout << "Introduzca el numero de alumnos que van a realizar el examen: ";
	cin >> numero_alumnos;	

	//Vamos haciendo el examen a los alumnos
	for (int i = 0; i < numero_alumnos; i++) {
	
		//Declaramos variables para usarlas para cada alumno
		string respuesta_alumno;
		int nota = 0; //Aqui iremos guardando la nota

		cout << "Examen para el alumno: " << i +1 << "\n";
		cout << "--------------------------\n";

		//Vamos recorriendo las preguntas
		for (int h = 0; h < examen.NumPreguntas(); h++) {
		
			//Hacemos la pregunta al alumno
			cout << "Pregunta " << h << ": " << examen.GetEnunciado(h) << "\n";
			cout << "Respuesta (s=si|n=no): ";
			cin >> respuesta_alumno;

			//Si ha respondido correctamente incrementamos la nota, 
			if (respuesta_alumno == examen.GetRespuesta(h)) {
				nota++;
				
			} else {
				//si no la decrementamos
				nota--;

			}

		}

		//Si la nota es inferior a 0, la nota es un 0
		if (nota < 0) {
			nota = 0;
		}

		//Mostramos la nota que ha sacado el alumno (ha terminado el examen)
		cout << "El alumno: " << i +1 << " ha sacado una nota de: " << nota << "\n";
		cout << "--------------------------\n";
	
	}


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}