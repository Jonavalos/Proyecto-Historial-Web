#pragma once
#include"Sesion.h"
class Control	
{				//controladora singleton
private:
	std::vector<Sesion*> sesiones;
	Sesion* sesionActual;
	Control();
	static Control* instance;
public:
	~Control() {
		for (Sesion* sesion : sesiones) {
			delete sesion;
		}
	}
	static void deleteInstance();
	static Control* getInstance();
	void navegar();
	void modificarSesion();
	void cambiarSesion();
	void crearNuevaSesion();
	void importarExportar();
	void importar();
	std::vector<Sesion*> leerSesiones();
	void exportar();
	void guardarSesionActual();
	void guardarSesiones();
	

};

