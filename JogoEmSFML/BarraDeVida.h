#pragma once
#include "stdafx.h"
#include "Ente.h"

class BarraDeVida : public Ente
{
private:
	sf::RectangleShape barra;
	sf::RectangleShape fundo;
	int vida;
	int vidaMaxima;

public:
	BarraDeVida(sf::Vector2f TamFundo, int vida_max);
	~BarraDeVida();

	void setPosicao(sf::Vector2f pos);
	void setVida(int v);
	void setCor(sf::Color cor);
	
	void desenhar();
	void executar(sf::Time deltaTime);
};
