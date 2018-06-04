
#include "polilinea.h"

/**
 * Constructor de copia
 * @param aCopiar
 */
Polilinea::Polilinea(const Polilinea& aCopiar) {
   cout << "Uso del constructor de copia...." << endl;

   // Se reserva espacio el array de puntos. Este metodo ya
   // asigna el valor del dato miembro num
   reservarEspacio(aCopiar.num);

   // Se copian los puntos. Como en la clase Punto no hay memoria
   // dinamica no es preciso contar con operador de asignacion de
   // la clase Punto
   asignarPuntos(num, aCopiar.p);
}

/**
 * Operador de asignacion
 * @param aAsignar objeto a usar en la asignacion
 * @return 
 */
Polilinea Polilinea::operator=(const Polilinea & aAsignar) {
   // En primer lugar se libera el espacio de este objeto
   liberarEspacio();

   // Ahora se reserva espacio para el nuevo array de puntos
   reservarEspacio(aAsignar.num);

   // Se copian los puntos
   asignarPuntos(num, aAsignar.p);
}

/**
 * Operador corchete
 * @param indice
 * @return 
 */
Punto & Polilinea::operator[](int indice) const {
   if (indice >= num) {
      throw out_of_range("Indice fuera de rango");
   }

   // Si todo Ok se devuelve una referencia al objeto
   return p[indice];
}

/**
 * Operador de igualdad
 * @param aComparar
 * @return 
 */
bool Polilinea::operator==(const Polilinea &aComparar) const {
   bool iguales = true;

   // Solo se comparan si no son el mismo objeto
   if (this != &aComparar) {
      // Si no tienen el mismo numero de puntos se devuelve false
      if (num != aComparar.num) {
         iguales = false;
      } else {
         // Hay que comparar punto a punto. Basamos la comparacion
         // en la sobrecarga del operador de igualdad en la clase
         // Punto
         for (int i = 0; i < num && iguales; i++) {
            if (!(p[i] == aComparar.p[i])) {
               iguales = false;
            }
         }
      }
   }

   // Devuelve el valor de iguales
   return iguales;
}

/**
 * Operador + para poder agregar un punto al objeto
 * @param punto
 * @return 
 */
Polilinea Polilinea::operator+(const Punto &punto) const {
   Polilinea resultado;

   // Se reserva espacio para resultado
   resultado.reservarEspacio(num + 1);

   // Se asignan los puntos presentes en this
   resultado.asignarPuntos(num, p);

   // En la ultima posicion se asigna el punto pasado como
   // argumento
   resultado.p[resultado.num - 1] = punto;

   // Se devuelve el resultado
   return resultado;
}

/**
 * Funcion amiga para poder agregar un punto al inicio
 * @param punto
 * @param linea
 */
Polilinea operator+(const Punto & punto, const Polilinea &linea) {
   // Se crea el objeto resultado
   Polilinea resultado;

   // Se reserva espacio
   resultado.reservarEspacio(linea.num + 1);

   // En la primera posicion se asigna el punto
   // pasado como argumento
   resultado.p[0] = punto;

   // Se copian el resto
   for (int i = 0; i < linea.num; i++) {
      resultado.p[i + 1] = linea.p[i];
   }

   // Se devuelve el resultado
   return resultado;
}

/**
 * Metodo para leer el conjunto de puntos almacenados en un archivo
 * @param nombre
 */
void Polilinea::leerPolilinea(const char *nombre) {
   char caracter;

   // Se crea el archivo para lectura
   ifstream archivo(nombre, ifstream::in);

   // Si no pudo abrirse, se sale del procedimiento
   if (!archivo.is_open()) {
      cout << "Problemas en apertura de archivo......" << endl;
   } else {
      // Se lee el identificador de la primera linea
      string cabecera;
      archivo >> cabecera;
      cout << "Leida cabecera: " << cabecera << endl;

      // Ignora hasta salto de linea
      archivo.ignore(1);

      // Se comprueba si es correcto
      if (cabecera.compare("POLILINEA") != 0) {
         cout << "Error en lectura de archivo......" << endl;
      }
      else {
         // Se salta el comentario opcional, en caso de estar
         caracter = (char) archivo.peek();
         cout << "Caracter de comentario: " << caracter << endl;

         // Si es la marca de comentario saltamos la linea
         if (caracter == '#') {
            char comentario[100];

            // OJO: getline consume el salto de linea
            archivo.getline(comentario, 100);
            cout << "Comentario leido: " << comentario << endl;
         }


         // Se lee el numero de puntos a leer
         int numeroPuntos;
         archivo >> numeroPuntos;
         cout << "Numero de puntos leidos en archivo: " << numeroPuntos << endl;

         // Se ignora el salto de linea
         archivo.ignore(1);

         // Se libera el espacio actual
         liberarEspacio();

         // Se reserva espacio para el numero de puntos indicado
         reservarEspacio(numeroPuntos);

         int x, y;
         for (int i = 0; i < numeroPuntos; i++) {
            // Se leen las coordenadas
            archivo >> x >> y;

            // Se ignora el salto de linea
            archivo.ignore(1);

            // Se crea el punto
            Punto punto(x, y);

            // Se agrega el punto
            cout << "Agregando " << x << " - " << y << endl;
            p[i] = punto;
         }
      }

      // Se cierra el archivo
      archivo.close();
   }
}

/**
 * Metodo para guardar en un archivo el contenido de un objeto
 * @param nombre
 * @param comentario
 */
void Polilinea::escribirPolilinea(const char *nombre, const char *comentario) {
   // Se crea el archivo
   ofstream archivo(nombre);
   
   // Se comprueba si pudo abrirse
   if (!archivo.is_open()){
      cout << "Problema en apertura de archivo......" << endl;
   }
   else {
      // Se comienza escribiendo la palabra reservada POLILINEA
      archivo << "POLILINEA" << endl;
      
      // Ahora se escribe el comentario, si lo hay
      if (comentario != 0){
         archivo << "# " << comentario << endl;
      }
      
      // Ahora se muestra el numero de puntos
      archivo << num << endl;
      
      // Ahora se muestran los puntos uno a uno
      for(int i=0; i < num; i++){
         archivo << p[i].obtenerX() << " " << p[i].obtenerY() << endl;
      }
      
      // Se cierra el archivo
      archivo.close();
   }
}

/**
 * Funcion amiga para mostrar el contenido de un objeto
 * @param flujo de salida
 * @param polilinea objeto a mostrar
 */
ostream & operator<<(ostream &flujo, const Polilinea & polilinea) {
   flujo << "---------------- Objeto clase Polilinea ----------------- " << endl;
   for (int i = 0; i < polilinea.num; i++) {
      flujo << polilinea.p[i];
   }

   // Devuelve el flujo
   return flujo;
}


