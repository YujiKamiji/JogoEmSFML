#include "Jogo.h"


Jogo::Jogo():
	pGE(Gerenciadores::GerenciadorDeEstados::getInstancia())
{
	executar(); 
}

Jogo::~Jogo() {}

void Jogo::executar()
{ 
	cout << "Jogo::executar()" << endl;
	pGE->executar();
}