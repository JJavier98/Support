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

import java.util.Date;

class Critica {
    
    private UsuarioVIP usuario;
    private Date fecha;
    private String titulo;
    private String comentario;
        
    Critica(UsuarioVIP usuario, String titulo, String comentario){
        this.usuario = usuario;
        this.fecha = new Date(); // Asignamos la fecha actual
        this.titulo = titulo;
        this.comentario = comentario;
        
    }
    
    String obtenerDatosCritica() {
        
        String resultado = "";
        
        resultado += "\tNombre: " + this.usuario.getNombre() + "\n";
        resultado += "\tFecha: " + String.valueOf(this.fecha) + "\n";

        resultado += "\tTitulo: " + this.titulo + "\n";
        resultado += "\tComentario: " + this.comentario + "\n";
        resultado += "\t-------------------------\n";
        
        return resultado;
        
    }
}
