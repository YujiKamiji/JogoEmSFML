#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"
#include "GerenciadorDeEstados.h"

using namespace Gerenciadores;

class Ente {
protected:
	const int id;
	static int cont;
	static Gerenciador_Grafico* pGG;
	static GerenciadorDeEstados* pGE;
	sf::Texture* textura;

public:
	Ente();
	virtual ~Ente();
	virtual void executar(sf::Time deltaTime) = 0;
	virtual void desenhar() = 0;
	const int getIdNumero() const;
};
