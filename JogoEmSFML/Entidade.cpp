#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	Entidade::Entidade():
		Ente(), posicao(0, 0), velocidades(0, 0), noAr(true) {}

	Entidade::~Entidade() {}

	void Entidade::setNoAr(bool b) { noAr = b; }

	void Entidade::setPosicao(sf::Vector2f pos) {
		posicao = pos;
	}
}

