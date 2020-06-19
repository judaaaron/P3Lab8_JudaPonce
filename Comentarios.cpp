#include "Comentarios.h"



string Comentarios:: getNombreU(){
	return this->nombre;
	
}
string Comentarios:: getContenido(){
	return this->contenido;	
}
		
void Comentarios:: setUsuarios(string n){
	this->nombre=n;
}
void Comentarios:: setContenido(string conte){
	this->contenido=conte;
}
Comentarios::Comentarios(string nombre, string contenido){
	this->nombre=nombre;
	this->contenido=contenido;
}



Comentarios::~Comentarios()
{
}
