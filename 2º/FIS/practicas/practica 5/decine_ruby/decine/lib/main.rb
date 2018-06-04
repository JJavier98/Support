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
  
  require_relative 'de_cine'
    
  
  #Obtenemos la instancia (singleton) de DeCine
  una_de_cine = DeCine.instance
  una_de_cine.inicializar
  
  una_de_cine.nueva_pelicula("El bosque animado", "El bosque animado", 1986, 100, "adaptado", "musico profesional", "España", "sin web", "el deseo s.a.", "sinopsis", 10000)
  una_de_cine.nueva_pelicula("La vida de brian", "Brian's life", 1986, 100, "adaptado", "musico profesional", "UK", "sin web", "monty Python", "vida de brian de nazaret", 10000)
  una_de_cine.nueva_pelicula("El Hobbit", "The Hobbbit", 2010, 100, "adaptado", "musico profesional", "Nueva Zelanda", "sin web", "Universal", "Un hobbit va por ahi dando vueltas cholando anillos hasta que un dragon se lo quita", 10000)
  una_de_cine.nueva_pelicula("Karate a muerte en torremolinos", "Karate a muerte en Torremolinos", 1999, 100, "adaptado", "musico semi-profesional", "España", "sin web", "Jess Franco.", "El doctor Malvedades despierta a la bestia jocántaro, solo los surfistas católicos podran salvar a la humanidad", 10000)
  una_de_cine.nueva_pelicula("El bueno, el feo y el malo", "The good, the bad & the ugly", 1960, 100, "adaptado", "musico profesional", "Italia", "sin web", "MGM", "Todo un clásico", 10000)

  
  
  
  una_de_cine.incluir_actor("Antonio Resines", "España", "no")
  una_de_cine.incluir_actor("Miguel Rellan", "España", "no")
  una_de_cine.incluir_actor("Gabino Diego", "España", "no")
  una_de_cine.incluir_actor("Fernando Fernan Gomez", "España", "no")
  una_de_cine.incluir_actor("Luis Ciges", "España", "no")
  una_de_cine.incluir_actor("Carlos Larrañaga", "España", "no")


  una_de_cine.incluir_director("Lars Von Trier", "Dinamarca", "www.lars.com")
  una_de_cine.incluir_director("Pedro Almodovar", "España", "www.pedro.com")
  una_de_cine.incluir_director("Sergio Leone", "Italia", "www.dollar.com")
  una_de_cine.incluir_director("Pedro Temboury", "España", "www.karateamuerteentorremolinos.com")


  una_de_cine.incluir_usuario("Ernesto", "erseco@correo.ugr.es")
  una_de_cine.incluir_usuario("Pablo", "pableitor@correo.ugr.es")
  una_de_cine.incluir_usuario("Carlos", "cgarrancho@correo.ugr.es")

  una_de_cine.incluir_festival_premio("Festival de Cannes")
  una_de_cine.incluir_festival_premio("Oscars")
  una_de_cine.incluir_festival_premio("Concha de oro")

  
  una_de_cine.nuevo_actor_pelicula(1, 2)
  una_de_cine.nuevo_director_pelicula(1, 0)
  una_de_cine.nuevo_genero_pelicula(1, :DRAMA)
  una_de_cine.nuevo_genero_pelicula(1, :CIENCIAFICCION)
  una_de_cine.nuevo_premio(1, 2, "Comedia", 1986)

  una_de_cine.nuevo_actor_pelicula(0, 2)
  una_de_cine.nuevo_director_pelicula(0, 0)
  una_de_cine.nuevo_genero_pelicula(0, :CIENCIAFICCION)
  una_de_cine.nuevo_premio(0, 0, "Comedia", 1987)

  una_de_cine.nuevo_actor_pelicula(0, 0)
  una_de_cine.nuevo_actor_pelicula(0, 1)
  una_de_cine.nuevo_premio(0, 1, "Comedia", 1987)

  una_de_cine.critica_pelicula(0, 0, "Muy buena", "Una de las obras maestras de Wenceslao Fernandez Flores")
  una_de_cine.critica_pelicula(0, 1, "Divertida", "Una gran pelicula de los Monty Python")
  una_de_cine.critica_pelicula(0, 4, "Un clasico", "Uno de los grandes clasicos del cine")

  
  
    
  opcion = 0;

  begin


    puts "******** ALTAS********************************"
    puts "1. Dar de alta un película "
    puts "2. Dar de alta un actor "
    puts "3. Dar de alta un director "
    puts "4. Dar de alte un UsuarioVIP "
    puts "5. Dar de alta un Festival/Premio"
    puts " ******  MODIFICACIONES **********************"
    puts "6. Incluir un director en una  película "
    puts "7. Incluir un actor en una película"
    puts "8. Incluir premio de película "
    puts "9. Incluir crítica de película"
    puts " ******  CONSULTA  ***************************"
    puts "10. Consultar película"
    puts " ****** TERMINAR *****************************"
    puts "0. Terminar"

    print "Comando: "
    opcion = gets.chomp.to_i
    puts ""

    case opcion
    when 1
   
      puts "Titulo:"
      titulo = gets.chomp
      puts "Titulo Original:" 
      tituloOriginal = gets.chomp
      puts "Año Estreno:" 
      añoEstreno = gets.chomp.to_i
      puts "Duracion:" 
      duracion = gets.chomp.to_i
      puts "Guion:"
      guion = gets.chomp 
      puts "Musica:"
      musica = gets.chomp
      puts "Pais:" 
      pais = gets.chomp 
      puts "Web Oficial:"
      webOficial = gets.chomp 
      puts "Productora:"
      productora = gets.chomp 
      puts "Sinopsis:"
      sinopsis = gets.chomp
      puts "Recaudacion:"
      recaudacion = gets.chomp.to_i

      
      una_de_cine.nueva_pelicula(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial, productora, sinopsis, recaudacion);



    when 2
      print "Nombre del Actor:"
      nombre = gets.chomp
      print "Nacionalidad del Actor:"
      pais = gets.chomp
      print "Web oficial del Actor:"
      web = gets.chomp
      una_de_cine.incluir_actor(nombre, pais, web);
    when 3
      print "Nombre del Director:"
      nombre = gets.chomp
      print "Nacionalidad del Director:"
      pais = gets.chomp
      print "Web oficial del Director:"
      web = gets.chomp
      una_de_cine.incluir_director(nombre, pais, web);
    when 4
      print "Nombre del Usuario:"
      nombre = gets.chomp
      print "Correo del usuario:"
      correo = gets.chomp
      una_de_cine.incluir_usuario(nombre, correo);
    when 5
      print "Nombre del Festival o Premio:"
      nombre = gets.chomp
      una_de_cine.incluir_festival_premio(nombre);
    when 6
      
      
      puts "Directores----"
      puts una_de_cine.obtener_directores
      print "Seleccione director:"
      id_director = gets.chomp.to_i
      
      
      puts "Peliculas----"
      puts una_de_cine.obtener_peliculas
      print "Seleccione pelicula:"
      id_pelicula = gets.chomp.to_i 
      
      
      una_de_cine.nuevo_director_pelicula(id_pelicula, id_director);
      
      
    when 7
      
      puts "Actores----"
      puts una_de_cine.obtener_actores
      print "Seleccione actor:"
      id_actor = gets.chomp.to_i
      
      
      puts "Peliculas----"
      puts una_de_cine.obtener_peliculas
      print "Seleccione pelicula:"
      id_pelicula = gets.chomp.to_i 
      
      una_de_cine.nuevo_actor_pelicula(id_pelicula, id_actor);
      
    when 8
      
      puts "Peliculas----"
      puts una_de_cine.obtener_peliculas
      print "Seleccione pelicula:"
      id_pelicula = gets.chomp.to_i 
      
      puts "Premios----"
      puts una_de_cine.obtener_premios
      print "Seleccione premio:"
      id_premio = gets.chomp.to_i
      
      print "Introduzca categoria:"
      categoria = gets.chomp
      print "Introduzca año:"
      año = gets.chomp.to_i

      una_de_cine.nuevo_premio(id_pelicula, id_premio, categoria, año);
      
    when 9
      
      puts "Peliculas----"
      puts una_de_cine.obtener_peliculas
      print "Seleccione pelicula:"
      id_pelicula = gets.chomp.to_i 
      
      puts "Usuario----"
      puts una_de_cine.obtener_usuarios
      print "Seleccione usuario:"
      id_usuario = gets.chomp.to_i
      
      print "Introduzca titulo:"
      titulo = gets.chomp
      print "Introduzca comentario:"
      comentario = gets.chomp
      
      una_de_cine.critica_pelicula(id_usuario, id_pelicula, titulo, comentario);
      
    when 10
      
      puts "Criterio de busqueda: 1: por titulo, 2: por Director, 3: por Actor, 4: genero, 5: año de estreno"

      criterio = gets.chomp.to_i
      puts "Valor de busqueda:"
      valor = gets.chomp

      criterio_busqueda = Array.new
      criterio_busqueda << criterio
      criterio_busqueda << valor


      puts una_de_cine.busqueda_pelicula(criterio_busqueda);
      
    else
      puts "-----------------"
      puts "Opcion incorrecta\n"

    end

  end while opcion != 0 

end
