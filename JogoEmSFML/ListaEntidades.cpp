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

	void ListaEntidades::draw() {
		Lista<Entidade>::Iterador<Entidade> i = lista.inicio();
		while (i != lista.fim()) {
			(*i)->desenhar();
			i++;
		}
	}

	void ListaEntidades::adicionar(Entidade* e) {
		lista.inserir(e);
	}
}