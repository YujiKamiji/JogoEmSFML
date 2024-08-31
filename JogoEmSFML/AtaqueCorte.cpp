#include "AtaqueCorte.h"

namespace Entidades {
	AtaqueCorte::AtaqueCorte(sf::Vector2f pos, sf::Vector2f tam) :
		Projetil(pos, tam), danoDado(false)
	{
		dano = 10;
		duracao = 200;
	}

	AtaqueCorte::~AtaqueCorte() {}

	void AtaqueCorte::mover(sf::Time deltaTime)  
	{ }

	void AtaqueCorte::executar(sf::Time deltaTime) {
		if (ativo) {
			duracao -= deltaTime.asMilliseconds();
			if (danoDado)
				dano = 0;
			else
				dano = 10;

			if (duracao <= 0)
			{
				ativo = false;
				danoDado = false;
				duracao = 200;
			}
		}
	}

	void AtaqueCorte::desenhar() {
		if (ativo)
			pGG->desenhar(&corpo);
	}

	void AtaqueCorte::salvar() { return; }

	void AtaqueCorte::colidir(Entidade* e, sf::Vector2f intersecao) { 
		if (e->getId() == NINJA_GARRAS || e->getId() == NINJA_SHURIKEN)
			danoDado = true;

		if (e->getId() == SHOGUN)
			danoDado = true;
	}
}