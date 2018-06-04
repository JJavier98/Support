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
  class Pelicula
    attr_accessor :titulo, :actores, :directores, :añoEstreno
    def initialize(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial,  productora,  sinopsis, recaudacion)
      @titulo = titulo
      @tituloOriginal = tituloOriginal
      @añoEstreno = añoEstreno
      @duracion = duracion
      @guion = guion
      @musica = musica
      @pais = pais
      @webOficial = webOficial
      @productora = productora
      @sinopsis = sinopsis
      @recaudacion = recaudacion
      
      @generos = Array.new
      @directores = Array.new
      @actores = Array.new

      @premios = Array.new
      @criticas = Array.new
     
    end
    
    def obtener_datos_basicos
      
      resultado = Array.new
      
      resultado << "\tTitulo: " + @titulo
      resultado << "\tAño Estreno: " + @fechaEstreno.to_s
      resultado << "\tDuracion: " + @duracion.to_s
      resultado << "\tRecaudacion: " + @recaudacion.to_s

      
    end
    
    def obtener_datos_complementarios
      
      resultado = Array.new
      
        resultado << "Genero: " + @genero.to_s
        resultado << "Sinopsis: " + @sinopsis        
        
        str_premios = "";
        @premios.each do |premio| 
            str_premios += "\n\t" + premio.obtener_datos.to_s
        end
        resultado << "Premios: " + str_premios    
        
        
        str_criticas = "";
        @criticas.each do |critica|
            str_criticas += "\n\t" + critica.obtener_datos.to_s
        end
        resultado << "Criticas: " + str_criticas   

      
    end
    
    def vincular_genero(genero)
      @generos << genero
    end
    
    def vincular_director(director)
      @directores << director
    end
    
    def vincular_actor(actor)
      @actores << actor
    end
    
    def incluir_critica(usuario, titulo, comentario)
      
      @criticas << Critica.new(usuario, titulo, comentario)
      
      
    end
    
    def incluir_premio(premio, categoria, año)
      
       @premios << Premio.new(premio, categoria, año)
      
    end
    
  end
end