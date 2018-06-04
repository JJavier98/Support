#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	double altura1, altura2, altura3, media, desviacion;

	cout << "\nIntroduzca la primera altura: ";
	cin >> altura1;
	cout << "\nIntroduzca la segunda altura: ";
	cin >> altura2;   
	cout << "\nIntroduzca la tercera altura: ";
	cin >> altura3;
   

	media = (altura1 + altura2 + altura3) / 3;    
	desviacion =  sqrt( ( pow(altura1 - media , 2) +pow(altura2 - media , 2) +pow(altura3 - media , 2)) / 3) ;
   

	cout << "\nLa media aritmética es de: " << media;
	cout << "\nLa desviación típica es de: " << desviacion;

}

