#pragma once
#include "stdafx.h"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			int pontuacao;
			int intervaloAtaque;
			bool olhandoDireita;

			int jogadorId;

			sf::RectangleShape ataque;

			static int cont;

		public:
			Jogador(sf::Vector2f pos, sf::Vector2f tam);
			~Jogador();

			void executar();
			void mover();
			void atacar();

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();

			void colidir(Entidade* e, sf::Vector2f intersecao);
		};
	}
}
