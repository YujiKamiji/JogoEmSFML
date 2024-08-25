#include "Jogo.h"

Jogo::Jogo():
	p1(sf::Vector2f(100, 100), sf::Vector2f(50.0, 100.0)),
	p2(sf::Vector2f(200, 100), sf::Vector2f(50.0, 100.0)),
	chao(sf::Vector2f(1280/2, 500), sf::Vector2f(1200, 30)),
	personagens(),
	obstaculos(),
	pGG(pGG->getInstancia()),
	pGC()
{
	std::cerr << "Inicializando Jogo" << std::endl;
	inicializar();
}

Jogo::~Jogo()
{
	std::cerr << "Destruindo Jogo" << std::endl;
	delete pGC;
}

void Jogo::inicializar()
{
	std::cerr << "Inicializando listas de personagens e obstáculos" << std::endl;
	//inicializar as listas
	personagens.inserir(&p1);
	personagens.inserir(&p2);

	obstaculos.inserir(&chao);

	pGC = new GerenciadorDeColisoes(&obstaculos, &personagens);
	std::cout << "Personagens inseridos: " << personagens.getTamanho() << std::endl;
	std::cout << "Obstaculos inseridos: " << obstaculos.getTamanho() << std::endl;
	std::cerr << "Chao Pos: " << chao.getPosicao().x << ", " << chao.getPosicao().y << std::endl;
	std::cerr << "Chao Tam: " << chao.getTamanho().x << ", " << chao.getTamanho().y << std::endl;


}

void Jogo::executar()
{
	std::cerr << "Executando Jogo" << std::endl;
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

	
}

void Jogo::salvar()
{
}
