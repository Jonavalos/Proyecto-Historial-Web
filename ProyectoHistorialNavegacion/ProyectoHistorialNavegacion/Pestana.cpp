#include "Pestana.h"

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

std::string Pestana::mostrarHistorial()
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
	s << mostrarHistorial() << '\n';
	s << " >>>>>>>>>>>>>>>>	Fin		<<<<<<<<<<<<<<<<" << '\n';

	return s.str();
}
