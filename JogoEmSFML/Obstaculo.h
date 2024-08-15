#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {

	using namespace Personagens;

	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			bool danoso;

		public:
			virtual void executar() = 0;
			virtual void obstacular(Jogador* p) = 0;
		};
	}
}
