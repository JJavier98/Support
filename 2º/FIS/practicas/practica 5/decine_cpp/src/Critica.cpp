#include "Critica.h"
#include "stringconverter.h"

namespace decine {

	Critica::Critica(UsuarioVIP *usuario, const std::string &titulo, const std::string &comentario) {
		
		this->usuario = usuario;
		this->fecha = 2014; // Asignamos la fecha actual fija
		this->titulo = titulo;
		this->comentario = comentario;

	}

	std::string Critica::obtenerDatosCritica() {

		std::string resultado = "";

		resultado += std::string("\tNombre: ") + this->usuario->getNombre() + std::string("\n");
		resultado += std::string("\tFecha: ") + StringConverterHelper::toString(this->fecha) + std::string("\n");

		resultado += std::string("\tTitulo: ") + this->titulo + std::string("\n");
		resultado += std::string("\tComentario: ") + this->comentario + std::string("\n");
		resultado += std::string("\t-------------------------\n");

		return resultado;

	}
}
