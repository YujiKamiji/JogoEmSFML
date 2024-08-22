#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		public:
			Inimigo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			virtual ~Inimigo();

			virtual void executar();
			virtual void desenhar() = 0;
			virtual void salvar() = 0;

			virtual void mover() = 0;
			virtual void atacar(Jogador* p) = 0;
			virtual void colidir(Entidade* e, sf::Vector2f intersecao);
		};
	}
}
