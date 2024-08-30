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
using namespace Consumiveis;

namespace Fases {
	class Fase: public Ente {
	protected:
		ListaEntidades entidades;
		Jogador* p1;
		Jogador* p2;

		
		Gerenciador_Grafico* pGG;
		GerenciadorDeColisoes* pGC;

		sf::RectangleShape corpo;
		nlohmann::json mapa;

		bool multijogador;

	public:
		Fase(bool m);
		~Fase();

		void setMultijogador(bool m);

		void executar(sf::Time deltaTime);
		virtual void verificarVivos();

		virtual void inicializar() = 0;
		virtual void executar() = 0;
		virtual void desenhar();
		virtual void salvar() = 0;

		void carregarMapa(std::string mapaJson);
		void criarChao();

		void criarJogadores();
		virtual void criarNinjaGarras() = 0;
		virtual void criarPlataforma() = 0;
		virtual void criarMoeda() = 0;
		virtual void criarCura() = 0;
	};
}
