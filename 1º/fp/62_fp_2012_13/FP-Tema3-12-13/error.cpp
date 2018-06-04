   #include <iostream>
   #include <cmath>
   using namespace std;

   //***************************************************************************
   void Division(double x, double y, double &resultado, bool &error)
   {
        if (y!=0)
        {
             resultado = x / y;
             error = false;
        }     
        else
             error = true;
   }
 
   // P R O G R A M A   P R I N C I P A L //////////////////////////////////////
   int main()
   {
      bool error;
      double x, y, div;

      //ENTRADAS
      cout << "\nIntroduzca primer numero: ";
      cin >> x;
      
      cout << "\nIntroduzca segundo numero: ";
      cin >> y;
     
      //PROCESO
      Division(x, y, div, error);
     
      //SALIDA
      if (error)
         cout << "La division no se ha podido efectuar" << endl;
      else   
         cout << "Resultado division: " << div << endl;
       
      system("pause");
   }
