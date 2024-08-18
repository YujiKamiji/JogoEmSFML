#pragma once
#include "stdafx.h"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			int pontuacao;
			int dano;
			int intervaloAtaque;
			bool olhandoDireita;
			bool atacando;

			float velocidadeMax;
			float aceleracao;

			int jogadorId;

			sf::RectangleShape ataque;

			static int cont;

		public:
			Jogador();
			~Jogador();

			void executar();
			void mover();
			void atacar();

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();
		};
	}
}
