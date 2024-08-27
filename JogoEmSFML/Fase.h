#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "GerenciadorDeColisoes.h"

using namespace Listas;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

namespace Fases {
	class Fase: public Ente {
	protected:
		ListaEntidades entidades;
		Lista<Personagem> personagens;
		Lista<Obstaculo> obstaculos;
		Lista<Projetil> projeteis;

		Gerenciador_Grafico* pGG;
		GerenciadorDeColisoes* pGC;

		sf::RectangleShape corpo;

	public:
		Fase();
		~Fase();

		void executar(sf::Time deltaTime);

		virtual void inicializar() = 0;
		virtual void executar() = 0;
		virtual void desenhar();
		virtual void salvar() = 0;
	};
}
