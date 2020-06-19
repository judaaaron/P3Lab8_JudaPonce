#ifndef POSTS_H
#define POSTS_H

#include<string>
#include"Comentarios.h"
#include<vector>

using namespace std;

class Posts
{
	public:
		Posts();
		Posts(string,string);
		string getTitulo();
		string getContenido();
		int getLikes();
		int getDislikes();
		vector<Comentarios*>& getComments();
		
		void setTitulo(string);
		void setContenido(string);
		void setLike(int);
		void setDislikes(int);
		
		~Posts();
	protected:
		string titulo,contenido;
		int likes, dislikes;
		vector<Comentarios*> comments;
};

#endif
