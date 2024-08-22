#pragma once
#include "stdafx.h"
#include "Projetil.h"

namespace Entidades {
	class Shuriken : public Projetil {
	private:
		sf::Vector2f alvo;

	public:
		Shuriken(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f j);
		~Shuriken();

		void mover();
		void executar();
		void desenhar();
		void salvar();

		void colidir(Entidade* e, sf::Vector2f intersecao);
	};
}
