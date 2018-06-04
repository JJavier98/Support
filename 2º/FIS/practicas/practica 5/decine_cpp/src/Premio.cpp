#include "Premio.h"

namespace decine {

	Premio::Premio(FestivalPremio *premio, const std::string &categoria, int año) {
		InitializeInstanceFields();
		this->premio = premio;
		this->categoriaPremio = categoria;
		this->año = año;
	}

	std::string Premio::obtenerDatos() {

		std::string resultado = "";

		resultado += std::string("\tNombre: ") + this->premio->getNombre() + std::string("\n");
		resultado += std::string("\tCategoria: ") + this->categoriaPremio + std::string("\n");
		resultado += std::string("\tAño: ") + StringConverterHelper::toString(this->año) + std::string("\n");
		resultado += std::string("\t------------\n");

		return resultado;

	}

	void Premio::InitializeInstanceFields() {
		año = 0;
	}
}
