#ifndef PREMIO
#define PREMIO

#include "FestivalPremio.h"
#include <string>
#include "stringconverter.h"

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

	class Premio {
	private:
		FestivalPremio *premio;
		std::string categoriaPremio;
		int año;

	public:
		Premio(FestivalPremio *premio, const std::string &categoria, int año);

		virtual std::string obtenerDatos();

	private:
		void InitializeInstanceFields();
	};

}


#endif	//#ifndef PREMIO
