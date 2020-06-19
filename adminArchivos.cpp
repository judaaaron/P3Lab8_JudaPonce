#include "adminArchivos.h"

adminArchivos::adminArchivos(string pFileName)
{
	this->fileName = pFileName;

}

bool adminArchivos::guardarPersona(vector<Usuarios*>& userss){
	if(outputFile.is_open()){
		for(int i=0; i< userss.size();i++){
			outputFile << userss[i]->getNombre() <<';'<< userss[i]->getNombreUsuario()<<';'<< userss[i]->getPassword()<<"\n";
		//	for(int j= 0; j < userss[i]->getPosts().size(); j++){
		//		outputFile<<"|"<< userss[i]->getPosts()[j]->getTitulo()<<','<< userss[i]->getPosts()[j]->getContenido()<<','<< userss[i]->getPosts()[j]->getLikes()<<','<< userss[i]->getPosts()[j]->getDislikes()<<"\n";
			//}
			
		}
			return true;
	}else
		return false; 
}

bool adminArchivos::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}

bool adminArchivos::abrirEscritura(int modo){
	modoEscritura = modo;
	if(modoEscritura == 1){
	
		outputFile.open(fileName.c_str(), std::ios::app);
		outputFile.flush();
}	else{

		outputFile.open(fileName.c_str());
}
	return outputFile.is_open();
}

vector<Usuarios*> adminArchivos:: cargarArchivoUsuario(){
	vector<Usuarios*> retval;
	archivoPersona.open("Users.txt",ios::in);
	if(archivoPersona.fail()){
		exit(1);
	}
	while(!archivoPersona.eof()){
		string nombre,nombreUsuario,password;
		string buffer;
		getline(archivoPersona,buffer);
		
		stringstream mystream;
		mystream<< buffer;
		
		getline(mystream,nombre,';');
		getline(mystream,nombreUsuario,';');
		getline(mystream,password,';');
	
		
		retval.push_back(new Usuarios(nombre,nombreUsuario,password));
	}
		
	
	
	
return retval;
	
}

adminArchivos::~adminArchivos()
{
}
