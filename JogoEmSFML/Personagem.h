#pragma once
#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			sf::RectangleShape corpo;
			int vidas;
			int dano;
			bool vivo;
			bool atacando;

			float velocidadeMax;
			float aceleracao;

		public:
			Personagem(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Personagem();

			sf::Vector2f getPosicao();
			sf::Vector2f getTamanho();
			virtual sf::Vector2f getVelocidade() = 0;
			int getVidas();
			int getDano();

			void receberDano(int dano);
			virtual void mover() = 0;
			virtual void atacar() = 0;

			virtual void executar() = 0;
			virtual void desenhar();
			virtual void salvar() = 0;

			virtual void colidir(Entidade* e, sf::Vector2f intersecao) = 0;
		};
	}
}
