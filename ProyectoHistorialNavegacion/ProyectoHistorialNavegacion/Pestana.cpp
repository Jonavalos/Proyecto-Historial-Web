#include "Pestana.h"
#define FLECHA_IZQ 75
#define FLECHA_DER 77

std::vector<SitioWeb*> Pestana::sitiosDisponibles;
std::vector<SitioWeb*> Pestana::historialSitios;

Pestana::Pestana()
{
	sitioActual = nullptr;
	//leerSitiosDisponibles();
}

Pestana::Pestana(SitioWeb* si)
{
	sitioActual = si;
}

void Pestana::leerSitiosDisponibles()
{
	std::fstream strm("sitiosDispinibles.csv", std::ios::in);
	if (strm.good() && strm.is_open()) {
		SitioWeb* aux;
		while ((aux = SitioWeb::recuperar(strm)) != nullptr) {
			sitiosDisponibles.push_back(aux);
		}
	}
	strm.close();
}

Pestana::~Pestana()
{
	if (this->sitioActual ==nullptr) {
		//delete sitio;		//No se si deberia borrar, por ahora no, eventualmente
	}
}

void Pestana::vaciarVectorSitiosDisponibles()
{
	std::vector<SitioWeb*>::iterator iter;
	for (iter = sitiosDisponibles.begin(); iter != sitiosDisponibles.end(); iter++) {
		delete (*iter);
	}
}

void Pestana::vaciarHistorialSitios()
{
	std::vector<SitioWeb*>::iterator iter;
	for (iter = historialSitios.begin(); iter != historialSitios.end(); iter++) {
		delete (*iter);
	}
}

SitioWeb* Pestana::getSitioActual()
{
	return sitioActual;
}

void Pestana::setSitio(SitioWeb& si)		//Por referencia
{
	sitioActual = &si;
}

void Pestana::guardarSitioActual(std::fstream& strm)
{
	sitioActual->guardar(strm);
}

Pestana* Pestana::recuperar(std::fstream& strm)
{
	SitioWeb* aux = SitioWeb::recuperar(strm);
	return new Pestana(aux);
}

bool Pestana::asignarActual(std::string dominio)
{
	SitioWeb sitioABuscar(dominio);
	
	auto it = std::find_if(sitiosDisponibles.begin(), sitiosDisponibles.end(),
		[&sitioABuscar](SitioWeb* p) { return *p == sitioABuscar; });

	if (it != sitiosDisponibles.end()) {
		sitioActual = *it;
		historialSitios.push_back(sitioActual);
		return true;
	}
	return false;

	//explicacion miedo
	/*
	itera el vector comparandolo con el dominio de sitioABuscar, si lo encuentra lo almacena en it
	lo de abajo es una lambda (funcion anonima interna).
	[&sitioABuscar] significa que lambda accede a esa variable externa por referencia (sin copia)
	(SitioWeb* p) es un parametro de la funcion, donde se almacena el valor de it (creo), si coinciden ahi se queda
	{return *p == sitioABuscar} es el cuerpo de la funcion
	Resumen: usa sitioABuscar y lo compara con la desreferencia de p, devuelve un bool
	*/
}

std::string Pestana::mostrarHistorialCompleto()
{
	std::stringstream s;
	s << '\n';
	s << "HISTORIAL DE NAVEGACION -> " << '\n';
	s << '\n';
	std::vector<SitioWeb*>::iterator iter;
	for (iter = historialSitios.begin(); iter != historialSitios.end(); iter++) {
		s << **iter << '\n';
	}
	s << '\n';
	s << " <- Fin del historial" << '\n';
	return s.str();
}

std::string Pestana::toString()
{
	std::stringstream s;
	s << " >>>>>>>>>>>>>>>>	PESTANA		<<<<<<<<<<<<<<<<" << '\n';
	s << sitioActual->toString();
	s << mostrarHistorialCompleto() << '\n';
	s << " >>>>>>>>>>>>>>>>	Fin		<<<<<<<<<<<<<<<<" << '\n';

	return s.str();
}
int indice = 0;
std::string Pestana::navegarPorHistorialStr()
{
	//system("pause");
	//system("cls");
	std::stringstream s;
	s << " >>>>>>>>>>>>>>>>	Historial		<<<<<<<<<<<<<<<<" << '\n';
	s << "Flecha de abajo para salir, Izq o Der para moverse" << '\n';
	char tecla;

	tecla = _getch();  // Captura una tecla



	if (tecla == 0 || tecla == -32) {
		// Esto es necesario para capturar las teclas especiales como las flechas
		tecla = _getch();

		if (tecla != FLECHA_IZQ && tecla != FLECHA_DER)
			return "";

		if (tecla == FLECHA_IZQ) { //izq
			if (indice - 1 >= 0) {
				s << "Posicion:" << indice - 1 << '\n';
				s << historialSitios.at(indice - 1)->toString() << '\n';
				indice--;
			}
		}
		if (tecla == FLECHA_DER) { //der
			if (indice + 1 < historialSitios.size()) {
				s << "Posicion:" << indice + 1 << '\n';
				s << historialSitios.at(indice + 1)->toString() << '\n';
				indice++;
			}
		}
		
	}


	s << " >>>>>>>>>>>>>>>>	Fin	Historial	<<<<<<<<<<<<<<<<" << '\n';

	return s.str();
}

void Pestana::navegarPorHistorial()
{
	 // Captura una tecla
	std::cout<<"Posicion:" << 0 << '\n';
	std::cout << *historialSitios.at(0) << '\n';
	while (true) {
		std::string h = navegarPorHistorialStr();

		if (h!="") {
			std::cout << h << '\n';
		}
		else {
			break;
		}
		
	}

}
