/*
1. Gesti�n de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes caracter�sticas: nombres completos,
sexo, edad, tel�fono, email, nacionalidad
El programa debe constar de un men� que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com,
outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecuci�n continuamente hasta que usuario indique que desea salir del
mismo.
*/
#include <iostream>
#include <string>

using namespace std;
const int limite_contactos = 50;  

struct contactoEmail{
	string 	nombrescompletos; 
	string 	sexo; 
	int 	edad; 
	int 	telefono; 
	string 	email; 
	string 	nacionalidad; 
};

void agregarContactos(contactoEmail contactos[], int & cantidadContactos){
	if(cantidadContactos >= limite_contactos){
		cout<<"Ya no queda espacio sufieciwente para agregar otro contacto.	 "; 

		return; 
	}
contactoEmail cont;
	cout<<"Digite sus nombres completos: "; 
 	cin.ignore(); 
 	getline(cin,cont.nombrescompletos);  
 	cout<<"Ingrese su sexo: "; 
 	getline(cin, cont.sexo); 
 	cout<<"Ingrese su edad: "; 
 	cin>>cont.edad; 
 	cout<<"Ingrese su telefono: "; 
 	cin>>cont.telefono; 
 	cout<<"Ingrese su email: "; 
 	cin>>cont.email;  
 	cout<<"Ingrese su nacionalidad: "; 
 	cin>>cont.nacionalidad ; 
 	cout<<"\n"; 
 	cout<<"Contacto guardado!\n"; 

 }
 
// void eliminarcontacto

int main(){
	int opcion;

	contactoEmail cont;

	do{
			cout<<"Buenos dias, estara en el programa de gestion de contactos "<<endl; 
			cout<<endl<<"Digite una de las siguientes opciones: "<<endl; 
			cout<<"[1] Agregar un contacto. "<<endl; 
			cout<<"[2] Eliminar un contacto. "<<endl; 
			cout<<"[3] Mostrar contactos registrados. "<<endl; 
	  		cout<<"[4] Mostrar lista de contactos, ordenado por servidor de cuentas. "<<endl; 
		   	cout<<"[5] Salir del programa. "; 
		   	cout<<endl<<"Digite el numero de la opcion: "<<endl;
  	   		cin>>opcion;

  	   	switch(opcion){
  			     case 1: 
   			  	 cout<<"Ingrese sus nombres completos: "; 
   			  	 cin.ignore(); 
   			  	 getline(cin,cont.nombrescompletos);  
   			  	 cout<<"Ingrese su sexo: "; 
   			  	 getline(cin, cont.sexo); 
   			  	 cout<<"Ingrese su edad: "; 
   			  	 cin>>cont.edad; 
   			  	 cout<<"Ingrese su telefono: "; 
   			  	 cin>>cont.telefono; 
				 cout<<"Ingrese su email: "; 
				 cin>>cont.email;  
				 cout<<"Ingrese su nacionalidad: "; 
				 cin>>cont.nacionalidad ; 
				 cout<<"\n"; 

				 cout<<"\nNombres completos:"<<cont.nombrescompletos<<endl;  
				 cout<<"Sexo: "<<cont.sexo<<endl; 
				 cout<<"Edad: "<<cont.edad<<endl; 
				 cout<<"Telefono: "<<cont.telefono<<endl; 
				 cout<<"Email: "<<cont.email<<endl; 
				 cout<<"Nacionalidad: "<<cont.nacionalidad<<endl; 

				 default : break;  
  	   		}

	}while(opcion != 5); 
	return 0; 
}
