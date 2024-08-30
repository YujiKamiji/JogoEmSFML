#include "Estados.h"

namespace Estados
{
	Estado::Estado(idEstado ID)
		: id(ID), floresta(nullptr)
	{
	}

	Estado::~Estado()
	{
	}

	void Estado::criarEstado()
	{
		switch (id)
		{
		case MENU:  
			break;
		case MENU_OPCOES: 
			break;
		case FLORESTA:
			floresta = new Floresta(false);
			break;
		case CASTELO: 
			break;
		case PAUSE: 
			break;
		case GAMEOVER: 
			break;
		case VITORIA: 
			break;
		default:
			cout << "idEstado invalido" << endl;
			break;
		}
		
		
	}

	void Estado::executar()
	{
		switch (id)
		{
		case MENU:
			break;
		case MENU_OPCOES:
			break;
		case FLORESTA:
			floresta->executar();
			break;
		case CASTELO:
			break;
		case PAUSE:
			break;
		case GAMEOVER:
			break;
		case VITORIA:
			break;
		default:
			break;
		}
	}

	idEstado Estado::getId() const
	{
		return idEstado(id);
	}
}