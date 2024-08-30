#include "Estados.h"

namespace Estados {

	Estados::Estado::Estado()
	{
	}

	Estados::Estado::~Estado()
	{
	}

	Estado* Estado::criarEstadoMenu(idEstado id)
	{
		return nullptr;
	}

	Estado* Estado::criarEstadoJogo(idEstado id)
	{
		return nullptr;
	}

	

	Estado* Estados::Estado::criarEstado(idEstado id)
	{
		//criar um estadoMenu
		if (id == MENU || id == MENU_OPCOES || id == PAUSE) 
		{
			EstadoMenu* estadoMenu = new EstadoMenu(id);
			return estadoMenu;
		}
		//criar um estadoJogo
		else
		{
			EstadoJogo* estadoJogo = new EstadoJogo(id);
			return estadoJogo;
		}

		cout << "idEstado invalido" << endl;
		return nullptr;		 
	}

}

