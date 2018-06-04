#include "Actor.h"

namespace decine {

	Actor::Actor(const std::string &nombre, const std::string &nacionalidad, const std::string &web) {
		this->nombre = nombre;
		this->nacionalidad = nacionalidad;
		this->webOficial = web;
	}

	std::string Actor::getNombre() {
		return this->nombre;
	}
}
