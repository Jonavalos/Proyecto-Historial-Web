#include "Control.h"

Control* Control::instance = nullptr;

Control::Control() {
    sesionActual = new Sesion();
    sesiones.push_back(sesionActual);
}
Control* Control::getInstance()
{
   if(instance == nullptr){
       instance = leer();
       if (instance == nullptr) {
           instance = new Control();
       }
       return instance;
   }
   return instance;
}

Control* Control::leer()
{
    //Lee lo que se guardo, y si no hay nada guardado retorna nullptr
    return nullptr;
}

void Control::navegar()
{
    while (true) {
        std::string aux = "";
        aux = sesionActual->navegarPestanas();
        if (aux == "change") {
            modificarSesion();
        }
    }
}

void Control::modificarSesion()
{
    std::string op = "";
    while (true) {
        system("cls");
        std::cout << "(0)Cambiar Sesion \n(1)Crear nueva sesion\n(2)Cancelar\n";
        std::cin >> op;
        if (op == "1" || op == "0" || op == "2") {
            break;
        }
        std::cout << "Ha insertado un valor invalido\n";
    }
    int o = std::stoi(op);
    switch (o) {
    case 0:
        cambiarSesion();
        break;
    case 1:
        crearNuevaSesion();
        break;
    case 2:
        break;
    }
}

void Control::crearNuevaSesion()
{
    sesionActual = new Sesion();
    sesiones.push_back(sesionActual);
    std::cout << "Se ha ingresado una nueva sesion con exito\n";
    system("pause");
}

void Control::cambiarSesion()
{
    int op = -1;
    std::cout << "Actualmente hay " << sesiones.size() << " sesiones\n";
    std::cout << "A cual de las siguientes sesiones desea viajar? Digite el numero de la sesion\n";
    for (int i = 0; i < sesiones.size(); i++) {
        std::cout << "Sesion#" << i << "\n";
    }
    while (true) {
        try {
            std::cin >> op;
            if (op >= 0 && op < sesiones.size()) {
                sesionActual = sesiones.at(op);
                break;
            }
        }
        catch (...) {
            op = 0;
        }
    }
}
