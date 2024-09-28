#include "Control.h"

Control* Control::instance = nullptr;

Control::Control() {
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
        if (!sesionActual) { crearNuevaSesion(); }
        std::string aux = "";
        aux = sesionActual->navegarPestanas();
        if (aux == "change") {
            modificarSesion();
        }
        if (aux == "save") {
            importarExportar();
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
    system("cls");
    std::string nom;
    std::cout<<"Digite el nombre de la nueva sesion:\n";
    std::cin >> nom;
    sesionActual = new Sesion(nom);
    sesiones.push_back(sesionActual);
    std::cout << "Se ha ingresado una nueva sesion con exito\n";
    system("pause");
}

void Control::importarExportar()
{
    int op = Interfaz::guardarONo();
    
    switch (op) {
    case 1: {
        std::vector<Sesion*> ses = importar();
        //Imprimir todas las sesiones guardadas y preguntar cual desea importar(creo que asi seria)

    }
    case 2: {//Exportar(Llevar)

    }
    case 3:
        break;
    }
}

std::vector<Sesion*> Control::importar()
{
    std::vector<Sesion*> vec;
    std::fstream leer("Sesiones.csv", std::ios::in | std::ios::binary);
    if (leer.is_open()) {
        while (true) {
            Sesion* sesion = Sesion::leer(leer);
            if (sesion == nullptr) {
                break;
            }
            vec.push_back(sesion);
        }
        leer.close();
    }
    return vec;
}

void Control::cambiarSesion()
{
    int op = -1;
    std::cout << "Actualmente hay " << sesiones.size() << " sesiones\n";
    std::cout << "A cual de las siguientes sesiones desea viajar? Digite el numero de la sesion\n";
    for (int i = 0; i < sesiones.size(); i++) {
        std::cout << "Sesion#" << i << " : "<<sesiones.at(i)->getNombre()<<"\n";
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
