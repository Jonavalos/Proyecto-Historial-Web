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
	nombreSesion = "Usuario";
	pestanaActual = new Pestana(nullptr, false,sitios);
	pestanas.push_back(pestanaActual);
	indiceP = 0;
}

Sesion::Sesion(std::string nom)
{
	std::fstream strm("sitiosDispinibles.csv", std::ios::in);
	if (strm.good() && strm.is_open()) {
		SitioWeb* aux;
		while ((aux = SitioWeb::recuperar(strm)) != nullptr) {
			sitios.push_back(aux);
		}
	}
	strm.close();
	nombreSesion = nom;

	pestanaActual = new Pestana(nullptr, false, sitios);
	pestanas.push_back(pestanaActual);
	indiceP = 0;
	
}

Sesion::~Sesion() {
	//por ahora no, eventualmente
}


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
					return h;
				}
				if (h == "create") {
					pestanaActual = new Pestana(nullptr, false, sitios);
					pestanas.push_back(pestanaActual);
					h = "Se ha creado una nueva pestana";
				}	
				if (h != "") {
					Interfaz::mostrar(h);
				}
				else {
						break;
					}
			}
			Interfaz::mostrar(p);
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

std::string Sesion::getNombre()
{
	return nombreSesion;
}

void Sesion::guardar(std::fstream& strm)
{

	/*std::vector<Pestana*> pestanas;
	Pestana* pestanaActual;
	std::vector<SitioWeb*> sitios;
	std::string nombreSesion;


	std::string nombre;
	Pestana* actual = nullptr;*/
	



}

Sesion* Sesion::leer(std::fstream& strm, std::vector<SitioWeb*> a)
{
	return nullptr;
}
