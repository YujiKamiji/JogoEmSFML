#include "Cura.h"

namespace Entidades
{
	namespace Consumiveis
	{
		Cura::Cura(sf::Vector2f pos, sf::Vector2f tam):
			Consumivel(pos, tam), cura(35), id(CURA)
		{
			corpo.setFillColor(sf::Color::Green);
		}
		Cura::~Cura()
		{
		}
		void Cura::executar(sf::Time deltaTime)
		{
		}
		void Cura::desenhar()
		{
			if (ativo)
				pGG->desenhar(&corpo);
		}
		void Cura::salvar()
		{
		}
		sf::Vector2f Cura::getPosicao()
		{
			return corpo.getPosition();
		}
		sf::Vector2f Cura::getTamanho()
		{
			return corpo.getSize();
		}
		sf::Vector2f Cura::getVelocidade()
		{
			return velocidades;
		}
		int Cura::getDano()
		{
			return -1;
		}
		ID Cura::getId()
		{
			return ID(id);
		}
		int Cura::getCura()
		{
			return cura;
		}
		void Cura::mover(sf::Time deltaTime)
		{
		}
		void Cura::colidir(Entidade* e, sf::Vector2f intersecao)
		{
			sf::Vector2f posOutro = e->getPosicao();

			if (e->getId() == JOGADOR)
			{
				//colisao em x
				if (intersecao.x > intersecao.y)
				{
					setAtivo(false);
				}
				//colisao em y
				else
				{
					setAtivo(false);
				}
			}

			
		}
	}
}