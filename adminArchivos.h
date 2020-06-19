#ifndef ADMINARCHIVOS_H
#define ADMINARCHIVOS_H
#include<iostream>
#include "Usuarios.h"
#include <string>
#include<sstream>
#include <fstream>
#include<vector>

class adminArchivos
{
	public:
		adminArchivos(string);
		Archivo(string);
		bool guardarPersona(vector<Usuarios*>&);
		bool abrirEscritura(int);
		bool cerrarEscritura();
		vector<Usuarios*> cargarArchivoUsuario();
		~adminArchivos();
	protected:
		
		string fileName;
		ofstream outputFile;
		ifstream archivoPersona;
		int modoEscritura;
};

#endif
