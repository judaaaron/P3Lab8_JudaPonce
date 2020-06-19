#include "Usuarios.h"

Usuarios::Usuarios()
{
}

string Usuarios:: getNombre(){
	return this->nombre;
}
string Usuarios:: getNombreUsuario(){
	return this->username;
}
string Usuarios::getPassword(){
	return this->password;
}
		
void Usuarios:: setNombre(string name){
	this->nombre=name;
}
void Usuarios:: setNombreUsuario(string userN){
	this->username=userN;
}
void Usuarios:: setPassword(string pass){
	this->password=pass;
}
		
vector<Usuarios*> Usuarios:: getMisSeguidores(){
	return this->misSeguidores;
}

void Usuarios:: agregarSeguidor(Usuarios* username){
	misSeguidores.push_back(username);
}

vector<Posts*>  Usuarios:: getPosts(){
	return this->publicaciones;
}

Usuarios::Usuarios(string name ,string userss ,string contra){
	this->nombre=name;
	this->username=userss;
	this->password=contra;
	
}

Usuarios::~Usuarios()
{
}
