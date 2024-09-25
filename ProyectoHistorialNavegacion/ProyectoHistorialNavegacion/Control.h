#pragma once
#include"Sesion.h"
class Control	
{
private:
	std::vector<Sesion*> sesiones;
	Sesion* sesionActual;
	Control();
	static Control* instance;
public:
	static Control* getInstance();
	static Control* leer();
	void navegar();
	void modificarSesion();
	void cambiarSesion();
	void crearNuevaSesion();

};

