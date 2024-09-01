#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		protected:
			Jogador* p1;
			Jogador* p2;
		public:
			Inimigo(sf::Vector2f pos, sf::Vector2f tam);
			virtual ~Inimigo();

			virtual void executar(sf::Time deltaTime) = 0;
			virtual void desenhar() = 0;
			virtual void salvar() = 0;

			virtual void mover(sf::Time deltaTime) = 0;
			virtual void atacar(sf::Time deltaTime) = 0;
			virtual void colidir(Entidade* e, sf::Vector2f intersecao) = 0;

			void setP1(Jogador* p);
			void setP2(Jogador* p);

			Jogador* getP1();
			Jogador* getP2();
			void verificarJogadores();
			virtual ID getId() const = 0;
			virtual sf::Vector2f getVelocidade() = 0;
		};
	}
}
