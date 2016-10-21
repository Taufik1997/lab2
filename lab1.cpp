#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

bool primo(int);

int main(){
	int opcion = 0;
	do{
		cout<<"Menu\n1)Ejercicio 1\n2)Ejercicio 2\n3)Ejercicio 3\n4)Salir\n";
		cin>>opcion;
		switch(opcion){
			case 1:{
				string numeros;
				cout<<"\nIngrese el numero: ";
				cin>>numeros;
				int arreglo[numeros.size()];
				for (int i = 0; i < numeros.size(); ++i)
				{
					arreglo[i]= (int)numeros[i];
					arreglo[i]= arreglo[i]-48; 
				}
				int mayor = 0;
				for (int i = 0; i < numeros.size(); ++i)
				{
					if 
						(mayor < arreglo[i])
					{
						mayor = arreglo[i];					
					}
				}
				bool exists = false;
				int cont=0;
				for (int i = 0; i <= mayor; ++i)
				{
					for (int j = 0; j < numeros.size(); ++j)
					{
						if (arreglo[j] == i)
						{
							exists =true;
						}
					}
					if(exists)
					{
						cont++;
					}
					exists = false;
				}
				int decimal = 0;
				int contador = 0;
				for (int i = numeros.size()-1; i >= 0 ; --i)
				{
					decimal += arreglo[contador] * pow(mayor+1,i);
					contador++;
				}
				if (cont-1 == mayor)
				{
					cout<< "\nEl numero "<<numeros<<" es en base de "<<mayor+1<< " y su base decimal es "<< decimal <<endl;
				}
				else
				{
					cout<<"\nEl numero no es pandigital"<<endl;
				}
				break;
			}
			case 2:{
				int n;
				cout<<"\nIngrese un numero: ";
				cin>>n;
				int contador= 0;
				for (int i = 1; i <= n; ++i)
				{
					if (n%i==0)
					{
						contador++;
					}
				}
				int arreglo[contador];
				int contador2 = 0; 
				for (int i = 1; i <= n; ++i)
				{
					if (n%i==0)
					{
						arreglo[contador2] = i;
						contador2++;
					}
				}
				cout<<arreglo[0];
				int respuesta = 0;

				for (int i = 0; i < contador2; ++i)
				{
					int k = (arreglo[i]+n)/arreglo[i];
					bool prime = primo(k);
					if(prime){
						respuesta+=k;
					}
				}
				cout<<"\nLa respuesta es "<<respuesta<<endl;

				break;
			}
			case 3:{
				string numero;
				cout<<"\nIngrese el numero:"<<endl;
				cin>> numero;
				int num;
				stringstream(numero) >> num;
				int arreglo[numero.size()];
				int suma = 0;
				for (int i = 0; i < numero.size(); ++i)
				{
					int a= (int)numero[i];
					suma+= a-48;
				}

				if (num%suma==0)
				{
					cout<<"El numero es un numero de Harshad"<<endl;
				}else{
					cout<<"El numero no es un numero de Harshad"<<endl;
				}
				int cont = 1;
				for (int i = 1; i < numero.size(); ++i)
				{
					int suma2 = 0;
					for (int i = 0; i < numero.size()-i; ++i)
					{
						int a= (int)numero[i];
						suma2+= a-48;

					}
					if(num%suma==0){
						cont++;
					}
				}
				if(cont==numero.size()){
					cout<<"El numero tambien es trucable"<<endl;
				}else{
					cout<<"El numero no es trucable"<<endl;
				}

				break;
			}
		}//Fin Switch 
	}while(opcion>=0 && opcion <=3);//Fin do while
	return 0;
}//Fin main

bool primo(int x){
	int cont=0;
	for (int i = 1; i <= x; ++i)
	{
		if(x%i==0)
		{
			cont++;
		}
	}

	if (cont == 2)
	{
		return true;
	}else{
		return false;
	}
}