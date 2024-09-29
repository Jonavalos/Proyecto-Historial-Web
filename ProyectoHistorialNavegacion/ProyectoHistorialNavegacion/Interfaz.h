#pragma once
#include<iostream>
#include<sstream>
#include<windows.h>
#include"SitioWeb.h"
#undef max



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
	static bool salir();
	static void despedida();
	static int insertarSesiones(int n);
	static void sesionesVacias();
	static int guardar();
	static bool confirmacionGuardar();
	static int modificarSesion();
	static std::string nombreSesion();
	static void sesionIngresada();
	static void cantidadSesiones(int n);
	static void mostrarSesion(int i, std::string nombre);
	static int cambiarSesion(int n);

};

