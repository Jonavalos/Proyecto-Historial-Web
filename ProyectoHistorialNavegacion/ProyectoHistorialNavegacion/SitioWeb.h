#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

class SitioWeb
{
private:
	bool marcado; //bookmark
	std::string etiqueta; //tag
	std::string nombre;
	std::string url;
public:
	SitioWeb(std::string nom,std::string ur);
	SitioWeb();
	virtual~SitioWeb();
	static SitioWeb leer(std::fstream& arch);		//Debe ser en binario
	bool getMarcado();
	std::string getEtiqueta();
	std::string getNombre();
	std::string getUrl();
	void setMarcado(bool mar);
	void setEtiqueta(std::string mar);
	void setNombre(std::string nom);
	void setUrl(std::string ur);

};

