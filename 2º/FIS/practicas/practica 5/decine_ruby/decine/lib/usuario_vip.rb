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
  class UsuarioVip
    attr_reader :nombre, :correo
    def initialize(nombre, correo)
      @nombre = nombre
      @correo = correo
    end
  end
end
