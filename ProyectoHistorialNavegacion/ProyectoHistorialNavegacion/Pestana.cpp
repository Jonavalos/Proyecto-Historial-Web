#include "Pestana.h"

std::vector<SitioWeb*> Pestana::sitiosPermitidos;

Pestana::Pestana()
{
	sitio=nullptr;
}

void Pestana::leerSitios(std::fstream& arc)
{
	//while (!arc.eof()) {
	//	sitiosPermitidos.push_back(SitioWeb::leer(arc));	//Ve la direccion de memoria del nuevo sitioWeb
	//}
}

Pestana::~Pestana()
{
	if (this->sitio ==nullptr) {
		delete sitio;		//No se si deberia borrar
	}
}

void Pestana::vaciarLista()
{
	std::vector<SitioWeb*>::iterator iter;

	for (iter = sitiosPermitidos.begin(); iter != sitiosPermitidos.end(); iter++) {
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
