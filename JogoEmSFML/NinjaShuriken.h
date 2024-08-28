#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "Shuriken.h"

namespace Entidades {
	namespace Personagens {
		class NinjaShuriken : public Inimigo {
		private:
			ID id;

			int modo;
			int intervaloAcao;

			float distanciaAtaque;
			float distanciaPerigo;

			float disP1;
			float disP2;

			Shuriken* s;
			bool fuga;

		public:
			NinjaShuriken(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b);
			~NinjaShuriken();

			void setModo();

			void executar(sf::Time deltaTime);
			void mover(sf::Time deltaTime);
			void atacar(sf::Time deltaTime);
			void desenhar();
			void salvar();
			void fugir();

			sf::Vector2f getVelocidade();

			Shuriken* getAtaque();

			void colidir(Entidade* e, sf::Vector2f intersecao);

			ID getId();
		};
	}
}