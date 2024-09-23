#include "Pestana.h"
std::vector<SitioWeb*> Pestana::sitiosDisponibles;
std::vector<SitioWeb*> Pestana::vecMarcados;

Pestana::Pestana()
{
	incognito = false;
	sitioActual = nullptr;
	indice = 0;
}

Pestana::Pestana(SitioWeb* si, bool in)
{
	sitioActual = si;
	incognito = in;
	indice = 0;
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

Pestana::~Pestana()
{
	if (this->sitioActual == nullptr) {
		//delete sitio; //Por ahora no, eventualmente
	}
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

std::vector<SitioWeb*> Pestana::getHistorialSitios()
{
	return historialSitios;
}

bool Pestana::asignarActual(std::string dominio) //para buscar
{
	SitioWeb sitioABuscar(dominio);

	auto it = std::find_if(sitiosDisponibles.begin(), sitiosDisponibles.end(),
		[&sitioABuscar](SitioWeb* p) { return *p == sitioABuscar; });

	if (it != sitiosDisponibles.end()) {
		if (historialSitios.size() == 10) {
			historialSitios.pop_back();
		}
		sitioActual = *it;
		if(!incognito)
			historialSitios.insert(historialSitios.begin(), sitioActual);
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

bool Pestana::buscar()
{
	system("cls");
	std::string dominio = "";
	std::cout << "Ingrese el dominio del sitio a buscar" << '\n'; std::cin >> dominio;
	system("cls");
	return asignarActual(dominio);
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

std::vector<SitioWeb*> Pestana::marcados() {		//No entra al ciclo porque no le da la gana
	std::vector<SitioWeb*> vec;
	/*for (SitioWeb* sitio:sitiosDisponibles) {*/
	for (int i = 0; i < sitiosDisponibles.size();i++) {
		/*if (sitio->getMarcado()) {
			vec.push_back(sitio);
		}*/
		if (sitiosDisponibles.at(i)->getMarcado()) {
			vec.push_back(sitiosDisponibles.at(i));
		}
	}
	return vec;
}

std::string Pestana::encabezado()
{
std::stringstream s;
s << " >>>>>>>>>>>>>>>> Historial <<<<<<<<<<<<<<<<" << '\n';
s << "salir (ESC), moverse entre paginas(<- ->), moverse entre pestanas(up down)" << '\n';
return s.str();
}
std::string Pestana::imprimirActual()
{
std::stringstream s;

s << "~~ PESTANA ~~" << '\n';
s << "incognito(i), marcar(m), buscar(b)" << '\n';
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
s << imprimirActual() << '\n';
s << encabezado();
s << "Posicion:" << indice - 1 << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice - 1)->toString() << '\n';
indice--;
}
else {
s << imprimirActual() << '\n';
s << encabezado();
s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice)->toString() << '\n';
}
}
if (FLECHA_DER) {
if (indice + 1 < historialSitios.size()) {
s << imprimirActual() << '\n';
s << encabezado();
s << "Posicion:" << indice + 1 << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice + 1)->toString() << '\n';
indice++;
}
else {
s << imprimirActual() << '\n';
s << encabezado();
s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
s << historialSitios.at(indice)->toString() << '\n';
}
}
if (LETRA_i) {
incognito = !incognito; //conmutacion incognito
s << imprimirActual() << '\n';
s << encabezado();
s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n'; //indice
s << historialSitios.at(indice)->toString() << '\n'; //cuerpo del historial
}

if (LETRA_M) {
	if (!incognito) {
		sitioActual->toggleMarcado(); //conmutacion de marcado
		if (sitioActual->getMarcado()) {
			etiquetar();
		}
	}
		s << imprimirActual() << '\n';
		s << encabezado();
		s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
		s << historialSitios.at(indice)->toString() << '\n';
	
}
if (LETRA_B) {
	if (!buscar())
		return "1";

	s << imprimirActual() << '\n';
	s << encabezado();
	s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
	s << historialSitios.at(indice)->toString() << '\n';
}
//if (LETRA_E) {
//	etiquetar();
//	s << imprimirActual() << '\n';
//	s << encabezado();
//	s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
//	s << historialSitios.at(indice)->toString() << '\n';
//}
if (FLECHA_DOWN) {
	return "down";
}
if (FLECHA_UP) {
	return "up";
}
if (ESCAPE) {
return "";
}
if (LETRA_V) {
	system("cls");
	std::string a = mostrarMarcados();
	if (a == "1") {
		return "No hay sitios marcados\n";
	}
	std::cout<< a;
	std::vector<SitioWeb*>aux = marcados();
	int num = ingresarMarcado(aux.size());
	if(num != -1){
		asignarActual(aux.at(num)->getDominio());
	}
	s << imprimirActual() << '\n';
	s << encabezado();
	s << "Posicion:" << indice << "/" << historialSitios.size() - 1 << '\n';
	s << historialSitios.at(indice)->toString() << '\n';
}
if (NO_FLECHAS_NI_ESC_NI_i_NI_m && NO_B_NI_E) {
return "Navegue con ( <-, ->, ESC, i, m, b,v) \n<-, -> = Historial\ni = Incognito\nm = Marcar\nb = Buscar\nv = Ver marcadores\n";
}

s << " >>>>>>>>>>>>>>>> Fin Historial <<<<<<<<<<<<<<<<" << '\n';

return s.str();
}

int Pestana::ingresarMarcado(int n)
{
	std::string op;
	while(true) {
		std::cout << "Desea navegar en un sitio marcado?\n(0)->No\n(1)->Si\n";
		std::cin>>op;
		if (op == "1" || op == "0") {
			break;
	}
		std::cout << "Ha insertado un valor invalido\n";
	}
	if (op == "1") {
		int o = -1;
		while(true) {
			std::cout << "Digite la posicion de la pagina que desea visitar(Empezando en 0)\n";
			try {
				std::cin >> o;
				if (o >= 0 && o < n) {
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
