#pragma once
#include "Fase.h"
#include "NinjaGarras.h"
#include "Shogun.h"
#include "Plataforma.h"
#include "Espinhos.h"
#include "Moeda.h"
#include "Cura.h"

namespace Fases {
	class Castelo : public Fase {
	private:

	public:
		Castelo(bool m, idEstado ID_ESTADO);
		~Castelo();

		void inicializar();

		void executar();
		void desenhar();
		void salvar();

		void criarNinjaGarras();
		void criarShogun();
		void criarPlataforma();
		void criarEspinho();
		void criarMoeda();
		void criarCura();
	};
}
