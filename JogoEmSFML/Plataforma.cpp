#include "Plataforma.h"
#include "stdafx.h"


Entidades::Obstaculos::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam):
	Obstaculo(pos, tam), 
	id(PLATAFORMA), 
	movel(false), 
	VelocidadeMaxPlat(1),
	atrasoMovel(5), 
	aceleracao(GRAVIDADE),
	atrasoMovimento(4),
	direcao(false)
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
	if (movel) {
		obstacular(deltaTime);
	}
	corpo.move(velocidades); 
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
	if (atrasoMovimento > 0 && direcao)
	{
		if (velocidades.y <= VelocidadeMaxPlat) 
			velocidades.y += aceleracao * deltaTime.asSeconds(); 
		else
			velocidades.y = VelocidadeMaxPlat;
		atrasoMovimento -= deltaTime.asSeconds(); 
	}
	else if (atrasoMovimento> 0 && !direcao) 
	{ 
		if (velocidades.y >= -VelocidadeMaxPlat)  
			velocidades.y -= aceleracao * deltaTime.asSeconds();  
		else
			velocidades.y = -VelocidadeMaxPlat; 
		atrasoMovimento -= deltaTime.asSeconds();  
	}
	else
	{
		direcao = !direcao;
		atrasoMovimento = 4;
	}			
	
}

void Entidades::Obstaculos::Plataforma::colidir(Entidade* e, sf::Vector2f intersecao)
{
	sf::Vector2f posOutro = e->getPosicao(); 

	//colisao em x
	if (intersecao.x > intersecao.y)
	{		
		velocidades.x = 0;
	}
	//colisao em y
	else if (e->getId() == CHAO || e->getId() == PLATAFORMA || e->getId() == CAIXOTE || e->getId() == ESPINHOS)
	{
		if (getPosicao().y < posOutro.y)
			corpo.move(0, intersecao.y);
		else
			corpo.move(0, -intersecao.y);
		velocidades.y = 0;
	}
	else if (posOutro.y > getPosicao().y) 
	{
		corpo.move(0, intersecao.y);
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
