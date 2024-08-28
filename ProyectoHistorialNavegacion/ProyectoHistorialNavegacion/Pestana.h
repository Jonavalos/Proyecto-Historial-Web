#pragma once
#include"SitioWeb.h"
#include<forward_list>
#include<vector>

class Pestana
{
private:
	static std::vector<SitioWeb*>  sitiosDisponibles;
	SitioWeb* sitio;
public:
	Pestana();
	static void leerSitiosDisponibles();
	virtual~Pestana();
	void vaciarLista();
	SitioWeb* getSitio();
	void setSitio(SitioWeb& si);
};

