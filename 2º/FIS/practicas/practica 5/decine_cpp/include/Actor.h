#ifndef ACTOR
#define ACTOR

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

	 class Actor {
	private:
		std::string nombre;
		std::string nacionalidad;
		std::string webOficial;

	public:
		Actor(const std::string &nombre, const std::string &nacionalidad, const std::string &web);

		virtual std::string getNombre();
	 };

}


#endif	//#ifndef ACTOR
