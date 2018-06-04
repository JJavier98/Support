#include "Pelicula.h"

namespace decine {

	Pelicula::Pelicula(const std::string &titulo, const std::string &tituloOriginal, int añoEstreno, int duracion, const std::string &guion, const std::string &musica, const std::string &pais, const std::string &webOficial, const std::string &productora, const std::string &sinopsis, float recaudacion) {
		InitializeInstanceFields();
		this->titulo = titulo;
		this->tituloOriginal = tituloOriginal;
		this->añoEstreno = añoEstreno;
		this->duracion = duracion;
		this->guion = guion;
		this->musica = musica;
		this->pais = pais;
		this->webOficial = webOficial;
		this->productora = productora;
		this->sinopsis = sinopsis;
		this->recaudacion = recaudacion;
	}

	std::string Pelicula::obtenerDatosBasicos() {

		std::string resultado = "";

		resultado += std::string("Titulo: ") + this->titulo + std::string("\n");
		resultado += std::string("Año Estreno: ") + StringConverterHelper::toString(this->añoEstreno) + std::string("\n");
		resultado += std::string("Duracion: ") + StringConverterHelper::toString(this->duracion) + std::string("\n");
		resultado += std::string("Recaudacion: ") + StringConverterHelper::toString(this->recaudacion) + std::string("\n");

		return resultado;

	}

	std::string Pelicula::obtenerDatosComplementarios() {

		std::string resultado = "";

		//resultado += std::string("Genero: ") + this->generos + std::string("\n");
		resultado += std::string("Sinopsis: ") + this->sinopsis + std::string("\n");

		resultado += std::string("Premios: ") + std::string("\n");
		for (auto premio : this->premios) {
			resultado += premio.obtenerDatos() + std::string("\n");
		}



		resultado += std::string("Criticas: ") + std::string("\n");
		for (auto critica : this->criticas) {
			resultado += critica.obtenerDatosCritica() + std::string("\n");
		}



		return resultado;

	}

	std::string Pelicula::getTitulo() {
		return this->titulo;
	}

	int Pelicula::getAñoEstreno() {
		return this->añoEstreno;
	}

	std::vector<Genero> Pelicula::getGeneros() {
		return this->generos;
	}

	std::vector<Director> Pelicula::getDirectores() {
		return this->directores;
	}

	std::vector<Actor> Pelicula::getActores() {
		return this->actores;
	}

	void Pelicula::vincularGenero(Genero miGenero) {
		this->generos.push_back(miGenero);
	}

	void Pelicula::vincularDirector(Director miDirector) {
		this->directores.push_back(miDirector);
	}

	void Pelicula::vincularActor(Actor miActor) {
		this->actores.push_back(miActor);
	}

	void Pelicula::incluirCritica(UsuarioVIP uVIP, const std::string &titulo, const std::string &comentario) {

		Critica miCritica = Critica(&uVIP, titulo, comentario);

		this->criticas.push_back(miCritica);

	}

	void Pelicula::incluirPremio(FestivalPremio premio, const std::string &categoria, int año) {

		Premio miPremio = Premio(&premio, categoria, año);

		this->premios.push_back(miPremio);


	}

	void Pelicula::InitializeInstanceFields() {
		añoEstreno = 0;
		duracion = 0;
		recaudacion = 0;
		// generos = std::vector();
		// directores = std::vector();
		// actores = std::vector();
		// premios = std::vector();
		// criticas = std::vector();
	}
}
