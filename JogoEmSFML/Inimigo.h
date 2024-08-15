#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		public:
			virtual void executar();
			virtual void atacar(Jogador* p) = 0;
		};
	}
}
