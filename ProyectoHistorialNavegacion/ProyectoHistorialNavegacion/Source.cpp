#include "Control.h"

//este programa incluye bibliotecas: iostream, sstream, string, conio.h, algorithm, windows.h, vector

int main() {
   /*Control::getInstance()->navegar();*/      //Guardar y leer de pestanas ya sirve 

   /* Pestana* pestana = new Pestana();
    pestana->leerSitiosDisponibles();
    pestana->asignarActual("firefox.com");
    pestana->asignarActual("google.com");
    pestana->asignarActual("firefox.com");

    Pestana* pestana2 = new Pestana();
    pestana2->asignarActual("yahoo.com");
    
    Sesion pantalla;
    pantalla.agregarPestanaActual(pestana);
    pantalla.agregarPestanaActual(pestana2);
    pantalla.navegarPestanas();*/
    //std::vector<SitioWeb*> sitios;

    //std::fstream strm("sitiosDispinibles.csv", std::ios::in);
    //if (strm.good() && strm.is_open()) {
    //    SitioWeb* aux;
    //    while ((aux = SitioWeb::recuperar(strm)) != nullptr) {
    //        sitios.push_back(aux);
    //    }
    //}
    //strm.close();

    //Pestana* pestana=new Pestana(nullptr, false, sitios);
    //pestana->asignarActual("firefox.com");
    //pestana->asignarActual("google.com");

    //std::fstream s("pruebaPestana.csv", std::ios::out);
    //if (s.good() && s.is_open()) {
    //    pestana->guardar(s);
    //    pestana->guardar(s);
    //}
    //s.close();
    //Pestana* pes2 = nullptr;
    //Pestana* pes3 = nullptr;
    //std::fstream leer("pruebaPestana.csv", std::ios::in);

    //if (leer.good() && leer.is_open()) {
    //     pes2 = Pestana::leer(leer, sitios);
    //     pes3 = Pestana::leer(leer, sitios);
    //}
    //leer.close();

    //pes3->getSitioActual()->setEtiqueta("Pop");
    //std::cout << pes3->imprimirActual();
    //std::cout << pes2->imprimirActual();
    //std::cout << pestana->imprimirActual();


    //if (pestana)
    //    delete pestana;
    //if (pes2)
    //    delete pes2;
    std::vector<std::string>* tags = new std::vector<std::string>;
    tags->push_back("buscador");
    tags->push_back("hola");

    std::vector<std::string>* tags2 = new std::vector<std::string>;
    tags2->push_back("busca");
    tags2->push_back("h");
    tags2->push_back("tigre");



    SitioWeb* sitio = new SitioWeb("Google", "google.com", "google.com.com", tags, false);
    SitioWeb* sitio3 = new SitioWeb("Firefox", "firefox.com", "firefox.com.com", tags2, false);

    std::fstream guardar("pruebaSitio.csv",std::ios::out);

    if (guardar.good() && guardar.is_open()) {
       sitio->guardar(guardar);
       sitio3->guardar(guardar);
    }
    guardar.close();

    std::fstream leer("pruebaSitio.csv", std::ios::in);

    SitioWeb* sitio2 = nullptr;
    SitioWeb* sitio4 = nullptr;

    if (leer.good() && leer.is_open()) {
        sitio2 = SitioWeb::recuperar(leer);
        sitio4 = SitioWeb::recuperar(leer);
    }
    leer.close();
    
    std::cout << sitio->getUrl() << "\n\n";
    std::cout << sitio2->getUrl() << "\n\n";
    std::cout << sitio3->getUrl() << "\n\n";
    std::cout << sitio4->getUrl() << "\n\n";

    for (std::string a : *sitio->getTags()) {
        std::cout << a << "\n";
    }
    std::cout << "\n";
    for (std::string a : *sitio2->getTags()) {
        std::cout << a << "\n";
    }
    std::cout << "\n";


    for (std::string a : *sitio3->getTags()) {
        std::cout << a << "\n";
    }
    std::cout << "\n";

    for (std::string a : *sitio4->getTags()) {
        std::cout << a << "\n";
    }
    std::cout << "\n";




    return 0;

}

/*
To do (para hacer)

agregarPestanaActual() en menu
guardar sesion 
limitar tamano del historial
vector de sitios marcados (bookmark)

*/