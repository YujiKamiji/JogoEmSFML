#include "Floresta.h"

namespace Fases {
	Floresta::Floresta(bool m):
		Fase(m), finalFase(11700.f)
	{
		inicializar();
	}
	Floresta::~Floresta() { delete pGC; }

	void Floresta::inicializar() {

		carregarMapa("Floresta.tmj");
		criarChao();
		criarJogadores();
		criarNinjaGarras();
		criarNinjaShuriken();
		criarPlataforma();
		criarMoeda();
		criarCura();
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

	void Floresta::criarNinjaGarras() {
		NinjaGarras* ng1 = new NinjaGarras(sf::Vector2f(1000, 1000), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng2 = new NinjaGarras(sf::Vector2f(4200, 800), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng3 = new NinjaGarras(sf::Vector2f(8000, 600), sf::Vector2f(50.0, 100.0), p1, p2);

		entidades.adicionar(ng1);
		entidades.adicionar(ng2);
		entidades.adicionar(ng3);

		pGC->incluirPersonagem(ng1);
		pGC->incluirPersonagem(ng2);
		pGC->incluirPersonagem(ng3);
	}

	void Floresta::criarNinjaShuriken() {
		NinjaShuriken* ns1 = new NinjaShuriken(sf::Vector2f(1200, 1000), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaShuriken* ns2 = new NinjaShuriken(sf::Vector2f(5000, 600), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaShuriken* ns3 = new NinjaShuriken(sf::Vector2f(9000, 500), sf::Vector2f(50.0, 100.0), p1, p2);

		entidades.adicionar(ns1);
		entidades.adicionar(ns1->getAtaque());
		entidades.adicionar(ns2);
		entidades.adicionar(ns2->getAtaque());
		entidades.adicionar(ns3);
		entidades.adicionar(ns3->getAtaque());

		pGC->incluirPersonagem(ns1);
		pGC->incluirPersonagem(ns2);
		pGC->incluirPersonagem(ns3);

		pGC->incluirProjetil(ns1->getAtaque());
		pGC->incluirProjetil(ns2->getAtaque());
		pGC->incluirProjetil(ns3->getAtaque());
	}

	void Floresta::criarPlataforma() {}
	void Floresta::criarMoeda() {}
	void Floresta::criarCura() {}
}