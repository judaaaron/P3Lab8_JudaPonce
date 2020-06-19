#include <iostream>
#include <string>
#include "Usuarios.h"
#include "Posts.h"
//#include "Comentarios.h"
#include "adminArchivos.h"
#include <vector>

using namespace std;

vector<Usuarios*> users;
vector<Posts*> posts;
vector<Comentarios*> comments;

int menu();


int main(int argc, char** argv) {
	adminArchivos* registros = new adminArchivos("Users.txt");
	int opcion=0;
		while( opcion != 3 ) {
		
			switch( opcion = menu() ){
				case 1:{// registrarse
					string nombre, nombreUsuario, password;
					cout<<"Por favor ingrese su nombre: ";
					cin>>nombre;
					cout<<"Por favor ingrese su nombre de usuario: ";
					cin>>nombreUsuario;
					cout<<"Ingrese su contraseña: ";
					cin>>password;
					users.push_back(new Usuarios(nombre,nombreUsuario,password));
					registros->abrirEscritura(0);
					registros->guardarPersona(users);
					registros->cerrarEscritura();
					cout<<"Ha sido registrado exitosamente :) "<<endl;
					cout<<endl;
					
					break;
				}
				
				case 2:{// iniciar sesion
					
					break;
				}
				
				case 3:{// salir
					
					break;
				}
			}
		
		
		
	}
	return 0;
}


int menu(){
	int opcion=0;
	while(opcion < 1 || opcion > 3){
		
		cout<<"    MENU "<<endl
			<<"1. Registrarse"<<endl
			<<"2. Iniciar sesion"<<endl
			<<"3. Salir del programa"<<endl
			<<"Ingrese una opcion entre 1 y 3: ";
			cin>>opcion;
			cout<<endl;
			if(opcion >= 1 && opcion <= 3)
				break;
			else
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;	
				
	}//Fin del ciclo while
	
	
	return opcion;
}



