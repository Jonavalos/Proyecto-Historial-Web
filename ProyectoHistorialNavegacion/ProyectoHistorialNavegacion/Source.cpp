#include "Pestana.h"

int main() {

	SitioWeb* google=new SitioWeb("google.com", "Google", "https::www.google.com");
	google->setMarcado(true);
	google->setEtiqueta("buscador");
	std::cout << google->toString() << '\n';

	std::fstream strm("prueba.csv", std::ios::out | std::ios::binary);
	google->guardar(strm);
	strm.close();

	std::fstream st("prueba.csv", std::ios::in |std::ios::binary);
	SitioWeb* go = SitioWeb::recuperar(st);
	st.close();

	std::cout << go->toString() << '\n';		

	/*Pestana* pes = new Pestana();*/


	return 0;
}