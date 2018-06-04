#include "Director.h"

namespace decine {

	Director::Director(const std::string &nombre, const std::string &nacionalidad, const std::string &web) {
		this->nombre = nombre;
		this->nacionalidad = nacionalidad;
		this->webOficial = web;
	}

	std::string Director::getNombre() {
		return this->nombre;
	}
}
