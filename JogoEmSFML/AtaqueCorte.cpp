#include "AtaqueCorte.h"

namespace Entidades {
	AtaqueCorte::AtaqueCorte(sf::Vector2f pos, sf::Vector2f tam) :
		Projetil(pos, tam)
	{
		dano = 100;
		duracao = 350;
	}

	AtaqueCorte::~AtaqueCorte() {}

	void AtaqueCorte::mover(sf::Time deltaTime)  
	{ }

	void AtaqueCorte::executar(sf::Time deltaTime) {
		if (ativo) {
			duracao -= deltaTime.asMilliseconds();
			if (duracao <= 0)
			{
				ativo = false;
				duracao = 350;
			}
		}
	}

	void AtaqueCorte::desenhar() {
		if (ativo)
			pGG->desenhar(&corpo);
	}

	void AtaqueCorte::salvar() { return; }

	void AtaqueCorte::colidir(Entidade* e, sf::Vector2f intersecao) { return; }
}