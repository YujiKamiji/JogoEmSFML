#pragma once
#include "stdafx.h"
#include "Projetil.h"

namespace Entidades {
	class AtaqueCorte : public Projetil {
	private:
		bool danoDado;
	public:
		AtaqueCorte(sf::Vector2f pos, sf::Vector2f tam);
		~AtaqueCorte();

		void mover(sf::Time deltaTime);
		void executar(sf::Time deltaTime);
		void desenhar();
		void salvar();

		void setDanoDado(bool b);
		bool getDanoDado();

		void colidir(Entidade* e, sf::Vector2f intersecao);
	};
}