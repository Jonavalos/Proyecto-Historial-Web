#include "SitioWeb.h"

SitioWeb::SitioWeb(std::string filtro)
	: titulo(filtro), dominio(filtro), url(filtro), tags(new std::vector<std::string>), marcado(false)
{
	tiempo_creacion = std::chrono::steady_clock::now();
}

SitioWeb::SitioWeb(std::string titu, std::string dom, std::string ur) : titulo(titu), dominio(dom), url(ur), tags(new std::vector<std::string>), marcado(false)
{
	tiempo_creacion = std::chrono::steady_clock::now();
}

SitioWeb::SitioWeb(std::string titu, std::string dom, std::string ur, std::vector<std::string>* tags, bool marcado)
	: titulo(titu), dominio(dom), url(ur), tags(tags), marcado(marcado) {
	
	tiempo_creacion = std::chrono::steady_clock::now();

}

SitioWeb::SitioWeb() : titulo(""), dominio(""), url(""), tags(new std::vector<std::string>), marcado(false)
{
	tiempo_creacion = std::chrono::steady_clock::now();
}

SitioWeb::~SitioWeb()
{
	if (tags)
		delete tags;
}



std::string SitioWeb::getTitulo()
{
	return titulo;
}

std::string SitioWeb::getDominio()
{
	return dominio;
}

std::string SitioWeb::getUrl()
{
	return url;
}

std::vector<std::string>* SitioWeb::getTags()
{
	return tags;
}

bool SitioWeb::getMarcado()
{
	return marcado;
}



void SitioWeb::setTitulo(std::string titu)
{
	titulo = titu;
}

void SitioWeb::setDominio(std::string dom)
{
	dominio = dom;	
}

void SitioWeb::setUrl(std::string ur)
{
	url = ur;
}

void SitioWeb::setTags(std::vector<std::string>* tags)
{
	this->tags = tags;
}

void SitioWeb::agregarTag(std::string tag)
{
	tags->push_back(tag);
}

void SitioWeb::setMarcado(bool mar)
{
	marcado = mar;
}



void SitioWeb::guardar(std::fstream& strm)	//Binario
{
	const char* tit = titulo.c_str();
	const char* domi = dominio.c_str();
	const char* ur = url.c_str();
	const char* etiq;
	bool marca = marcado;
	int cantTags = tags->size();

	strm.write(tit, LONGITUD_MAXIMA_STRING);	
	strm.write(domi, LONGITUD_MAXIMA_STRING);
	strm.write(ur, LONGITUD_MAXIMA_STRING);
	strm.write(reinterpret_cast<char*>(&marca), sizeof(bool));
	strm.write(reinterpret_cast<char*>(&cantTags), sizeof(int));
	for (const std::string& a:*tags) {
		etiq = a.c_str();
		strm.write(etiq, LONGITUD_MAXIMA_STRING);
	}
}

SitioWeb* SitioWeb::recuperar(std::fstream& strm) //Binario
{
	char tit[LONGITUD_MAXIMA_STRING];
	char domi[LONGITUD_MAXIMA_STRING];
	char ur[LONGITUD_MAXIMA_STRING];
	std::vector<std::string>* etiq = new std::vector<std::string>;
	bool marca;
	int cantTags=0;

	strm.read(tit, LONGITUD_MAXIMA_STRING);
	strm.read(domi, LONGITUD_MAXIMA_STRING);
	strm.read(ur, LONGITUD_MAXIMA_STRING);
	strm.read(reinterpret_cast<char*>(&marca), sizeof(bool));
	strm.read(reinterpret_cast<char*>(&cantTags),sizeof(int));

	for (int i = 0; i < cantTags;i++) {
		char tag[LONGITUD_MAXIMA_STRING];
		strm.read(tag, LONGITUD_MAXIMA_STRING);
		etiq->push_back(tag);
	}

	if (strm.fail()) {
		//Ocurrio un error, deberia tirar excepcion
		return nullptr;
	}

	return new SitioWeb(tit, domi, ur, etiq, marca);
}

void SitioWeb::toggleMarcado()
{
	marcado = !marcado;
}

void SitioWeb::guardarEnSitiosDisponibles()
{
	std::fstream strm("sitiosDispinibles.csv", std::ios::app | std::ios::binary);
	if(strm.good())
		this->guardar(strm);
	strm.close();

}

std::string SitioWeb::toString() const
{
	std::stringstream s;
	s << "[		" << url << "			]" << '\n';
	s << "[		" << dominio << " -> " << titulo << "			]" << '\n';
	if (marcado && !tags->empty()) {
		s << "[		" << "Marcado(Bookmark): activo" << "		]" << '\n';
		s << "[		" << "Ultima Etiqueta(Tag): " << tags->at(0) << "			]" << '\n';
	}
	return s.str();
}