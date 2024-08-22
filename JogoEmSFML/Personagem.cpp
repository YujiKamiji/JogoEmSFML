#include "stdafx.h"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam):
			Entidade(), corpo(tam), vidas(1), dano(0), vivo(true),
			atacando(false), velocidadeMax(0), aceleracao(0)
		{
			corpo.setOrigin(corpo.getSize() / 2.f);
			corpo.setPosition(pos);
		}

		Personagem::~Personagem() {}

		sf::Vector2f Personagem::getPosicao() { return corpo.getPosition(); }
		sf::Vector2f Personagem::getTamanho() { return corpo.getSize(); }

		int Personagem::getVidas() { return vidas; }

		int Personagem::getDano() { return dano; }

		void Personagem::receberDano(int dano) { vidas -= dano; }

		void Personagem::desenhar() {
			if (vivo)
				pGG->desenhar(&corpo);
		}
	}
}