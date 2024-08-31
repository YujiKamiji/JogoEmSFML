#pragma once
#include "stdafx.h"
#include "Floresta.h"
#include "Castelo.h"

using namespace Fases;

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
	class EstadoJogo;
	class EstadoMenu;

	class Estado 
	{
	protected:
		idEstado id;
		Floresta* floresta;
		Castelo* castelo;
	public:
		Estado(idEstado ID);
		virtual ~Estado();
		void criarEstado();
		void executar();

		idEstado getId() const;
	};
}
