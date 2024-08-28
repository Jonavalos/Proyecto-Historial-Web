#include "SitioWeb.h"

SitioWeb::SitioWeb(std::string dom, std::string titu, std::string ur) :dominio(dom), titulo(titu), url(ur), etiqueta(""), marcado(false) 
{

}

SitioWeb::SitioWeb() :dominio(""), titulo(""), url(""), etiqueta(""), marcado(false)
{
}

SitioWeb::~SitioWeb()
{

}

SitioWeb SitioWeb::leer(std::fstream& arch)
{
	return SitioWeb();		//Desarrollar
}

bool SitioWeb::getMarcado()
{
	return marcado;
}

std::string SitioWeb::getEtiqueta()
{
	return etiqueta;
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

void SitioWeb::setMarcado(bool mar)
{
	marcado = mar;
}

void SitioWeb::setEtiqueta(std::string tag)
{
	etiqueta = tag;
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
