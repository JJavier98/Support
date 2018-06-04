# encoding: UTF-8
# 
#   Fundamentos de Ingenieria del Software
#   Grado en Ingeniería Informática
#
#   2014 © Copyleft - All Wrongs Reserved
# 
#   Ernesto Serrano <erseco@correo.ugr.es>
#   Carlos Garrancho
#   Pablo Martinez
#

module Decine
  class Director
    attr_reader :nombre, :nacionalidad, :webOficial

		def initialize(nombre, nacionalidad, web)
			@nombre = nombre
			@nacionalidad = nacionalidad
			@webOficial = web
		end
  end
end
