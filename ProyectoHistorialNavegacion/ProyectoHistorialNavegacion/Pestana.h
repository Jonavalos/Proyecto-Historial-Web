#pragma once
#include"SitioWeb.h"
#include<forward_list>
#include<vector>
#include <algorithm>
#include <windows.h>
class Pestana
{
private:
	static std::vector<SitioWeb*> sitiosDisponibles;
	std::vector<SitioWeb*> historialSitios;
	SitioWeb* sitioActual;
	bool incognito;
	int indice;
public:
	Pestana();
	Pestana(SitioWeb* si, bool in = false);
	static void leerSitiosDisponibles();
	virtual~Pestana();
	void vaciarVectorSitiosDisponibles();
	SitioWeb* getSitioActual();
	int getIndice();

	std::vector<SitioWeb*> getHistorialSitios();

	bool asignarActual(std::string dominio);

	

	bool buscar();

	bool etiquetar();

	std::string encabezado();

	std::string imprimirActual(); //imprime el actual dentro de la pestana

	std::string navegarStr();


};