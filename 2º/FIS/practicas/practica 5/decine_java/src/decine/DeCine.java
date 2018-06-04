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
package decine;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class DeCine { 
    
    // Definición de atributos 
    private Map<String,UsuarioVIP> misUsuarios = new HashMap();
    private Map<String, Actor> misActores = new HashMap();
    private Map <String, Director> misDirectores = new HashMap();
    private Map <String, FestivalPremio> misFestivales = new HashMap();
    private Map <String, Pelicula> misPeliculas = new HashMap();

    // incluir los que faltan
    
    // implementación del Singleton
    private static DeCine instancia = new DeCine();
    public static DeCine getDeCine(){
        return instancia;
    }
    private DeCine(){}
    
    // Búsqueda de un determinado elemento en un Map
    private UsuarioVIP buscarUsuario(String correo) throws Exception{    
        if (!misUsuarios.containsKey(correo)) throw new Exception ("no existe el usuario con ese correo");
        return misUsuarios.get(correo);
    }
    
    // Obtener todos los id (key) de una lista de objetos.
    public Set<String> obtenerUsuariosVIP(){
        return  misUsuarios.keySet();    
    }
    public Set<String> obtenerPeliculas(){
        return  misPeliculas.keySet();    
    }
    public Set<String> obtenerActores(){
        return  misActores.keySet();    
    }
    public Set<String> obtenerDirectores(){
        return  misDirectores.keySet();    
    }
    public Set<String> obtenerPremios(){
        return  misFestivales.keySet();    
    }    
 
     // .... Para todos los demas igual la busqueda de uno concreto o de todas sus claves
   
    // Inicialización del sistema 
    public void incluirActor(String nombre, String nacionalidad, String web){
        misActores.put(nombre, new Actor(nombre,nacionalidad, web));
    }
    public void incluirDirector(String nombre, String nacionalidad, String web){
        misDirectores.put(nombre, new Director(nombre,nacionalidad, web));
    }
    public void incluirFestivalPremio(String nombre){
        misFestivales.put(nombre, new FestivalPremio(nombre));
    }
     public void incluirUsuario(String nombre, String correo){
        misUsuarios.put(correo, new UsuarioVIP(nombre,correo));
    }
     
     void incluirPelicula(String titulo, Pelicula pelicula) {
         misPeliculas.put(titulo, pelicula);
     }
     
     
     // NOTA DURACION ESTA COMO INT Y FLOAT EN LOS DIAGRAMAS
     
    public void nuevaPelicula(String titulo, String tituloOriginal, int añoEstreno, int duracion, String guion, String musica, String pais, String webOficial, String productora, String sinopsis, float recaudacion) throws Exception {

        boolean existe = existePelicula(titulo);
        
        if (existe) throw new Exception ("Esa película ya está incluida en el sistema");
        
        Pelicula miPelicula = new Pelicula(titulo, tituloOriginal, añoEstreno, duracion, guion, musica, pais, webOficial, productora, sinopsis, recaudacion);
        
        incluirPelicula(titulo, miPelicula);
        
    
    
    }
    
    public String busquedaPelicula(ArrayList<String> criterioBusqueda) {
        
        
        String resultadoBusqueda = "";
        
        
        ArrayList<Pelicula> peliculas = seleccionarPeliculas(criterioBusqueda);
        
        for (Pelicula pelicula: peliculas) {
        
            String datosBasicos = pelicula.obtenerDatosBasicos();
            
            
            resultadoBusqueda += datosBasicos;
            
            resultadoBusqueda += "Directores:\n";
            ArrayList<Director> directores = pelicula.getDirectores();            
            for (Director director: directores) {
                resultadoBusqueda += director.getNombre() + "\n";
            }
            
            resultadoBusqueda += "Actores:\n";
            ArrayList<Actor> actores = pelicula.getActores();
            for (Actor actor: actores) {
                resultadoBusqueda +=  actor.getNombre() + "\n";
            }
            
            
            
            if (Integer.parseInt(criterioBusqueda.get(0)) == 1) {
            
            
                String datosComplementarios = pelicula.obtenerDatosComplementarios();
                
                
                // Esta mal en el diagrama
                resultadoBusqueda += datosComplementarios;
                
            
            }

            
        }
        
        
        return resultadoBusqueda;
        
    }
    
    public void nuevoGeneroPelicula(String titulo, Genero miGenero) throws Exception {
    
        Pelicula miPelicula = buscarPelicula(titulo);
     
        miPelicula.vincularGenero(miGenero);

        
    
    }
    
    public void nuevoDirectorPelicula(String titulo, String nombreDirector) throws Exception {
        
        Pelicula miPelicula = buscarPelicula(titulo);

        Director miDirector = buscarDirector(nombreDirector);
        
        miPelicula.vincularDirector(miDirector);

        
    }

    public void nuevoActorPelicula(String titulo, String nombreActor) throws Exception {
        
        Pelicula miPelicula = buscarPelicula(titulo);

        Actor miActor = buscarActor(nombreActor);
        
        miPelicula.vincularActor(miActor);  
        
    }
    
    public void criticaPelicula(String correo, String titulo, String tituloCritica, String comentario) throws Exception {
        
        UsuarioVIP uVIP = buscarUsuarioVIP(correo);
        
        Pelicula peli = buscarPelicula(titulo);
        
        peli.incluirCritica(uVIP, tituloCritica, comentario);

        
    }
    
    public void nuevoPremio(String titulo, String nombreFP, String categoria, int año) throws Exception {
        
        Pelicula pelicula = buscarPelicula(titulo);
        
        FestivalPremio premio = buscarPremio(nombreFP);
        
        pelicula.incluirPremio(premio, categoria, año);
        
        
    }
    
    private ArrayList<Pelicula> seleccionarPeliculas(ArrayList<String> criterioBusqueda) {
        
        ArrayList<Pelicula> listaPeliculas = new ArrayList();
        

        
        for(Entry<String, Pelicula> entry : misPeliculas.entrySet()) {
            
            int criterio = Integer.parseInt(criterioBusqueda.get(0));
            String valor = criterioBusqueda.get(1);
            Pelicula pelicula = entry.getValue();
            
            switch (criterio) {
            
                case 1: // Por titulo
                    if (valor.equals(pelicula.getTitulo()))
                        listaPeliculas.add(pelicula);

                    break;
                case 2: // Por director
                    
                    ArrayList<Director> directores = pelicula.getDirectores();
                    for (Director director: directores) {
                    
                        if (valor.equals(director.getNombre())) {
                             listaPeliculas.add(pelicula);
                             break; // Paramos el bucle (ya ha encontrado el elemento
                        }
                    }
                    
                    
                    break;
                case 3: // Por actor
                    
                    ArrayList<Actor> actores = pelicula.getActores();
                    for (Actor actor: actores) {
                    
                        if (valor.equals(actor.getNombre())) {
                             listaPeliculas.add(pelicula);
                             break; // Paramos el bucle (ya ha encontrado el elemento
                        }
                    }
                    
                    
                    break;
                case 4: // Por genero
                    
                    ArrayList<Genero> generos = pelicula.getGeneros();
                    for (Genero genero: generos) {
                    
                        if (genero.equals(Genero.valueOf(valor))) {
                            listaPeliculas.add(pelicula);
                             break; // Paramos el bucle (ya ha encontrado el elemento
                        }
                        
                    }
                    
                    break;
                case 5: // Por año estreno
                    
                    if (Integer.parseInt(valor) == pelicula.getAñoEstreno()) {
                             listaPeliculas.add(pelicula);
                    
                    
                    break;
                    
            
            
            }
                 
           
                
                
            }
            
        }
       
        return listaPeliculas;
        
    }
    
    private boolean existePelicula(String titulo) throws Exception {
         
        return misPeliculas.containsKey(titulo);
    }
    
    private Pelicula buscarPelicula(String titulo) throws Exception {

        if (!misPeliculas.containsKey(titulo)) throw new Exception ("no existe la pelicula id");
        return misPeliculas.get(titulo);
    }
    
    private UsuarioVIP buscarUsuarioVIP(String correo) throws Exception {
        if (!misUsuarios.containsKey(correo)) throw new Exception ("no existe el usuario con ese correo");
        return misUsuarios.get(correo);
    }
    
    private Director buscarDirector(String idDirector) throws Exception {
        
        if (!misDirectores.containsKey(idDirector)) throw new Exception ("no existe el director con ese id: " + idDirector);
        return misDirectores.get(idDirector);
        
    }
    
    private Actor buscarActor(String idActor) throws Exception {
        if (!misActores.containsKey(idActor)) throw new Exception ("no existe el actor con ese id");
        return misActores.get(idActor);
    }
    
    private FestivalPremio buscarPremio(String nombre) throws Exception {
        if (!misFestivales.containsKey(nombre)) throw new Exception ("no existe el festival con ese nombre");
        return misFestivales.get(nombre);
    }
     
     
}
