#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		protected:
			int dano;
		public:
			Inimigo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			virtual ~Inimigo();
			virtual void executar();
			virtual void mover() = 0;
			virtual void atacar(Jogador* p) = 0;

			int getDano();
		};
	}
}
