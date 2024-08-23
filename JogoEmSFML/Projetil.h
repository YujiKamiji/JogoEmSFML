#pragma once
#include "stdafx.h"
#include "Entidade.h"

namespace Entidades {
	class Projetil : public Entidade {
	protected:
		int dano;
		int duracao;
		sf::RectangleShape corpo;

		bool ativo;
		bool amigavel;

	public:
		Projetil(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
		~Projetil();

		virtual void mover() = 0;
		virtual void executar() = 0;
		virtual void desenhar() = 0;
		virtual void salvar() = 0;

		virtual void colidir(Entidade* e, sf::Vector2f intersecao) = 0;

		void Posicionar(sf::Vector2f pos);
		void setAtivo(bool b);
		void setAmigavel(bool b);

		virtual sf::Vector2f getPosicao();
		virtual sf::Vector2f getVelocidades();

		bool getAtivo();
		bool getAmigavel();
	};
}
