#include "DeCine.h"
#include "Genero.h"
#include<iostream>


using namespace std; 
using namespace decine;

string MostrarCombo(const string mensaje, vector<string> opciones) {

	cout << mensaje << endl;

	for (auto opcion: opciones) {
		cout <<  opcion << endl;

	}
	string resultado;
	cin >> resultado;
	return resultado;

}

string MostrarInput(const string &mensaje) {

	cout << mensaje << endl;

	string resultado;
	cin >> resultado;
	return resultado;
}


int main(void) {
	// Obtención de la única instancia de DeCine, DeCine es un singleton. 
	decine::DeCine *unaDeCine = decine::DeCine::getDeCine();

	//Definición de la variable in que va a permitir leer String desde teclado.  

	// Ejemplos de lectura desde teclado con in.readLine()
	// String s = in.readLine();        //Lectura de un String
	// double d= Double.parseDouble(in.readLine());         // lectura de un duoble
	// int i = Integer.parseInt(in.readLine());         // lectura d10e un int               
	// Genero estado = Genero.valueOf(in.readLine());       // lectura de un enum   


	// Introducimos algunos actores y películas a mano, para que no esté vacío el sistema

	unaDeCine->nuevaPelicula("El bosque animado", "El bosque animado", 1986, 100, "adaptado", "musico profesional", "España", "sin web", "el deseo s.a.", "sinopsis", 10000);
	unaDeCine->nuevaPelicula("La vida de brian", "Brian's life", 1986, 100, "adaptado", "musico profesional", "UK", "sin web", "monty Python", "vida de brian de nazaret", 10000);
	unaDeCine->nuevaPelicula("El Hobbit", "The Hobbbit", 2010, 100, "adaptado", "musico profesional", "Nueva Zelanda", "sin web", "Universal", "Un hobbit va por ahi dando vueltas cholando anillos hasta que un dragon se lo quita", 10000);
	unaDeCine->nuevaPelicula("Karate a muerte en torremolinos", "Karate a muerte en Torremolinos", 1999, 100, "adaptado", "musico semi-profesional", "España", "sin web", "Jess Franco.", "El doctor Malvedades despierta a la bestia jocántaro, solo los surfistas católicos podran salvar a la humanidad", 10000);
	unaDeCine->nuevaPelicula("El bueno, el feo y el malo", "The good, the bad & the ugly", 1960, 100, "adaptado", "musico profesional", "Italia", "sin web", "MGM", "Todo un clásico", 10000);






	unaDeCine->incluirActor("Antonio Resines", "España", "no");
	unaDeCine->incluirActor("Miguel Rellan", "España", "no");
	unaDeCine->incluirActor("Gabino Diego", "España", "no");
	unaDeCine->incluirActor("Fernando Fernan Gomez", "España", "no");
	unaDeCine->incluirActor("Luis Ciges", "España", "no");
	unaDeCine->incluirActor("Carlos Larrañaga", "España", "no");


	unaDeCine->incluirDirector("Lars Von Trier", "Dinamarca", "www.lars.com");
	unaDeCine->incluirDirector("Pedro Almodovar", "España", "www.pedro.com");
	unaDeCine->incluirDirector("Sergio Leone", "Italia", "www.dollar.com");
	unaDeCine->incluirDirector("Pedro Temboury", "España", "www.karateamuerteentorremolinos.com");


	unaDeCine->incluirUsuario("Ernesto", "erseco@correo.ugr.es");
	unaDeCine->incluirUsuario("Pablo", "pableitor@correo.ugr.es");
	unaDeCine->incluirUsuario("Carlos", "cgarrancho@correo.ugr.es");

	unaDeCine->incluirFestivalPremio("Festival de Cannes");
	unaDeCine->incluirFestivalPremio("Oscars");
	unaDeCine->incluirFestivalPremio("Concha de oro");



	try {
		unaDeCine->nuevoActorPelicula("La vida de brian", "Fernando Fernan Gomez");
		unaDeCine->nuevoDirectorPelicula("La vida de brian", "Lars Von Trier");
		unaDeCine->nuevoGeneroPelicula("La vida de brian", Genero::Aventura);
		unaDeCine->nuevoGeneroPelicula("La vida de brian", Genero::CienciaFiccion);
		unaDeCine->nuevoPremio("La vida de brian", "Oscars", "Comedia", 1986);


		unaDeCine->nuevoActorPelicula("El bosque animado", "Fernando Fernan Gomez");
		unaDeCine->nuevoDirectorPelicula("El bosque animado", "Lars Von Trier");
		unaDeCine->nuevoGeneroPelicula("El bosque animado", Genero::CienciaFiccion);
		unaDeCine->nuevoPremio("El bosque animado", "Oscars", "Comedia", 1987);


		unaDeCine->nuevoActorPelicula("El bosque animado", "Luis Ciges");
		unaDeCine->nuevoActorPelicula("El bosque animado", "Miguel Rellan");
		unaDeCine->nuevoPremio("El bosque animado", "Concha de oro", "Comedia", 1987);

		unaDeCine->criticaPelicula("erseco@correo.ugr.es", "El bosque animado", "Muy buena", "Una de las obras maestras de Wenceslao Fernandez Flores");
		unaDeCine->criticaPelicula("erseco@correo.ugr.es", "La vida de brian", "Divertida", "Una gran pelicula de los Monty Python");
		unaDeCine->criticaPelicula("erseco@correo.ugr.es", "El bueno, el feo y el malo", "Un clasico", "Uno de los grandes clasicos del cine");

	}
	catch (exception &e) {
	}



	int opcion = 0; //variable que controla la opción de menú

	do { //do-while que controlara todo el menú

			//Terminar de diseñar el menú (usando System.out.println(...)) con las opciones que faltan
			// Podéis hacer vuestros propios diseños de interfaz, esta es la interfaz mínima que tenéis que entregar
			cout << string("******** ALTAS*****************************") << endl;
			cout << string("1. Dar de alta un película \n") << string("2. Dar de alta un actor \n") << string("3. Dar de alta un director \n") << string("4. Dar de alte un UsuarioVIP \n") << string("5. Dar de alta un Festival/Premio") << endl;

			cout << string("\n ******  MODIFICACIONES *****************************") << endl;
			cout << string("6. Incluir un directr en una  película \n") << string("7. Incluir un actor en una película \n") << string("8. Incluir premio de película \n") << string("9. Incluir crítica de película") << endl;
			cout << string("\n ******  CONSULTA  *****************************") << endl;
			cout << string("10. Consultar película") << endl;
			cout << string("\n ****** TERMINAR *****************************") << endl;
			cout << string("0. Terminar") << endl;

			// Lectura de un int, para darle valor a opcion.
			cin >> opcion;

			// Estructura switch con todas las opciones de menú. Algunos de ellos ya lo tenéis hecho
			// Tenéis que terminar las opciones que están incompletas y las que no están hechas
			switch (opcion) {
				case 1: {/*todo lo que hay que hacer para dar de alta una película
	                         lectura de los valores de inicialización de la pelicula, son:                                                        
	                                    
	                         * Titulo: ----
	                         * Titulo Original ---
	                         * Fecha de Estreno
	                         * Duracion:----
	                         * Guion --
	                         * Musica---
	                         * Pais:---
	                         * Web oficial ---
	                         * Productora --
	                         * Sinopsis: ----
	                         * Recaudacion
	                         * Generos:---,---,---.                              
	                         Una vez leída, mensaje a unaDeCine para que incluya una nueva película */

					cout << string("Titulo:") << endl;
					string titulo;
					cin >> titulo;
					cout << string("Titulo Origional:") << endl;
					string tituloOriginal;
					cin >> tituloOriginal;
					cout << string("Año estreno:") << endl;
					int añoEstreno; // Lo hemos pasado de fecha a año de estreno por comodidad
					cin >> añoEstreno;
					cout << string("Duracion:") << endl;
					int duracion;
					cin >> duracion;
					cout << string("Guion:") << endl;
					string guion;
					cin >> guion;
					cout << string("Musica:") << endl;
					string musica;
					cin >> musica;
					cout << string("Pais:") << endl;
					string pais;
					cin >> pais;
					cout << string("web Oficial:") << endl;
					string webOficial;
					cin >> webOficial;
					cout << string("Productora:") << endl;
					string productora;
					cin >> productora;
					cout << string("Sinopsis:") << endl;
					string sinopsis;
					cin >> sinopsis;
					cout << string("Recaudacion:") << endl;
					int recaudacion;
					cin >> recaudacion;
					cout << string("Genero: 1=Aventura, 2=CienciaFiccion, 3=Drama") << endl;

					Genero genero;
					int generoOption;
					cin >> generoOption;

					if (generoOption == 1) {
						genero = Genero::Aventura;
					}
					else if (generoOption == 2) {
						genero = Genero::CienciaFiccion;
					}
					else {
						genero = Genero::Drama;
					}

					unaDeCine->nuevaPelicula(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial, productora, sinopsis, recaudacion);

					unaDeCine->nuevoGeneroPelicula(titulo, genero);

					break;}
				case 2: {//Dar de alta un actor
					cout << string("Nombre del Actor:") << endl;
					string nombreA;
					cout << string("Nacionalidad del Actor:") << endl;
					string nacionalidadA;
					cout << string("Web oficial del Actor:") << endl;
					string webA;
					unaDeCine->incluirActor(nombreA, nacionalidadA, webA);
					break;}
				case 3: {//Dar de alta a un Director
					cout << string("Nombre del Director:") << endl;
					string nombreD;
					cout << string("Nacionalidad del Directorr:") << endl;
					string nacionalidadD;
					cout << string("Web oficial del Director:") << endl;
					string webD;
					unaDeCine->incluirDirector(nombreD, nacionalidadD, webD);
					break;}
				case 4: {// Dar de alta a un usuario VIP
					cout << string("Nombre del Usuario VIP:") << endl;
					string nombreU;
					cout << string("Correo del Usuario VIP:") << endl;
					string correo;
					unaDeCine->incluirUsuario(nombreU, correo);
					break;}
				case 5: {// Dar de alta un Festival  o Premio
					cout << string("Nombre del Festival o Premio:") << endl;
					string nombreF;
					unaDeCine->incluirFestivalPremio(nombreF);
					break;}
				case 6: {/* Incluir  un director en una película
	                         Obtener a todos los directores disponibles
	                         Lectura del nombre del director 
	                         Obtener todas las películas disponibles (título y año de estreno)
	                         Lectura  del título de la pelicula.
	                         Lectura del año de estreno
	                         mensaje a unaDeCine para que incluya a ese director en esa película 
	                         */

					vector<string> directores = unaDeCine->obtenerDirectores();
					string director = MostrarCombo("Seleccione un director", directores);

					vector<string> peliculas = unaDeCine->obtenerPeliculas();
					string pelicula = MostrarCombo("Seleccione una pelicula", peliculas);

					unaDeCine->nuevoDirectorPelicula(pelicula, director);

					break;}
				case 7: {// Incluir  un actor en una pelicula

					vector<string> actores = unaDeCine->obtenerActores();
					string actor = MostrarCombo("Seleccione un actor", actores);

					vector<string> peliculas = unaDeCine->obtenerPeliculas();
					string pelicula = MostrarCombo("Seleccione una pelicula", peliculas);

					unaDeCine->nuevoActorPelicula(pelicula, actor);

					break;}
				case 8: {/*Incluir un premio a pelicula
	                         Obtener  los Premios o Festivales  disponibles en el sistem                                                          
	                         Lectura del nombre del premio o festival
	                         Obtener todas las películas disponibles (título y año de estreno)
	                         Lectura  del título de la pelicula.
	                         Lectura del año de estreno
	                         mensaje a unaDeCine para que incluya  ese premio a la pelicula 
	                         */
					vector<string> peliculas = unaDeCine->obtenerPeliculas();
					string pelicula = MostrarCombo("Seleccione una pelicula", peliculas);

					vector<string> premios = unaDeCine->obtenerPremios();
					string premio = MostrarCombo("Seleccione un premio", premios);


					string categoria = MostrarInput("Introduzca la categoria:");
					int año = StringConverterHelper::fromString<int>(MostrarInput("Introduzca el año:"));


					unaDeCine->nuevoPremio(pelicula, premio, categoria, año);



					break;}
				case 9: {/* Incluir una critica a pelicula
	                         Obtener los usuarios VIP disponibles en el sistema*/


					vector<string> peliculas = unaDeCine->obtenerPeliculas();
					string pelicula = MostrarCombo("Seleccione una pelicula", peliculas);

					vector<string> usuarios = unaDeCine->obtenerUsuariosVIP();
					string usuario = MostrarCombo("Seleccione un usuario", usuarios);


					string tituloCritica = MostrarInput("Introduzca un titulo para la critica:");
					string comentario = MostrarInput("Introduzca un comentario:");

					unaDeCine->criticaPelicula(usuario, pelicula, tituloCritica, comentario);

					break;}
				case 10: {/* Consultar una pelicula por distintos criterios:
	                         Lectura del criterio de consulta 
	                         (1 == por titulo, 1 == por Director, 3 == por Actor, 4== genero, 5 == año de estreno)
	                         Lectura del valor de la busqueda
	                         mensaje a unaDeCine para que realice la busqueda
	                         muestra del resultado de la busqueda (esta salida tiene que estar bien elaborada)
	                         */

					cout << string("Criterio de busqueda: 1 == por titulo, 2 == por Director, 3 == por Actor, 4== genero, 5 == año de estreno") << endl;
					string criterio;
					cin >> criterio;
					cout << string("Valor de busqueda:") << endl;
					string valor;
					cin >> valor;

					vector<string> criterioBusqueda;
					criterioBusqueda.push_back(criterio);
					criterioBusqueda.push_back(valor);


					string resultado = unaDeCine->busquedaPelicula(criterioBusqueda);


					cout << resultado << endl;

					break;}   
			}

	} while (opcion != 0);
} // de main(...)


