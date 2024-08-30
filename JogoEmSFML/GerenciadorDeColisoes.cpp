#include "GerenciadorDeColisoes.h"

namespace Gerenciadores {
	GerenciadorDeColisoes::GerenciadorDeColisoes() :
		obstaculos(), personagens(), projeteis(), consumiveis()
	{
	}

	GerenciadorDeColisoes::~GerenciadorDeColisoes()
	{
	}

	sf::Vector2f GerenciadorDeColisoes::criterioDeColisao(Entidades::Entidade* e1, Entidades::Entidade* e2)
	{
		sf::Vector2f intersecao;
		sf::Vector2f DistCentros;

		DistCentros.x = e1->getPosicao().x - e2->getPosicao().x;
		DistCentros.y = e1->getPosicao().y - e2->getPosicao().y;

		//criterio de colisao
		intersecao.x = abs(DistCentros.x) - (e1->getTamanho().x + e2->getTamanho().x) / 2;
		intersecao.y = abs(DistCentros.y) - (e1->getTamanho().y + e2->getTamanho().y) / 2;

		return intersecao;
	}

	void GerenciadorDeColisoes::colidir()
	{
		//mudar isso aqui, ter uma lista de entidades e somente 1 for aninhado

		sf::Vector2f intersecao;
		sf::Vector2f DistCentros;
		Listas::Lista<Entidades::Obstaculos::Obstaculo>::Iterador<Entidades::Obstaculos::Obstaculo> itObs(NULL);
		Listas::Lista<Entidades::Obstaculos::Obstaculo>::Iterador<Entidades::Obstaculos::Obstaculo> itObs2(NULL);
		Listas::Lista<Entidades::Personagens::Personagem>::Iterador<Entidades::Personagens::Personagem> itPers1(NULL);
		Listas::Lista<Entidades::Personagens::Personagem>::Iterador<Entidades::Personagens::Personagem> itPers2(NULL);
		Listas::Lista<Entidades::Projetil>::Iterador<Entidades::Projetil> itProjetil(NULL);
		Listas::Lista<Entidades::Consumiveis::Consumivel>::Iterador<Entidades::Consumiveis::Consumivel> itConsumivel(NULL);

		//verifica se houve colisao entre personagens e obstaculos

		for (itObs = obstaculos.inicio(); itObs != obstaculos.fim(); itObs++)
		{

			for (itPers1 = personagens.inicio(); itPers1 != personagens.fim(); itPers1++)
			{
				intersecao = criterioDeColisao((*itPers1), (*itObs));

				if (intersecao.x < 0.0 && intersecao.y < 0.0)
				{
					(*itPers1)->colidir((*itObs), intersecao);
					(*itObs)->colidir((*itPers1), intersecao);
				}
			}

		}

		//verifica se houve colisao entre personagens

		for (itPers1 = personagens.inicio(); itPers1 != personagens.fim(); itPers1++)
		{
			if (!(*itPers1)->getVivo())
			{
				continue;
			}
			for (itPers2 = (personagens.inicio())++; itPers2 != personagens.fim(); itPers2++)
			{
				if (!(*itPers2)->getVivo())
				{
					continue;
				}
				if (itPers1 != itPers2)
				{
					intersecao = criterioDeColisao((*itPers1), (*itPers2));

					if (intersecao.x < 0.0 && intersecao.y < 0.0)
					{
						(*itPers1)->colidir((*itPers2), intersecao);
						(*itPers2)->colidir((*itPers1), intersecao);
					}
				}
			}
		}

		//verifica se houve colisao entre projeteis e personagens

		for (itProjetil = projeteis.inicio(); itProjetil != projeteis.fim(); itProjetil++)
		{
			if (!(*itProjetil)->getAtivo())
			{
				continue;
			}
			for (itPers1 = personagens.inicio(); itPers1 != personagens.fim(); itPers1++)
			{
				if (!(*itPers1)->getVivo())
				{
					continue;
				}

				intersecao = criterioDeColisao((*itPers1), (*itProjetil));

				if (intersecao.x < 0.0 && intersecao.y < 0.0)
				{
					(*itPers1)->colidir((*itProjetil), intersecao);
					(*itProjetil)->colidir((*itPers1), intersecao);
				}
			}
		}

		//verifica se houve colisao entre projeteis e chao
		for (itProjetil = projeteis.inicio(); itProjetil != projeteis.fim(); itProjetil++)
		{
			if (!(*itProjetil)->getAtivo())
			{
				continue;
			}
			for (itObs = obstaculos.inicio(); itObs != obstaculos.fim(); itObs++)
			{


				intersecao = criterioDeColisao((*itProjetil), (*itObs));

				if (intersecao.x < 0.0 && intersecao.y < 0.0)
				{
					(*itProjetil)->colidir((*itObs), intersecao);
				}


			}
		}

		//verifica se houve colisao entre obstaculos
		for (itObs = obstaculos.inicio(); itObs != obstaculos.fim(); itObs++)
		{
			if ((*itObs)->getId() == CHAO)
			{
				continue;
			}
			for (itObs2 = (obstaculos.inicio())++; itObs2 != obstaculos.fim(); itObs2++)
			{
				if (itObs != itObs2)
				{
					intersecao = criterioDeColisao((*itObs), (*itObs2));

					if (intersecao.x < 0.0 && intersecao.y < 0.0)
					{
						(*itObs)->colidir((*itObs2), intersecao);
						(*itObs2)->colidir((*itObs), intersecao);
					}
				}
			}

		}

		//verifica se houve colisao entre jogador consumiveis
		for (itConsumivel = consumiveis.inicio(); itConsumivel != consumiveis.fim(); itConsumivel++)
		{
			if (!(*itConsumivel)->getAtivo())
			{
				continue;
				//cout << "pulou consu" << endl;
			}
			for (itPers1 = personagens.inicio(); itPers1 != personagens.fim(); itPers1++)
			{
				if (!(*itPers1)->getVivo())
				{
					continue;
				}

				if ((*itPers1)->getId() != JOGADOR)
				{
					continue;
				}

				intersecao = criterioDeColisao((*itPers1), (*itConsumivel));

				if (intersecao.x < 0.0 && intersecao.y < 0.0)
				{
					//cout << "colisao consumivel" << endl;
					(*itConsumivel)->colidir((*itPers1), intersecao);
					(*itPers1)->colidir((*itConsumivel), intersecao);
				}
			}
		}

	}

	//Verifica colisao de plataforma movel com outros obstaculos
	void GerenciadorDeColisoes::plataformasMoveis(Entidades::Obstaculos::Plataforma* plat)
	{
		sf::Vector2f intersecao;
		sf::Vector2f DistCentros;

		Listas::Lista<Entidades::Obstaculos::Obstaculo>::Iterador<Entidades::Obstaculos::Obstaculo> itObs(NULL);
		Listas::Lista<Entidades::Personagens::Personagem>::Iterador<Entidades::Personagens::Personagem> itPers1(NULL);

		for (itObs = obstaculos.inicio(); itObs != obstaculos.fim(); itObs++)
		{
			intersecao = criterioDeColisao(plat, (*itObs));

			if (intersecao.x < 0.0 && intersecao.y < 0.0)
			{
				plat->colidir((*itObs), intersecao);
			}
		}
	}

	void GerenciadorDeColisoes::verificarVivos() {
		Listas::Lista<Personagem>::Iterador<Personagem> itPers(NULL);
		for (itPers = personagens.inicio(); itPers != personagens.fim(); itPers++) {
			if (!(*itPers)->getVivo())
				personagens.remover(*itPers);
		}
	}

	void GerenciadorDeColisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* o) {
		if(o)
			obstaculos.inserir(o);
	}
	void GerenciadorDeColisoes::incluirPersonagem(Personagem* p) {
		if(p)
			personagens.inserir(p);
	}
	void GerenciadorDeColisoes::incluirProjetil(Entidades::Projetil* p) {
		if(p)
			projeteis.inserir(p);
	}
	void GerenciadorDeColisoes::incluirConsumivel(Entidades::Consumiveis::Consumivel* c) {
		if(c)
			consumiveis.inserir(c);
	}

	GerenciadorDeColisoes* GerenciadorDeColisoes::instancia = nullptr;
	GerenciadorDeColisoes* GerenciadorDeColisoes::getInstancia() {
		if (instancia == nullptr)
			instancia = new GerenciadorDeColisoes();
		return instancia;
	}
}

