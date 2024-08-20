#pragma once
#include "stdafx.h"
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class NinjaGarras : public Inimigo {
		private:
			float distanciaAtaque;
			float distanciaJogador;

		public:
			NinjaGarras(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~NinjaGarras();

			void executar();
			void mover();
			void atacar(Jogador* p);

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();

			void colidir(Entidade* e, sf::Vector2f intersecao);
		};
	}
}
