#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include <conio.h>
#define LONGITUD_MAXIMA_STRING 50
#define FLECHA_IZQ GetAsyncKeyState(VK_LEFT) & 0x8000
#define FLECHA_DER GetAsyncKeyState(VK_RIGHT) & 0x8000
#define FLECHA_UP GetAsyncKeyState(VK_UP) & 0x8000
#define FLECHA_DOWN GetAsyncKeyState(VK_DOWN) & 0x8000
#define LETRA_i GetAsyncKeyState('I') & 0x8000	//incognito
#define LETRA_B GetAsyncKeyState('B') & 0x8000	//buscar
#define LETRA_E GetAsyncKeyState('E') & 0x8000	//etiquetar
#define ESCAPE GetAsyncKeyState(VK_ESCAPE) & 0x8000
#define LETRA_V GetAsyncKeyState('V') & 0x8000	//Ver lista marcados
#define LETRA_M GetAsyncKeyState('M') & 0x8000	//marcar
#define NO_FLECHAS_NI_ESC_NI_i_NI_m (!(GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(GetAsyncKeyState(VK_LEFT) & 0x8000) && !(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && !(GetAsyncKeyState('I') & 0x8000) && !(GetAsyncKeyState('M') & 0x8000) )
#define NO_B_NI_E (!(GetAsyncKeyState('B') & 0x8000) && !(GetAsyncKeyState('E') & 0x8000))
#define NO_UP_DOWN (!(GetAsyncKeyState(VK_DOWN) & 0x8000) && !(GetAsyncKeyState(VK_UP) & 0x8000))

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

	void toggleMarcado();
	void guardarEnSitiosDisponibles();


	std::string toString() const;

};

