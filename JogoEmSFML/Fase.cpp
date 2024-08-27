#include "Fase.h"

namespace Fases {
	Fase::Fase() :
		entidades(), personagens(), obstaculos(), projeteis(),
		pGG(pGG->getInstancia()), pGC(), corpo() {}

	Fase::~Fase() {}

	void Fase::executar(sf::Time deltaTime) {}

	void Fase::desenhar() {
		pGG->desenhar(&corpo);
	}
}