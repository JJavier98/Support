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

import com.sun.org.apache.bcel.internal.generic.IMPDEP1;
import java.util.ArrayList;
import java.util.List;

class Pelicula {
    private String titulo;
    private String tituloOriginal;
    private int añoEstreno;
    private int duracion;
    private String guion;
    private String musica;
    private String pais;
    private String webOficial;
    private String productora;
    private String sinopsis;
    private float recaudacion;
    
    private ArrayList<Genero> generos = new ArrayList();
    private ArrayList<Director> directores = new ArrayList();
    private ArrayList<Actor> actores = new ArrayList();
    
    private ArrayList<Premio> premios = new ArrayList();
    
    private ArrayList<Critica> criticas = new ArrayList();

    

    Pelicula(String titulo, String tituloOriginal, int añoEstreno, int duracion, String guion, String musica, String pais, String webOficial, String  productora, String  sinopsis, float recaudacion){
        this.titulo = titulo;
        this.tituloOriginal = tituloOriginal;
        this.añoEstreno = añoEstreno;
        this.duracion = duracion;
        this.guion = guion;
        this.musica = musica;
        this.pais = pais;
        this.webOficial = webOficial;
        this.productora = productora;
        this.sinopsis = sinopsis;
        this.recaudacion = recaudacion;
    }
    
    String obtenerDatosBasicos() {
        
        String resultado = "";
        
        resultado += "Titulo: " + this.titulo + "\n";
        resultado += "Año Estreno: " + String.valueOf(this.añoEstreno) + "\n";
        resultado += "Duracion: " + String.valueOf(this.duracion) + "\n";
        resultado += "Recaudacion: " + String.valueOf(this.recaudacion) + "\n";

        return resultado;
        
    }
    
    String obtenerDatosComplementarios() {
        
        String resultado = "";
        
        resultado += "Genero: " + this.generos.toString() + "\n";
        resultado += "Sinopsis: " + this.sinopsis + "\n";        
        
        resultado += "Premios: " + "\n";   
        for (Premio premio: this.premios) {
            resultado +=  premio.obtenerDatos() + "\n";
        }
         
        
        
        resultado += "Criticas: " + "\n";   
        for (Critica critica: this.criticas) {
            resultado += critica.obtenerDatosCritica() + "\n";
        }
         

        
        return resultado;
        
    }
    
    String getTitulo() {
        return this.titulo;
    }
    
    int getAñoEstreno() {
        return this.añoEstreno;
    }
    
    ArrayList<Genero> getGeneros() {
        return this.generos;
    }
    
    ArrayList<Director> getDirectores() {
        return this.directores;
    }
    
    ArrayList<Actor> getActores() {
        return this.actores;
    }
    
    void vincularGenero(Genero miGenero) {
        this.generos.add(miGenero);
    }
    
    void vincularDirector(Director miDirector) {
        this.directores.add(miDirector);
    }
    
    void vincularActor(Actor miActor) {
        this.actores.add(miActor);
    }
    
    void incluirCritica(UsuarioVIP uVIP, String titulo, String comentario) {
        
        Critica miCritica = new Critica(uVIP, titulo, comentario);
        
        this.criticas.add(miCritica);
        
    }
    
    void incluirPremio(FestivalPremio premio, String categoria, int año) {
        
        Premio miPremio = new Premio(premio, categoria, año);
        
        this.premios.add(miPremio);
        
        
    }


}
