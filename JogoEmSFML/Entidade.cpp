#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade(sf::Vector2f pos = sf::Vector2f(0, 0)):
		Ente(), posicao(pos), velocidades(0, 0), noAr(true) {}

	Entidade::~Entidade() {}

	void Entidade::mover() { 
		if (velocidades.y <= VEL_TERMINAL)
			velocidades.y += GRAVIDADE;
		else
			velocidades.y = VEL_TERMINAL;
	}

	void Entidade::setNoAr(bool b) { noAr = b; }

	void Entidade::setPosicao(sf::Vector2f pos) {
		posicao = pos;
	}
}

