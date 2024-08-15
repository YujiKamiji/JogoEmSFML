#pragma once
#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			int vidas;

		public:
			virtual void executar() = 0;
			int getVidas();
		};
	}
}
