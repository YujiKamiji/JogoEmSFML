#pragma once
#include "stdafx.h"
#include "Projetil.h"

namespace Entidades {
	class AtaqueCorte : public Projetil {
	public:
		AtaqueCorte(sf::Vector2f pos = sf::Vector2f(0, 0), 
			sf::Vector2f tam = sf::Vector2f(25, 50));
		~AtaqueCorte();

		void mover(sf::Time deltaTime);
		void executar(sf::Time deltaTime);
		void desenhar();
		void salvar();

		void colidir(Entidade* e, sf::Vector2f intersecao);
	};
}