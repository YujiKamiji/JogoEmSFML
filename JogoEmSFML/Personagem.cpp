#include "stdafx.h"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam):
			Entidade(), corpo(tam), vidas(1)
		{
			corpo.setOrigin(corpo.getSize() / 2.f);
			corpo.setPosition(pos);
		}

		Personagem::~Personagem() {}

		sf::Vector2f Personagem::getPosicao() { return corpo.getPosition(); }
		sf::Vector2f Personagem::getTamanho() { return corpo.getSize(); }

		int Personagem::getVidas() { return vidas; }

		void Personagem::receberDano(int dano) { vidas -= dano; }
	}
}