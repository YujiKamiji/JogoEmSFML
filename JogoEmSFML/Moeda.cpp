#include "Moeda.h"

namespace Entidades
{
	namespace Consumiveis
	{
		Moeda::Moeda(sf::Vector2f pos, sf::Vector2f tam):
			Consumivel(pos, tam), valor(10), id(MOEDA)
		{
			textura = pGG->carregarTextura("Moeda.png");
			corpo.setTexture(textura);
		}
		Moeda::~Moeda()
		{
		}
		void Moeda::desenhar()
		{
			if (getAtivo())
				pGG->desenhar(&corpo);
		}
		void Moeda::salvar()
		{
		}
		const int Moeda::getPontos() const
		{
			return valor;
		}
		sf::Vector2f Moeda::getPosicao()
		{
			return corpo.getPosition();
		}
		sf::Vector2f Moeda::getTamanho()
		{
			return corpo.getSize();
		}
		sf::Vector2f Moeda::getVelocidade()
		{
			return velocidades;
		}
		ID Moeda::getId() const
		{
			return ID(id);
		}
		void Moeda::colidir(Entidade* e, sf::Vector2f intersecao)
		{
			sf::Vector2f posOutro = e->getPosicao();

			if (e->getId() == JOGADOR)
				setAtivo(false);
		}
	}
}