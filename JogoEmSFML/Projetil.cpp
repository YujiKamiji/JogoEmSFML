#include "Projetil.h"

namespace Entidades {
	Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam):
		Entidade(), dano(0), duracao(0), corpo(tam), ativo(false), amigavel(true), olhandoDireita(true)
	{
		corpo.setOrigin(corpo.getSize() / 2.f);
		corpo.setPosition(pos);
		setNoAr(false);
	}
	Projetil::~Projetil() {}

	void Projetil::Posicionar(sf::Vector2f pos) { corpo.setPosition(pos); }
	
	void Projetil::setAtivo(bool b)  
	{ 
		ativo = b; 
	}

	void Projetil::setAmigavel(bool b)
	{
		amigavel = b;
	}

	//void Projetil::setAmigavel(bool b) { amigavel = b; }

	void Projetil::setOlhandoDireita(bool b)
	{
		olhandoDireita = b;
		if (olhandoDireita)
			corpo.setScale(1, 1);
		else
			corpo.setScale(-1, 1);
	}

	sf::Vector2f Projetil::getPosicao() { return corpo.getPosition(); }
	sf::Vector2f Projetil::getVelocidade() { return velocidades; }

	bool Projetil::getAtivo() { return ativo; }
	bool Projetil::getAmigavel() { return amigavel; }
}