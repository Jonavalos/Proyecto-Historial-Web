#include "Pestana.h"
#define FLECHA_IZQ GetAsyncKeyState(VK_LEFT) & 0x8000
#define LETRA_i GetAsyncKeyState('I') & 0x8000
#define FLECHA_DER GetAsyncKeyState(VK_RIGHT) & 0x8000
#define ESCAPE GetAsyncKeyState(VK_ESCAPE) & 0x8000
#define NO_FLECHAS_NI_ESC_NI_i (!(GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(GetAsyncKeyState(VK_LEFT) & 0x8000) && !(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && !(GetAsyncKeyState('I') & 0x8000) )
std::vector<SitioWeb*> Pestana::sitiosDisponibles;
std::vector<SitioWeb*> Pestana::historialSitios;

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

void Pestana::setSitio(SitioWeb* si) //Por referencia
{
	sitioActual = si;
	if (!incognito)
		historialSitios.push_back(sitioActual);

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
s << " >>>>>>>>>>>>>>>> PESTANA <<<<<<<<<<<<<<<<" << '\n';
s << sitioActual->toString();
s << mostrarHistorialCompleto() << '\n';
s << " >>>>>>>>>>>>>>>> Fin <<<<<<<<<<<<<<<<" << '\n';

return s.str();
}
std::string Pestana::encabezado()
{
std::stringstream s;
s << " >>>>>>>>>>>>>>>> Historial <<<<<<<<<<<<<<<<" << '\n';
s << "salir (ESC), moverse (<- ->), incognito(i)" << '\n';
return s.str();
}
std::string Pestana::imprimir()//sitio actual
{
std::stringstream s;

s << "~~ PESTANA ~~" << '\n';
s << "Incognito: " << incognito << '\n';
s << sitioActual->toString();
s << "~~ FinPestana ~~" << '\n';
return s.str();
}
int indice = 0;

std::string Pestana::navegarPorHistorialStr()
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
incognito = !incognito;
s << imprimir() << '\n'; //sitio actual
s << encabezado();
s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice)->toString() << '\n';
}
if (ESCAPE) {
return "";
}
if (NO_FLECHAS_NI_ESC_NI_i) { // se puede mover a navegarPorHistorial(), que retorne algo diferente
return "Navegue con ( <-, ->, ESC, i ) \n";
}

s << " >>>>>>>>>>>>>>>> Fin Historial <<<<<<<<<<<<<<<<" << '\n';

return s.str();
}

void Pestana::navegarPorHistorial()
{
char tecla;
std::cout << "Posicion:" << 0 << "/" << historialSitios.size() - 1 << '\n';
std::cout << *historialSitios.at(0) << '\n';
while (true) {
std::string h = navegarPorHistorialStr();

if (h!="") {
system("cls");
std::cout << h << '\n';
system("pause");
}
else {
break;
}
}

}
