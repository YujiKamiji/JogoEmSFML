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

		void executar(sf::Time deltaTime);
		void desenhar();

		void adicionar(Entidade* e);
		void remover(Entidade* e);

		Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> getPrimeiro();
		Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> getUltimo();
	};
}
