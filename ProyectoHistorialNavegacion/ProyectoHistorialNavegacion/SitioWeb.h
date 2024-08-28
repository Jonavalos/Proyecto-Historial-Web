#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

class SitioWeb
{
private:
	bool marcado;			//bookmark
	std::string etiqueta;	//tag
	std::string titulo;		//Google (nombre)
	std::string dominio;	//google.com
	std::string url;		//https::www.google.com/algo
public:
	SitioWeb(std::string dom, std::string titu, std::string ur);
	SitioWeb();
	virtual~SitioWeb();
	static SitioWeb leer(std::fstream& arch);		//Debe ser en binario
	bool getMarcado();
	std::string getEtiqueta();
	std::string getTitulo();
	std::string getDominio();
	std::string getUrl();
	void setMarcado(bool mar);
	void setEtiqueta(std::string mar);
	void setTitulo(std::string titu);
	void setDominio(std::string dom);
	void setUrl(std::string ur);

	std::string toString() {
		std::stringstream s;
		s << "[		" << url << "			]" << '\n';
		s << "[	" << dominio << "		-> "  << titulo << "		]" << '\n';
		if (marcado)
			s << "[		" << "Marcado(Bookmark): activo" << "		]" << '\n';
		s << "[		" << "Etiqueta(Tag): " << etiqueta << "			]" << '\n';
		return s.str();
	}

};

