#include "Pestana.h"

int main() {
    //SitioWeb* google = new SitioWeb("Google", "google.com", "https::www.google.com", "buscador", true);	
    //google->guardarEnSitiosDisponibles();
    //SitioWeb* yahoo = new SitioWeb("Yahoo", "yahoo.com", "https::www.yahoo.com", "buscador", true);
    //yahoo->guardarEnSitiosDisponibles();
    //SitioWeb* firefox = new SitioWeb("Firefox", "firefox.com", "https::www.firefox.com", "buscador", true);
    //firefox->guardarEnSitiosDisponibles();

    Pestana* pestana = new Pestana();
    pestana->leerSitiosDisponibles();
    std::cout << pestana->asignarActual("firefox.com") << '\n';
    std::cout << pestana->asignarActual("google.com") << '\n';
    std::cout << pestana->asignarActual("firefox.com") << '\n';

    Pestana* pestana2 = new Pestana();
    std::cout << pestana2->asignarActual("yahoo.com") << '\n';
    pestana2->navegarPorHistorial();
    std::cout << pestana2->imprimir() << '\n';

    /*
    *  std::cout << "Presiona las flechas direccionales. Presiona ESC para salir." << std::endl;

    while (true) {
        // Verifica si la tecla ESC est� siendo presionada para salir del bucle
        if (GetAsyncKeyState(VK_ESCAPE)) {
            std::cout << "ESC presionado. Saliendo..." << std::endl;
            break;
        }

        // Verifica si la flecha hacia arriba est� siendo presionada
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            std::cout << "Flecha hacia arriba presionada." << std::endl;
        }

        // Verifica si la flecha hacia abajo est� siendo presionada
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            std::cout << "Flecha hacia abajo presionada." << std::endl;
        }

        // Verifica si la flecha hacia la izquierda est� siendo presionada
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            std::cout << "Flecha hacia la izquierda presionada." << std::endl;
        }

        // Verifica si la flecha hacia la derecha est� siendo presionada
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            std::cout << "Flecha hacia la derecha presionada." << std::endl;
        }

        // A�adir un peque�o retraso para no sobrecargar la CPU
        Sleep(100);
    }
    */
   

        return 0;
}