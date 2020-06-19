#include "Posts.h"

Posts::Posts()
{
}

string Posts:: getTitulo(){
	return this->titulo;
}
string Posts:: getContenido(){
	return this->contenido;
}
int Posts:: getLikes(){
	return this->likes;
}
int Posts:: getDislikes(){
	return this->dislikes;
}
vector<Comentarios*> Posts:: getComments(){
	return this->comments;
}
		
void Posts:: setTitulo(string title){
	this->titulo=title;
	
}
void Posts:: setContenido(string cont){
	this->contenido=cont;	
}
void Posts:: setLike(int megusta){
	this->likes+=megusta;
	
}
void Posts:: setDislikes(int odio){
	this->dislikes+=odio;
}

Posts::Posts(string titulo,string contenido){
	this->titulo=titulo;
	this->contenido=contenido;
	this->likes=0;
	this->dislikes=0;
}

Posts::~Posts()
{
}
