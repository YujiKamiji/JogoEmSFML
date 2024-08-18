#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo():
			Personagem(), dano(0) {}

		Inimigo::~Inimigo() {}

		void Inimigo::executar() {
			mover();
			if (vidas <= 0)
				vivo = false;
		}

		int Inimigo::getDano() { return dano; }
	}
}