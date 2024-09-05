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

}
int indiceP = 0;

std::string Pantalla::navegarPestanasStr()
{
	std::stringstream s;
	if (FLECHA_DOWN) {
		
		if (indiceP - 1 >= 0) {
			s << "Posicion:" << indiceP - 1 << "/" << pestanas.size() - 1 << '\n';
			pestanas.at(indiceP - 1)->navegar();
			indiceP--;
		}
		else {
			s << "Posicion:" << indiceP << "/" << pestanas.size() - 1 << '\n';
			pestanas.at(indiceP)->navegar();
		}
	}
	if (FLECHA_UP) {
		if (indiceP + 1 <= pestanas.size()-1) {
			s << "Posicion:" << indiceP + 1 << "/" << pestanas.size() - 1 << '\n';
			pestanas.at(indiceP + 1)->navegar();
			indiceP++;
		}
		else {
			s << "Posicion:" << indiceP << "/" << pestanas.size() - 1 << '\n';
			pestanas.at(indiceP)->navegar();
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
	/*std::cout << "Posicion:" << 0 << "/" << pestanas.at(indiceP)->getHistorialSitios().size() - 1 << '\n';
	std::cout << *(pestanas.at(indiceP)->getHistorialSitios().at(0)) << '\n';*/
	

	while (true) {
		std::string p = navegarPestanasStr();
		if (p == "1") {
			system("cls");
			p = "navegue con flechas";
			system("pause");
		}
		if (p != "") { //mientras no sea ESC, navegar en Pestana

			while (true) {
				std::string h = pestanas.at(indiceP)->navegarStr();
				if (h == "1") {
					system("cls");
					h = "Pagina no encontrada";
					system("pause");
				}
				if (h == "up" || h=="down") {
					h=navegarPestanasStr();
					//h = "cambiando";
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
