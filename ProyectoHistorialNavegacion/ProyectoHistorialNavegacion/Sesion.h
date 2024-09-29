#pragma once
#include"Pestana.h"

class Sesion
{
private:
	std::vector<Pestana*> pestanas;
	Pestana* pestanaActual;
	std::vector<SitioWeb*> sitios;
	std::string nombreSesion;
	int indiceP;
public:
	Sesion();
	Sesion(std::string nom);
	Sesion(std::string nom, int ind, Pestana* act, std::vector<SitioWeb*> sit, std::vector<Pestana*> pest);
	
	virtual ~Sesion();
	

	std::string navegarPestanasStr();
	std::string navegarPestanas();
	bool agregarPestanaActual(Pestana* pestana);
	std::string getNombre();
	std::vector<SitioWeb*> getSitios();

	//Archivos
	void guardar(std::fstream& strm);
	static Sesion* leer(std::fstream& strm);

};
