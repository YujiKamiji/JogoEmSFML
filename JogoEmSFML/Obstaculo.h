#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {

	using namespace Personagens;

	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			sf::RectangleShape corpo;
			bool danoso;

		public:
			Obstaculo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Obstaculo();

			sf::Vector2f getPosicao();
			sf::Vector2f getTamanho();

			virtual void executar() = 0;
			virtual void mover();
			virtual void obstacular(Jogador* p) = 0;
		};
	}
}
