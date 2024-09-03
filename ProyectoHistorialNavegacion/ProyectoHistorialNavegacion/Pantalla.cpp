#include "Pantalla.h"

Pantalla::Pantalla()
{
	pestanaActual = nullptr;
}

Pantalla::Pantalla(Pestana* pestana)
{
	pestanaActual = pestana;
}

Pantalla::~Pantalla() {

}