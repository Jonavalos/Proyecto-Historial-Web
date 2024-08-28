#include "Pestana.h"

std::vector<SitioWeb*> Pestana::sitiosDisponibles;

Pestana::Pestana()
{
	sitio=nullptr;
}

void Pestana::leerSitiosDisponibles()
{
	std::fstream strm("sitiosDispinibles.csv", std::ios::in);
	std::string  tituloStr = "", dominioStr = "", urlStr = "", marcadoStr = "", etiquetaStr = "";

	while (std::getline(strm, marcadoStr, SEPARA_DATO)) {

	}

}

Pestana::~Pestana()
{
	if (this->sitio ==nullptr) {
		//delete sitio;		//No se si deberia borrar, por ahora no, eventualmente
	}
}

void Pestana::vaciarLista()
{
	std::vector<SitioWeb*>::iterator iter;

	for (iter = sitiosDisponibles.begin(); iter != sitiosDisponibles.end(); iter++) {
		delete (*iter);
	}
}

SitioWeb* Pestana::getSitio()
{
	return sitio;
}

void Pestana::setSitio(SitioWeb& si)		//Por referencia
{
	sitio = &si;
}
