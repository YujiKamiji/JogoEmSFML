#pragma once
#include "Consumiveis.h"

namespace Entidades
{
	namespace Consumiveis
	{
		class Moeda : public Consumivel
		{
		private:
			const int valor;
			ID id;
		public:
			Moeda(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Moeda();

			void desenhar();
			void salvar();

			const int getPontos() const;
			sf::Vector2f getPosicao();
			sf::Vector2f getTamanho();
			sf::Vector2f getVelocidade();
			ID getId() const;
			void colidir(Entidade* e, sf::Vector2f intersecao);
		};

	}
}