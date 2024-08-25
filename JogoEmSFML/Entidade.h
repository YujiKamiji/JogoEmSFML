#pragma once
#include "stdafx.h"
#include "Ente.h"

#define GRAVIDADE 2
#define VEL_TERMINAL 16

namespace Entidades {
	class Entidade: public Ente {
	protected:
		sf::Vector2f velocidades;
		bool noAr;

	public:
		Entidade();
		virtual ~Entidade();

		virtual void mover(sf::Time deltaTime);
		void setNoAr(bool b);

		virtual void executar(sf::Time deltaTime) = 0;
		virtual void desenhar() = 0;
		virtual void salvar() = 0;

		virtual sf::Vector2f getPosicao() = 0;
		virtual sf::Vector2f getVelocidade() = 0;
	};
}
