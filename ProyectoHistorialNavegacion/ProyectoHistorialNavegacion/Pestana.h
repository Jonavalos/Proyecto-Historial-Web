#pragma once
#include"SitioWeb.h"
#include<forward_list>
#include<vector>
#include<fstream>
class Pestana
{
private:
	static std::vector<SitioWeb*>  sitiosDisponibles;
	SitioWeb* sitio;
public:
	Pestana();
	static void leerSitios(std::fstream& arc);
	virtual~Pestana();
	void vaciarLista();
	SitioWeb* getSitio();
	void setSitio(SitioWeb& si);
};

