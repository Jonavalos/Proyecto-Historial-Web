#include "Control.h"

Control* Control::instance = nullptr;

Control::Control() {
    sesionActual = nullptr;
}
void Control::deleteInstance()
{
    if (instance != NULL)
        delete instance;
}
Control* Control::getInstance()
{
   if(instance == nullptr){
           instance = new Control();
           atexit(deleteInstance);
   }
   return instance;
}

void Control::navegar()
{
    while (true) {
        if (!sesionActual) { crearNuevaSesion(); }
        std::string aux = "";
        aux = sesionActual->navegarPestanas();
        if (aux == "change") {modificarSesion();}
        if (aux == "save") {importarExportar();}
        if (aux == "exit") {
            if (Interfaz::salir()) break;
        }
    }
}

void Control::modificarSesion()
{
    int o = Interfaz::modificarSesion();
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
    std::string nom = Interfaz::nombreSesion();
    sesionActual = new Sesion(nom);
    sesiones.push_back(sesionActual);
    Interfaz::sesionIngresada();
}

void Control::importarExportar()
{
    int op = Interfaz::guardarONo();
    switch (op) {
    case 1: {
        importar();
        break;
    }
    case 2: {
        exportar();
        break;
    }
    default:
        break;
    }
}

void Control::importar()
{
    std::vector<Sesion*> ses = leerSesiones();
    if (!ses.empty()) {
        int op = Interfaz::insertarSesiones(ses.size());
        switch(op) {
        case 1:
            for (Sesion* s : sesiones) {
                delete s;
            }
            sesiones.clear();
            for (Sesion* s:ses) {
                sesiones.push_back(s);
            }
            break;
        case 2:
            for (Sesion* s : ses) {
                sesiones.push_back(s);
            }
            break;
        }
        cambiarSesion();
        return;
    }
    Interfaz::sesionesVacias();

}

std::vector<Sesion*> Control::leerSesiones()
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
    }
    leer.close();
    return vec;
}

void Control::exportar()
{
    int op = Interfaz::guardar();
    bool conf = Interfaz::confirmacionGuardar();
    if (!conf) return;
    switch (op) {
    case 1: //Actual
        guardarSesionActual();
        break;
    case 2: //Todas
        guardarSesiones();
        break;
    }
}

void Control::guardarSesionActual()
{
    std::fstream guardar("Sesiones.csv", std::ios::out | std::ios::binary | std::ios::trunc);
    if (guardar.is_open()) {
        sesionActual->guardar(guardar);
    }
    guardar.close();
}

void Control::guardarSesiones()
{
    std::fstream guardar("Sesiones.csv", std::ios::out | std::ios::binary | std::ios::trunc);
    if (guardar.is_open()) {
        for (Sesion* s : sesiones) {
            s->guardar(guardar);
        }
    }
    guardar.close();
}

void Control::cambiarSesion()
{
    int op = -1;
    Interfaz::cantidadSesiones(sesiones.size());
    int i = 0;
    for (Sesion* s:sesiones) {
        Interfaz::mostrarSesion(i++, s->getNombre());
    }
    op = Interfaz::cambiarSesion(sesiones.size());
    sesionActual = sesiones.at(op);
}
