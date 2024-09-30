#pragma once
#include"SitioWeb.h"
#include<forward_list>
#include<vector>
#include <algorithm>
#include <limits>
#include <windows.h>
#include"Interfaz.h"
#undef max

class Pestana
{
private:
	std::vector<SitioWeb*> sitiosDisponibles;	//sitios que se pueden buscar, los del archivo
	std::vector<SitioWeb*> historialSitios;		//sitios que se han visitado
	SitioWeb* sitioActual;						//mostrado en la parte de arriba, el mas reciente
	bool incognito;
	int indice;
	std::string filtro;
public:
	Pestana();
	Pestana(int n);
	Pestana(SitioWeb* si, bool in, std::vector<SitioWeb*> = std::vector<SitioWeb*>());
	Pestana(SitioWeb* si = nullptr, bool in = false,int indice = 0, std::vector<SitioWeb*> sitios = std::vector<SitioWeb*>(), std::vector<SitioWeb*> hist = std::vector<SitioWeb*>());
	virtual~Pestana();
	bool verificarTimerHistorial();

	void leerSitiosDisponibles();
	std::vector < SitioWeb*> getSitiosDisponibles();
	void vaciarVectorSitiosDisponibles();
	SitioWeb* getSitioActual();
	int getIndice();
	void setSitiosDisponibles(std::vector<SitioWeb*>a);
	std::vector<SitioWeb*> getHistorialSitios();

	bool asignarActual(std::string dominio);

	std::vector<SitioWeb*> marcados();
	std::vector<SitioWeb*> busquedaEnHistorial(std::string filtro);
	bool contiene(std::string filtro, std::string texto);

	bool buscar();

	std::string mostrarMarcados();

	bool etiquetar();

	std::string imprimirActual();

	std::string navegarStr();

	//Archivos

	static SitioWeb* sitioPorURL(std::vector<SitioWeb*> sit,std::string url);
	void guardar(std::fstream& strm);
	static Pestana* leer(std::fstream& strm, std::vector<SitioWeb*> a);

};
