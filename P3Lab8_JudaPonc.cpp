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
int seleccionPost;
int seleccion;
void dejarDeseguir();

int menu();


int main(int argc, char** argv) {
	adminArchivos* registros = new adminArchivos("Users.txt");
	int escoger;
			
			do{
				cout<<"    MENU "<<endl
			<<"1. Registrarse"<<endl
			<<"2. Iniciar sesion"<<endl
			<<"3. Salir del programa"<<endl
			<<"Ingrese una opcion entre 1 y 3: ";
			cin>>escoger;
			cout<<endl;
				
				
				
			
			
		
			switch(escoger){
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
						for(int i =0; i< users[personaIngresada]->getMisSeguidores().size(); i++){
							cout<<"-> Posts de: "<<users[personaIngresada]->getMisSeguidores()[i]->getNombreUsuario()<<endl;
							
							for(int j =0; j< users[personaIngresada]->getMisSeguidores()[i]->getPosts().size(); j++){
								cout<< "--Titulo--\n"<<users[personaIngresada]->getMisSeguidores()[i]->getPosts()[j]->getTitulo()<<endl;
								cout<<"'" << users[personaIngresada]->getMisSeguidores()[i]->getPosts()[j]->getContenido()<<"' \n";
								cout<<"Likes: "<<users[personaIngresada]->getMisSeguidores()[i]->getPosts()[j]->getLikes()<<endl;
								cout<<"Hates: "<<users[personaIngresada]->getMisSeguidores()[i]->getPosts()[j]->getDislikes()<<endl<<endl;
								
							}
						}
						for(int i =0; i< users[personaIngresada]->getPosts().size(); i++){
							cout<<"-> Posts de: "<<users[personaIngresada]->getNombreUsuario()<<endl;
							
							cout<< "--Titulo--\n"<<users[personaIngresada]->getPosts()[i]->getTitulo()<<endl;
							cout<<"'" << users[personaIngresada]->getPosts()[i]->getContenido()<<"' \n";
							cout<<"Likes: "<<users[personaIngresada]->getPosts()[i]->getLikes()<<endl;
							cout<<"Hates: "<<users[personaIngresada]->getPosts()[i]->getDislikes()<<endl<<endl;
								
							
						}
		
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
								
								cout<<endl;
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
									if(!users[personaIngresada]->getMisSeguidores()[personaIngresada]->getPosts().size()==0){
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
									vector<Posts*> posts1;
									for(int i=0;i<users[personaIngresada]->getMisSeguidores().size();i++){
										for (int j=0; j<users[personaIngresada]->getMisSeguidores()[i]->getPosts().size();j++){
											posts.push_back(users[personaIngresada]->getMisSeguidores()[i]->getPosts()[j]);
										}
									}
									for(int i=0; i<users[personaIngresada]->getPosts().size();i++){
										posts1.push_back(users[personaIngresada]->getPosts()[i]);
									}
	
									if (posts1.size()==0){
										cout << "No hay post disponibles hasta el momento :(" << endl << endl;
									} else{
										int opcion;
										cout << "Ingrese a posts desea dar like: ";
										 cin >> opcion;
										cout << endl;
										if (opcion < 0 || opcion >= posts1.size()){
										cout << "Este post no existe" << endl << endl;
										} else {
											posts1[opcion]->setLike(1);
										}	
									}
									
									
									break;
								}
								
								case 4:{// dar dislikes
										vector<Posts*> posts1;
									for(int i=0;i<users[personaIngresada]->getMisSeguidores().size();i++){
										for (int j=0; j<users[personaIngresada]->getMisSeguidores()[i]->getPosts().size();j++){
											posts.push_back(users[personaIngresada]->getMisSeguidores()[i]->getPosts()[j]);
										}
									}
									for(int i=0; i<users[personaIngresada]->getPosts().size();i++){
										posts1.push_back(users[personaIngresada]->getPosts()[i]);
									}
	
									if (posts1.size()==0){
										cout << "No hay posts para dar hate :(" << endl << endl;
									} else{
										int opcion;
										cout << "Ingrese a posts desea dar hate: ";
										 cin >> opcion;
										cout << endl;
										if (opcion < 0 || opcion >= posts1.size()){
										cout << "Este post no existe" << endl << endl;
										} else {
											posts1[opcion]->setDislikes(1);
										}	
									}
									break;
								}
								
								case 5:{// seguir usuario
								int bandera;
									for(int i = 0; i< users.size()-1; i++){
										cout<<i<<". "<< users[i]->getNombreUsuario()<<endl;
										bandera=i;
									}
									cout<<endl;
									cout<<"Sugerencias de usuarios para seguir, seleccione un usuario: ";
									cin>>seleccion;
									while(seleccion == personaIngresada){
										cout<<"No puedes seguirte a ti mismo :("<<endl;
										cout<<"Seleccione un usuario de nuevo: ";
										cin>>seleccion;
									}
									
									while(seleccion > bandera){
										cout<<"Esta posicion no existe "<<endl;
										cout<<"Seleccione un usuario de nuevo: ";
										cin>>seleccion;
									}
									users[personaIngresada]->agregarSeguidor(users[seleccion]);
									cout<<"Has empezado a seguir a: "<<users[seleccion]->getNombreUsuario()<<" exitosamente"<<endl;
									cout<<endl;	
									
									
									break;
								}
								
								case 6:{// dejar de seguir usuario
								int opcion;
								
								if(users[personaIngresada]->getMisSeguidores().size()==0){
									cout<<"No sigues a ninguna persona hasta el momento"<<endl;
								}else{
									for(int i=0;i<users[personaIngresada]->getMisSeguidores().size();i++){
										cout <<i << ". Nombre de usuario: " << users[personaIngresada]->getMisSeguidores()[i]->getNombreUsuario() << endl;
									}
									cout << "Selecciona usuario para dejar de seguirlo: "; 
									cin >> opcion;
									cout << endl;
									users[personaIngresada]->getMisSeguidores().erase(users[personaIngresada]->getMisSeguidores().begin() + opcion);
									cout << "Ya no sigues a este usuario!" << endl;
									cout << endl;	
								}
								
								
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
		
		}while(escoger!=3);
		
	
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


void dejarDeseguir(){
	if (users[personaIngresada]->getMisSeguidores().size() == 0){
		cout << "No sigues a nadie..." << endl << endl;
	} else {
		int opcion;
		for(int i=0;i<users.size();i++){
			cout <<i << ". Nombre de usuario: " << users[i]->getNombreUsuario() << endl;
		}
		cout << "Selecciona usuario para dejar de seguirlo: "; 
		cin >> opcion;
		cout << endl;
		
		users[personaIngresada]->getMisSeguidores()[opcion] = NULL;
		delete users[personaIngresada]->getMisSeguidores()[opcion];
		users[personaIngresada]->getMisSeguidores().erase(users[personaIngresada]->getMisSeguidores().begin() + opcion);
		cout << "Ya no sigues a este usuario!" << endl << endl;
	}
}



