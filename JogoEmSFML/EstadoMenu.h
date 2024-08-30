#pragma once
#include "Estados.h"

namespace Estados
{
	//estado menu abrange o menu principal, menu de opcoes e menu de pause
	class EstadoMenu : public Estado
	{
	private:
		
	public:
		EstadoMenu(idEstado ID);
		~EstadoMenu();

		void executar(sf::Time deltaTime);
	};
}