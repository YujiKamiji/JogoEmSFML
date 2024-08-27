#pragma once
#include "Floresta.h"

using namespace Fases;

class Jogo {
private:
	Floresta* fase1;

public:
	Jogo();
	~Jogo();

	void executar();
};
