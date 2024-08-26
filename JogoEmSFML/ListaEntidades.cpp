#include "ListaEntidades.h"

namespace Listas {
	ListaEntidades::ListaEntidades():
	lista() {}

	ListaEntidades::~ListaEntidades() {}

	//executa tudo que estiver na lista
	void ListaEntidades::executar(sf::Time deltaTime) {
		Lista<Entidade>::Iterador<Entidade> i = lista.inicio();
		while (i != lista.fim()) {
			(*i)->executar(deltaTime);
			i++;
		}
	}

	//desenha tudo que estiver na lista
	void ListaEntidades::desenhar() {
		Lista<Entidade>::Iterador<Entidade> i = lista.inicio();
		while (i != lista.fim()) {
			(*i)->desenhar();
			i++;
		}
	}

	//adiciona item na lista
	void ListaEntidades::adicionar(Entidade* e) {
		lista.inserir(e);
	}

	//remove item da lista
	void ListaEntidades::remover(Entidade* e)
	{
		lista.remover(e);
	}

	Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> 
	ListaEntidades::getPrimeiro() { return lista.inicio(); }
}