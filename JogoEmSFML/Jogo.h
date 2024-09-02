#pragma once
#include "GerenciadorDeEstados.h"
#include "Gerenciador_Grafico.h"



class Jogo {
private:
	Gerenciadores::GerenciadorDeEstados* pGE;
	Gerenciadores::Gerenciador_Grafico* pGG;
	//vai ter o gerenciador de estados aqui

public:
	Jogo();
	~Jogo();

	void executar(); //o executar vai executar o gerenciador de estados e ele vai decidir oq fazer
	//começando pelo estado MENU e dps empilhando e desempilhando os outros estados
};
