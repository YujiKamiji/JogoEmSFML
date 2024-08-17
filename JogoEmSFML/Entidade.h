#pragma once
#include "stdafx.h"
#include "Ente.h"

namespace Entidades {
	class Entidade: public Ente {
	protected:
		sf::Vector2f posicao;
		sf::Vector2f velocidades;
		bool noAr;
		float massa;

	public:
		Entidade();
		virtual ~Entidade();

		void setNoAr(bool b);

		virtual void executar() = 0;
		virtual void desenhar() = 0;
		virtual void salvar() = 0;

		virtual sf::Vector2f getPosicao() = 0;
		virtual sf::Vector2f getVelocidade() = 0;
		virtual float getMassa() = 0;
	};
}
