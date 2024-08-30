#include "Consumiveis.h"

namespace Entidades
{
	namespace Consumiveis
	{
		Consumivel::Consumivel(sf::Vector2f pos, sf::Vector2f tam):
			Entidade(), ativo(true), corpo(tam)
		{
			corpo.setOrigin(corpo.getSize() / 2.f);
			corpo.setPosition(pos);
		}
		Consumivel::~Consumivel()
		{
		}
		bool Consumivel::getAtivo()
		{
			return ativo;
		}
		void Consumivel::setAtivo(bool b)
		{
			ativo = b;
		}
	}
}