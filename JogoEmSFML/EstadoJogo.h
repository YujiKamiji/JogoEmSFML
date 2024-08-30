#pragma once
#include "Estados.h"

namespace Estados
{
	//estado jogo abrange a floresta, o castelo, o game over e a vitoria
	class EstadoJogo : public Estado
	{
	private:
		idEstado id;
	public:
		EstadoJogo(idEstado ID);
		~EstadoJogo();

	};
}