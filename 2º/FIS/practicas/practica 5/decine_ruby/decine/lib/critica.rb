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
	class Critica
		def initialize(usuario, titulo, comentario)
			@usuario = usuario
			@fecha = Time.new # Asignamos la fecha actual
			@titulo = titulo
			@comentario = comentario
		end

		def obtener_datos
      
      resultado = ""
      
      resultado += "\n\tNombre: " + @usuario.nombre
      resultado += "\n\tFecha: " + @fecha.to_s
      resultado += "\n\tTitulo: " + @titulo
      resultado += "\n\tComentario: " + @comentario
      resultado += "\n\t------------"
      
      return resultado
      
		end
	end
end
