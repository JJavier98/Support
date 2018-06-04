#ifndef PELICULA
#define PELICULA

#include "Genero.h"
#include "Director.h"
#include "Actor.h"
#include "Premio.h"
#include "Critica.h"
#include "UsuarioVIP.h"
#include "FestivalPremio.h"
#include <string>
#include <vector>
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
namespace decine {

	class Pelicula {
	private:
		std::string titulo;
		std::string tituloOriginal;
		int añoEstreno;
		int duracion;
		std::string guion;
		std::string musica;
		std::string pais;
		std::string webOficial;
		std::string productora;
		std::string sinopsis;
		float recaudacion;

		std::vector<Genero> generos;
		std::vector<Director> directores;
		std::vector<Actor> actores;

		std::vector<Premio> premios;

		std::vector<Critica> criticas;



	public:
		Pelicula(const std::string &titulo, const std::string &tituloOriginal, int añoEstreno, int duracion, const std::string &guion, const std::string &musica, const std::string &pais, const std::string &webOficial, const std::string &productora, const std::string &sinopsis, float recaudacion);

		virtual std::string obtenerDatosBasicos();

		virtual std::string obtenerDatosComplementarios();

		virtual std::string getTitulo();

		virtual int getAñoEstreno();

		virtual std::vector<Genero> getGeneros();

		virtual std::vector<Director> getDirectores();

		virtual std::vector<Actor> getActores();

		virtual void vincularGenero(Genero miGenero);

		virtual void vincularDirector(Director miDirector);

		virtual void vincularActor(Actor miActor);

		virtual void incluirCritica(UsuarioVIP uVIP, const std::string &titulo, const std::string &comentario);

		virtual void incluirPremio(FestivalPremio premio, const std::string &categoria, int año);



	private:
		void InitializeInstanceFields();
	};

}


#endif	//#ifndef PELICULA
