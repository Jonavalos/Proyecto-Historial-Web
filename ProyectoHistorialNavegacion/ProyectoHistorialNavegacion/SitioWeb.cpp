#include "SitioWeb.h"

SitioWeb::SitioWeb(std::string nom, std::string ur):nombre(nom),url(ur),marcador(""),marcado(false)
{
}

SitioWeb::SitioWeb() :nombre(""), url(""), marcador(""), marcado(false)
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

std::string SitioWeb::getMarcador()
{
	return marcador;
}

std::string SitioWeb::getNombre()
{
	return nombre;
}

std::string SitioWeb::getUrl()
{
	return url;
}

void SitioWeb::setMarcado(bool mar)
{
	marcado = mar;
}

void SitioWeb::setMarcador(std::string mar)
{
	marcador = mar;
}

void SitioWeb::setNombre(std::string nom)
{
	nombre = nom;
}

void SitioWeb::setUrl(std::string ur)
{
	url = ur;
}
