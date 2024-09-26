#include "Control.h"

int main() {
   Control::getInstance()->navegar();      //Guardar y leer de pestanas ya sirve 

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

    return 0;

}

/*
To do (para hacer)

agregarPestanaActual() en menu
guardar sesion 
limitar tamano del historial
vector de sitios marcados (bookmark)

*/