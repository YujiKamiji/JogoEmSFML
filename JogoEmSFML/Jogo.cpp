#include "Jogo.h"


Jogo::Jogo():
	pGE(Gerenciadores::GerenciadorDeEstados::getInstancia()),
	pGG(Gerenciadores::Gerenciador_Grafico::getInstancia()) 
{
	pGE->adicionarEstado(MENU);

	executar(); 
}

Jogo::~Jogo() {}

void Jogo::executar()
{ 
	while (pGG->janela_aberta() && pGE->getEstadoAtual())
	{
		cout << "Jogo::executar()" << endl;
		pGE->executar();
	}
	
}