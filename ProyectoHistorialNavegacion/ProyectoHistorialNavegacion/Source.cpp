#include "Pestana.h"

int main() {

	//SitioWeb* google = new SitioWeb("Google", "google.com", "https::www.google.com", "buscador", true);	
	//google->guardarEnSitiosDisponibles();
	//SitioWeb* yahoo = new SitioWeb("Yahoo", "yahoo.com", "https::www.yahoo.com", "buscador", true);
	//yahoo->guardarEnSitiosDisponibles();
	//SitioWeb* firefox = new SitioWeb("Firefox", "firefox.com", "https::www.firefox.com", "buscador", true);
	//firefox->guardarEnSitiosDisponibles();

	Pestana* pestana = new Pestana();
	pestana->leerSitiosDisponibles();
	std::cout << pestana->asignarActual("firefox.com") << '\n';
	std::cout << pestana->toString() << '\n';

	Pestana* pestana2 = new Pestana();
	std::cout << pestana2->asignarActual("yahoo.com") << '\n';
	std::cout << pestana2->toString() << '\n';
	

	return 0;
}