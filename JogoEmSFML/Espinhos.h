#pragma once
#include "stdafx.h"
#include "Obstaculo.h"
#include "stdafx.h"

namespace Entidades {

	using namespace Personagens;

	namespace Obstaculos {
		class Espinhos : public Obstaculo
		{
		private:
			ID id;
			int afiacao;
			float decrescimo;

		public:
			Espinhos(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Espinhos();

			void executar(sf::Time deltaTime);
			void desenhar();
			void salvar();

			void mover(sf::Time deltaTime);
			void obstacular(sf::Time deltaTime);

			void colidir(Entidade* e, sf::Vector2f intersecao);

			ID getId();
			int getDano();
		};

	}
}