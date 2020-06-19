#ifndef COMENTARIOS_H
#define COMENTARIOS_H
#include <string>

using namespace std;


class Comentarios
{
	public:
	
		Comentarios(string, string);
		string getNombreU();
		string getContenido();
		
		void setUsuarios(string);
		void setContenido(string);
		~Comentarios();
	protected:
		string nombre, contenido;
};

#endif
