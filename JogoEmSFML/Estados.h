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
	private:
		Estado* criarEstadoMenu(idEstado id);
		Estado* criarEstadoJogo(idEstado id);
		
		
	public:
		Estado();
		~Estado();
		Estado* criarEstado(idEstado id);
	};
}
