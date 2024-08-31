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
	Pestana(SitioWeb* si);
	static void leerSitiosDisponibles();
	virtual~Pestana();
	void vaciarLista();
	SitioWeb* getSitio();
	void setSitio(SitioWeb& si);

	void guardar(std::fstream& strm);
	static Pestana* recuperar(std::fstream& strm);
};

