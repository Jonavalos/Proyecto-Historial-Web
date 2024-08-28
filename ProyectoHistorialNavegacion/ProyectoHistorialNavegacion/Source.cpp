#include "Pestana.h"

int main() {

	SitioWeb google("google.com", "Google", "https::www.google.com");
	google.setMarcado(true);
	google.setEtiqueta("buscador");
	std::cout << google.toString() << '\n';




	return 0;
}