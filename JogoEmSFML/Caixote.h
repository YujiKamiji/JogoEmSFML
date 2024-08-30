#pragma once
#include "Jogador.h"
#include "Obstaculo.h"

namespace Entidades {

	using namespace Personagens;

	namespace Obstaculos {
		class Caixote : public Obstaculo {
		private:
			ID id;
			float atrito;
		public:
			Caixote(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Caixote();

			void executar(sf::Time deltaTime);
			void desenhar();
			void salvar();

			void mover(sf::Time deltaTime);
			void obstacular(sf::Time deltaTime);

			void colidir(Entidade* e, sf::Vector2f intersecao);

			ID getId() const;
		};
	}
}
