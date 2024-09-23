#include "SitioWeb.h"

SitioWeb::SitioWeb(std::string dominio)
	: titulo(""), dominio(dominio), url(""), etiqueta(""), marcado(false)
{
}

SitioWeb::SitioWeb(std::string titu, std::string dom, std::string ur) : titulo(titu), dominio(dom), url(ur), etiqueta(""), marcado(false)
{

}

SitioWeb::SitioWeb(std::string titu, std::string dom, std::string ur, std::string etiqueta, bool marcado)
	: titulo(titu), dominio(dom), url(ur), etiqueta(etiqueta), marcado(marcado) {}

SitioWeb::SitioWeb() : titulo(""), dominio(""), url(""), etiqueta(""), marcado(false)
{
}

SitioWeb::~SitioWeb()
{

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

std::string SitioWeb::getEtiqueta()
{
	return etiqueta;
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

void SitioWeb::setEtiqueta(std::string tag)
{
	etiqueta = tag;
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
	const char* etiq = etiqueta.c_str();
	bool marca = marcado;

	strm.write(tit, LONGITUD_MAXIMA_STRING);	
	strm.write(domi, LONGITUD_MAXIMA_STRING);
	strm.write(ur, LONGITUD_MAXIMA_STRING);
	strm.write(etiq, LONGITUD_MAXIMA_STRING);
	strm.write(reinterpret_cast<char*>(&marca), sizeof(bool));
}

SitioWeb* SitioWeb::recuperar(std::fstream& strm) //Binario
{
	char tit[LONGITUD_MAXIMA_STRING];
	char domi[LONGITUD_MAXIMA_STRING];
	char ur[LONGITUD_MAXIMA_STRING];
	char etiq[LONGITUD_MAXIMA_STRING];
	bool marca;

	strm.read(tit, LONGITUD_MAXIMA_STRING);
	strm.read(domi, LONGITUD_MAXIMA_STRING);
	strm.read(ur, LONGITUD_MAXIMA_STRING);
	strm.read(etiq, LONGITUD_MAXIMA_STRING);
	strm.read(reinterpret_cast<char*>(&marca), sizeof(bool));

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
	if (marcado) {
		s << "[		" << "Marcado(Bookmark): activo" << "		]" << '\n';
		s << "[		" << "Etiqueta(Tag): " << etiqueta << "			]" << '\n';
	}
	return s.str();
}


/*
std::fstream strm("sitiosDispinibles.csv", std::ios::in);
		std::string  tituloStr = "", dominioStr = "", urlStr = "", etiquetaStr = "", marcadoStr = "";

		std::getline(strm, tituloStr, SEPARA_DATO);
		std::getline(strm, dominioStr, SEPARA_DATO);
		std::getline(strm, urlStr, SEPARA_DATO);
		std::getline(strm, etiquetaStr, SEPARA_REGISTRO);
		std::getline(strm, marcadoStr, SEPARA_DATO);


		if (tituloStr == "" || dominioStr == "" || urlStr == "")
			return nullptr;

		return new SitioWeb(blabla)
*/