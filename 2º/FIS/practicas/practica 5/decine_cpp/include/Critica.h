#ifndef CRITICA
#define CRITICA

#include "UsuarioVIP.h"
#include <string>

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


	class Critica {

	private:
		UsuarioVIP *usuario;
		int fecha;
		std::string titulo;
		std::string comentario;

	public:
		Critica(UsuarioVIP *usuario, const std::string &titulo, const std::string &comentario);
		
		virtual std::string obtenerDatosCritica();
	};

}


#endif	//#ifndef CRITICA
