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
		return new Menus::MenuPrincipal(id); 
		break;
	case MENU_RANKING: 
		return new Menus::MenuRanking(id);
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
	default:
		break;
	}
	
}
