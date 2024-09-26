#include "Interfaz.h"

std::string Interfaz::encabezado()
{
	std::stringstream s;
	s << " >>>>>>>>>>>>>>>> Historial <<<<<<<<<<<<<<<<" << '\n';
	s << "salir (ESC), moverse entre paginas(<- ->), moverse entre pestanas(up down)" << '\n';
	return s.str();
}

std::string Interfaz::buscarDominio()
{
	system("cls");
	std::string dominio = "";
	std::cout << "Ingrese el dominio del sitio a buscar" << '\n'; 
	std::cin >> dominio;
	system("cls");
	return dominio;
}

std::string Interfaz::buscarFiltro()
{
	system("cls");
	std::string filtro = "";
	std::cout << "Ingrese el filtro (string) a buscar" << '\n';
	std::cin >> filtro;
	system("cls");
	return filtro;
}

std::string Interfaz::etiquear()
{
	system("cls");
	std::string tag = "";
	std::cout << "Ingrese la etiqueta(Tag): " << '\n'; 
	std::cin >> tag;
	system("cls");
	return tag;
}

bool Interfaz::etiquetaEsValida(std::string tag)
{
	if (tag.length() > 15) {
		std::cout << "Limite de caracteres alcanzado..." << '\n';
		return false;
	}
	return true;
}

int Interfaz::mostrarMarcados(std::vector<SitioWeb*> marcados)
{
	for (SitioWeb* sitio:marcados) {
		std::cout<< sitio->toString() << "\n\n";
	}

	std::string op;
	while (true) {
		std::cout << "Desea navegar en un sitio marcado?\n(0)->No\n(1)->Si\n";
		std::cin >> op;
		if (op == "1" || op == "0") {
			break;
		}
		std::cout << "Ha insertado un valor invalido\n";
	}
	if (op == "1") {
		int o = -1;
		while (true) {
			std::cout << "Digite la posicion de la pagina que desea visitar(Empezando en 0)\n";
			try {
				std::cin >> o;
				if (o >= 0 && o < marcados.size()) {
					break;
				}
				std::cout << "Ha digitado un valor invalido\n";
			}
			catch (const std::invalid_argument& e) {
				std::cout << "Ha digitado un valor invalido\n";
				o = -1;
			}
		}
		return o;
	}
	return -1;
}

int Interfaz::mostrarFiltrados(std::vector<SitioWeb*> marcados)
{
	for (SitioWeb* sitio : marcados) {
		std::cout << sitio->toString() << "\n\n";
	}

	std::string op;
	while (true) {
		std::cout << "Desea navegar en un sitio filtrado?\n(0)->No\n(1)->Si\n";
		std::cin >> op;
		if (op == "1" || op == "0") {
			break;
		}
		std::cout << "Ha insertado un valor invalido\n";
	}
	if (op == "1") {
		int o = -1;
		while (true) {
			std::cout << "Digite la posicion de la pagina que desea visitar(Empezando en 0)\n";
			try {
				std::cin >> o;
				if (o >= 0 && o < marcados.size()) {
					break;
				}
				std::cout << "Ha digitado un valor invalido\n";
			}
			catch (const std::invalid_argument& e) {
				std::cout << "Ha digitado un valor invalido\n";
				o = -1;
			}
		}
		return o;
	}
	return -1;
}

void Interfaz::mostrar(std::string m)
{
	system("cls");
	std::cout << m << '\n';
	system("pause");
}

std::string Interfaz::imprimirSitioActual(SitioWeb* actual,bool inc)
{
	std::stringstream s;

	if (actual) {
		s << "~~ PESTANA ACTUAL ~~" << '\n';
		s << "incognito(i), marcar(m), buscar(b)" << '\n';
		s << "Incognito: ";
		if (inc) {
			s << "Activo\n";
		}
		else {
			s << "Desactivado\n";
		}
		s << actual->toString();
		s << "~~ FinPestana ~~" << '\n';
	}
	else {
		s << "No se ha ingresado un SitioWeb\n";
	}
	return s.str();
}
