#pragma once
#include "stdafx.h"
#include "Floresta.h"
#include "Menu.h"
#include "MenuOpc.h"
#include "Castelo.h"

class GeradorDeEstados
{
public:
	GeradorDeEstados();
	~GeradorDeEstados();
	
	Estados::Estado* criarEstado(idEstado id); 

};