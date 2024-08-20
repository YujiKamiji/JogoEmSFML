#include "GerenciadorDeColisoes.h"

Gerenciadores::GerenciadorDeColisoes::GerenciadorDeColisoes(Lista<Entidades::Obstaculos::Obstaculo>* obs,
															Lista<Entidades::Personagens::Personagem>* pers) :
obstaculos(obs), 
personagens(pers)
{
}

Gerenciadores::GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
	if(obstaculos)
		delete obstaculos;
	if (personagens)
		delete personagens;
}

void Gerenciadores::GerenciadorDeColisoes::colidir()
{
	sf::Vector2f intersecao;
	sf::Vector2f DistCentros;
	Listas::Lista<Entidades::Obstaculos::Obstaculo>::Iterador<Entidades::Obstaculos::Obstaculo> itObs(NULL);
	Listas::Lista<Entidades::Personagens::Personagem>::Iterador<Entidades::Personagens::Personagem> itPers(NULL);

	//verifica se houve colisao entre personagens e obstaculos

	for (itObs = obstaculos->inicio(); itObs != obstaculos->fim(); itObs++)
	{
		for (itPers = personagens->inicio(); itPers != personagens->fim(); itPers++)
		{

		}

	}
}
