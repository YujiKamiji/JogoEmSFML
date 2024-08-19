#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade():
		Ente(), velocidades(0, 0), noAr(true) {}

	Entidade::~Entidade() {}

	void Entidade::mover() { 
		if (velocidades.y <= VEL_TERMINAL)
			velocidades.y += GRAVIDADE;
		else
			velocidades.y = VEL_TERMINAL;
	}

	void Entidade::setNoAr(bool b) { noAr = b; }
}

