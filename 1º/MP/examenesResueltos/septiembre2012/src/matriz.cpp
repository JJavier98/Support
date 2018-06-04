#include "matriz.h"

/**
 * Constructor por defecto de la clase
 */
Matriz::Matriz() {
   // Se asigna valor 0 a todos los datos miembros
   nfilas = 0;
   ncolumnas = 0;
   datos = 0;
}

/**
 * Constructor para inicializar el objeto con una determinada
 * dimension
 * @param nfilas
 * @param ncolumnas
 */
Matriz::Matriz(int nfilas, int *ncolumnas) {
   // Se reserva espacio para las dimensiones indicadas
   reservarEspacio(nfilas, ncolumnas);
}

/**
 * Metodo privado para liberar espacio de memoria
 */
void Matriz::liberarEspacio() {
   // Se borra el espacio de cada fila
   for (int i = 0; i < nfilas; i++) {
      delete [] datos[i];
   }

   // Se borra el array con tamaños de columnas
   delete [] ncolumnas;

   // Se borra el array de punteros a las filas
   delete [] datos;
}

/**
 * Metodo de reserva de espacio
 * @param nfilas numero de filas de la matriz
 * @param ncolumnas array indicando el tamaño de cada fila
 */
void Matriz::reservarEspacio(int nfilas, int *ncolumnas) {
   // Se asigna el dato miembro nfilas
   this->nfilas = nfilas;

   // Se reserva espacio para el array de punteros a las filas
   datos = new double*[nfilas];

   // Se reserva espacio para el array de tamaño de filas
   this->ncolumnas = new int[nfilas];

   // Se copian los tamaños de cada fila
   for (int i = 0; i < nfilas; i++) {
      this->ncolumnas[i] = ncolumnas[i];
   }

   // Ahora se crea el espacio para cada fila
   for (int i = 0; i < nfilas; i++) {
      datos[i] = new double[ncolumnas[i]];
   }
}

/**
 * Metodo privado de copia de datos de otro objeto, que se
 * asume tiene las mismas dimensiones que this
 * @param otro objeto del que copiar los datos
 */
void Matriz::copiarDatos(const Matriz &otro) {
   // Se copian los datos
   for (int i = 0; i < nfilas; i++) {
      for (int j = 0; j < ncolumnas[i]; j++) {
         datos[i][j] = otro.datos[i][j];
      }
   }
}

/**
 * Destructor de la clase
 */
Matriz::~Matriz() {
   // Se llama al metodo de liberacion de espacio
   liberarEspacio();
}

/**
 * Constructor de copia
 * @param otro objeto a copiar 
 */
Matriz::Matriz(const Matriz& otro) {
   // Se comienza haciendo la reserva de espacio
   reservarEspacio(otro.nfilas, otro.ncolumnas);

   // Ahora se copian los datos
   copiarDatos(otro);
}

/**
 * Operador de asignacion
 * @param otro objeto que asignar
 * @return objeto modificado
 */
const Matriz & Matriz::operator=(const Matriz & otro) {
   // En primer lugar se libera todo el espacio
   liberarEspacio();

   // Se asigna espacio (con las medidas de otro)
   reservarEspacio(otro.nfilas, otro.ncolumnas);

   // Se copian los datos
   copiarDatos(otro);

   // Se devuelve this
   return *this;
}

/**
 * Funcion amiga para sobrecargar el operador <<
 * @param flujo flujo a usar para la salida
 * @param objeto objeto a mostrar
 */
ostream & operator<<(ostream &flujo, const Matriz &objeto) {
   // Se muestran los datos del objeto
   for (int i = 0; i < objeto.nfilas; i++) {
      for (int j = 0; j < objeto.ncolumnas[i]; j++) {
         flujo << objeto.datos[i][j] << " ";
      }

      // Se salta de linea
      flujo << endl;
   }

   // Se devuelve el flujo
   return flujo;
}

/**
 * Funcion amiga a la clase para sobrecargar el operador <<
 * @param flujo flujo de entrada
 * @param objeto objeto sobre el que almacenar los datos leidos
 */
istream & operator>>(istream &flujo, const Matriz & objeto) {
   // Se van leyendo los datos del flujo
   for (int i = 0; i < objeto.nfilas; i++) {
      for (int j = 0; j < objeto.ncolumnas[i]; j++) {
         flujo >> objeto.datos[i][j];
      }
   }

   // Se devuelve el flujo
   return flujo;
}

/**
 * Metodo para acceder al contenido de una posicion
 * @param fila
 * @param columna
 * @return 
 */
double Matriz::get(int fila, int columna) {
   // Se devuelve el valor almacenado en la posicion indicada
   return datos[fila][columna];
}

/**
 * Metodo para asignar valor a una posicion
 * @param fila
 * @param columna
 * @param valor
 */
void Matriz::set(int fila, int columna, double valor) {
   datos[fila][columna] = valor;
}

/**
 * Metodo para devolver una nueva matriz intercambiando las
 * filas de la matriz sobre la que se hace la llamada
 * (primera por ultima, segunda por penultima, ....)
 * @param nombreArchivo
 * @param comentario
 */
Matriz & Matriz::vflip() {
   // Se crea una matriz con las mismas dimensiones
   Matriz *resultado = new Matriz(*this);

   // Se hacen los cambios en las filas
   for (int i = 0; i < nfilas / 2; i++) {
      resultado->ncolumnas[i] = ncolumnas[nfilas - i - 1];
      resultado->ncolumnas[nfilas - i - 1] = ncolumnas[i];
      resultado->datos[i] = datos[nfilas - i - 1];
      resultado->datos[nfilas - i - 1] = datos[i];
   }

   // Se devuelve el resultado
   return *resultado;
}

/**
 * Metodo para obtener la posicion del valor de maximo
 * valor de la matriz
 * @param fila
 * @param columna
 */
void Matriz::obtenerMaximo(int &fila, int &columna){
   double valorMaximo=datos[0][0];
   fila=0;
   columna=0;
   
   // Se recorre la matriz
   for(int i=0; i < nfilas; i++){
      for(int j=0; j < ncolumnas[i]; j++){
         if (valorMaximo < datos[i][j]){
            valorMaximo=datos[i][j];
            fila=i;
            columna=j;
         }
      }
   }
}

/**
 * Metodo para escribir el contenido del objeto en un archivo
 * @param nombreArchivo nombre del archivo a escribir
 * @param comentario comentario a agregar al archivo
 */
void Matriz::escribirArchivo(string nombreArchivo, string comentario) {
   // Se procede a la creacion del archivo
   ofstream fichero(nombreArchivo.c_str(), ios::out | ios::binary);

   // Se comprueba que pudo abrirse bien
   if (fichero.is_open()) {
      // Se escribe el identificador MP
      fichero << "MP" << endl;

      // El comentario se incluye si es necesario
      if (comentario.compare("") != 0) {
         fichero << "# " << comentario << endl;
      }

      // Se escribe el numero de filas de la matriz
      fichero << nfilas << endl;

      // Ahora se escriben los datos en binario. Para cada fila se
      // indica su longitud y posteriormente sus datos
      for (int i = 0; i < nfilas; i++) {
         // Se escribe la longitud de la fila
         fichero.write(reinterpret_cast<char *> (&ncolumnas[i]), sizeof (int));

         // Ahora se escriben los datos de la fila, de una vez
         fichero.write(reinterpret_cast<char *> (datos[i]), sizeof (double)*ncolumnas[i]);
      }

      // Se cierra el archivo
      fichero.close();
   }
}

/**
 * Metodo para leer los datos desde un archivo. El objeto sobre el
 * que se hace la llamada se modifica y cambia su estructura para
 * poder capturar los datos del archivo
 * @param nombreArchivo nombre del archivo del que leer los datos
 */
void Matriz::leerArchivo(string nombreArchivo) {
   char linea[100];
   char marcaComentario;
   int tamFila;

   // Se libera el espacio previo
   liberarEspacio();

   // Se crea objeto fichero para entrada
   ifstream fichero(nombreArchivo.c_str(), ios::in | ios::binary);

   // Se comprueba si pudo hacerse la apertura
   if (fichero.is_open()) {
      // Se debe leer el identificador MP, en la primera linea
      fichero.getline(linea, 100);

      // Se sigue solo si su contenido es MP
      if (strcmp(linea, "MP") == 0) {
         // Se lee un caracter sin extrearlo del flujo, por si hubiera
         // un comentario
         marcaComentario = fichero.peek();

         // Si hay comentario, se lee la linea entera, pero no se hace
         // caso a su contenido
         if (marcaComentario == '#') {
            fichero.getline(linea, 100);
         }

         // Ahora aparece en la siguiente linea el indicado del
         // numero de filas
         fichero >> nfilas;

         // Se ignora el salto de linea que separa al numero de
         // salto de lineas del resto de valores de la matriz
         fichero.ignore();

         // Debemos almacenar la longitud de cada fila
         ncolumnas = new int[nfilas];
         datos = new double*[nfilas];

         // Bucle de lectura de los datos
         for (int i = 0; i < nfilas; i++) {
            // El primer valor indica la longitud de la fila
            tamFila = 0;
            fichero.read(reinterpret_cast<char *> (&tamFila), sizeof (int));
            ncolumnas[i] = tamFila;

            // Se reserva espacio para la fila
            datos[i] = new double[ncolumnas[i]];

            // Se leen todos los valores de la fila de una vez
            fichero.read((char *) datos[i], sizeof (double)*ncolumnas[i]);
         }
      }

      // Se cierra el archivo
      fichero.close();
   }
}
