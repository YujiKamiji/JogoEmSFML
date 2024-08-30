#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "GerenciadorDeColisoes.h"
#include "Chao.h"
#include "nlohmann/json.hpp"

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
		nlohmann::json mapa;

	public:
		Fase();
		~Fase();

		void executar(sf::Time deltaTime);

		virtual void inicializar() = 0;
		virtual void executar() = 0;
		virtual void desenhar();
		virtual void salvar() = 0;

		void carregarMapa(std::string mapaJson);
		void criarChao();
		//virtual void criarNinjaGarras() = 0;
		//virtual void criarNinjaShuriken() = 0;
		//virtual void criarPlataforma() = 0;
	};
}
