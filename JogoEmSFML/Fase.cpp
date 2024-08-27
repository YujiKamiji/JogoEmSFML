#include "Fase.h"

namespace Fases {
	Fase::Fase() :
		entidades(), personagens(), obstaculos(),
		pGG(pGG->getInstancia()), pGC(), corpo() {}

	Fase::~Fase() {}

	void Fase::desenhar() {
		pGG->desenhar(&corpo);
	}
}