#pragma once
#include "stdafx.h"
#include "Projetil.h"

namespace Entidades {
	class Shuriken : public Projetil {
	private:
		sf::Vector2f alvo;

	public:
		Shuriken(sf::Vector2f pos, sf::Vector2f tam);
		~Shuriken();

		void mover();
		void executar();
		void desenhar();
		void salvar();

		void setAlvo(sf::Vector2f a);
		void colidir(Entidade* e, sf::Vector2f intersecao);
	};
}
