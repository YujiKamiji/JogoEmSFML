#pragma once
#include "Fase.h"
#include "Chao.h"
#include "NinjaGarras.h"
#include "NinjaShuriken.h"
#include "Plataforma.h"
#include "Caixote.h"
#include "Moeda.h"
#include "Cura.h"

namespace Fases {
	class Floresta : public Fase {
	private:
		float finalFase;

	public:
		Floresta(bool m, idEstado ID_ESTADO);
		~Floresta();

		void inicializar();
		bool verificarFinalFase();

		void executarEstado();
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
