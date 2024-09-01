#pragma once
#include"SitioWeb.h"
#include<forward_list>
#include<vector>
#include <algorithm>
class Pestana
{
private:
	static std::vector<SitioWeb*>  sitiosDisponibles;
	static std::vector<SitioWeb*>  historialSitios;
	SitioWeb* sitioActual;
public:
	Pestana();
	Pestana(SitioWeb* si);
	static void leerSitiosDisponibles();
	virtual~Pestana();
	void vaciarVectorSitiosDisponibles();
	void vaciarHistorialSitios();
	SitioWeb* getSitioActual();
	void setSitio(SitioWeb& si);

	void guardarSitioActual(std::fstream& strm);
	static Pestana* recuperar(std::fstream& strm);

	//busca el sitioWeb y lo asigna al atributo sitioActual
	bool asignarActual(std::string dominio);

	std::string mostrarHistorial();

	std::string toString();


};


/*
verificar si existe en vector
setearlo en atributo
y de ahi imprimirlo
*/
