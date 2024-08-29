#pragma once
#include "stdafx.h"
#include "Ente.h"

#define GRAVIDADE 30
#define VEL_TERMINAL 16

enum ID {
	JOGADOR,
	PROJETIL,
	NINJA_GARRAS,
	NINJA_SHURIKEN,
	SHOGUM,
	CHAO,
	PLATAFORMA,
	CAIXOTE,
	ESPINHOS
};

namespace Entidades {
	class Entidade: public Ente {
	protected:
		ID id;
		sf::Vector2f velocidades;
		bool noAr;

	public:
		Entidade();
		virtual ~Entidade();

		virtual void mover(sf::Time deltaTime) = 0;
		void setNoAr(bool b);

		virtual void executar(sf::Time deltaTime) = 0;
		virtual void desenhar() = 0;
		virtual void salvar() = 0;

		void gravidade(sf::Time deltaTime);

		virtual sf::Vector2f getPosicao() = 0;
		virtual sf::Vector2f getTamanho() = 0;
		virtual sf::Vector2f getVelocidade() = 0;
		virtual int getDano() = 0;
		virtual ID getId() = 0;
	};
}
