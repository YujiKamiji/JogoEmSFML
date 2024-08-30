#pragma once
#include "stdafx.h"
#include "Floresta.h"
#include "EstadoJogo.h"
#include "EstadoMenu.h"

enum idEstado 
{ 
	MENU, 
	MENU_OPCOES,
	FLORESTA,
	CASTELO,
	PAUSE, 
	GAMEOVER, 
	VITORIA 
};


namespace Estados
{
	class Estado 
	{
	protected:
		idEstado id;
	public:
		Estado();
		virtual ~Estado();
		Estado* criarEstado(idEstado id);
		virtual void executar(sf::Time deltaTime) = 0;

		idEstado getId() const;
	};
}
