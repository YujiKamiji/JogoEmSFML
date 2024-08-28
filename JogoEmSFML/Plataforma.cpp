#include "Plataforma.h"
#include "stdafx.h"

Entidades::Obstaculos::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam):
	Obstaculo(pos, tam), id(PLATAFORMA), movel(false), VelocidadeMaxPlat((rand() % 5) + 1)
{
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Entidades::Obstaculos::Plataforma::executar(sf::Time deltaTime)
{
	mover(deltaTime);
}

void Entidades::Obstaculos::Plataforma::desenhar()
{
	pGG->desenhar(&corpo);
}

void Entidades::Obstaculos::Plataforma::salvar()
{
}

void Entidades::Obstaculos::Plataforma::mover(sf::Time deltaTime)
{
	gravidade(deltaTime);
	levitacao(deltaTime);
	obstacular(deltaTime);
	
}

void Entidades::Obstaculos::Plataforma::levitacao(sf::Time deltaTime)
{
	if (velocidades.y <= VEL_TERMINAL)
		velocidades.y -= GRAVIDADE * deltaTime.asSeconds();
	else
		velocidades.y = VEL_TERMINAL;
}

void Entidades::Obstaculos::Plataforma::obstacular(sf::Time deltaTime)
{
	//MOVE PRA CIMA E PRA BAIXO CASO SEJA MOVEL
	if (movel)
	{
		if(velocidades.y < VelocidadeMaxPlat)
			velocidades.y += 
	}
}

void Entidades::Obstaculos::Plataforma::colidir(Entidade* e, sf::Vector2f intersecao)
{
	sf::Vector2f posOutro = e->getPosicao(); 

	//colisao em x
	if (intersecao.x > intersecao.y)
	{
		if (getPosicao().x < posOutro.x)
			corpo.move(intersecao.x, 0);
		else
			corpo.move(-intersecao.x, 0);
		velocidades.x = 0;
	}
	//colisao em y
	else
	{
		if (getPosicao().y < posOutro.y)
			corpo.move(0, intersecao.y);
		else
			corpo.move(0, -intersecao.y);
		velocidades.y = 0;
	}
}

ID Entidades::Obstaculos::Plataforma::getId()
{
	return ID(id);
}

int Entidades::Obstaculos::Plataforma::getDano()
{
	return 0;
}

void Entidades::Obstaculos::Plataforma::setMovel(bool Movel)
{
	movel = Movel;
}
