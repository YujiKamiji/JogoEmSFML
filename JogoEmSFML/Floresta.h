#pragma once
#include "Fase.h"
#include "Chao.h"
#include "Plataforma.h"
#include "Caixote.h"
#include "Espinhos.h"
#include "NinjaGarras.h"
#include "NinjaShuriken.h"
#include "Shogun.h"
#include "Cura.h"
#include "Municao.h"
#include "Moeda.h"

namespace Fases {
	class Floresta : public Fase {
	private:
		Jogador* p1;
		Jogador* p2;

	public:
		Floresta();
		~Floresta();

		void inicializar();
		void verificarVivos();
		void executar();
		void desenhar();
		void salvar();

		//void criarNinjaGarras();
		//void criarNinjaShuriken();
		//void criarPlataforma();
	};
}
