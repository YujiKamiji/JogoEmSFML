#include "Floresta.h"

namespace Fases {
	Floresta::Floresta():
		Fase()
	{
		inicializar();
	}
	Floresta::~Floresta() { delete pGC; }

	void Floresta::inicializar() {

		carregarMapa("C:/Users/Enzo/HelloWorld/JogoEmSFML/Floresta.tmj");
		criarChao();
		p1 = new Jogador(sf::Vector2f(100, 1400), sf::Vector2f(50.0, 100.0));
		personagens.inserir(p1);
		projeteis.inserir(p1->getAtaque());

		entidades.adicionar(p1);
		entidades.adicionar(p1->getAtaque());

		/*p2 = new Jogador(sf::Vector2f(300, 300), sf::Vector2f(50.0, 100.0));
		personagens.inserir(p2);
		projeteis.inserir(p2->getAtaque());
		entidades.adicionar(p2);
		entidades.adicionar(p2->getAtaque());*/
    
		pGC = new GerenciadorDeColisoes(&obstaculos, &personagens, &projeteis, &consumiveis);
	}


	void Floresta::verificarVivos()
	{
		if (p1 && p2) {
			if (p1->getVivo() && p2->getVivo())
			{
				pGG->camera_segue(p1->getPosicao(), p2->getPosicao());
			}
			else if (!(p1->getVivo()) && p2->getVivo())
			{
				pGG->camera_segue(p2->getPosicao());
			}
			else if (p1->getVivo() && !(p2->getVivo()))
			{
				pGG->camera_segue(p1->getPosicao());
			}
			else
			{
				pGG->fechar_janela(); //TEMPORARIO ENQUANTO NAO TEMOS MENU!!!!!!!!
			}
		}
		else {
			if (p1->getVivo())
				pGG->camera_segue(p1->getPosicao());
			else
				pGG->fechar_janela();
		}

		
		Lista<Personagem>::Iterador<Personagem> itPers(nullptr);  

		for(itPers = personagens.inicio(); itPers != personagens.fim(); itPers++)
		{
			if (!(*itPers)->getVivo())
			{
				entidades.remover(*itPers);
				personagens.remover(*itPers);  
			}
		}
	}

	void Floresta::executar() {
		sf::Clock relogio;
		sf::Time dt;
		sf::RenderWindow* janela = pGG->getJanela();
		Listas::Lista<Entidades::Obstaculos::Obstaculo>::Iterador<Entidades::Obstaculos::Obstaculo> itObs(NULL); 

		if (!janela) {
			std::cerr << "Erro: Janela nao foi inicializada corretamente." << std::endl;
			return;
		}
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

			
			entidades.executar(dt);

			pGC->colidir();						
			janela->clear();
			verificarVivos();
			
			entidades.desenhar();
			pGG->mostrar();
		}
	}
	void Floresta::desenhar() {}
	void Floresta::salvar() {}

	//void criarNinjaGarras() {}
	//void criarNinjaShuriken() {}
	//void criarPlataforma() {}
}