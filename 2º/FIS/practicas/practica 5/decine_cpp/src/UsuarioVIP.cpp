#include "UsuarioVIP.h"

namespace decine {

	UsuarioVIP::UsuarioVIP(const std::string &nombre, const std::string &correo) {
		this->nombre = nombre;
		this->correo = correo;
	}

	std::string UsuarioVIP::getNombre() {
		return this->nombre;
	}

	std::string UsuarioVIP::getCorreo() {
		return this->correo;
	}

}
