#pragma once
#include "stdafx.h"
#include "Floresta.h"
#include "Menu.h"
#include "MenuPrincipal.h"
#include "MenuRanking.h"
#include "Castelo.h"

class GeradorDeEstados
{
public:
	GeradorDeEstados();
	~GeradorDeEstados();
	
	Estados::Estado* criarEstado(idEstado id); 

};