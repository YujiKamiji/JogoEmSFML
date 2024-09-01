#include "GeradorDeEstados.h"

GeradorDeEstados::GeradorDeEstados()
{
}

GeradorDeEstados::~GeradorDeEstados()
{
}

Estados::Estado* GeradorDeEstados::criarEstado(idEstado id)
{
	switch(id)
	{
	case MENU:
		return new Menus::MenuPrincipal(id); //TODO
		break;
	case MENU_OPCOES: //TODO
		break;
	case FLORESTA_SINGLE:
		return new Fases::Floresta(false, id);
		break;
	case FLORESTA_MULTI:
		return new Fases::Floresta(true, id);
		break;
	case CASTELO_SINGLE:
		return new Fases::Castelo(false, id);
		break;
	case CASTELO_MULTI:
		return new Fases::Castelo(true, id);
		break;
	case PAUSE: //TODO
		break;
	case GAMEOVER: //TODO
		break;
	case VITORIA: //TODO	
		break;
	default:
		break;
	}
	
}
