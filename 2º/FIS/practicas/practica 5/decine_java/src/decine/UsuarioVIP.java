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

public class UsuarioVIP {
    private String nombre;
    private String correo;
    
    UsuarioVIP(String nombre, String correo){
        this.nombre = nombre;
        this.correo = correo;
    }
    
    String getNombre() {
        return this.nombre;
    }
}
