#pragma once
#include"Pestana.h"

class Pantalla
{
private:
	std::vector<Pestana*> pestanas;
	Pestana* pestanaActual;
public:
	Pantalla();
	Pantalla(Pestana* pestana);
	virtual ~Pantalla();

};
