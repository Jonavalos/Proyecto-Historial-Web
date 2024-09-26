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
	
	virtual ~Sesion();

	std::string navegarPestanasStr();
	std::string navegarPestanas();
	bool agregarPestanaActual(Pestana* pestana);
	std::string getNombre();

	//Archivos
	void guardar(std::fstream& strm);
	static Sesion* leer(std::fstream& strm, std::vector<SitioWeb*> a);

};
