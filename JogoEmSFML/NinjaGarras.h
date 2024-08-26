#pragma once
#include "stdafx.h"
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class NinjaGarras : public Inimigo {
		private:
			ID id;

			float distanciaAtaque;
			
			float disP1;
			float disP2;

			//colocar ponteiros static para os jogadores no inimigo
			//Jogador* p1;
			//Jogador* p2;

		public:
			NinjaGarras(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b);
			~NinjaGarras();

			void executar(sf::Time deltaTime);
			void mover(sf::Time deltaTime);
			void atacar(Jogador* j, sf::Time deltaTime);

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();

			void colidir(Entidade* e, sf::Vector2f intersecao);

			ID getId();
		};
	}
}
