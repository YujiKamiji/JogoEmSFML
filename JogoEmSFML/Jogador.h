#pragma once
#include "stdafx.h"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			int pontuacao;

		public:
			void executar();
		};
	}
}
