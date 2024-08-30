#include "Shogun.h"

namespace Entidades {
	namespace Personagens {
		Shogun::Shogun(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b) :
			Inimigo(pos, tam), id(SHOGUN), modo(-1),
			intervaloAcao(0), disP1(1000), disP2(1000), enfurecido(false),
			s(new Shuriken(sf::Vector2f(0, 0), sf::Vector2f(75, 75)))
		{
			srand(time(NULL));
			vidas = 200;
			dano = 10;
			velocidadeMax = 4;
			aceleracao = 40;
			setP1(a);
			setP2(b);

			corpo.setFillColor(sf::Color::Blue);
		}

		Shogun::~Shogun() {}

		void Shogun::setModo() {
			if (modo == -1) {
				modo = rand() % 3;
				intervaloAcao = 1000;
			}
		}

		void Shogun::executar(sf::Time deltaTime) {
			noAr = true;
			gravidade(deltaTime);

			if (vidas <= 0)
				vivo = false;

			if (intervaloAcao > 0)
				intervaloAcao -= deltaTime.asMilliseconds();
			else {
				modo = -1;
				atacando = false;
				velocidades.x = 0;
			}

			disP1 = getPosicao().x - p1->getPosicao().x;
			disP1 = sqrt(disP1 * disP1);
			disP2 = getPosicao().x - p2->getPosicao().x;
			disP2 = sqrt(disP2 * disP2);

			if (disP1 <= 400 || disP2 <= 400)
				enfurecido = true;

			if (enfurecido)
				setModo();

			if (!noAr)
				velocidades.y = 0;

			switch (modo) {
			case -1:
				break;
			case 0:
				if (atacando == false) {
					cout << "Ataque Shogun" << endl;
					verificarJogadores();
					atacar(deltaTime);
				}
				break;
			case 1:
				mover(deltaTime);
				break;
			}
			corpo.move(velocidades);
		}

		void Shogun::mover(sf::Time deltaTime) {
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

		void Shogun::atacar(sf::Time deltaTime) {
			atacando = true;
			int rng = rand() % 2;
			if (rng)
				alvoAtual = p1;
			else
				alvoAtual = p2;

			rng = rand() % 3;
			switch (rng) {
			case 0: //teletransporte
				corpo.setPosition(alvoAtual->getPosicao().x,
					alvoAtual->getPosicao().y - 250);
			case 1: //pulo
				velocidades.y -= 10;
				if (alvoAtual->getPosicao().x > getPosicao().x)
					velocidades.x = 10;
				else if (alvoAtual->getPosicao().x < getPosicao().x)
					velocidades.x = -10;
			case 2: //shuriken
				s->Posicionar(corpo.getPosition());
				s->setAlvo(alvoAtual->getPosicao());
				s->setAtivo(true);
				s->executar(deltaTime);
			}
		}

		void Shogun::desenhar() {
			if (vivo) {
				pGG->desenhar(&corpo);
				s->desenhar();
			}			
		}

		void Shogun::salvar() {}

		sf::Vector2f Shogun::getVelocidade() { return velocidades; }

		Shuriken* Shogun::getAtaque() { return s; }

		void Shogun::colidir(Entidade* e, sf::Vector2f intersecao) {
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
					cout << "inimigo tomou dano" << endl;
				}
			}
		}

		ID Shogun::getId() const { return ID(id); }
	}
}