/*
1. Gestión de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos,
sexo, edad, teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com,
outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del
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
 	cout<<"Contacto guardado "<<endl;

 }
 
void eliminarcontactos(contactoEmail contactos[], int &cantidadContactos, int indice){
	if(indice>=0 && indice < limite_contactos){
		for(int i=indice; i< cantidadContactos -1; i++){
			contactos[i] = contactos [i+1];
		}
		cantidadContactos--;
		cout << "\nContacto eliminado"<< endl;
	} else {
		cout << "\nIndice no valido" << endl;
	}
}

int main(){
	int opcion;
	contactoEmail contactos[limite_contactos];
	int cantidadContactos=0;

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

  	   	switch (opcion) {
				case 1: 
   			  	 	agregarContactos(contactos, cantidadContactos);
					break;
				case 2:
					int indice;
					cout << "Ingrese indice del contacto a eliminar, Comenzar del 0" << endl;
					cin >> indice;
					eliminarcontactos(contactos, cantidadContactos, indice);

				 default : break;  
  	   		}

	}while(opcion != 5); 
	return 0; 
}
