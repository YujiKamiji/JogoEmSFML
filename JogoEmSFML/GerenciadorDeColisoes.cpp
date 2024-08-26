#include "GerenciadorDeColisoes.h"

Gerenciadores::GerenciadorDeColisoes::GerenciadorDeColisoes(Lista<Entidades::Obstaculos::Obstaculo>* obs,
															Lista<Entidades::Personagens::Personagem>* pers) :
obstaculos(obs), 
personagens(pers)
{
}

Gerenciadores::GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
}

void Gerenciadores::GerenciadorDeColisoes::colidir()
{
	sf::Vector2f intersecao;
	sf::Vector2f DistCentros;
	Listas::Lista<Entidades::Obstaculos::Obstaculo>::Iterador<Entidades::Obstaculos::Obstaculo> itObs(NULL);
	Listas::Lista<Entidades::Personagens::Personagem>::Iterador<Entidades::Personagens::Personagem> itPers1(NULL);
	Listas::Lista<Entidades::Personagens::Personagem>::Iterador<Entidades::Personagens::Personagem> itPers2(NULL);

	//verifica se houve colisao entre personagens e obstaculos

	for (itObs = obstaculos->inicio(); itObs != obstaculos->fim(); itObs++)
	{
		for (itPers1 = personagens->inicio(); itPers1 != personagens->fim(); itPers1++)
		{
			DistCentros.x = (*itPers1)->getPosicao().x - (*itObs)->getPosicao().x;
			DistCentros.y = (*itPers1)->getPosicao().y - (*itObs)->getPosicao().y;

			//criterio de colisao
			intersecao.x = abs(DistCentros.x) - ((*itPers1)->getTamanho().x + (*itObs)->getTamanho().x) / 2;
			intersecao.y = abs(DistCentros.y) - ((*itPers1)->getTamanho().y + (*itObs)->getTamanho().y) / 2;

			if (intersecao.x < 0.0 && intersecao.y < 0.0)
			{
				(*itPers1)->colidir((*itObs), intersecao);
			}
		}

	}

	//verifica se houve colisao entre personagens

	for (itPers1 = personagens->inicio(); itPers1 != personagens->fim(); itPers1++)
	{
		for (itPers2 = itPers1++; itPers2 != personagens->fim(); itPers2++)
		{
			if (itPers1 != itPers2)
			{
				DistCentros.x = (*itPers1)->getPosicao().x - (*itPers2)->getPosicao().x;
				DistCentros.y = (*itPers1)->getPosicao().y - (*itPers2)->getPosicao().y;

				//criterio de colisao
				intersecao.x = abs(DistCentros.x) - ((*itPers1)->getTamanho().x + (*itPers2)->getTamanho().x) / 2;
				intersecao.y = abs(DistCentros.y) - ((*itPers1)->getTamanho().y + (*itPers2)->getTamanho().y) / 2;

				if (intersecao.x < 0.0 && intersecao.y < 0.0)
				{
					(*itPers1)->colidir((*itPers2), intersecao);
					(*itPers2)->colidir((*itPers1), intersecao);
				}
			}
		}
	}
}
