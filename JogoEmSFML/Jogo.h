#pragma once
#include "Floresta.h"

using namespace Fases;

class Jogo {
private:
	Floresta* fase1;
	//vai ter o gerenciador de estados aqui

public:
	Jogo();
	~Jogo();

	void executar(); //o executar vai executar o gerenciador de estados e ele vai decidir oq fazer
	//começando pelo estado MENU e dps empilhando e desempilhando os outros estados
};
