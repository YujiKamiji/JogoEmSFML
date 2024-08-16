#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;

class Ente {
protected:
	const int id;
	static Gerenciador_Grafico* pGG;
	sf::Texture* textura;

public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	virtual void desenhar() = 0;
};
