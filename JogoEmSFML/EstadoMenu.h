#pragma once
#include "Estados.h"

namespace Estados
{
	//estado menu abrange o menu principal, menu de opcoes e menu de pause
	class EstadoMenu : public Estado
	{
	private:
		idEstado id;
	public:
		EstadoMenu(idEstado ID);
		~EstadoMenu();
	};
}