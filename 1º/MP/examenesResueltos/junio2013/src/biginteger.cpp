
#include "biginteger.h"

using namespace std;

/**
 * Constructor a partir de cadena de caracteres
 * @param cadena
 */
BigInteger::BigInteger(const char * cadena){   
   // Se determina la longitud de la cadena y se reserva espacio
   // para los caracteres
   reservarEspacio(strlen(cadena));
   cout << "Numero de caracteres en la cadena: " << strlen(cadena) << endl;
   
   // Se trata caracter a caracter
   for(int i=0; i < strlen(cadena); i++){
      datos[numeroDigitos-i-1]=cadena[i]-'0';
   }
}

/**
  * Constructor a partir de valor
  * @param valor
  */
BigInteger::BigInteger(unsigned long int valor){
   // En una primera pasada hay que determinar el numero
   // de digitos del numero
   int maximaPotencia=0;
   unsigned long int copiaValor=valor;
   while(copiaValor > 0){
      copiaValor=copiaValor/10;
      maximaPotencia++;
   }
   
   // Se reserva espacio para maxima potencia
   reservarEspacio(maximaPotencia);
   
   // Se van asignando los digitos
   for(int i=0; i < numeroDigitos; i++){
      datos[i]=valor%10;
      valor=valor/10;
   }
}

BigInteger::BigInteger(const BigInteger &otro){
   // Se reserva espacio de memoria
   reservarEspacio(otro.numeroDigitos);
   
   // Se copian los datos
   copiarDatos(otro);
}

const BigInteger & BigInteger::operator=(const BigInteger &otro){
   // Evitar asignacion con this como argumento
   if(&otro != this){
      // Se libera el espacio
      liberarEspacio();
      
      // Se reserva espacio
      reservarEspacio(otro.numeroDigitos);
      
      // Se copian los datos
      copiarDatos(otro);
   }
   
   // Se devuelve this
   return *this;
}

const BigInteger & BigInteger::operator+(const BigInteger &otro){
   // Se determina si hay acarreo
   bool acarreo=hayAcarreo(otro);
   
   // En caso de haberlo, se reserva el espacio del mayor de los
   // numeros mas 1
   const BigInteger *mayor, *menor;
   if(numeroDigitos > otro.numeroDigitos){
      mayor=this;
      menor=&otro;
   }
   else{
      mayor=&otro;
      menor=this;
   }
      
   // Se reserva ahora nuevo espacio
   int *nuevosDatos;
   int nuevoTam;
   if (acarreo){
      nuevoTam=mayor->numeroDigitos+1;
   }
   else{
      nuevoTam=mayor->numeroDigitos;
   }
   
   // Se reserva espacio
   nuevosDatos=new int[nuevoTam];
   
   // Se va considerando digito a digito, con todas las
   // cifras del menor
   int digitoMenor, digitoMayor, suma;
   acarreo=false;
   for(int i=0; i < menor->numeroDigitos; i++){
      digitoMenor=menor->datos[i];
      digitoMayor=mayor->datos[i];
      suma=digitoMayor+digitoMenor;
      
      // Si hay acarreo de antes se suma
      if (acarreo){
         suma++;
      }
      
      // Se trata el digito a almacenar y el siguiente acarreo
      if(suma > 9){
         nuevosDatos[i]=(suma%10);
         acarreo=true;
      }
      else{
         nuevosDatos[i]=suma;
         acarreo=false;
      }
   }
   
   // Ahora hay que continuar con las del mayor
   for(int i=menor->numeroDigitos; i < mayor->numeroDigitos; i++){
      digitoMayor=mayor->datos[i];
      
      // Si hay acarreo previo se suma
      if (acarreo){
         digitoMayor++;
      }
      
      // Se trata el numero a almacenar
      if(digitoMayor > 9){
         nuevosDatos[i]=(digitoMayor%10);
         acarreo=true;
      }
      else{
         nuevosDatos[i]=digitoMayor;
         acarreo=false;
      }
   }
   
   // Quedaria por tratar el posible ultimo acarreo
   if(acarreo){
      nuevosDatos[nuevoTam-1]=1;
   }
   
   // Se libera el espacio previo
   liberarEspacio();
   
   // Se apuntan los nuevos datos
   datos=nuevosDatos;
   numeroDigitos=nuevoTam;
   
   // Se devuelve this
   return *this;
}

ostream & operator<<(ostream &flujo, const BigInteger &objeto){
   for(int i=objeto.numeroDigitos-1; i >= 0; i--){
      flujo << objeto.datos[i];
   }
   
   // Se devuelve el flujo
   return flujo;
}

istream & operator>>(istream &flujo, BigInteger &objeto){
   string cadena;
  
   // Se lee la cadena
   flujo >> cadena;
  
   // Se crea un objeto nuevo
   BigInteger nuevo(cadena.c_str());

   // Se asigna al objeto pasado como arumento
   objeto=nuevo;

   // Se devuelve el flujo
   return flujo;   
}

/**
 * Metodo toString
 */
string BigInteger::toString(){
   ostringstream flujo;
   
   // Se vuelcan todos los caracteres al flujo
   for(int i=numeroDigitos-1; i >= 0; i--){
      flujo << datos[i];
   }
   
   // Se devuelve la cadena resultante
   return flujo.str();
}

/**
 * Metodo para determinar la existencia de acarreo ante una suma
 * @param otro
 * @return 
 */
bool BigInteger::hayAcarreo(const BigInteger &otro){
   // Se obtiene la maxima potencia de cada numero
   int potenciaMaximaThis=numeroDigitos;
   int potenciaMaximaOtro=otro.numeroDigitos;
   
   // Usamos un puntero para el objeto con menor valor y mayor valor
   const BigInteger *menor, *mayor;
   
   // Nos quedamos con la menor de ellas
   int menorPotencia;
   if (potenciaMaximaThis < potenciaMaximaOtro){
      menorPotencia=potenciaMaximaThis;
      menor=this;
      mayor=&otro;
   }
   else{
      menorPotencia=potenciaMaximaOtro;
      menor=&otro;
      mayor=this;
   }
   
   // Se determina si la suma los valores asociados a la menor potencia
   // generan acarreo
   int digitoMayor=mayor->datos[menorPotencia-1];
   int digitoMenor=menor->datos[menorPotencia-1];
   bool acarreo=(digitoMayor+digitoMenor) > 9;
   
   // Para que termine habiendo acarreo general, las siguientes cifras
   // del numero mayor, deben ser siempre 9
   for(int i=menorPotencia; i < mayor->numeroDigitos && acarreo; i++){
      digitoMayor=mayor->datos[i];
      if (digitoMayor < 9){
         acarreo=false;
      }
   }

   // Se devuelve el valor de acarreo
   return acarreo;   
}