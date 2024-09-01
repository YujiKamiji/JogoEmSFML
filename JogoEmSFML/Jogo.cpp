#include "Jogo.h"


Jogo::Jogo():
	pGE(Gerenciadores::GerenciadorDeEstados::getInstancia())
{
	pGE->adicionarEstado(CASTELO_SINGLE);
	pGE->adicionarEstado(FLORESTA_SINGLE);
	pGE->adicionarEstado(MENU);

	executar(); 
}

Jogo::~Jogo() {}

void Jogo::executar()
{ 
	cout << "Jogo::executar()" << endl;
	pGE->executar();
}