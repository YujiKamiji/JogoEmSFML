#include "Jogo.h"

Jogo::Jogo():
	p1(nullptr), 
	p2(nullptr),
	chao(nullptr),
	personagens(),
	obstaculos(),
	pGG(pGG->getInstancia()),
	pGC()
{
	inicializar();
}

Jogo::~Jogo()
{
	delete pGC;
}

void Jogo::inicializar()
{
	p1 = new Jogador(sf::Vector2f(100, 100), sf::Vector2f(50.0, 100.0));
	p2 = new Jogador(sf::Vector2f(200, 100), sf::Vector2f(50.0, 100.0));
	chao = new Chao(sf::Vector2f(1280 / 2, 500), sf::Vector2f(1200, 30));
	//inicializar as listas
	personagens.inserir(p1);
	personagens.inserir(p2);

	obstaculos.inserir(chao);

	pGC = new GerenciadorDeColisoes(&obstaculos, &personagens);
}

void Jogo::executar()
{
	
	sf::Clock relogio;
	sf::Time dt;
	sf::RenderWindow* janela = pGG->getJanela();

	Lista<Personagem>::Iterador<Personagem> itPers = nullptr;
	Lista<Obstaculo>::Iterador<Obstaculo> itObs = nullptr;

	if (!janela) {
		std::cerr << "Erro: Janela não foi inicializada corretamente." << std::endl;
		return;
	}

	//loop principal
	while (pGG->janela_aberta())
	{

		sf::Event evento;
		while (janela->pollEvent(evento))
		{
			if (evento.type == sf::Event::Closed)
			{
				janela->close();
			}
		}

		dt = relogio.restart();

		itPers = personagens.inicio();
		itObs = obstaculos.inicio();

		while (itPers != personagens.fim())
		{
			(*itPers)->executar(dt);
			itPers++;
			
		}

		while (itObs != obstaculos.fim())
		{
			(*itObs)->executar(dt);
			itObs++;
		}

		p1->getAtaque()->executar(dt);
		p2->getAtaque()->executar(dt); 

		pGC->colidir();
		
		janela->clear();
		desenhar();
		pGG->mostrar();
	}
}

void Jogo::desenhar()
{
	Lista<Personagem>::Iterador<Personagem> itPers = personagens.inicio();
	Lista<Obstaculo>::Iterador<Obstaculo> itObs = obstaculos.inicio();

	while (itPers != personagens.fim()) 
	{
		(*itPers)->desenhar();
		itPers++;
	}

	while (itObs != obstaculos.fim()) 
	{
		
		(*itObs)->desenhar();
		itObs++;
	}
	
	p1->getAtaque()->desenhar();
	p2->getAtaque()->desenhar(); 
	
}

void Jogo::salvar()
{
}
