#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;

class Ente {
protected:
	int id;
	static Gerenciador_Grafico* pGG;
	sf::Texture texture;

public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	void desenhar();
};

Gerenciador_Grafico* Ente::pGG = NULL;
