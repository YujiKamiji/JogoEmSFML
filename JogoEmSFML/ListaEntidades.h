#pragma once
#include "stdafx.h"
#include "Lista.h"
#include "Entidade.h"

using namespace Entidades;

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidade> lista;

	public:
		ListaEntidades();
		~ListaEntidades();

		void executar();
		void adicionar(Entidade* e);
	};
}
