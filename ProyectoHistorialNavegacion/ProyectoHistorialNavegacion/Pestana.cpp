#include "Pestana.h"

std::vector<SitioWeb*> Pestana::sitiosDisponibles;

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
