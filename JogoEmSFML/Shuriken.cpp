#include "Shuriken.h"

namespace Entidades {
	Shuriken::Shuriken(sf::Vector2f pos, sf::Vector2f tam):
		Projetil(pos, tam), alvo(getPosicao()), m(-1), n(-1)
	{
		dano = 8;
		duracao = 2000;
	}

	Shuriken::~Shuriken() {}

	void Shuriken::mover(sf::Time deltaTime) {
		if (alvo.x > getPosicao().x)
			velocidades.x = 3;
		else if (alvo.x < getPosicao().x)
			velocidades.x = -3;
		corpo.move(velocidades);
	}

	void Shuriken::executar(sf::Time deltaTime) {
		if (ativo) {
			mover(deltaTime);
			duracao -= deltaTime.asMilliseconds();
			if (duracao <= 0) {
				ativo = false;
				duracao = 2000;
			}		
		}
	}

	void Shuriken::desenhar() {
		if (ativo)
			pGG->desenhar(&corpo);
	}

	void Shuriken::salvar() {}

	sf::Vector2f Shuriken::getPosicao() { return corpo.getPosition(); }
	sf::Vector2f Shuriken::getVelocidades() { return velocidades; }

	void Shuriken::setAlvo(sf::Vector2f a) { 
		alvo = a;
		m = (alvo.y - getPosicao().y) / (alvo.x - getPosicao().x);
		n = (alvo.y - (m * alvo.x));
	}

	void Shuriken::colidir(Entidade* e, sf::Vector2f intersecao) {}
}