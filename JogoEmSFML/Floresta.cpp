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
		criarCaixote();
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
		NinjaGarras* ng1 = new NinjaGarras(sf::Vector2f(2200, 900), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng2 = new NinjaGarras(sf::Vector2f(5700, 1000), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng3 = new NinjaGarras(sf::Vector2f(7900, 1000), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng4 = new NinjaGarras(sf::Vector2f(8800, 1100), sf::Vector2f(50.0, 100.0), p1, p2);

		entidades.adicionar(ng1);
		entidades.adicionar(ng2);
		entidades.adicionar(ng3);
		entidades.adicionar(ng4);

		pGC->incluirPersonagem(ng1);
		pGC->incluirPersonagem(ng2);
		pGC->incluirPersonagem(ng3);
		pGC->incluirPersonagem(ng4);

		int rng = rand() % 2;
		if (rng) {
			NinjaGarras* ng5 = new NinjaGarras(sf::Vector2f(4600, 1200), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ng5);
			pGC->incluirPersonagem(ng5);
		}

		rng = rand() % 2;
		if (rng) {
			NinjaGarras* ng6 = new NinjaGarras(sf::Vector2f(11400, 600), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ng6);
			pGC->incluirPersonagem(ng6);
		}

	}

	void Floresta::criarNinjaShuriken() {
		NinjaShuriken* ns1 = new NinjaShuriken(sf::Vector2f(2700, 800), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaShuriken* ns2 = new NinjaShuriken(sf::Vector2f(6200, 800), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaShuriken* ns3 = new NinjaShuriken(sf::Vector2f(9300, 700), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaShuriken* ns4 = new NinjaShuriken(sf::Vector2f(11200, 700), sf::Vector2f(50.0, 100.0), p1, p2);

		entidades.adicionar(ns1);
		entidades.adicionar(ns1->getAtaque());
		entidades.adicionar(ns2);
		entidades.adicionar(ns2->getAtaque());
		entidades.adicionar(ns3);
		entidades.adicionar(ns3->getAtaque());
		entidades.adicionar(ns4);
		entidades.adicionar(ns4->getAtaque());

		pGC->incluirPersonagem(ns1);
		pGC->incluirPersonagem(ns2);
		pGC->incluirPersonagem(ns3);
		pGC->incluirPersonagem(ns4);

		pGC->incluirProjetil(ns1->getAtaque());
		pGC->incluirProjetil(ns2->getAtaque());
		pGC->incluirProjetil(ns3->getAtaque());
		pGC->incluirProjetil(ns4->getAtaque());


		int rng = rand() % 2;
		if (rng) {
			NinjaShuriken* ns5 = new NinjaShuriken(sf::Vector2f(1300, 1100), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ns5);
			entidades.adicionar(ns5->getAtaque());
			pGC->incluirPersonagem(ns5);
			pGC->incluirProjetil(ns5->getAtaque());
		}

		rng = rand() % 3;
		if (rng == 0) {
			NinjaShuriken* ns6 = new NinjaShuriken(sf::Vector2f(5000, 1100), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ns6);
			entidades.adicionar(ns6->getAtaque());
			pGC->incluirPersonagem(ns6);
			pGC->incluirProjetil(ns6->getAtaque());
		}

		rng = rand() % 3;
		if (rng) {
			NinjaShuriken* ns7 = new NinjaShuriken(sf::Vector2f(9500, 700), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ns7);
			entidades.adicionar(ns7->getAtaque());
			pGC->incluirPersonagem(ns7);
			pGC->incluirProjetil(ns7->getAtaque());
		}
	}

	void Floresta::criarPlataforma() {}

	void Floresta::criarCaixote() {
		Caixote* cx1 = new Caixote(sf::Vector2f(3050, 750), sf::Vector2f(200.0, 200.0));
		Caixote* cx2 = new Caixote(sf::Vector2f(3000, 600), sf::Vector2f(100.0, 100.0));
		Caixote* cx3 = new Caixote(sf::Vector2f(6000, 800), sf::Vector2f(200.0, 100.0));
		
		entidades.adicionar(cx1);
		entidades.adicionar(cx2);
		entidades.adicionar(cx3);

		pGC->incluirObstaculo(cx1);
		pGC->incluirObstaculo(cx2);
		pGC->incluirObstaculo(cx3);
		

		int rng = rand() % 3;
		if (rng == 0) {
			Caixote* cx4 = new Caixote(sf::Vector2f(5900, 700), sf::Vector2f(100.0, 100.0));
			entidades.adicionar(cx4);
			pGC->incluirObstaculo(cx4);
		}

		rng = rand() % 4;
		if (rng == 0) {
			Caixote* cx5 = new Caixote(sf::Vector2f(7550, 950), sf::Vector2f(200.0, 200.0));
			entidades.adicionar(cx5);
			pGC->incluirObstaculo(cx5);
		}

		rng = rand() % 2;
		if (rng) {
			Caixote* cx6 = new Caixote(sf::Vector2f(8500, 1100), sf::Vector2f(100.0, 100.0));
			Caixote* cx7 = new Caixote(sf::Vector2f(9100, 700), sf::Vector2f(100.0, 100.0));

			entidades.adicionar(cx6);
			entidades.adicionar(cx7);

			pGC->incluirObstaculo(cx6);
			pGC->incluirObstaculo(cx7);
		}
	}

	void Floresta::criarMoeda() {}
	void Floresta::criarCura() {}
}