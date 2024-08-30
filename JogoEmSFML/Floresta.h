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
		float finalFase;

	public:
		Floresta(bool m);
		~Floresta();

		void inicializar();
		void verificarFinalFase();

		void executar();
		void desenhar();
		void salvar();

		void criarNinjaGarras();
		void criarNinjaShuriken();
		void criarPlataforma();
		void criarCaixote();
		void criarMoeda();
		void criarCura();
	};
}
