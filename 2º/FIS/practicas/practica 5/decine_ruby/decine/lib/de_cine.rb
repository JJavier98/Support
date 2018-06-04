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
  require_relative "pelicula"
  require_relative "actor"
  require_relative "director"
  require_relative "critica"
  require_relative "festival_premio"
  require_relative "usuario_vip"
  require_relative "genero"
  require_relative "premio"
  
  require "singleton"
  class DeCine

        
    #Hacemos que la clase use el patrón Singleton (unica instancia)
    include Singleton
    
    def inicializar
        @misUsuarios = Array.new
        @misActores = Array.new
        @misDirectores = Array.new
        @misFestivales = Array.new
        @misPeliculas = Array.new      
    end



 
    # Búsqueda de un determinado elemento en un Map

    
    # Obtener todos los id (key) de una lista de objetos.
    def obtener_usuarios

      resultado = ""
      @misUsuarios.each do |usuario|
        resultado += @misusuarios.index(usuario).to_s + ": " + usuario.correo + "\n"
      end
      return resultado
    end
    def obtener_peliculas
      resultado = ""
      @misPeliculas.each do |pelicula|
        resultado += @misPeliculas.index(pelicula).to_s + ": " + pelicula.titulo + "\n"
      end
      return resultado
    end
    def obtener_actores
      resultado = ""
      @misActores.each do |actor|
        resultado += @misActores.index(actor).to_s + ": " + actor.nombre + "\n"
      end  
      return resultado
    end
    def obtener_directores
      resultado = ""
      @misDirectores.each do |director|
        resultado += @misDirectores.index(director).to_s + ": " + director.nombre + "\n"
      end
      return resultado
    end
    def obtener_premios
      resultado = ""
      @misFestivales.each do |festival|
        resultado += @misFestivales.index(festival).to_s + ": " + festival.nombre + "\n"
      end 
      return resultado
    end
 
     # .... Para todos los demas igual la busqueda de uno concreto o de todas sus claves
   
    # Inicialización del sistema 
    def incluir_actor(nombre, nacionalidad, web)
        @misActores << Actor.new(nombre,nacionalidad, web)
    end
    def incluir_director(nombre, nacionalidad, web)
        @misDirectores << Director.new(nombre,nacionalidad, web)
    end
    def incluir_festival_premio(nombre)
        @misFestivales << FestivalPremio.new(nombre)
    end
     def incluir_usuario(nombre, correo)
        @misUsuarios << UsuarioVip.new(nombre,correo)
    end
     
     def incluir_pelicula(pelicula)
        @misPeliculas << pelicula
     end
     
     
     # NOTA DURACION ESTA COMO INT Y FLOAT EN LOS DIAGRAMAS
     
    def nueva_pelicula(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial, productora, sinopsis, recaudacion)

        existe = existe_pelicula(titulo);
        
        if existe
            raise "Esa película ya está incluida en el sistema"
        else
          
          pelicula = Pelicula.new(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial, productora, sinopsis, recaudacion)

          incluir_pelicula(pelicula)         
       
        end
    
    end
    
    def busqueda_pelicula(criterioBusqueda)
        
        resultado = Array.new
        
        
        peliculas = seleccionar_peliculas(criterioBusqueda);
        
        peliculas.each do |pelicula|
        
            datosBasicos = pelicula.obtener_datos_basicos
            
            
            resultado << datosBasicos
            
            directores = pelicula.directores
            
            resultado << "Directores:"
            directores.each do |director|
              resultado << "\t" + director.nombre
            end

    
            
            actores = pelicula.actores
            resultado << "Actores:"
            actores.each do |actor|
              resultado << "\t" + actor.nombre
            end
            
            if criterioBusqueda[0] == 1 
              
                  datosComplementarios = pelicula.obtener_datos_complementarios
                
                
                # Esta mal en el diagrama
                resultado << datosComplementarios
          
            end


        end
        
        
        return resultado #el return no es necesario en ruby
        
    end
    
    def nuevo_genero_pelicula(id_pelicula, genero)
    
        pelicula = buscar_pelicula(id_pelicula)
        
        
        pelicula.vincular_genero(genero);

    end
    
    def nuevo_director_pelicula(id_pelicula, id_director)
        
        pelicula = buscar_pelicula(id_pelicula)

        director = buscar_director(id_director)
        
        pelicula.vincular_director(director)
 
    end

    def nuevo_actor_pelicula(id_pelicula, id_actor)
        
        pelicula = buscar_pelicula(id_pelicula)

        actor = buscar_actor(id_actor)
        
        pelicula.vincular_actor(actor) 
        
    end
    
    def critica_pelicula(id_usuario, id_pelicula, titulo, comentario)
        
        usuario = buscar_usuario(id_usuario)
        
        peli = buscar_pelicula(id_pelicula)
        
        peli.incluir_critica(usuario, titulo, comentario)

        
    end
    
    def nuevo_premio(id_pelicula, id_premio, categoria, año)
        
        pelicula = buscar_pelicula(id_pelicula)
        
        premio = buscar_premio(id_premio)
        
        pelicula.incluir_premio(premio, categoria, año)
        
        
    end
    
    def seleccionar_peliculas(criterioBusqueda)
        
        lista_peliculas = Array.new
        
        @misPeliculas.each do |pelicula|
          
        
          case criterioBusqueda[0]
            when 1 #Pelicula
              if  criterioBusqueda[1] == pelicula.titulo
                lista_peliculas << pelicula
              end
            when 2 #Director
              directores = pelicula.directores
              directores.each do |director|
                if criterioBusqueda[1] == director.nombre 
                  lista_peliculas << pelicula
                  break
                end
              end
              
            when 3 #Actor
              actores = pelicula.actores
              actores.each do |actor|
                if criterioBusqueda[1] == actor.nombre 
                  lista_peliculas << pelicula
                  break
                end
              end
        when 4 #Genero
              generos pelicula.generos
              generos.each do |genero|
                if criterioBusqueda[1] == genero
                  lista_peliculas << pelicula
                  break
                end
              end
          when 5 #Año estreno
              if  criterioBusqueda[1] == pelicula.añoEstreno
                lista_peliculas << pelicula
              end
          end

        
        
        end

       
        return lista_peliculas #el return no es necesario en ruby
        
   end
    
    def existe_pelicula(titulo)
        
        @misPeliculas.each do |pelicula|
          if pelicula.titulo == titulo
              return true
          end
        end
        
        return false
         
    end
    
    def buscar_pelicula(id_pelicula)   
      @misPeliculas.at(id_pelicula)   
    end
    
    def buscar_usuario(id_usuario)
        @misUsuarios.at(id_usuario)  
    end
    
    def buscar_director(id_director)
       @misDirectores.at(id_director) 
    end
    
    def buscar_actor(id_actor)
      @misActores.at(id_actor) 
    end
    
    def buscar_premio(id_festival)
         @misFestivales.at(id_festival) 
    end
  end
end
