#include "SitioWeb.h"

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



SitioWeb* SitioWeb::recuperar(std::fstream& strm) //binario
{
	SitioWeb* sitio = new SitioWeb();
	strm.read(reinterpret_cast<char*>(sitio), sizeof(SitioWeb));
	return sitio;
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