#include "Espinhos.h"

Entidades::Obstaculos::Espinhos::Espinhos(sf::Vector2f pos, sf::Vector2f tam) :
	Obstaculo(pos, tam), id(ESPINHOS), afiacao(15), decrescimo(0.0f)
{
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}

void Entidades::Obstaculos::Espinhos::executar(sf::Time deltaTime)
{
	obstacular(deltaTime);
	mover(deltaTime);
	cout << "afiacao: " << afiacao << endl;
}

void Entidades::Obstaculos::Espinhos::desenhar()
{
	pGG->desenhar(&corpo);
}

void Entidades::Obstaculos::Espinhos::salvar()
{
}

void Entidades::Obstaculos::Espinhos::mover(sf::Time deltaTime)
{
	gravidade(deltaTime);
	corpo.move(velocidades);
}

void Entidades::Obstaculos::Espinhos::obstacular(sf::Time deltaTime)
{
	if(decrescimo < 10.0f)
		decrescimo += deltaTime.asSeconds();
	else
	{
		decrescimo = 0.0f;
		if(afiacao >= 3)
			afiacao--;
	}
}

void Entidades::Obstaculos::Espinhos::colidir(Entidade* e, sf::Vector2f intersecao)
{
	sf::Vector2f posOutro = e->getPosicao();

	
	//colisao em x
	if (intersecao.x > intersecao.y)
	{
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

ID Entidades::Obstaculos::Espinhos::getId()
{
	return ID(id);
}

int Entidades::Obstaculos::Espinhos::getDano()
{
	return afiacao;
}
