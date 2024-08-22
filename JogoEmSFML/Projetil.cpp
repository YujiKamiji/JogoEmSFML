#include "Projetil.h"

namespace Entidades {
	Projetil::Projetil(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0)):
		dano(0), duracao(0), corpo(tam), ativo(false) 
	{
		corpo.setOrigin(corpo.getSize() / 2.f);
		corpo.setPosition(pos);
	}
	Projetil::~Projetil() {}

	void Projetil::Posicionar(sf::Vector2f pos) { corpo.setPosition(pos); }
	void Projetil::setAtivo(bool b) { ativo = b; }
	bool Projetil::getAtivo() { return ativo; }
}