#pragma once
#include "Fase.h"
#include "Chao.h"
#include "NinjaGarras.h"

namespace Fases {
	class Floresta : public Fase {
	private:
		Jogador* p1;
		Jogador* p2;
	public:
		Floresta();
		~Floresta();

		void inicializar();
		void executar();
		void desenhar();
		void salvar();
	};
}
