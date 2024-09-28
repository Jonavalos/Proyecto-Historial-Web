#pragma once
#include"SitioWeb.h"
#include<forward_list>
#include<vector>
#include <algorithm>
#include <windows.h>
#include"Interfaz.h"

class Pestana
{
private:
	std::vector<SitioWeb*> sitiosDisponibles;
	std::vector<SitioWeb*> historialSitios;
	SitioWeb* sitioActual;
	bool incognito;
	int indice;
	std::string filtro;
public:
	Pestana();
	Pestana(SitioWeb* si, bool in, std::vector<SitioWeb*> = std::vector<SitioWeb*>());
	Pestana(SitioWeb* si, bool in,int indice = 0, std::vector<SitioWeb*> = std::vector<SitioWeb*>());

	bool verificarTimerHistorial() {

		//for (auto it = historialSitios.begin(); it != historialSitios.end(); ) {
		//	if ((*it)->debeEliminarse()) {
		//		it = historialSitios.erase(it);  // Eliminar y actualizar el iterador
		//		return true;
		//	}
		//	else {
		//		++it;  // Avanzar al siguiente elemento solo si no se eliminó
		//	}
		//}
		//return false;

		for (SitioWeb* sitio : historialSitios) {
			if (sitio->debeEliminarse()) {
				historialSitios.pop_back();
				if (indice > 0)
					indice -= 1;
				return true;
			}
		}
		return false;
	}

	void leerSitiosDisponibles();
	std::vector < SitioWeb*> getSitiosDisponibles();
	virtual~Pestana();
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


	std::string imprimirActual(); //imprime el actual dentro de la pestana

	std::string navegarStr();

	int ingresarMarcado(int n);

	//Archivos

	static SitioWeb* sitioPorURL(std::vector<SitioWeb*> sit,std::string url);

	void guardar(std::fstream& strm);
	static Pestana* leer(std::fstream& strm, std::vector<SitioWeb*> a);

};
