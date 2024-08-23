#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "ListaEntidades.h"

namespace Entidades {
	namespace Personagens {
		class NinjaGarras : public Inimigo {
		private:
			float distanciaAtaque;
			Listas::ListaEntidades* jogadores;

		public:
			NinjaGarras(sf::Vector2f pos, sf::Vector2f tam, Jogador* p1, Jogador* p2);
			~NinjaGarras();

			void executar();
			void mover();
			void atacar();

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();
			Jogador* getAlvo();

			void colidir(Entidade* e, sf::Vector2f intersecao);
		};
	}
}
