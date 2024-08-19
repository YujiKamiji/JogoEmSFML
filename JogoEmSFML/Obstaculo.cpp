#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam):
			Entidade(), corpo(pos), danoso(false)
		{
			corpo.setOrigin(corpo.getSize() / 2.f);
			corpo.setPosition(pos);
			noAr = false;
		}

		Obstaculo::~Obstaculo() {}

		sf::Vector2f Obstaculo::getPosicao() { return corpo.getPosition(); }
		sf::Vector2f Obstaculo::getTamanho() { return corpo.getSize(); }

		void Obstaculo::mover() {
			if (!noAr)
				velocidades.y -= GRAVIDADE;
			corpo.move(velocidades);
		}
	}
}