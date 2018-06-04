#include "FestivalPremio.h"

namespace decine {

	FestivalPremio::FestivalPremio(const std::string &nombre) {
		this->nombre = nombre;
	}

	std::string FestivalPremio::getNombre() {
		return this->nombre;
	}
}
