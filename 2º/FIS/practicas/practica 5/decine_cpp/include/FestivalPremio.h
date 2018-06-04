#ifndef FESTIVALPREMIO
#define FESTIVALPREMIO

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

	class FestivalPremio {
	private:
		std::string nombre;

	public:
		FestivalPremio(const std::string &nombre);

		virtual std::string getNombre();
	};

}


#endif	//#ifndef FESTIVALPREMIO
