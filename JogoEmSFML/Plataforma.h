#pragma once
#include "Jogador.h"
#include "Obstaculo.h"

namespace Entidades {

	using namespace Personagens;

	namespace Obstaculos {

		class Plataforma : public Obstaculo {
		private:
			ID id;
			bool movel;
			float VelocidadeMaxPlat;
			float atrasoMovimento;
			float aceleracao;
			bool direcao;
		public:
			Plataforma(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Plataforma();

			void executar(sf::Time deltaTime);
			void desenhar();
			void salvar();

			void mover(sf::Time deltaTime);
			void levitacao(sf::Time deltaTime);

			void obstacular(sf::Time deltaTime);
			void colidir(Entidade* e, sf::Vector2f intersecao);

			ID getId() const;
			int getDano();

			void setMovel(bool Movel);
		};
	}

	
}