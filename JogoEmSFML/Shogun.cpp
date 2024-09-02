#include "Shogun.h"

namespace Entidades {
	namespace Personagens {
		Shogun::Shogun(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b) :
			Inimigo(pos, tam), id(SHOGUN), modo(-1), alvoAtual(nullptr),
			intervaloAcao(0), disP1(1000), disP2(1000), enfurecido(false),
			s(new Shuriken(sf::Vector2f(0, 0), sf::Vector2f(75, 75)))
		{
			srand(time(NULL));
			vidas = 50;
			dano = 6;
			velocidadeMax = 4;
			aceleracao = 40;
			setP1(a);
			setP2(b);

			textura = pGG->carregarTextura("Shogun.png");
			corpo.setTexture(textura);
		}

		Shogun::~Shogun() {}

		void Shogun::setModo() {
			if (modo == -1) {
				modo = rand() % 2;
				intervaloAcao = 1000;
			}
		}

		void Shogun::executar(sf::Time deltaTime) {
			if (!vivo)
				return;

			noAr = true;
			gravidade(deltaTime);

			if (vidas <= 0)
				vivo = false;

			if (intervaloAcao > 0)
				intervaloAcao -= deltaTime.asMilliseconds();
			else {
				modo = -1;
				atacando = false;
				velocidades.x = velocidades.x * 0.5;
			}

			calculaDis();

			if (disP1 <= 300 || disP2 <= 300)
				enfurecido = true;
			if (vidas < 50)
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

			rng = rand() % 4;
			switch (rng) {
			case 0: //teletransporte
				corpo.setPosition(alvoAtual->getPosicao().x,
					alvoAtual->getPosicao().y - 400);
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
			case 3: //teletransporte
				corpo.setPosition(alvoAtual->getPosicao().x,
					alvoAtual->getPosicao().y - 400);
			}
		}

		void Shogun::desenhar() {
			if (vivo) {
				pGG->desenhar(&corpo);
				s->desenhar();
			}			
		}

		void Shogun::salvar() {}

		void Shogun::calculaDis() {
			if (p1) {
				float x1 = getPosicao().x - p1->getPosicao().x;
				x1 = x1 * x1;
				float y1 = getPosicao().y - p1->getPosicao().y;
				y1 = y1 * y1;
				disP1 = sqrt(x1 + y1);
			}

			if (p2) {
				float x2 = getPosicao().x - p2->getPosicao().x;
				x2 = x2 * x2;
				float y2 = getPosicao().y - p2->getPosicao().y;
				y2 = y2 * y2;
				disP1 = sqrt(x2 + y2);
			}
		}

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

		ID Shogun::getId() const { return ID(id); }
	}
}