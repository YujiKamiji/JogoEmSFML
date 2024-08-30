#include "Estados.h"

namespace Estados {

	Estado::Estado()
	{
	}

	Estado::~Estado()
	{
	}

	

	Estado* Estado::criarEstado(idEstado id)
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

	void Estado::executar(sf::Time deltaTime)
	{
	}

	idEstado Estado::getId() const
	{
		return idEstado(id);
	}

}

