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
			sf::Vector2f getVelocidade();

			virtual void executar(sf::Time deltaTime) = 0;
			virtual void desenhar() = 0;
			virtual void salvar() = 0;

			virtual void mover(sf::Time deltaTime);
			virtual void obstacular(Jogador* p) = 0;
		};
	}
}
