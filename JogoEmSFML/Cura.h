#pragma once
#include "Consumiveis.h"

namespace Entidades
{
	namespace Consumiveis
	{
		class Cura : public Consumivel
		{
		private:
			int cura;
			ID id;
		public:
			Cura(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Cura();

			void desenhar();
			void salvar();

			sf::Vector2f getPosicao();
			sf::Vector2f getTamanho();
			sf::Vector2f getVelocidade();
			
			ID getId() const;
			int getCura();

			void mover(sf::Time deltaTime);
			void colidir(Entidade* e, sf::Vector2f intersecao);
		};
	}
}
