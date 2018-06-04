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
/* 
 Con este main tenéis que probar todo el diseño que os hemos dejado.
 Si ejecutáis este código veréis que funciona (permite incluir UsuariosVIP)
 Una vez incluidos los usuarios VIP, con la opción 9 de muestran su correos, para elegir uno de ellos
 */
package IUDeCine;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import decine.Genero;
import decine.DeCine;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import javax.swing.JOptionPane;

/**
 *
 * @author ana
 */
public class Decine {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // Obtención de la única instancia de DeCine, DeCine es un singleton. 
        DeCine unaDeCine = DeCine.getDeCine();

        //Definición de la variable in que va a permitir leer String desde teclado.  
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        // Ejemplos de lectura desde teclado con in.readLine()
        // String s = in.readLine();        //Lectura de un String
        // double d= Double.parseDouble(in.readLine());         // lectura de un duoble
        // int i = Integer.parseInt(in.readLine());         // lectura d10e un int               
        // Genero estado = Genero.valueOf(in.readLine());       // lectura de un enum   
        
        
        // Introducimos algunos actores y películas a mano, para que no esté vacío el sistema
        try{
            unaDeCine.nuevaPelicula("El bosque animado", "El bosque animado", 1986, 100, "adaptado", "musico profesional", "España", "sin web", "el deseo s.a.", "sinopsis", 10000);
            unaDeCine.nuevaPelicula("La vida de brian", "Brian's life", 1986, 100, "adaptado", "musico profesional", "UK", "sin web", "monty Python", "vida de brian de nazaret", 10000);
            unaDeCine.nuevaPelicula("El Hobbit", "The Hobbbit", 2010, 100, "adaptado", "musico profesional", "Nueva Zelanda", "sin web", "Universal", "Un hobbit va por ahi dando vueltas cholando anillos hasta que un dragon se lo quita", 10000);
            unaDeCine.nuevaPelicula("Karate a muerte en torremolinos", "Karate a muerte en Torremolinos", 1999, 100, "adaptado", "musico semi-profesional", "España", "sin web", "Jess Franco.", "El doctor Malvedades despierta a la bestia jocántaro, solo los surfistas católicos podran salvar a la humanidad", 10000);
            unaDeCine.nuevaPelicula("El bueno, el feo y el malo", "The good, the bad & the ugly", 1960, 100, "adaptado", "musico profesional", "Italia", "sin web", "MGM", "Todo un clásico", 10000);

        } catch(Exception e) {
        
            System.out.println(e.getMessage());
        
        }
        
            

        
        unaDeCine.incluirActor("Antonio Resines", "España", "no");
        unaDeCine.incluirActor("Miguel Rellan", "España", "no");
        unaDeCine.incluirActor("Gabino Diego", "España", "no");
        unaDeCine.incluirActor("Fernando Fernan Gomez", "España", "no");
        unaDeCine.incluirActor("Luis Ciges", "España", "no");
        unaDeCine.incluirActor("Carlos Larrañaga", "España", "no");
    
        
        unaDeCine.incluirDirector("Lars Von Trier", "Dinamarca", "www.lars.com");
        unaDeCine.incluirDirector("Pedro Almodovar", "España", "www.pedro.com");
        unaDeCine.incluirDirector("Sergio Leone", "Italia", "www.dollar.com");
        unaDeCine.incluirDirector("Pedro Temboury", "España", "www.karateamuerteentorremolinos.com");
        
        
        unaDeCine.incluirUsuario("Ernesto", "erseco@correo.ugr.es");
        unaDeCine.incluirUsuario("Pablo", "pableitor@correo.ugr.es");
        unaDeCine.incluirUsuario("Carlos", "cgarrancho@correo.ugr.es");
        
        unaDeCine.incluirFestivalPremio("Festival de Cannes");
        unaDeCine.incluirFestivalPremio("Oscars");
        unaDeCine.incluirFestivalPremio("Concha de oro");
        

        
        try {
            unaDeCine.nuevoActorPelicula("La vida de brian", "Fernando Fernan Gomez");
            unaDeCine.nuevoDirectorPelicula("La vida de brian", "Lars Von Trier");
            unaDeCine.nuevoGeneroPelicula("La vida de brian", Genero.Aventura);
            unaDeCine.nuevoGeneroPelicula("La vida de brian", Genero.CienciaFiccion);
            unaDeCine.nuevoPremio("La vida de brian", "Oscars", "Comedia", 1986);
            
            
            unaDeCine.nuevoActorPelicula("El bosque animado", "Fernando Fernan Gomez");
            unaDeCine.nuevoDirectorPelicula("El bosque animado", "Lars Von Trier");
            unaDeCine.nuevoGeneroPelicula("El bosque animado", Genero.CienciaFiccion);
            unaDeCine.nuevoPremio("El bosque animado", "Oscars", "Comedia", 1987);
            
            
            unaDeCine.nuevoActorPelicula("El bosque animado", "Luis Ciges");
            unaDeCine.nuevoActorPelicula("El bosque animado", "Miguel Rellan");
            unaDeCine.nuevoPremio("El bosque animado", "Concha de oro", "Comedia", 1987);
            
            unaDeCine.criticaPelicula("erseco@correo.ugr.es", "El bosque animado", "Muy buena", "Una de las obras maestras de Wenceslao Fernandez Flores");
            unaDeCine.criticaPelicula("erseco@correo.ugr.es", "La vida de brian", "Divertida", "Una gran pelicula de los Monty Python");
            unaDeCine.criticaPelicula("erseco@correo.ugr.es", "El bueno, el feo y el malo", "Un clasico", "Uno de los grandes clasicos del cine");

        } catch (Exception e) {
        }
            


        int opcion = 0; //variable que controla la opción de menú

        do { //do-while que controlara todo el menú
            try { // tratamiento de las excepciones. Bloque try en el que se puede producir una excepción y la capturamos

                //Terminar de diseñar el menú (usando System.out.println(...)) con las opciones que faltan
                // Podéis hacer vuestros propios diseños de interfaz, esta es la interfaz mínima que tenéis que entregar
                System.out.println("******** ALTAS*****************************");
                System.out.println("1. Dar de alta un película \n"
                        + "2. Dar de alta un actor \n"
                        + "3. Dar de alta un director \n"
                        + "4. Dar de alte un UsuarioVIP \n"
                        + "5. Dar de alta un Festival/Premio");

                System.out.println("\n ******  MODIFICACIONES *****************************");
                System.out.println("6. Incluir un directr en una  película \n"
                        + "7. Incluir un actor en una película \n"
                        + "8. Incluir premio de película \n"
                        + "9. Incluir crítica de película");
                System.out.println("\n ******  CONSULTA  *****************************");
                System.out.println("10. Consultar película");
                System.out.println("\n ****** TERMINAR *****************************");
                System.out.println("0. Terminar");

                // Lectura de un int, para darle valor a opcion.
                opcion = Integer.parseInt(in.readLine());

                // Estructura switch con todas las opciones de menú. Algunos de ellos ya lo tenéis hecho
                // Tenéis que terminar las opciones que están incompletas y las que no están hechas
                switch (opcion) {
                    case 1: /*todo lo que hay que hacer para dar de alta una película
                         lectura de los valores de inicialización de la pelicula, son:                                                        
                                    
                         * Titulo: ----
                         * Titulo Original ---
                         * Fecha de Estreno
                         * Duracion:----
                         * Guion --
                         * Musica---
                         * Pais:---
                         * Web oficial ---
                         * Productora --
                         * Sinopsis: ----
                         * Recaudacion
                         * Generos:---,---,---.                              
                         Una vez leída, mensaje a unaDeCine para que incluya una nueva película */

                        System.out.println("Titulo:");
                        String titulo = in.readLine();
                        System.out.println("Titulo Origional:");
                        String tituloOriginal = in.readLine();
                        System.out.println("Año estreno:");
                        int añoEstreno = Integer.parseInt(in.readLine()); // Lo hemos pasado de fecha a año de estreno por comodidad
                        System.out.println("Duracion:");
                        int duracion = Integer.parseInt(in.readLine());
                        System.out.println("Guion:");
                        String guion = in.readLine();
                        System.out.println("Musica:");
                        String musica = in.readLine();
                        System.out.println("Pais:");
                        String pais = in.readLine();
                        System.out.println("web Oficial:");
                        String webOficial = in.readLine();
                        System.out.println("Productora:");
                        String productora = in.readLine();
                        System.out.println("Sinopsis:");
                        String sinopsis = in.readLine();
                        System.out.println("Recaudacion:");
                        int recaudacion = Integer.parseInt(in.readLine());
                        System.out.println("Genero: 1=Aventura, 2=CienciaFiccion, 3=Drama");

                        Genero genero;
                        int generoOption = Integer.parseInt(in.readLine());

                        if (generoOption == 1) {
                            genero = Genero.Aventura;
                        } else if (generoOption == 2) {
                            genero = Genero.CienciaFiccion;
                        } else {
                            genero = Genero.Drama;
                        }

                        unaDeCine.nuevaPelicula(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial, productora, sinopsis, recaudacion);

                        unaDeCine.nuevoGeneroPelicula(titulo, genero);
                        
                        break;
                    case 2:/*Dar de alta un actor */
                        System.out.println("Nombre del Actor:");
                        String nombreA = in.readLine();
                        System.out.println("Nacionalidad del Actor:");
                        String nacionalidadA = in.readLine();
                        System.out.println("Web oficial del Actor:");
                        String webA = in.readLine();
                        unaDeCine.incluirActor(nombreA, nacionalidadA, webA);
                        break;
                    case 3: /*Dar de alta a un Director */
                        System.out.println("Nombre del Director:");
                        String nombreD = in.readLine();
                        System.out.println("Nacionalidad del Directorr:");
                        String nacionalidadD = in.readLine();
                        System.out.println("Web oficial del Director:");
                        String webD = in.readLine();
                        unaDeCine.incluirDirector(nombreD, nacionalidadD, webD);
                        break;
                    case 4: /* Dar de alta a un usuario VIP  */
                        System.out.println("Nombre del Usuario VIP:");
                        String nombreU = in.readLine();
                        System.out.println("Correo del Usuario VIP:");
                        String correo = in.readLine();
                        unaDeCine.incluirUsuario(nombreU, correo);
                        break;
                    case 5: /* Dar de alta un Festival  o Premio  */
                        System.out.println("Nombre del Festival o Premio:");
                        String nombreF = in.readLine();
                        unaDeCine.incluirFestivalPremio(nombreF);
                        break;
                    case 6: /* Incluir  un director en una película
                         Obtener a todos los directores disponibles
                         Lectura del nombre del director 
                         Obtener todas las películas disponibles (título y año de estreno)
                         Lectura  del título de la pelicula.
                         Lectura del año de estreno
                         mensaje a unaDeCine para que incluya a ese director en esa película 
                         */

                        Set<String> directores = unaDeCine.obtenerDirectores();
                        String director = MostrarCombo("Seleccione un director", directores.toArray());
                        
                        Set<String> peliculas = unaDeCine.obtenerPeliculas();
                        String pelicula = MostrarCombo("Seleccione una pelicula", peliculas.toArray());

                        unaDeCine.nuevoDirectorPelicula(pelicula, director);

                        break;
                    case 7: /* Incluir  un actor en una pelicula */
                        
                        Set<String> actores = unaDeCine.obtenerActores();
                        String actor = MostrarCombo("Seleccione un actor", actores.toArray());
                        
                        peliculas = unaDeCine.obtenerPeliculas();
                        pelicula = MostrarCombo("Seleccione una pelicula", peliculas.toArray());

                        unaDeCine.nuevoActorPelicula(pelicula, actor);

                        break;
                    case 8: /*Incluir un premio a pelicula
                         Obtener  los Premios o Festivales  disponibles en el sistem                                                          
                         Lectura del nombre del premio o festival
                         Obtener todas las películas disponibles (título y año de estreno)
                         Lectura  del título de la pelicula.
                         Lectura del año de estreno
                         mensaje a unaDeCine para que incluya  ese premio a la pelicula 
                         */
                        peliculas = unaDeCine.obtenerPeliculas();
                        pelicula = MostrarCombo("Seleccione una pelicula", peliculas.toArray());
                        
                        Set<String> premios = unaDeCine.obtenerPremios();
                        String premio = MostrarCombo("Seleccione un premio", premios.toArray());
                        
                        
                        String categoria = MostrarInput("Introduzca la categoria:");
                        int año = Integer.parseInt(MostrarInput("Introduzca el año:"));
                    

                        unaDeCine.nuevoPremio(pelicula, premio, categoria, año);



                        break;
                    case 9: /* Incluir una critica a pelicula
                         Obtener los usuarios VIP disponibles en el sistema*/
                        
                        
                        peliculas = unaDeCine.obtenerPeliculas();
                        pelicula = MostrarCombo("Seleccione una pelicula", peliculas.toArray());
                        
                        Set<String> usuarios = unaDeCine.obtenerUsuariosVIP();
                        String usuario = MostrarCombo("Seleccione un usuario", usuarios.toArray());
                        
                        
                        String tituloCritica = MostrarInput("Introduzca un titulo para la critica:");
                        String comentario = MostrarInput("Introduzca un comentario:");

                        unaDeCine.criticaPelicula(usuario, pelicula, tituloCritica, comentario);

                        break;
                    case 10: /* Consultar una pelicula por distintos criterios:
                         Lectura del criterio de consulta 
                         (1 == por titulo, 1 == por Director, 3 == por Actor, 4== genero, 5 == año de estreno)
                         Lectura del valor de la busqueda
                         mensaje a unaDeCine para que realice la busqueda
                         muestra del resultado de la busqueda (esta salida tiene que estar bien elaborada)
                         */

                        System.out.println("Criterio de busqueda: 1 == por titulo, 2 == por Director, 3 == por Actor, 4== genero, 5 == año de estreno");
                        String criterio = in.readLine();
                        System.out.println("Valor de busqueda:");
                        String valor = in.readLine();

                        ArrayList<String> criterioBusqueda = new ArrayList();
                        criterioBusqueda.add(criterio);
                        criterioBusqueda.add(valor);


                        String resultado = unaDeCine.busquedaPelicula(criterioBusqueda);


                        System.out.println(resultado);

                        break;
                }
            } catch (Exception ex) { // captura de la excepción
                System.err.println(ex);
            }
        } while (opcion != 0);
    } // de main(...)
    
    
    static String MostrarCombo(String mensaje, Object[] opciones) {
    
        return (String) JOptionPane.showInputDialog(null,  mensaje, "DeCine", JOptionPane.QUESTION_MESSAGE, null, opciones, null);
                       
    }
    
    static String MostrarInput(String mensaje) {
        return (String) JOptionPane.showInputDialog(null,  mensaje, "DeCine", JOptionPane.QUESTION_MESSAGE);

    }
    
}
