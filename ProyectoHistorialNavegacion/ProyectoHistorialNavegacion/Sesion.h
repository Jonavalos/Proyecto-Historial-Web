#pragma once
#include"Pestana.h"

class Sesion
{
private:
	std::vector<Pestana*> pestanas;
	Pestana* pestanaActual;
	std::vector<SitioWeb*> sitios;
public:
	Sesion();
	Sesion(Pestana* pestana);
	virtual ~Sesion();

	std::string navegarPestanasStr();
	std::string navegarPestanas();
	bool agregarPestanaActual(Pestana* pestana);
	

};
