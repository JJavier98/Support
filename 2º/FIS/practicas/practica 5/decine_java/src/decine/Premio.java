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

class Premio {
    private FestivalPremio premio;
    private String categoriaPremio;
    private int año;
    
    Premio(FestivalPremio premio, String categoria, int año){
        this.premio = premio;
        this.categoriaPremio = categoria;
        this.año = año;
    }
    
    String obtenerDatos() {
        
        String resultado = "";
        
        resultado += "\tNombre: " + this.premio.getNombre() + "\n";
        resultado += "\tCategoria: " + this.categoriaPremio + "\n";
        resultado += "\tAño: " + String.valueOf(this.año) + "\n";
        resultado += "\t------------\n";
        
        return resultado;
        
    }
}
