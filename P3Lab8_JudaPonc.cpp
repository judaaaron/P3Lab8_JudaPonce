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
int personaIngresada;

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
					registros->abrirEscritura(1);
					registros->guardarPersona(users);
					registros->cerrarEscritura();
					cout<<"Ha sido registrado exitosamente :) "<<endl;
					cout<<endl;
					
					break;
				}
				
				case 2:{// iniciar sesion
					users= registros->cargarArchivoUsuario();
					string username, password;
					bool aceptado=false;
					cout<<"Ingrese su nombre de usuario: ";
					cin>> username;
					cout<<"Ingrese su contraseña: ";
					cin>>password;
					for(int i = 0; i< users.size(); i++){
						if(username == users[i]->getNombreUsuario() && password == users[i]->getPassword()){
							aceptado=true;
							personaIngresada=i;
							break;
						}
					}
					
					if(aceptado==true){
						int option;
						cout<<" Bienvenido(a) "<< users[personaIngresada]->getNombreUsuario()<<" :)"<<endl;
						cout<<endl;
						do{
							cout<<"1. Crear post"<<endl;
							cout<<"2. Comentar post"<<endl;
							cout<<"3. Dar like"<<endl;
							cout<<"4. Dar hate"<<endl;
							cout<<"5 Seguir Usuario"<<endl;
							cout<<"6 Dejar de seguir a un usuario"<<endl;
							cout<<"7 Cerrar sesion"<<endl;
							cout<<"Seleccione una opcion: ";
							cin>>option;
							
							switch(option){
								
								case 1:{// crear post
									cout<<"Que estas pensando?"<<endl;
									string titulo, contenido;
									cout<<"Ponle titulo a tu post: ";
									cin>>titulo;
									cout<<"Escribe algo acerca de tu post: "<<endl;
									cin>>contenido;
									users[personaIngresada]->getPosts().push_back(new Posts(titulo,contenido));
									cout<<"Tu post ha sido publicado exitosamente!!"<<endl;
									cout<<endl;
									break;
								}
								
								case 2:{// comentar post
									if( !users[personaIngresada]->getMisSeguidores().size()== 0 || !users[personaIngresada]->getMisSeguidores()[personaIngresada]->getPosts().size()==0){
										for(int i=0; i< users[personaIngresada]->getMisSeguidores().size(); i++){
											for(int j=0; j< users[personaIngresada]->getMisSeguidores()[i]->getPosts().size(); j++){
												
											}
										}
									}else{
										cout<<"No hay ningun post publicado hasta el momento "<<endl;
										cout<<endl;
									}
									
									break;
								}
								
								case 3:{// dar like
									
									
									break;
								}
								
								case 4:{// dar dislikes
									
									
									break;
								}
								
								case 5:{// seguir usuario
									
									break;
								}
								
								case 6:{// dejar de seguir usuario
									
									
									break;
								}
							}
						
						
						}while(option!= 7);
						
					}else{
						cout<<" Usuario y/o contraseña incorretos :( "<<endl;
						cout<<endl;
					}
					
					
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



