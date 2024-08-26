#include "AtaqueCorte.h"

namespace Entidades {
	AtaqueCorte::AtaqueCorte(sf::Vector2f pos, sf::Vector2f tam) :
		Projetil(pos, tam)
	{
		dano = 10;
		duracao = 5;
	}

	AtaqueCorte::~AtaqueCorte() {}

	void AtaqueCorte::mover() {}

	void AtaqueCorte::executar() {
		if (ativo) {
			duracao--;
			if (duracao <= 0)
				ativo = false;
		}
		cout << "AtaqueCorte::executar()" << endl;
		desenhar();
	}

	void AtaqueCorte::desenhar() {
		if (ativo)
			pGG->desenhar(&corpo);
	}

	void AtaqueCorte::salvar() {}

	void AtaqueCorte::colidir(Entidade* e, sf::Vector2f intersecao) {}
}