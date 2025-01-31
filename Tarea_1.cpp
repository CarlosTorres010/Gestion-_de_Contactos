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
	contactos[cantidadContactos] = cont;
	cantidadContactos++;

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

void mostrarContactos(contactoEmail contactos[], int cantidadContactos){
	if(cantidadContactos == 0){
		cout<<"\nNingun contacto por mostrar. "<<endl;
	}
	else{
	   for(int i=0; i<cantidadContactos; ++i){
	   	cout<<"Contacto: "<<i+1<<" | "<<" -> "<<"INDICE: "<< i <<endl; 
	   	cout<<"Nombres completos: "<<contactos[i].nombrescompletos<<endl;
	   	cout<<"Sexo: "<<contactos[i].sexo<<endl; 
	   	cout<<"Edad: "<<contactos[i].edad<<endl; 
	   	cout<<"Telefono: "<<contactos[i].telefono<<endl; 
	   	cout<<"Email: "<<contactos[i].email<<endl; 
	   	cout<<"Nacionalidad: "<<contactos[i].nacionalidad<<endl; 
	   	cout<<"\n"; 
	   }
	}
}

string obtenerDominio(const string& email){
    int buscarroba=-1;
    for (int i=0;i<email.length();++i){
        if(email[i]=='@') {
            buscarroba=i;
            break;
        }
    }
    if(buscarroba == -1){
        return "";
    }
    string dominio = "";
    for(int i = buscarroba + 1; i<email.length();++i){
        dominio+=email[i];
    }
    return dominio;
}

void enumerarContactos(contactoEmail contactos[], int cantidadContactos) {
    for (int i = 0; i<cantidadContactos - 1; ++i) {
        for (int j = 0; j<cantidadContactos - 1 - i; ++j) {
            if (obtenerDominio(contactos[j].email)>obtenerDominio(contactos[j + 1].email)){
                contactoEmail temp =contactos[j];
                contactos[j]=contactos[j + 1];
                contactos[j+1]=temp;
            }
        }
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
					break;
				case 3:
				    mostrarContactos(contactos, cantidadContactos);  
				    break;
				case 4: 
                    if(cantidadContactos == 0){
					cout<<"\nNingun contacto por mostrar. "<<endl;
					}
     	            cout<<"\nMOSTRANDO CONTACTOS SEGUN EL ORDEN POR SERVIDOR: \n"; 
     	            
					enumerarContactos(contactos, cantidadContactos); 
                    mostrarContactos(contactos, cantidadContactos); 
   	  			    break; 
                case 5: 
   	 	            cout<<"Saliendo del programa..."<<endl;
				 default : break;  
  	   		}

	}while(opcion != 5); 
	return 0; 
}
