#include "Sesion.h"
Sesion::Sesion()
{
	std::fstream strm("sitiosDispinibles.csv", std::ios::in);
	if (strm.good() && strm.is_open()) {
		SitioWeb* aux;
		while ((aux = SitioWeb::recuperar(strm)) != nullptr) {
			sitios.push_back(aux);
		}
	}
	strm.close();
	pestanaActual = new Pestana(nullptr, false,sitios);
	pestanas.push_back(pestanaActual);
}

Sesion::Sesion(Pestana* pestana)
{
	std::fstream strm("sitiosDispinibles.csv", std::ios::in);
	if (strm.good() && strm.is_open()) {
		SitioWeb* aux;
		while ((aux = SitioWeb::recuperar(strm)) != nullptr) {
			sitios.push_back(aux);
		}
	}
	strm.close();
	pestanaActual = pestana;
	
}

Sesion::~Sesion() {
	//por ahora no, eventualmente
}
int indiceP = 0;

std::string Sesion::navegarPestanasStr()
{
	std::stringstream s;
	if (FLECHA_DOWN) {
		
		if (indiceP - 1 >= 0) {
			s << "Posicion:" << indiceP - 1 << "/" << pestanas.size() - 1 << '\n';
			indiceP--;
		}
		else {
			s << "Posicion:" << indiceP << "/" << pestanas.size() - 1 << '\n';
		}
	}
	if (FLECHA_UP) {
		if (indiceP + 1 <= pestanas.size()-1) {
			s << "Posicion:" << indiceP + 1 << "/" << pestanas.size() - 1 << '\n';
			indiceP++;
		}
		else {
			s << "Posicion:" << indiceP << "/" << pestanas.size() - 1 << '\n';
		}
	}
	if (ESCAPE) {
		return "";
	}
	if (NO_UP_DOWN) {
		return "1";
	}
	
	return s.str();
}

std::string Sesion::navegarPestanas()
{	

	while (true) {
		std::string p = navegarPestanasStr();
		if (p == "1") {
			system("cls");
			p = "Navegue con flechas";

		}
		if (p != "") { //mientras no sea ESC, navegar en Pestana

			while (true) {
				std::string h = pestanas.at(indiceP)->navegarStr();
				if (h == "1") {
					system("cls");
					h = "404-Not Found";
				}
				if (h == "up" || h=="down") {
					h=navegarPestanasStr();
				}
				if (h == "change") {
					return "change";
				}
				if (h != "") {
					system("cls");
					std::cout << h << '\n';
					system("pause");
				}
				else {
					break;
				}
			}
			system("cls");
			std::cout << p << '\n';
			system("pause");
		}
		else {
			break;
		}
	}
}

bool Sesion::agregarPestanaActual(Pestana* pestana)
{
	if (!pestana)
		return false;

	pestanaActual = pestana;
	pestanas.push_back(pestana);
	return true;
}
