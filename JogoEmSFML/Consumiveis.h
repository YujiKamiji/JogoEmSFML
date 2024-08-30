#pragma once
#include "stdafx.h"
#include "Entidade.h"

namespace Entidades
{
	namespace Consumiveis
	{
		class Consumivel : public Entidade
		{
		protected:
			bool ativo;
			sf::RectangleShape corpo;

		public:
			Consumivel(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Consumivel();

			virtual void executar(sf::Time deltaTime) = 0;
			virtual void desenhar() = 0;
			virtual void salvar() = 0;

			virtual sf::Vector2f getPosicao() = 0;
			virtual sf::Vector2f getTamanho() = 0;
			virtual sf::Vector2f getVelocidade() = 0;
			virtual int getDano() = 0;
			virtual ID getId() = 0;
			bool getAtivo();

			void setAtivo(bool b);

			virtual void colidir(Entidade* e, sf::Vector2f intersecao) = 0; 
		};
	}
}
