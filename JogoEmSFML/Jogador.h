#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "AtaqueCorte.h"
#include "Cura.h"
#include "Moeda.h"

#define VIDAMAX 200

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			ID id;

			int pontuacao;
			int intervaloAtaque;
			bool olhandoDireita;

			float aceleracao;

			int jogadorId;

			AtaqueCorte* ataque;

		public:
			Jogador(sf::Vector2f pos, sf::Vector2f tam, int jId);
			~Jogador();

			void executar(sf::Time deltaTime);
			void mover(sf::Time deltaTime);
			void atacar(sf::Time deltaTime);

			void desenhar();
			void salvar();

			sf::Vector2f getVelocidade();
			AtaqueCorte* getAtaque();
			ID getId() const;
			int getPontuacao();

			void colidir(Entidade* e, sf::Vector2f intersecao);
			void recuperarVida(int Cura);
			void ganharPontos(const int Pontos);
		};
	}
}
