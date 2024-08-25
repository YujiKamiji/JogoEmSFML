#include "Jogo.h"

Jogo::Jogo():
	p1(sf::Vector2f(100, 100), sf::Vector2f(50.0, 100.0)),
	p2(sf::Vector2f(200, 100), sf::Vector2f(50.0, 100.0)),
	personagens(),
	obstaculos(),
	pGG(pGG->getInstancia()),
	pGC(new GerenciadorDeColisoes(&obstaculos, &personagens))
{
	inicializar();
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	//inicializar as listas
	personagens.inserir(&p1);
	personagens.inserir(&p2);

}

void Jogo::executar()
{

}

void Jogo::desenhar()
{
}

void Jogo::salvar()
{
}
