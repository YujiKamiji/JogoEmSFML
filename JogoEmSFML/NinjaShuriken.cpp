#include "NinjaShuriken.h"

namespace Entidades {
	namespace Personagens {
		NinjaShuriken::NinjaShuriken(sf::Vector2f pos, sf::Vector2f tam,
			Jogador* a, Jogador* b) :
			Inimigo(pos, tam), distanciaAtaque(40), distanciaPerigo(20), 
			disP1(100), disP2(100), p1(a), p2(b), fuga(true), s()
		{
			srand(time(NULL));
			vidas = 20;
			dano = 5;
			velocidadeMax = 6;
			aceleracao = 1;
		}
		NinjaShuriken::~NinjaShuriken() {
			delete s;
		}

		void NinjaShuriken::executar() {
			disP1 = getPosicao().x - p1->getPosicao().x;
			disP1 = sqrt(disP1 * disP1);
			disP2 = getPosicao().x - p2->getPosicao().x;
			disP2 = sqrt(disP2 * disP2);

			if (disP1 <= distanciaPerigo || disP2 <= distanciaPerigo)
				fugir();
			else if (disP2 <= distanciaAtaque)
				atacar(p2);
			else if (disP1 <= distanciaAtaque)
				atacar(p1);
			else
				mover();
		}
		void NinjaShuriken::mover() {
			if (!noAr)
				velocidades.y -= GRAVIDADE;
			int rng = rand() % 2;
			switch (rng) {
			case 0:
				if (velocidades.x <= velocidadeMax)
					velocidades.x += aceleracao;
				else
					velocidades.x = velocidadeMax;
				break;
			case 1:
				if (velocidades.x >= velocidadeMax)
					velocidades.x -= aceleracao / 2;
				else
					velocidades.x = -velocidadeMax;
				break;
			}
			corpo.move(velocidades);
		}

		void NinjaShuriken::atacar(Jogador* j) {
			s->setAtivo(true);
			s->setAmigavel(false);
			s->Posicionar(getPosicao());
			s->setAlvo(j->getPosicao());
			s->executar();
		}

		void NinjaShuriken::fugir() {
			corpo.setPosition(getPosicao().x + 10, getPosicao().y);
			fuga = false;
		}

		void NinjaShuriken::desenhar() {
			if (vivo)
				pGG->desenhar(&corpo);
			s->desenhar();
		}

		void NinjaShuriken::salvar() {}

		sf::Vector2f NinjaShuriken::getVelocidade() { return getVelocidade(); }

		void NinjaShuriken::colidir(Entidade* e, sf::Vector2f intersecao) {}
	}
}