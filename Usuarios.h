#ifndef USUARIOS_H
#define USUARIOS_H
#include<string>
#include<vector>
#include"Posts.h"

using namespace std;

class adminArchivo;

class Usuarios
{
	public:
		Usuarios();
		Usuarios(string,string,string);
		string getNombre();
		string getNombreUsuario();
		string getPassword();
		
		void setNombre(string);
		void setNombreUsuario(string);
		void setPassword(string);
		
		vector<Usuarios*>& getMisSeguidores();
		vector<Posts*>& getPosts();
		~Usuarios();
	protected:
		string nombre, username, password;
		vector<Usuarios*>misSeguidores;
		vector<Posts*> publicaciones;
		
		friend class adminArchivo;
};

#endif
