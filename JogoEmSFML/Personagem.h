#pragma once
#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			sf::RectangleShape corpo;
			int vidas;

		public:
			Personagem(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Personagem();

			sf::Vector2f getPosicao();
			sf::Vector2f getTamanho();

			int getVidas();
			virtual void mover() = 0;
			virtual void atacar(int dano) = 0;

			virtual void executar() = 0;
			virtual void desenhar() = 0;
			virtual void salvar() = 0;

			virtual sf::Vector2f getVelocidade() = 0;
			virtual float getMassa() = 0;
		};
	}
}
