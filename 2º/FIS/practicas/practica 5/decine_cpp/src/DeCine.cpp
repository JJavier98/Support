#include "DeCine.h"

namespace decine {

DeCine *DeCine::instancia = new DeCine();

	DeCine *DeCine::getDeCine() {
		return instancia;
	}

	DeCine::DeCine() {
		InitializeInstanceFields();
	}

	UsuarioVIP DeCine::buscarUsuario(const std::string &correo) throw(std::exception) {

		for (auto usuario: misUsuarios) {
			if (usuario.getCorreo() == correo) {
				return usuario;
			}
		}

		throw std::runtime_error("no existe el usuario con ese correo");

	}

	vector<string> DeCine::obtenerUsuariosVIP() {

		vector<string> resultado;
		for(auto value: misUsuarios) {
			resultado.push_back(value.getCorreo());
		}
		return resultado;
	}

	vector<string> DeCine::obtenerPeliculas() {
		vector<string> resultado;
		for(auto value: misPeliculas) {
			resultado.push_back(value.getTitulo());
		}
		return resultado;
	}

	vector<string> DeCine::obtenerActores() {
		vector<string> resultado;
		for(auto value: misActores) {
			resultado.push_back(value.getNombre());
		}
		return resultado;	
	}

	vector<string> DeCine::obtenerDirectores() {
		vector<string> resultado;
		for(auto value: misDirectores) {
			resultado.push_back(value.getNombre());
		}
		return resultado;	
	}

	vector<string> DeCine::obtenerPremios() {
		vector<string> resultado;
		for(auto value: misFestivales) {
			resultado.push_back(value.getNombre());
		}
		return resultado;	
	}

	void DeCine::incluirActor(const std::string &nombre, const std::string &nacionalidad, const std::string &web) {
		misActores.push_back(Actor(nombre,nacionalidad, web));
	}

	void DeCine::incluirDirector(const std::string &nombre, const std::string &nacionalidad, const std::string &web) {

		Director director = Director(nombre,nacionalidad, web);

		misDirectores.push_back(director);
	}

	void DeCine::incluirFestivalPremio(const std::string &nombre) {
		misFestivales.push_back(FestivalPremio(nombre));
	}

	void DeCine::incluirUsuario(const std::string &nombre, const std::string &correo) {
	   misUsuarios.push_back(UsuarioVIP(nombre,correo));
	}

	void DeCine::incluirPelicula(const std::string &titulo, Pelicula &pelicula) {
		misPeliculas.push_back(pelicula);
	}

	void DeCine::nuevaPelicula(const std::string &titulo, const std::string &tituloOriginal, int añoEstreno, int duracion, const std::string &guion, const std::string &musica, const std::string &pais, const std::string &webOficial, const std::string &productora, const std::string &sinopsis, float recaudacion) throw(std::exception) {

		bool existe = existePelicula(titulo);

		if (existe) {
			throw std::runtime_error("Esa película ya está incluida en el sistema");
		}

		Pelicula miPelicula = Pelicula(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial, productora, sinopsis, recaudacion);

		incluirPelicula(titulo, miPelicula);



	}

	std::string DeCine::busquedaPelicula(std::vector<std::string> &criterioBusqueda) {


		std::string resultadoBusqueda = "";


		std::vector<Pelicula> peliculas = seleccionarPeliculas(criterioBusqueda);

		for (auto pelicula : peliculas) {

			std::string datosBasicos = pelicula.obtenerDatosBasicos();


			resultadoBusqueda += datosBasicos;

			resultadoBusqueda += std::string("Directores:\n");
			std::vector<Director> directores = pelicula.getDirectores();
			for (auto director : directores) {
				resultadoBusqueda += director.getNombre() + std::string("\n");
			}

			resultadoBusqueda += std::string("Actores:\n");
			std::vector<Actor> actores = pelicula.getActores();
			for (auto actor : actores) {
				resultadoBusqueda += actor.getNombre() + std::string("\n");
			}



			if (StringConverterHelper::fromString<int>(criterioBusqueda[0]) == 1) {


				std::string datosComplementarios = pelicula.obtenerDatosComplementarios();


				// Esta mal en el diagrama
				resultadoBusqueda += datosComplementarios;


			}


		}


		return resultadoBusqueda;

	}

	void DeCine::nuevoGeneroPelicula(const std::string &titulo, Genero miGenero) throw(std::exception) {

		Pelicula miPelicula = buscarPelicula(titulo);

		miPelicula.vincularGenero(miGenero);



	}

	void DeCine::nuevoDirectorPelicula(const std::string &titulo, const std::string &nombreDirector) throw(std::exception) {

		Pelicula miPelicula = buscarPelicula(titulo);

		Director miDirector = buscarDirector(nombreDirector);

		miPelicula.vincularDirector(miDirector);


	}

	void DeCine::nuevoActorPelicula(const std::string &titulo, const std::string &nombreActor) throw(std::exception) {

		Pelicula miPelicula = buscarPelicula(titulo);

		Actor miActor = buscarActor(nombreActor);

		miPelicula.vincularActor(miActor);

	}

	void DeCine::criticaPelicula(const std::string &correo, const std::string &titulo, const std::string &tituloCritica, const std::string &comentario) throw(std::exception) {

		UsuarioVIP uVIP = buscarUsuarioVIP(correo);

		Pelicula peli = buscarPelicula(titulo);

		peli.incluirCritica(uVIP, tituloCritica, comentario);


	}

	void DeCine::nuevoPremio(const std::string &titulo, const std::string &nombreFP, const std::string &categoria, int año) throw(std::exception) {

		Pelicula pelicula = buscarPelicula(titulo);

		FestivalPremio premio = buscarPremio(nombreFP);

		pelicula.incluirPremio(premio, categoria, año);


	}

	std::vector<Pelicula> DeCine::seleccionarPeliculas(std::vector<std::string> &criterioBusqueda) {

		std::vector<Pelicula> listaPeliculas;


		for (auto pelicula : misPeliculas) {

			int criterio = StringConverterHelper::fromString<int>(criterioBusqueda[0]);
			std::string valor = criterioBusqueda[1];

			switch (criterio) {

				case 1: {// Por titulo
					if (valor == pelicula.getTitulo()) {
						listaPeliculas.push_back(pelicula);
					}

					break;}
				case 2: {// Por director

					std::vector<Director> directores = pelicula.getDirectores();
					for (auto director : directores) {

						if (valor == director.getNombre()) {
							 listaPeliculas.push_back(pelicula);
							 break; // Paramos el bucle (ya ha encontrado el elemento
						}
					}


					break;}
				case 3: {// Por actor

					std::vector<Actor> actores = pelicula.getActores();
					for (auto actor : actores) {

						if (valor == actor.getNombre()) {
							 listaPeliculas.push_back(pelicula);
							 break; // Paramos el bucle (ya ha encontrado el elemento
						}
					}


					break;}
				case 4: {// Por genero

					std::vector<Genero> generos = pelicula.getGeneros();
					for (auto genero : generos) {

						//POR HACER!!!
						// if (genero == valor) {
						// 	listaPeliculas.push_back(pelicula);
						// 	 break; // Paramos el bucle (ya ha encontrado el elemento
					 

					}

					break;}
				case 5: {// Por año estreno

					if (StringConverterHelper::fromString<int>(valor) == pelicula.getAñoEstreno()) {
							 listaPeliculas.push_back(pelicula);


					break;}



					}




			}

		}

		return listaPeliculas;

	}

	bool DeCine::existePelicula(const std::string &titulo) {

		for (auto pelicula: misPeliculas) {
			if (pelicula.getTitulo() == titulo) {
				return true;
			}
		}

		return false;
	}

	Pelicula DeCine::buscarPelicula(const std::string &titulo) throw(std::exception) {

		for (auto pelicula: misPeliculas) {
			if (pelicula.getTitulo() == titulo) {
				return pelicula;
			}
		}

		throw std::runtime_error("no existe la pelicula");

	}

	UsuarioVIP DeCine::buscarUsuarioVIP(const std::string &correo) throw(std::exception) {
		for (auto usuario: misUsuarios) {
			if (usuario.getCorreo() == correo) {
				return usuario;
			}
		}

		throw std::runtime_error("no existe el usuario con ese correo");

	}

	Director DeCine::buscarDirector(const std::string &idDirector) throw(std::exception) {
		for (auto director: misDirectores) {
			if (director.getNombre() == idDirector) {
				return director;
			}
		}

		throw std::runtime_error(std::string("no existe el director con ese id: "));


	}

	Actor DeCine::buscarActor(const std::string &idActor) throw(std::exception) {
		for (auto actor: misActores) {
			if (actor.getNombre() == idActor) {
				return actor;
			}
		}

		throw std::runtime_error(std::string("no existe el actor con ese id: "));
	}

	FestivalPremio DeCine::buscarPremio(const std::string &nombre) throw(std::exception) {

		for (auto festival: misFestivales) {
			if (festival.getNombre() == nombre) {
				return festival;
			}
		}

		throw std::runtime_error("no existe el festival con ese nombre");

	}

	void DeCine::InitializeInstanceFields() {
		// misUsuarios = std::vector();
		// misActores = std::vector();
		// misDirectores = std::vector();
		// misFestivales = std::vector();
		// misPeliculas = std::vector();
	}
}
