#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade():
		Ente(), velocidades(0, 0), noAr(true) {}

	Entidade::~Entidade() {}

	void Entidade::mover(sf::Time deltaTime) {
		//todas as entidades sofrem efeito da gravidade
		if (velocidades.y <= VEL_TERMINAL)
			velocidades.y += GRAVIDADE;
		else
			velocidades.y = VEL_TERMINAL;
		velocidades.y *= deltaTime.asSeconds();
	}

	void Entidade::setNoAr(bool b) { noAr = b; }
}

