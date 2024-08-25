#include "ListaEntidades.h"

namespace Listas {
	ListaEntidades::ListaEntidades():
	lista() {}

	ListaEntidades::~ListaEntidades() {}

	void ListaEntidades::executar() {
		Lista<Entidade>::Iterador<Entidade> i = lista.inicio();
		while (i != lista.fim()) {
			(*i)->executar();
			i++;
		}
	}

	void ListaEntidades::desenhar() {
		Lista<Entidade>::Iterador<Entidade> i = lista.inicio();
		while (i != lista.fim()) {
			(*i)->desenhar();
			i++;
		}
	}

	void ListaEntidades::adicionar(Entidade* e) {
		lista.inserir(e);
	}

	void ListaEntidades::remover(Entidade* e)
	{
		lista.remover(e);
	}

	Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> 
		ListaEntidades::getPrimeiro() { return lista.inicio(); }
}