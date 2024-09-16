#include "Pantalla.h"
Pantalla::Pantalla()
{
	pestanaActual = nullptr;
}

Pantalla::Pantalla(Pestana* pestana)
{
	pestanaActual = pestana;
}

Pantalla::~Pantalla() {
	//por ahora no, eventualmente
}
int indiceP = 0;

std::string Pantalla::navegarPestanasStr()
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

void Pantalla::navegarPestanas()
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
					h = "Pagina no encontrada";
				}
				if (h == "up" || h=="down") {
					h=navegarPestanasStr();
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

bool Pantalla::agregarPestanaActual(Pestana* pestana)
{
	if (!pestana)
		return false;

	pestanaActual = pestana;
	pestanas.push_back(pestana);
	return true;
}
