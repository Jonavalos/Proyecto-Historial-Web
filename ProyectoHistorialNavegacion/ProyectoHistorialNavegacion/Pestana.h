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
	void vaciarHistorialSitios();
	SitioWeb* getSitioActual();
	int getIndice();

	std::vector<SitioWeb*> getHistorialSitios();

	void guardarSitioActual(std::fstream& strm);
	static Pestana* recuperar(std::fstream& strm);

	//busca el sitioWeb y lo asigna al atributo sitioActual
	bool asignarActual(std::string dominio);

	std::string mostrarHistorialCompleto();

	bool buscar();

	bool etiquetar();

	std::string encabezado();

	std::string imprimir(); //imprime el actual dentro de la pestana

	std::string navegarStr();

	void navegar();
};


/*
verificar si existe en vector
setearlo en atributo
y de ahi imprimirlo
*/

