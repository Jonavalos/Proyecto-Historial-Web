#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#define SEPARA_DATO ' '
#define SEPARA_REGISTRO '\n'
#define LONGITUD_MAXIMA_STRING 50
class SitioWeb
{
private:
	
	std::string titulo;		//Google (nombre)
	std::string dominio;	//google.com
	std::string url;		//https//::www.google.com/algo (no usar // porque lo comenta)			
	std::string etiqueta;	//tag
	bool marcado;			//bookmark

public:

	

	SitioWeb(std::string dominio); //Para uso exclusivo 'find' de <algorithm>, no usar
	SitioWeb(std::string titu, std::string dom, std::string ur);
	SitioWeb(std::string titu, std::string dom, std::string ur, std::string etiqueta, bool marcado);
	SitioWeb();
	virtual~SitioWeb();
	
	bool operator==(const SitioWeb& obj) const { //Para uso exclusivo 'find' de <algorithm>, no verifica todo, no usar
		return (this->dominio == obj.dominio);
	}
	friend std::ostream& operator<<(std::ostream& os, const SitioWeb& obj)
	{
		os << obj.toString();
		return os;
	}
	

	std::string getTitulo();
	std::string getDominio();
	std::string getUrl();
	std::string getEtiqueta();
	bool getMarcado();
	
	void setTitulo(std::string titu);
	void setDominio(std::string dom);
	void setUrl(std::string ur);
	void setEtiqueta(std::string mar);
	void setMarcado(bool mar);

	void guardar(std::fstream& strm);
	static SitioWeb* recuperar(std::fstream& strm);


	void guardarEnSitiosDisponibles();


	std::string toString() const;

};

