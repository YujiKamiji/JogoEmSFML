#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam):
			Personagem(pos, tam) {}

		Inimigo::~Inimigo() {}

		void Inimigo::executar() {
			mover();
			if (vidas <= 0)
				vivo = false;
		}

		void Inimigo::colidir(Entidade* e, sf::Vector2f intersecao)
		{
		}
	}
}