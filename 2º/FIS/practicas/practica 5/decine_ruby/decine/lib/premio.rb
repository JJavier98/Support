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
  class Premio
    def initialize(premio, categoria, año)
      @premio = premio
      @categoria = categoria
      @año = año
    end
    
    def obtener_datos
      
      resultado = ""
      
      resultado += "\n\tNombre: " + @premio.nombre
      resultado += "\n\tCategoria: " + @categoria
      resultado += "\n\tAño: " + @año.to_s
      resultado += "\n\t------------"

      return resultado
      
    end
    
    
  end
end

