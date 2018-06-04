#ifndef DECINE
#define DECINE

#include "UsuarioVIP.h"
#include "Actor.h"
#include "Director.h"
#include "FestivalPremio.h"
#include "Pelicula.h"
#include "Genero.h"
#include <string>
#include <vector>
#include <stdexcept>
#include "stringconverter.h"

/*  
 *  Fundamentos de Ingenieria del Software
 *  Grado en Ingeniería Informática
 * 
 *  2014 © Copyleft - All Wrongs Reserved
 *
 *  Ernesto Serrano <erseco@correo.ugr.es>
 *  Carlos Garrancho
 *  Pablo Martinez
 * 
 */

using namespace std;

namespace decine {


	class DeCine {

		// Definición de atributos 
	private:
		vector<UsuarioVIP> misUsuarios;
		vector<Actor> misActores;
		vector<Director> misDirectores;
		vector<FestivalPremio> misFestivales;
		vector<Pelicula> misPeliculas;

		// incluir los que faltan

		// implementación del Singleton
		static DeCine *instancia;
	public:
		static DeCine *getDeCine();
	private:
		DeCine();

		// Búsqueda de un determinado elemento en un Map
		UsuarioVIP buscarUsuario(const std::string &correo) throw(std::exception);

		// Obtener todos los id (key) de una lista de objetos.
	public:
		virtual vector<string> obtenerUsuariosVIP();
		virtual vector<string> obtenerPeliculas();
		virtual vector<string> obtenerActores();
		virtual vector<string> obtenerDirectores();
		virtual vector<string> obtenerPremios();

		 // .... Para todos los demas igual la busqueda de uno concreto o de todas sus claves

		// Inicialización del sistema 
		virtual void incluirActor(const std::string &nombre, const std::string &nacionalidad, const std::string &web);
		virtual void incluirDirector(const std::string &nombre, const std::string &nacionalidad, const std::string &web);
		virtual void incluirFestivalPremio(const std::string &nombre);
		virtual void incluirUsuario(const std::string &nombre, const std::string &correo);

		virtual void incluirPelicula(const std::string &titulo, Pelicula &pelicula);


		 // NOTA DURACION ESTA COMO INT Y FLOAT EN LOS DIAGRAMAS

		virtual void nuevaPelicula(const std::string &titulo, const std::string &tituloOriginal, int añoEstreno, int duracion, const std::string &guion, const std::string &musica, const std::string &pais, const std::string &webOficial, const std::string &productora, const std::string &sinopsis, float recaudacion) throw(std::exception);

		virtual std::string busquedaPelicula(std::vector<std::string> &criterioBusqueda);

		virtual void nuevoGeneroPelicula(const std::string &titulo, Genero miGenero) throw(std::exception);

		virtual void nuevoDirectorPelicula(const std::string &titulo, const std::string &nombreDirector) throw(std::exception);

		virtual void nuevoActorPelicula(const std::string &titulo, const std::string &nombreActor) throw(std::exception);

		virtual void criticaPelicula(const std::string &correo, const std::string &titulo, const std::string &tituloCritica, const std::string &comentario) throw(std::exception);

		virtual void nuevoPremio(const std::string &titulo, const std::string &nombreFP, const std::string &categoria, int año) throw(std::exception);

	private:
		std::vector<Pelicula> seleccionarPeliculas(std::vector<std::string> &criterioBusqueda);

		bool existePelicula(const std::string &titulo);

		Pelicula buscarPelicula(const std::string &titulo) throw(std::exception);

		UsuarioVIP buscarUsuarioVIP(const std::string &correo) throw(std::exception);

		Director buscarDirector(const std::string &idDirector) throw(std::exception);

		Actor buscarActor(const std::string &idActor) throw(std::exception);

		FestivalPremio buscarPremio(const std::string &nombre) throw(std::exception);



	private:
		void InitializeInstanceFields();
	};

}


#endif	//#ifndef DECINE
