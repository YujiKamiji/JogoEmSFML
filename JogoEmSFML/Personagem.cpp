#include "stdafx.h"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		Personagem::Personagem(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0)):
			Entidade(pos), corpo(tam), vidas(1)
		{
			posicao = pos;
			corpo.setOrigin(corpo.getSize() / 2.f);
			corpo.setPosition(posicao);
		}

		Personagem::~Personagem() {}

		sf::Vector2f Personagem::getPosicao() { return corpo.getPosition(); }
		sf::Vector2f Personagem::getTamanho() { return corpo.getSize(); }

		int Personagem::getVidas() { return vidas; }

		void Personagem::receberDano(int dano) { vidas -= dano; }
	}
}