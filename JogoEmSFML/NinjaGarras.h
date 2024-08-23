#pragma once
#include "stdafx.h"
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class NinjaGarras : public Inimigo {
		private:
			float distanciaAtaque;
			
			float disP1;
			float disP2;

			Jogador* p1;
			Jogador* p2;

		public:
			NinjaGarras(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b);
			~NinjaGarras();

			void executar();
			void mover();
			void atacar(Jogador* j);

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();

			void colidir(Entidade* e, sf::Vector2f intersecao);
		};
	}
}
