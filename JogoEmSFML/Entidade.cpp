#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade():
		Ente(), velocidades(0, 0), noAr(true) {}

	Entidade::~Entidade() {}
	
	void Entidade::setNoAr(bool b) { noAr = b; }

	void Entidade::gravidade(sf::Time deltaTime)
	{
		if (velocidades.y <= VEL_TERMINAL)
			velocidades.y += GRAVIDADE * deltaTime.asSeconds();
		else
			velocidades.y = VEL_TERMINAL;
	}
}

