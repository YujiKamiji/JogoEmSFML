#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0)):
			Personagem(pos, tam), dano(0) {}

		Inimigo::~Inimigo() {}

		void Inimigo::executar() {
			mover();
			if (vidas <= 0)
				vivo = false;
		}

		int Inimigo::getDano() { return dano; }
	}
}