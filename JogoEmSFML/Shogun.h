#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "Shuriken.h"
#include "ListaEntidades.h"

namespace Entidades {
	namespace Personagens {
		class Shogun : public Inimigo {
		private:
			ID id;

			int modo;
			int intervaloAcao;

			float disP1;
			float disP2;

			Shuriken* s;
			bool enfurecido;
			Jogador* alvoAtual;

		public:
			Shogun(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b);
			~Shogun();

			void setModo();

			void executar(sf::Time deltaTime);
			void mover(sf::Time deltaTime);
			void atacar(sf::Time deltaTime);
			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();

			Shuriken* getAtaque();

			void colidir(Entidade* e, sf::Vector2f intersecao);

			ID getId() const;
		};
	}
}
