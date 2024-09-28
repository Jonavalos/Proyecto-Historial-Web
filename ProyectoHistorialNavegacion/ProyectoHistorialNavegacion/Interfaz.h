#pragma once
#include<iostream>
#include<sstream>
#include"SitioWeb.h"

class Interfaz
{
public:
	static std::string encabezado();
	static std::string buscarDominio();
	static std::string buscarFiltro();
	static std::string buscarConTag();
	static std::string etiquear();
	static bool etiquetaEsValida(std::string tag);
	static int mostrarMarcados(std::vector<SitioWeb*> marcados);
	static int mostarBusquedaHistorial(std::vector<SitioWeb*> marcados);
	static void mostrar(std::string m);
	static std::string imprimirSitioActual(SitioWeb* actual,bool inc);
	static int guardarONo();

};

