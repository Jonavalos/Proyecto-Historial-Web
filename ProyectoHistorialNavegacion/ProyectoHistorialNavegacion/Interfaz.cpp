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

std::string Interfaz::buscarConTag()
{
	system("cls");
	std::string filtro = "";
	std::cout << "Ingrese el tag (string) a buscar" << '\n';
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
	int i = 0;
	for (SitioWeb* sitio:marcados) {
		std::cout << "Sitio#" << i++ << "\n";
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
		system("pause");
	}
	if (op == "1") {
		int o = -1;
		while (true) {
			std::cout << "Digite la posicion de la pagina que desea visitar(Empezando en 0)\n";
				std::cin >> o;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					o = -1;
				}
				if (o >= 0 && o < marcados.size()) {
					break;
				}
				std::cout << "Ha insertado un valor invalido\n";
				system("pause");
			}
		return o;
	}
	return -1;
}

int Interfaz::mostarBusquedaHistorial(std::vector<SitioWeb*> marcados)
{
	for (SitioWeb* sitio : marcados) {
		std::cout << sitio->toString() << "\n\n";
	}

	std::string op;
	while (true) {
		std::cout << "Desea navegar en un sitio ?\n(0)->No\n(1)->Si\n";
		std::cin >> op;
		if (op == "1" || op == "0") {
			break;
		}
		std::cout << "Ha insertado un valor invalido\n";
		system("pause");
	}
	if (op == "1") {
		int o = -1;
		while (true) {
			std::cout << "Digite la posicion de la pagina que desea visitar(Empezando en 0)\n";
				std::cin >> o;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					o = -1;
				}
				if (o >= 0 && o < marcados.size()) {
					break;
				}
				std::cout << "Ha insertado un valor invalido\n";
				system("pause");
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

int Interfaz::guardarONo()
{
	int op = -1;
	while (true) {
			system("cls");
			std::cout << "Importar/Exportar\n";
			std::cout << "(1)Importar\n(2)Exportar\n(3)Cancelar\n";
			std::cin >> op;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				op = -1;
			}
			if (op > 0 && op < 4) {
				return op;
			}
			std::cout << "Ha insertado un valor invalido\n";
			system("pause");
	}
	
}

bool Interfaz::salir()
{
	while (true) {
	system("cls");
	std::cout << "Salir?\n(ESC)Salir\n(0)Cancelar\n";
	system("pause");
	if (ESCAPE) {
		despedida();
		return true;
	}
	if (CERO) {
		return false;
	}
	std::cout << "Ha insertado un valor invalido\n";
	system("pause");
	}
}

void Interfaz::despedida()
{
	std::cout << "Ha sido un placer. Hasta pronto!\n";
}

int Interfaz::insertarSesiones(int n)
{
	int op = 0;
	while (true) {
			system("cls");
			std::cout << "Se han encontrado " << n << " sesiones\n";
			std::cout << "Que desea hacer?\n";
			std::cout << "(1)Reemplazar las sesiones existentes\n";
			std::cout << "(2)Agregar las sesiones leidas a las actuales.\n";
			std::cin >> op;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				op = -1;
			}
			if (op == 1 || op == 2) {
				return op;
			}
			std::cout << "Ha insertado un valor invalido\n";
			system("pause");
	}
}

void Interfaz::sesionesVacias()
{
	std::cout << "No se han encontrado sesiones guardadas\n";
	system("pause");
}

int Interfaz::guardar()
{
	int op = 0;
	while (true) {
	
			system("cls");
			std::cout << "Guardar Sesiones\n";
			std::cout << "Que desea hacer?\n";
			std::cout << "(1)Guardar sesion actual\n";
			std::cout << "(2)Guardar todas las sesiones\n";
			std::cin >> op;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				op = -1;
			}
			if (op == 1 || op == 2) {
				return op;
			}
			std::cout << "Ha insertado un valor invalido\n";
			system("pause");
	}
}

bool Interfaz::confirmacionGuardar()
{
	int op = -1;
	while (true) {
			system("cls");
			std::cout << "Esta seguro?\nSe borraran las sesiones que se hayan guardado anteriormente\n";
			std::cout << "(1)Si\n(0)No\n";
			std::cin >> op;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				op = -1;
			}
			if (op == 1 || op == 0) {
				return op;
			}
			std::cout << "Ha insertado un valor invalido\n";
			system("pause");
	}
}

int Interfaz::modificarSesion()
{
	int op = -1;
	while (true) {
		system("cls");
		std::cout << "(0)Cambiar Sesion \n(1)Crear nueva sesion\n(2)Cancelar\n";
		std::cin >> op;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			op = -1;
		}
		if (op == 1 || op == 0 || op == 2) {
			return op;
		}
		std::cout << "Ha insertado un valor invalido\n";
		system("pause");
	}
	
}

std::string Interfaz::nombreSesion()
{
	system("cls");
	std::string nom;
	std::cout << "Digite el nombre de la nueva sesion:\n";
	std::cin >> nom;
	return nom;
}

void Interfaz::sesionIngresada()
{
	std::cout << "Se ha ingresado una nueva sesion con exito\n";
	system("pause");
}

void Interfaz::cantidadSesiones(int n)
{
	system("cls");
	std::cout << "Actualmeste hay " << n << " sesiones\n";
	std::cout << "A cual de las siguientes sesiones desea viajar? Digite el numero de la sesion\n";
}

void Interfaz::mostrarSesion(int i, std::string nombre)
{
	std::cout << "Sesion# " << i << " : " << nombre << "\n";
}

int Interfaz::cambiarSesion(int n)
{
	int op = -1;
	while (true) {
		std::cin >> op;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			op = -1;
		}
		if (op >= 0 && op < n) {
			return op;
		}
		std::cout << "Ha insertado un valor invalido\n";
		system("pause");
	}
}
