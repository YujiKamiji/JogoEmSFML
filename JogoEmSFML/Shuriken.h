#pragma once
#include "stdafx.h"
#include "Projetil.h"

namespace Entidades {
	class Shuriken : public Projetil {
	private:
		sf::Vector2f alvo;

	public:
		Shuriken(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(5, 5));
		~Shuriken();

		void mover();
		void executar();
		void desenhar();
		void salvar();

		sf::Vector2f getPosicao();
		sf::Vector2f getVelocidades();

		void setAlvo(sf::Vector2f a);
		void colidir(Entidade* e, sf::Vector2f intersecao);
	};
}
