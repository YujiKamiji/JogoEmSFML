#include "NinjaShuriken.h"

namespace Entidades {
	namespace Personagens {
		NinjaShuriken::NinjaShuriken(sf::Vector2f pos, sf::Vector2f tam, Jogador* a, Jogador* b) :
			Inimigo(pos, tam), id(NINJA_SHURIKEN), modo(-1), intervaloAcao(0), 
			distanciaPerigo(150), disP1(1000), disP2(1000), fuga(true), 
			s(new Shuriken(sf::Vector2f(0, 0), sf::Vector2f(50, 50))), intervaloAtaque(1.5f)
		{
			srand(time(NULL));
			vidas = 20;
			dano = 5;
			velocidadeMax = 2;
			aceleracao = 10;
			setP1(a);
			setP2(b);

			corpo.setFillColor(sf::Color::Magenta);
		}

		NinjaShuriken::~NinjaShuriken() {
			delete s;
		}

		void NinjaShuriken::setModo() {
			if (modo == -1) {
				modo = rand() % 2;
				intervaloAcao = 1500;
			}
		}

		void NinjaShuriken::executar(sf::Time deltaTime) {
			gravidade(deltaTime);
			noAr = true;

			if (vidas <= 0)
				vivo = false;

			if (intervaloAcao > 0)
				intervaloAcao -= deltaTime.asMilliseconds();
			else
				modo = -1;
			
			setModo();

			disP1 = getPosicao().x - p1->getPosicao().x;
			disP1 = sqrt(disP1 * disP1);
			disP2 = getPosicao().x - p2->getPosicao().x;
			disP2 = sqrt(disP2 * disP2);

			intervaloAtaque -= deltaTime.asSeconds();
			if (!atacando && intervaloAtaque <= 0.0f) {
				atacar(deltaTime);
				intervaloAtaque = 1.5f;
				cout << "Ataque shuriken" << endl;
			}
			else {
				if (!s->getAtivo())
					atacando = false;
			}

			if (fuga == true) {
				if (disP1 <= distanciaPerigo || disP2 <= distanciaPerigo)
					fugir();
			}
				

			if (!noAr)
				velocidades.y = 0;

			switch (modo) {
			case -1:
				break;
			case 0:
				mover(deltaTime);
				break;
			case 1:
				mover(deltaTime);
				break;
			}
			corpo.move(velocidades);
		}

		void NinjaShuriken::mover(sf::Time deltaTime) {
			if (modo == 0) {
				if (velocidades.x <= velocidadeMax)
					velocidades.x += (aceleracao * deltaTime.asSeconds());
				else
					velocidades.x = velocidadeMax;
			}
			else if (modo == 1) {
				if (velocidades.x >= -velocidadeMax)
					velocidades.x -= (aceleracao * deltaTime.asSeconds());
				else
					velocidades.x = -velocidadeMax;
			}
		}

		void NinjaShuriken::atacar(sf::Time deltaTime) {
			atacando = true;
			s->Posicionar(corpo.getPosition());

			if (modo == 0)
				s->setAlvo(p1->getPosicao());
			else
				s->setAlvo(p2->getPosicao());

			s->setAtivo(true);
			s->executar(deltaTime);
		}

		void NinjaShuriken::fugir() {
			corpo.setPosition(getPosicao().x + 300, getPosicao().y - 100);
			fuga = false;
		}

		void NinjaShuriken::desenhar() {
			if (vivo) {
				pGG->desenhar(&corpo);
				s->desenhar();
			}	
		}

		void NinjaShuriken::salvar() {}

		sf::Vector2f NinjaShuriken::getVelocidade() { return velocidades; }

		Shuriken* NinjaShuriken::getAtaque()
		{
			if (s)
				return s;
			cout << "ponteiro nulo" << endl;
			return nullptr;
		}

		void NinjaShuriken::colidir(Entidade* e, sf::Vector2f intersecao) {
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

		ID NinjaShuriken::getId() { return ID(id); }
	}
}