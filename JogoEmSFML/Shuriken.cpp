#include "Shuriken.h"

namespace Entidades {
	Shuriken::Shuriken(sf::Vector2f pos, sf::Vector2f tam):
		Projetil(pos, tam)
	{
		dano = 8;
		duracao = 30;
	}

	Shuriken::~Shuriken() {}

	void Shuriken::mover() {
		float m = (alvo.y - getPosicao().y) / (alvo.x - getPosicao().x);
		float n = (alvo.y - (m * alvo.x));

		corpo.move(2, (2 * m + n));
	}

	void Shuriken::executar() {
		if (ativo) {
			mover();
			duracao--;
			if (duracao <= 0)
				ativo = false;
		}
	}

	void Shuriken::desenhar() {
		if (ativo)
			pGG->desenhar(&corpo);
	}

	void Shuriken::salvar() {}

	void Shuriken::setAlvo(sf::Vector2f a) { alvo = a; }

	void Shuriken::colidir(Entidade* e, sf::Vector2f intersecao) {}
}