#include "Pestana.h"
std::vector<SitioWeb*> Pestana::sitiosDisponibles;
//std::vector<SitioWeb*> Pestana::historialSitios;

Pestana::Pestana()
{
	incognito = false;
	sitioActual = nullptr;
	//leerSitiosDisponibles();
}

Pestana::Pestana(SitioWeb* si, bool in)
{
	sitioActual = si;
	incognito = in;
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
	if (this->sitioActual == nullptr) {
		//delete sitio; //No se si deberia borrar, por ahora no, eventualmente
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

int Pestana::getIndice()
{
	return indice;
}

std::vector<SitioWeb*> Pestana::getHistorialSitios()
{
	return historialSitios;
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
		if(!incognito)
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

bool Pestana::buscar()
{
	system("cls");
	std::string dominio = "";
	std::cout << "Ingrese el dominio del sitio a buscar" << '\n'; std::cin >> dominio;
	system("cls");
	return asignarActual(dominio);
}

bool Pestana::etiquetar()
{
	system("cls");
	std::string tag = "";
	std::cout << "Ingrese la etiqueta(Tag): " << '\n'; std::cin >> tag;
	system("cls");
	if (tag.length() > 15) {
		std::cout << "Limite de caracteres alcanzado..." << '\n';
		return false;
	}
	sitioActual->setEtiqueta(tag);
	return true;
}


std::string Pestana::encabezado()
{
std::stringstream s;
s << " >>>>>>>>>>>>>>>> Historial <<<<<<<<<<<<<<<<" << '\n';
s << "salir (ESC), moverse entre paginas(<- ->), moverse entre pestanas(up down)" << '\n';
return s.str();
}
std::string Pestana::imprimir()//sitio actual
{
std::stringstream s;

s << "~~ PESTANA ~~" << '\n';
s << "incognito(i), marcar(m), buscar(b), etiquetar(e)" << '\n';
s << "Incognito: " << incognito << '\n';
s << sitioActual->toString();
s << "~~ FinPestana ~~" << '\n';
return s.str();
}

std::string Pestana::navegarStr()
{
std::stringstream s;

if (FLECHA_IZQ) {
if (indice - 1 >= 0) {
s << imprimir() << '\n'; //sitio actual
s << encabezado();
s << "Posicion:" << indice - 1 << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice - 1)->toString() << '\n';
indice--;
}
else {
s << imprimir() << '\n'; //sitio actual
s << encabezado();
s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice)->toString() << '\n';
}
}
if (FLECHA_DER) {
if (indice + 1 < historialSitios.size()) {
s << imprimir() << '\n'; //sitio actual
s << encabezado();
s << "Posicion:" << indice + 1 << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice + 1)->toString() << '\n';
indice++;
}
else {
s << imprimir() << '\n'; //sitio actual
s << encabezado();
s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice)->toString() << '\n';
}
}
if (LETRA_i) {
incognito = !incognito; //conmutacion incognito
s << imprimir() << '\n'; //sitio actual
s << encabezado();
s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n'; //indice
s << historialSitios.at(indice)->toString() << '\n'; //cuerpo del historial
}

if (LETRA_M) {
	sitioActual->toggleMarcado(); //conmutacion de marcado
	s << imprimir() << '\n';
	s << encabezado();
	s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
	s << historialSitios.at(indice)->toString() << '\n';

}
if (LETRA_B) {
	if (!buscar())
		return "1";

	s << imprimir() << '\n';
	s << encabezado();
	s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
	s << historialSitios.at(indice)->toString() << '\n';
}
if (LETRA_E) {
	etiquetar();
	s << imprimir() << '\n';
	s << encabezado();
	s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
	s << historialSitios.at(indice)->toString() << '\n';
}
if (FLECHA_DOWN) {
	return "down";
}
if (FLECHA_UP) {
	return "up";
}
if (ESCAPE) {
return "";
}
if (NO_FLECHAS_NI_ESC_NI_i_NI_m && NO_B_NI_E) { // se puede mover a navegarPorHistorial(), que retorne algo diferente
return "Navegue con ( <-, ->, ESC, i, m, b) \n";
}

s << " >>>>>>>>>>>>>>>> Fin Historial <<<<<<<<<<<<<<<<" << '\n';

return s.str();
}

void Pestana::navegar()
{
//std::cout << "Posicion:" << 0 << "/" << historialSitios.size() - 1 << '\n';
//std::cout << *historialSitios.at(0) << '\n';
//while (true) {
//std::string h = navegarStr();
//if (h == "1") {
//	system("cls");
//	h = "Pagina no encontrada";
//	system("pause");
//}
//if (h!="") {
//system("cls");
//std::cout << h << '\n';
//system("pause");
//}
//else {
//break;
//}
//}

}
