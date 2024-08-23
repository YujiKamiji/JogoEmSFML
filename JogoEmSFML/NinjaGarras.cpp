#include "NinjaGarras.h"

namespace Entidades {
	namespace Personagens {
		NinjaGarras::NinjaGarras(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b) :
			Inimigo(pos, tam), distanciaAtaque(20), 
			disP1(100), disP2(100), p1(a), p2(b)
		{
			srand(time(NULL));
			vidas = 40;
			dano = 12;
			velocidadeMax = 8;
			aceleracao = 0.2;
		}

		NinjaGarras::~NinjaGarras() {}

		void NinjaGarras::executar() {
			int rng = rand() % 2;
			switch (rng) {
			case 0:
				mover();
				break;
			case 1:
				disP1 = getPosicao().x - p1->getPosicao().x;
				disP1 = sqrt(disP1 * disP1);
				disP2 = getPosicao().x - p2->getPosicao().x;
				disP2 = sqrt(disP2 * disP2);

				if (atacando == false) {
					if (disP1 <= disP2)
						atacar(p1);
					else
						atacar(p2);
				}
				break;
			}

			if (!noAr && velocidades.x == velocidadeMax) {
				velocidades.x = 0;
				atacando = false;
			}
		}

		void NinjaGarras::mover() {
			int rng = rand() % 2;
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
			}
			corpo.move(velocidades);
		}

		void NinjaGarras::atacar(Jogador* j) {
			atacando = true;
			if (j->getPosicao().x <= distanciaAtaque) {
				velocidades.y = 5;
				if (j->getPosicao().x > getPosicao().x)
					velocidades.x += velocidadeMax;
				else if (j->getPosicao().x < getPosicao().x)
					velocidades.x -= velocidadeMax;
				else
					mover();
			}
			corpo.move(velocidades);
		}

		void NinjaGarras::desenhar() {
			if (vivo)
				pGG->desenhar(&corpo);
		}

		void NinjaGarras::salvar() {}

		sf::Vector2f NinjaGarras::getVelocidade() { return velocidades; }

		void NinjaGarras::colidir(Entidade* e, sf::Vector2f intersecao) {

		}
	}
}