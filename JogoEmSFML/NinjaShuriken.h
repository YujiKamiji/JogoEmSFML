#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "Shuriken.h"

namespace Entidades {
	namespace Personagens {
		class NinjaShuriken : public Inimigo {
		private:
			float distanciaAtaque;
			float distanciaPerigo;

			float disP1;
			float disP2;

			Shuriken* s;
			bool fuga;

		public:
			NinjaShuriken(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b);
			~NinjaShuriken();

			void executar();
			void mover();
			void atacar(Jogador* j);
			void fugir();

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();

			void colidir(Entidade* e, sf::Vector2f intersecao);
		};
	}
}