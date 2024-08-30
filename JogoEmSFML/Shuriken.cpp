#include "Shuriken.h"

namespace Entidades {
	Shuriken::Shuriken(sf::Vector2f pos, sf::Vector2f tam):
		Projetil(pos, tam), alvo(getPosicao())
	{
		setAmigavel(false);
		dano = 8;
		duracao = 0;
	}

	Shuriken::~Shuriken() {}

	void Shuriken::mover(sf::Time deltaTime) {
		gravidade(deltaTime);
		corpo.move(velocidades);
	}

	void Shuriken::executar(sf::Time deltaTime) {
		if (ativo) {
			mover(deltaTime);						
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

		if (alvo.x > getPosicao().x)
			velocidades.x = 12;
		else if (alvo.x < getPosicao().x)
			velocidades.x = -12;

		
		if (alvo.y < getPosicao().y - 10)
			velocidades.y = -15; //pra cima
		else
			velocidades.y = -10; //reto
	}

	void Shuriken::colidir(Entidade* e, sf::Vector2f intersecao) {
		if (e->getId() == JOGADOR || e->getId() == CHAO)
		{
			ativo = false;
			cout << "bateu no chao" << endl;
		}
			
	}
}