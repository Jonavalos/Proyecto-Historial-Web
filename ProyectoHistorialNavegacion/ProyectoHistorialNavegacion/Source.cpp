#include "Pantalla.h"

int main() {

    Pestana* pestana = new Pestana();
    pestana->leerSitiosDisponibles();
    std::cout << pestana->asignarActual("firefox.com") << '\n';
    std::cout << pestana->asignarActual("google.com") << '\n';
    std::cout << pestana->asignarActual("firefox.com") << '\n';

    Pestana* pestana2 = new Pestana();
    std::cout << pestana2->asignarActual("yahoo.com") << '\n';
    
    Pantalla pantalla;
    pantalla.agregarPestanaActual(pestana);
    pantalla.agregarPestanaActual(pestana2);
    pantalla.navegarPestanas();

        return 0;
}


/*
To do (para hacer)

agregarPestanaActual() en menu
guardar sesion 
limitar tamano del historial

*/