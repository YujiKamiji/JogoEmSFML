#pragma once
#include "stdafx.h"
#include "Projetil.h"

namespace Entidades {
	class AtaqueCorte : public Projetil {
	public:
		AtaqueCorte(sf::Vector2f pos = sf::Vector2f(0, 0), 
			sf::Vector2f tam = sf::Vector2f(4, 8));
		~AtaqueCorte();

		void mover();
		void executar();
		void desenhar();
		void salvar();

		void colidir(Entidade* e, sf::Vector2f intersecao);
	};
}