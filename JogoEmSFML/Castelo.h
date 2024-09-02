#pragma once
#include "Fase.h"
#include "NinjaGarras.h"
#include "Shogun.h"
#include "Plataforma.h"
#include "Espinhos.h"
#include "Moeda.h"
#include "Cura.h"
#include "BarraDeVida.h"

namespace Fases {
	class Castelo : public Fase {
	private:
		sf::Sprite fundo; 
		sf::Texture* texturaFundo;

		Shogun* shogunChefe;

		BarraDeVida barraDeVidaP1;
		BarraDeVida barraDeVidaP2;
	public:
		Castelo(bool m, idEstado ID_ESTADO);
		~Castelo();

		void inicializar();
		bool chefeFinalDerrotado();

		void executarEstado();
		void desenhar();
		void salvar();

		void fundoSegue(sf::Vector2f posicao1);
		void fundoSegue(sf::Vector2f posicao1, sf::Vector2f posicao2);
		void moverFundo();

		void ajustarBarraDeVida();
		void desenharBarraDeVida();

		void criarNinjaGarras();
		void criarShogun();
		void criarPlataforma();
		void criarEspinho();
		void criarMoeda();
		void criarCura();
	};
}
