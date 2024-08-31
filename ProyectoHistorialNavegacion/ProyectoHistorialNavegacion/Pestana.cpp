#include "Pestana.h"

std::vector<SitioWeb*> Pestana::sitiosDisponibles;

Pestana::Pestana()
{
	sitio=nullptr;
}

Pestana::Pestana(SitioWeb* si)
{
	sitio = si;
}

void Pestana::leerSitiosDisponibles()
{
	std::fstream strm("sitiosDispinibles.csv", std::ios::in);
	if (strm.good() && strm.is_open()) {
		SitioWeb* aux;
		while ((aux = SitioWeb::recuperar(strm)) != nullptr) {
			sitiosDisponibles.push_back(aux);
		}
	}
	strm.close();
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

void Pestana::guardar(std::fstream& strm)
{
	sitio->guardar(strm);
}

Pestana* Pestana::recuperar(std::fstream& strm)
{
	SitioWeb* aux = SitioWeb::recuperar(strm);
	return new Pestana(aux);
}
