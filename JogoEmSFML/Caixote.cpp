#include "Caixote.h"

Entidades::Obstaculos::Caixote::Caixote(sf::Vector2f pos, sf::Vector2f tam):
	id(CAIXOTE), Obstaculo(pos, tam), atrito(1.0f)
{
	textura = pGG->carregarTextura("Caixote.png");
	corpo.setTexture(textura);
}

Entidades::Obstaculos::Caixote::~Caixote()
{
}

void Entidades::Obstaculos::Caixote::executar(sf::Time deltaTime)
{
	mover(deltaTime);
}

void Entidades::Obstaculos::Caixote::desenhar()
{
	pGG->desenhar(&corpo);
}

void Entidades::Obstaculos::Caixote::salvar()
{
}


void Entidades::Obstaculos::Caixote::mover(sf::Time deltaTime)
{
	obstacular(deltaTime);
	corpo.move(velocidades); 
}

void Entidades::Obstaculos::Caixote::obstacular(sf::Time deltaTime)
{
	gravidade(deltaTime);
}

void Entidades::Obstaculos::Caixote::colidir(Entidade* e, sf::Vector2f intersecao)
{
	sf::Vector2f posOutro = e->getPosicao(); 

	if (e->getId() != PROJETIL)
	{
		//colisao em x
		if (intersecao.x > intersecao.y)
		{
			if (getPosicao().x < posOutro.x)
				corpo.move(intersecao.x - atrito, 0);
			else
				corpo.move(-intersecao.x + atrito, 0);
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
}

ID Entidades::Obstaculos::Caixote::getId() const
{
	return ID(id);
}
