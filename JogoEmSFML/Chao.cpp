#include "Chao.h"

Entidades::Obstaculos::Chao::Chao(sf::Vector2f pos, sf::Vector2f tam):
	Obstaculo(pos, tam), id(CHAO)
{
}

Entidades::Obstaculos::Chao::~Chao()
{
}

void Entidades::Obstaculos::Chao::executar(sf::Time deltaTime)
{
}

void Entidades::Obstaculos::Chao::desenhar()
{
	pGG->desenhar(&corpo);
}

void Entidades::Obstaculos::Chao::salvar()
{
}

void Entidades::Obstaculos::Chao::mover(sf::Time deltaTime)
{
}

void Entidades::Obstaculos::Chao::obstacular(sf::Time deltaTime)
{
}

void Entidades::Obstaculos::Chao::colidir(Entidade* e, sf::Vector2f intersecao)
{
}

ID Entidades::Obstaculos::Chao::getId() const
{
	return ID(id);
}

int Entidades::Obstaculos::Chao::getDano()
{
	return 0;
}
