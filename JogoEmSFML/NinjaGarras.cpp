#include "NinjaGarras.h"

namespace Entidades {
	namespace Personagens {
		NinjaGarras::NinjaGarras(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b) :
			Inimigo(pos, tam), id(NINJA_GARRAS), modo(-1), 
			intervaloAcao(0), disP1(0), disP2(0)
		{
			srand(time(NULL));
			vidas = 30;
			dano = 3;
			velocidadeMax = 4;
			aceleracao = 30;
			setP1(a);
			setP2(b);

			corpo.setFillColor(sf::Color::Red);
		}

		NinjaGarras::~NinjaGarras() {}

		void NinjaGarras::setModo() {
			if (modo == -1) {
				modo = rand() % 2;
				intervaloAcao = 1500;
			}
		}

		void NinjaGarras::executar(sf::Time deltaTime) {
			noAr = true;
			gravidade(deltaTime);

			if(vidas <= 0)
				vivo = false;

			if (intervaloAcao > 0)
				intervaloAcao -= deltaTime.asMilliseconds();
			else {
				modo = -1;
				atacando = false;
				velocidades.x = velocidades.x * 0.5;
			}

			setModo();

			if (!noAr)
				velocidades.y = 0;

			switch (modo) {
			case -1:
				break;
			case 0:
				if (atacando == false) {
					//cout << "Ataque inimigo" << endl;
					atacar(deltaTime);
				}
				break;
			case 1:
				mover(deltaTime);
				break;
			}
			corpo.move(velocidades);
		}

		void NinjaGarras::mover(sf::Time deltaTime) {
			int rng = rand() % 2;
			if (rng) {
				if (velocidades.x <= velocidadeMax)
					velocidades.x += (aceleracao * deltaTime.asSeconds());
				else
					velocidades.x = velocidadeMax;
			}
			else {
				if (velocidades.x >= -velocidadeMax)
					velocidades.x -= (aceleracao * deltaTime.asSeconds());
				else
					velocidades.x = -velocidadeMax;
			}
		}

		void NinjaGarras::atacar(sf::Time deltaTime) {
			atacando = true;
			velocidades.y -= 15;

			disP1 = getPosicao().x - p1->getPosicao().x;
			disP1 = sqrt(disP1 * disP1);
			disP2 = getPosicao().x - p2->getPosicao().x;
			disP2 = sqrt(disP2 * disP2);

			if (disP1 <= disP2) {
				if (p1->getPosicao().x > getPosicao().x)
					velocidades.x = 6;
				else if (p1->getPosicao().x < getPosicao().x)
					velocidades.x = -6;
			}	
			else {
				if (p2->getPosicao().x > getPosicao().x)
					velocidades.x = 6;
				else if (p2->getPosicao().x < getPosicao().x)
					velocidades.x = -6;
			}
		}

		void NinjaGarras::desenhar() {
			if (vivo)
				pGG->desenhar(&corpo);
		}

		void NinjaGarras::salvar() {}

		sf::Vector2f NinjaGarras::getVelocidade() { return velocidades; }

		void NinjaGarras::colidir(Entidade* e, sf::Vector2f intersecao) {
			sf::Vector2f posOutro = e->getPosicao();

			if (e->getId() != PROJETIL || e->getId() == ESPINHOS)
			{
				//colisao em x
				if (intersecao.x > intersecao.y)
				{
					if (getPosicao().x < posOutro.x)
						corpo.move(intersecao.x, 0);
					else
						corpo.move(-intersecao.x, 0);
					velocidades.x = 0;
				}
				//colisao em y
				else
				{
					if (getPosicao().y < posOutro.y)
						corpo.move(0, intersecao.y);
					else
						corpo.move(0, -intersecao.y);
					velocidades.y = 0;
					noAr = false;
				}
			}

			//tomar dano do player
			if (e->getId() == PROJETIL)
			{
				Projetil* p = static_cast<Projetil*>(e);

				if (p->getAmigavel() == true) {
					receberDano(p->getDano());

					if (getVidas() <= 0) //inimigo morreu
					{
						if (p == p1->getAtaque()) //p1 q matou
							p1->ganharPontos(PONTOS);
						else if (p == p2->getAtaque()) //p2 q matou
							p2->ganharPontos(PONTOS);
					}
				}
			}
			
		}

		ID NinjaGarras::getId() const { return ID(id); }
	}
}