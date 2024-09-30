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
	pestanaActual = new Pestana(nullptr, false,0,sitios);
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

	pestanaActual = new Pestana(nullptr, false,0, sitios);
	pestanas.push_back(pestanaActual);
	indiceP = 0;
	
}

Sesion::Sesion(std::string nom, int ind, Pestana* act, std::vector<SitioWeb*> sit, std::vector<Pestana*> pest)
{
	this->nombreSesion = nom;
	this->indiceP = ind;
	this->pestanaActual = act;
	this->sitios = sit;
	this->pestanas = pest;
}

Sesion::~Sesion() {
	for (Pestana* pestana : pestanas) { //tiene sitios pero se borran en el siguiente for
		delete pestana;
	}
	for (SitioWeb* sitio : sitios) { //se borran los 25 sitios, cada uno con su vector respectivo de tags
		delete sitio;
	}
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
		if (p != "") { 
			//h es la navegacion de pestana. aqui se ejecutan cosas dependiendo de su output
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
				if (h == "save") {
					return h;
				}
				if (h == "exit") {
					return h;
				}
				if (h == "create") {
					pestanaActual = new Pestana(nullptr, false,0, sitios);
					indiceP += 1;
					pestanas.push_back(pestanaActual);
					h = "Se ha creado una nueva pestana";
				}
				if (h == "i") {
					pestanaActual = new Pestana(nullptr, true,0, sitios);
					indiceP += 1;
					pestanas.push_back(pestanaActual);
					h = "Se ha creado una nueva pestana MODO INCOGNITO";
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

std::vector<SitioWeb*> Sesion::getSitios()
{
	return sitios;
}

void Sesion::guardar(std::fstream& strm)
{
	int indice = indiceP;
	const char* nom = nombreSesion.c_str();
	bool pesActualExiste = (pestanaActual != nullptr);
	int cantPestanas = pestanas.size();
	int cantSitios = sitios.size();

	strm.write(reinterpret_cast<char*>(&indice), sizeof(int));
	strm.write(nom, LONGITUD_MAXIMA_STRING);
	
	strm.write(reinterpret_cast<char*>(&cantSitios), sizeof(int));
	for (SitioWeb* s : sitios) {
		s->guardar(strm);
	}

	strm.write(reinterpret_cast<char*>(&pesActualExiste), sizeof(bool));
	
	strm.write(reinterpret_cast<char*>(&cantPestanas), sizeof(int));
	for (Pestana* s : pestanas) {
		s->guardar(strm);
	}
}

Sesion* Sesion::leer(std::fstream& strm)
{
	int indice=0;
	bool existePesAct = false;
	char nombre[LONGITUD_MAXIMA_STRING];
	int cantPestanas = 0;
	int cantSitios = 0;
	SitioWeb* sit = nullptr;
	Pestana* pes = nullptr;
	std::vector<SitioWeb*> sitios;
	std::vector<Pestana*> pestanas;

	if (!strm.read(reinterpret_cast<char*>(&indice), sizeof(int))) {
		return nullptr; 
	}

	if (!strm.read(nombre, LONGITUD_MAXIMA_STRING)) {
		return nullptr; 
	}

	if (!strm.read(reinterpret_cast<char*>(&cantSitios), sizeof(int))) {
		return nullptr;
	}

	for (int i = 0; i < cantSitios;i++) {
		sit = SitioWeb::recuperar(strm);
		if (!sit)	return nullptr;
		sitios.push_back(sit);
	}

	if (!strm.read(reinterpret_cast<char*>(&existePesAct), sizeof(bool))) {
		return nullptr;
	}

	if (!strm.read(reinterpret_cast<char*>(&cantPestanas), sizeof(int))) {
		return nullptr; 
	}

	for (int i = 0; i < cantPestanas; i++) {
		pes = Pestana::leer(strm,sitios);
		if (!pes) return nullptr;
		pestanas.push_back(pes);
	}
	return new Sesion(nombre, indice,pestanas.at(indice), sitios, pestanas);
}
