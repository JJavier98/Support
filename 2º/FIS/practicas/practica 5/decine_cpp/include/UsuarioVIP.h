#ifndef USUARIOVIP
#define USUARIOVIP

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

	class UsuarioVIP {
	private:
		std::string nombre;
		std::string correo;

	public:
		UsuarioVIP(const std::string &nombre, const std::string &correo);

		virtual std::string getNombre();
		virtual std::string getCorreo();
	};

}


#endif	//#ifndef USUARIOVIP
