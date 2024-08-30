#pragma once
#include "stdafx.h"
#include "Obstaculo.h"

namespace Entidades 
{
	namespace Obstaculos 
	{
		class Chao : public Obstaculo
		{
		private:
			ID id;
		public:
			Chao(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Chao();

			void executar(sf::Time deltaTime);
			void desenhar();
			void salvar();

			void mover(sf::Time deltaTime);

			void obstacular(sf::Time deltaTime);

			void colidir(Entidade* e, sf::Vector2f intersecao);

			ID getId() const;
			int getDano();
		};
	}
}
