#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {

	using namespace Personagens;

	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			sf::RectangleShape corpo;
			bool danoso;

		public:
			Obstaculo();
			~Obstaculo();
			virtual void executar() = 0;
			virtual void mover() = 0;
			virtual void obstacular(Jogador* p) = 0;
		};
	}
}
