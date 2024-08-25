#pragma once
#include "stdafx.h"
#include "Obstaculo.h"

namespace Entidades 
{
	namespace Obstaculos 
	{
		class Chao : public Obstaculo
		{
		public:
			Chao(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Chao();

			void executar();
			void desenhar();
			void salvar();

			void mover();
		};
	}
}
