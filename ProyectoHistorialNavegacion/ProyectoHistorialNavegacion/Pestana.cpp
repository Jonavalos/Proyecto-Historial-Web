#include "Pestana.h"


Pestana::Pestana()
{
	incognito = false;
	sitioActual = nullptr;
	indice = 0;
}

Pestana::Pestana(int n) //para mock y unit tests
{
	incognito = false;
	sitioActual = nullptr;
	indice = 0;
}

Pestana::Pestana(SitioWeb* si, bool in, std::vector<SitioWeb*> sit)
{
	sitiosDisponibles = sit;
	sitioActual = si;
	incognito = in;
	indice = 0;
	filtro = "";
}

Pestana::Pestana(SitioWeb* si, bool in, int indice, std::vector<SitioWeb*> sitios, std::vector<SitioWeb*> hist)
{
	this->sitioActual = si;
	this->incognito = in;
	this->indice = indice;
	this->sitiosDisponibles = sitios;
	this->historialSitios = hist;
	this->filtro = "";
}

Pestana::~Pestana() //los sitios se eliminan en sesion
{
	/*for (SitioWeb* sitio : historialSitios) {
		delete sitio;
	}*/
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

std::vector<SitioWeb*> Pestana::getSitiosDisponibles()
{
	return sitiosDisponibles;
}

void Pestana::vaciarVectorSitiosDisponibles()
{
	std::vector<SitioWeb*>::iterator iter;
	for (iter = sitiosDisponibles.begin(); iter != sitiosDisponibles.end(); iter++) {
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

void Pestana::setSitiosDisponibles(std::vector<SitioWeb*> a)
{
	this->sitiosDisponibles = a;
}

std::vector<SitioWeb*> Pestana::getHistorialSitios()
{
	return historialSitios;
}

bool Pestana::asignarActual(std::string filtro) //para buscar
{
	SitioWeb sitioABuscar(filtro);

	auto it = std::find_if(sitiosDisponibles.begin(), sitiosDisponibles.end(),
		[&sitioABuscar](SitioWeb* p) { return *p == sitioABuscar; });

	if (it != sitiosDisponibles.end()) {
		if (historialSitios.size() == 10) {
			historialSitios.pop_back();
		}
		sitioActual = *it;
		sitioActual->restartTimer();
		if(!incognito)
			historialSitios.insert(historialSitios.begin(), sitioActual);
		return true;
	}
	return false;

	//explicacion miedo		//ya no es dominio, ahora string filtro se setea en todos los atributos tipo string de SitioWeb
	/*
	itera el vector comparandolo con el dominio de sitioABuscar, si lo encuentra lo almacena en it
	lo de abajo es una lambda (funcion anonima interna).
	[&sitioABuscar] significa que lambda accede a esa variable externa por referencia (sin copia)
	(SitioWeb* p) es un parametro de la funcion, donde se almacena el valor de it (creo), si coinciden ahi se queda
	{return *p == sitioABuscar} es el cuerpo de la funcion
	Resumen: usa sitioABuscar y lo compara con la desreferencia de p, devuelve un bool
*/
}

bool Pestana::buscar()
{
	return asignarActual(Interfaz::buscarDominio());
}

std::string Pestana::mostrarMarcados()
{
	std::stringstream s;

	std::vector<SitioWeb*> aux = marcados();
	if (aux.size()>0) {
		for (int i = 0; i < aux.size(); i++) {
			s << aux.at(i)->toString()<<"\n\n";
		}
		return s.str();
	}
	return "1";
}

bool Pestana::etiquetar()
{
	std::string tag = Interfaz::etiquear();
	if (Interfaz::etiquetaEsValida(tag)) {
		return false;
	}
	sitioActual->agregarTag(tag);
	return true;
}

std::vector<SitioWeb*> Pestana::marcados() {		
	std::vector<SitioWeb*> vec;
	for (SitioWeb* sitio:sitiosDisponibles) {
		if (sitio->getMarcado()) {
			vec.push_back(sitio);
		}
	}
	return vec;
}
std::vector<SitioWeb*> Pestana::busquedaEnHistorial(std::string filtro)
{
	std::vector<SitioWeb*> vec;
	for (SitioWeb* sitio : historialSitios) {
		if (contiene(filtro, sitio->getTitulo())) {
			vec.push_back(sitio);
		}
	}
	return vec;
}
bool Pestana::contiene(std::string filtro, std::string texto)
{
	bool encontrado = false;
	if (texto.find(filtro) != std::string::npos) {	//npos es una constante de c++ 
		encontrado = true;						//que contiene el valor  max de indice de string
	}
	return encontrado;
}
std::string Pestana::imprimirActual()
{
std::stringstream s;

if (sitioActual) {
	s << "~~ PESTANA ACTUAL ~~" << '\n';
	s << "incognito(i), marcar(m), buscar(b)" << '\n';
	s << "Incognito: " << incognito << '\n';
	s << sitioActual->toString();
	s << "~~ FinPestana ~~" << '\n';
}
else {
	s << "No se ha ingresado un SitioWeb\n";
}
return s.str();
}

std::string Pestana::navegarStr()
{
std::stringstream s;
//if (sitioActual)
//{
//	if (sitioActual->debeEliminarse())
//		sitioActual = nullptr;
//}
verificarTimerHistorial();
if (FLECHA_IZQ) {
if (indice - 1 >= 0) {
	indice -= 1;
}
}
if (FLECHA_DER) {
if (indice + 1 < historialSitios.size()) {
	indice+=1;
}
}
if (LETRA_i) {		//!incognito, crea una nueva en incognito. incognito, lo pasa a normal 
	if (incognito)
		incognito = false;
	else
		return "i";
}

if (LETRA_M) {
	if (!incognito && sitioActual) {
		sitioActual->toggleMarcado(); //conmutacion de marcado
		if (sitioActual->getMarcado()) {
			etiquetar();
		}
	}
}
if (LETRA_B) {			//se resetea el timer del sitioActual (el que acaba de buscar)
	if (!buscar())	
		return "1";
}

if (FLECHA_DOWN) {
	return "down";
}
if (FLECHA_UP) {
	return "up";
}
if (ESCAPE) {
return "exit";
}
if (LETRA_V) {
	system("cls");
	std::vector<SitioWeb*>aux = marcados();
	if (aux.size() == 0) {
		return "No hay sitios marcados\n";
	}
	int num = Interfaz::mostrarMarcados(aux);
	if(num != -1){
		asignarActual(aux.at(num)->getDominio());
	}
}
if (LETRA_H) {
	system("cls");
	std::string filtro = Interfaz::buscarFiltro();
	std::vector<SitioWeb*>aux = busquedaEnHistorial(filtro);
	if (aux.size() == 0) {
		return "No coincide el filtro\n";
	}
	int num = Interfaz::mostarBusquedaHistorial(aux);
	if (num != -1) {
		asignarActual(aux.at(num)->getDominio());
	}
}
if (LETRA_S) {
	return "change";
}
if (LETRA_C) {
	return "create";
}
if (LETRA_G) {		
	return "save";
}

if (LETRA_F) {
	system("cls");
	filtro = Interfaz::buscarFiltro();
	if (filtro == "reset")
		filtro = "";
}
if (NO_FLECHAS_NI_ESC_NI_i_NI_m_NI_b_NI_NI_S_NI_c_NI_g_NI_f_NI_NI_H) {
	return "<-, -> = Historial\nup & down = Pestanas\ni = Incognito\nESC = Salir\nm = Marcar\nb = Buscar\nv = Ver marcadores\nc = Crear nueva pestana\ns = Cambiar de sesion\nf = Filtrar\ng = Importar/Exportar\nh = Buscar en Historial";
}
s << Interfaz::imprimirSitioActual(sitioActual, incognito) << '\n';
if (!incognito) {
	s << Interfaz::encabezado();
	if (historialSitios.size() != 0) {
		if (contiene(filtro, historialSitios.at(indice)->getTitulo())) {
			s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
			s << historialSitios.at(indice)->toString() << '\n';
		}
	}
}
if (historialSitios.size() == 0) {
	s << "Aun no se han realizado busquedas\n";
}

s << " >>>>>>>>>>>>>>>> Fin Historial <<<<<<<<<<<<<<<<" << '\n';

return s.str();
}

void Pestana::guardar(std::fstream& strm)
{
	bool incog = incognito;
	int ind = indice;
	bool sitioActualExiste = (sitioActual != nullptr);
	int cantHistorial = historialSitios.size();
	std::string url;
	

	strm.write(reinterpret_cast<char*>(&incog), sizeof(bool));
	strm.write(reinterpret_cast<char*>(&ind), sizeof(int));
	strm.write(reinterpret_cast<char*>(&sitioActualExiste), sizeof(bool));

	if (sitioActualExiste) {
		url = sitioActual->getUrl(); // Usar std::string para mantener la validez
		strm.write(url.c_str(), LONGITUD_MAXIMA_STRING);
	}

	strm.write(reinterpret_cast<char*>(&cantHistorial), sizeof(int));
	for (SitioWeb* sitio:historialSitios) {
		url = sitio->getUrl().c_str();
		strm.write(url.c_str(), LONGITUD_MAXIMA_STRING);
	}
}

SitioWeb* Pestana::sitioPorURL(std::vector<SitioWeb*> sit, std::string url)
{
	std::vector<SitioWeb*>::iterator iter;
	for (iter = sit.begin(); iter != sit.end(); iter++) {
		if ((*iter)->getUrl() == url)
			return (*iter);
	}
	return nullptr;
}

Pestana* Pestana::leer(std::fstream& strm, std::vector<SitioWeb*> a) {
	bool incog=false;
	int ind = 0;
	bool sitioActualExiste = false;
	int cantHistorial = 0;
	char url[LONGITUD_MAXIMA_STRING];
	std::vector<SitioWeb*> historial;
	SitioWeb* auxiliar = nullptr;
	SitioWeb* actual = nullptr;

	strm.read(reinterpret_cast<char*>(&incog), sizeof(bool));
	strm.read(reinterpret_cast<char*>(&ind), sizeof(int));
	strm.read(reinterpret_cast<char*>(&sitioActualExiste), sizeof(bool));
	if (sitioActualExiste) {
		strm.read(url, LONGITUD_MAXIMA_STRING);
		actual=sitioPorURL(a,url);
	}
	strm.read(reinterpret_cast<char*>(&cantHistorial), sizeof(int));
	for (int i = 0; i < cantHistorial; i++) {
		strm.read(url, LONGITUD_MAXIMA_STRING);
		auxiliar = sitioPorURL(a, url);
		if (auxiliar) historial.push_back(auxiliar);
	}
	return new Pestana(actual, incog, ind, a, historial);

}
