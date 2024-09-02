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
		sf::Sprite fundo; 
		sf::Texture* texturaFundo; 
	public:
		Castelo(bool m, idEstado ID_ESTADO);
		~Castelo();

		void inicializar();

		void executarEstado();
		void desenhar();
		void salvar();

		void fundoSegue(sf::Vector2f posicao1);
		void fundoSegue(sf::Vector2f posicao1, sf::Vector2f posicao2);

		void criarNinjaGarras();
		void criarShogun();
		void criarPlataforma();
		void criarEspinho();
		void criarMoeda();
		void criarCura();
	};
}
