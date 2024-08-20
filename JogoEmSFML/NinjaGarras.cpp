#include "NinjaGarras.h"

namespace Entidades {
	namespace Personagens {
		NinjaGarras::NinjaGarras(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0)) :
			Inimigo(pos, tam), distanciaAtaque(20), distanciaJogador(300)
		{
			vidas = 40;
			dano = 12;
			velocidadeMax = 8;
			aceleracao = 2;
		}

		NinjaGarras::~NinjaGarras() {}

		void NinjaGarras::executar() {}

		void NinjaGarras::mover() {
			int rng = rand() % 3;
			if (!noAr)
				velocidades.y -= GRAVIDADE;
			switch (rng) {
			case 0:
				if (velocidades.x <= velocidadeMax)
					velocidades.x += aceleracao;
				else
					velocidades.x = velocidadeMax;
				break;
			case 1:
				if (velocidades.x >= -velocidadeMax)
					velocidades.x -= aceleracao;
				else
					velocidades.x = -velocidadeMax;
				break;
			case 3:
				if (velocidades.x > 0) {
					velocidades.x -= aceleracao * 2;
					if (velocidades.x < 0)
						velocidades.x = 0;
				}
				else {
					velocidades.x += aceleracao * 2;
					if (velocidades.x > 0)
						velocidades.x = 0;
				}
				break;
			}
			corpo.move(velocidades);
		}

		void NinjaGarras::atacar(Jogador* p) {
			distanciaJogador = getPosicao().x - p->getPosicao().x;
			distanciaJogador = sqrt(distanciaJogador * distanciaJogador);

			if (distanciaJogador <= distanciaAtaque) {
				velocidades.y -= 6;
				if (p->getPosicao().x > getPosicao().x)
					velocidades.x += velocidadeMax;
				else
					velocidades.x -= velocidadeMax;
			}
		}

		void NinjaGarras::desenhar();

		void NinjaGarras::salvar();

		sf::Vector2f NinjaGarras::getVelocidade() { return velocidades; }

		void NinjaGarras::colidir(Entidade* e, sf::Vector2f intersecao) {

		}
	}
}