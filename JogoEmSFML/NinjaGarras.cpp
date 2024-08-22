#include "NinjaGarras.h"

namespace Entidades {
	namespace Personagens {
		NinjaGarras::NinjaGarras(sf::Vector2f pos = sf::Vector2f(0, 0),
			sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidades* j = nullptr) :
			Inimigo(pos, tam), distanciaAtaque(20), jogadores(j)
		{
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
				atacar();
				break;
			}
		}

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

		void NinjaGarras::atacar() {
			Jogador* alvo = getAlvo();
			float distanciaJogador = getPosicao().x - alvo->getPosicao().x;
			distanciaJogador = sqrt(distanciaJogador * distanciaJogador);

			if (distanciaJogador <= distanciaAtaque) {
				velocidades.y -= 6;
				if (alvo->getPosicao().x > getPosicao().x)
					velocidades.x += velocidadeMax;
				else
					velocidades.x -= velocidadeMax;
			}
			corpo.move(velocidades);
		}

		void NinjaGarras::desenhar() {}

		void NinjaGarras::salvar() {}

		sf::Vector2f NinjaGarras::getVelocidade() { return velocidades; }

		Jogador* NinjaGarras::getAlvo() {
			Entidade* p1 = NULL;
			Entidade* p2 = NULL;
			float disP1;
			float disP2;

			Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>
				alvo = jogadores->getPrimeiro();
			p1 = (*alvo);
			alvo++;
			p2 = (*alvo);

			disP1 = getPosicao().x - p1->getPosicao().x;
			disP1 = sqrt(disP1 * disP1);

			disP2 = getPosicao().x - p2->getPosicao().x;
			disP2 = sqrt(disP2 * disP2);

			if (disP1 <= disP2)
				return static_cast<Jogador*>(p1);
			else
				return static_cast<Jogador*>(p2);
		}

		void NinjaGarras::colidir(Entidade* e, sf::Vector2f intersecao) {

		}
	}
}