#include "Floresta.h"
#include "GerenciadorDeEstados.h"

namespace Fases {
	Floresta::Floresta(bool m, idEstado ID_ESTADO):
		Fase(m, ID_ESTADO), finalFase(1100.f)
	{
		corpo.setSize(sf::Vector2f(12000.f, 2000.f));
		corpo.setOrigin(sf::Vector2f(50.f, 50.f));
		textura = pGG->carregarTextura("Sprites/Floresta.png");
		corpo.setTexture(textura);
	}
	Floresta::~Floresta() { pGC->limparListas(); }

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

	bool Floresta::verificarFinalFase() {
		if (p1->getPosicao().x > finalFase && p2->getPosicao().x > finalFase) {
			pGE->removerEstado();
			//pGE->adicionarEstado(CASTELO_SINGLE);
			return false;
		}
		else
			return true;
	}

	void Floresta::executarEstado() {
		inicializar();
		sf::Clock relogio;
		sf::Time dt;
		sf::RenderWindow* janela = pGG->getJanela();
		Listas::Lista<Entidades::Obstaculos::Obstaculo>::Iterador<Entidades::Obstaculos::Obstaculo> itObs(NULL); 

		if (!janela) {
			std::cerr << "Erro: Janela nao foi inicializada corretamente." << std::endl;
			return;
		}
		while (pGG->janela_aberta() && verificarFinalFase() && verificarVivos())
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
			//verificarFinalFase();
			
			entidades.executar(dt);

			pGC->colidir();						
			janela->clear();
			//verificarVivos();
			
			entidades.desenhar();
			desenhar();
			pGG->mostrar();
		
		}
	}
	void Floresta::desenhar() {
		pGG->desenhar(&corpo);
	}
	void Floresta::salvar() {}

	void Floresta::criarNinjaGarras() {
		NinjaGarras* ng1 = new NinjaGarras(sf::Vector2f(2200, 900), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng2 = new NinjaGarras(sf::Vector2f(5700, 1000), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng3 = new NinjaGarras(sf::Vector2f(7900, 1000), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng4 = new NinjaGarras(sf::Vector2f(9200, 700), sf::Vector2f(50.0, 100.0), p1, p2);

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
			NinjaGarras* ng5 = new NinjaGarras(sf::Vector2f(4600, 900), sf::Vector2f(50.0, 100.0), p1, p2);
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
		NinjaShuriken* ns3 = new NinjaShuriken(sf::Vector2f(9400, 100), sf::Vector2f(50.0, 100.0), p1, p2);
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
			NinjaShuriken* ns6 = new NinjaShuriken(sf::Vector2f(4500, 900), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ns6);
			entidades.adicionar(ns6->getAtaque());
			pGC->incluirPersonagem(ns6);
			pGC->incluirProjetil(ns6->getAtaque());
		}

		rng = rand() % 3;
		if (rng) {
			NinjaShuriken* ns7 = new NinjaShuriken(sf::Vector2f(9600, 300), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ns7);
			entidades.adicionar(ns7->getAtaque());
			pGC->incluirPersonagem(ns7);
			pGC->incluirProjetil(ns7->getAtaque());
		}
	}

	void Floresta::criarPlataforma() {
		Plataforma* plat1 = new Plataforma(sf::Vector2f(900, 1200), sf::Vector2f(300.0, 50.0));		
		Plataforma* plat2 = new Plataforma(sf::Vector2f(4500, 1000), sf::Vector2f(700.0, 50.0));
		Plataforma* plat3 = new Plataforma(sf::Vector2f(8200, 1000), sf::Vector2f(300.0, 50.0));
		Plataforma* plat4 = new Plataforma(sf::Vector2f(9700, 600), sf::Vector2f(700.0, 50.0));

		plat1->setMovel(false);		
		plat2->setMovel(false);		
		plat3->setMovel(false);
		plat4->setMovel(true);

		entidades.adicionar(plat1);		
		entidades.adicionar(plat2);		
		entidades.adicionar(plat3);
		entidades.adicionar(plat4);

		pGC->incluirObstaculo(plat1);		
		pGC->incluirObstaculo(plat2);		
		pGC->incluirObstaculo(plat3);
		pGC->incluirObstaculo(plat4);

		int rng = rand() % 2;
		if (rng) {
			Plataforma* plat5 = new Plataforma(sf::Vector2f(2400, 600), sf::Vector2f(300.0, 50.0));
			plat5->setMovel(false);
			entidades.adicionar(plat5);
			pGC->incluirObstaculo(plat5);
		}

		rng = rand() % 2;
		if (rng) {
			Plataforma* plat6 = new Plataforma(sf::Vector2f(5400, 900), sf::Vector2f(300.0, 50.0));
			plat6->setMovel(true);
			entidades.adicionar(plat6);
			pGC->incluirObstaculo(plat6);
		}
	}

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

	void Floresta::criarMoeda() {
		Moeda* m1 = new Moeda(sf::Vector2f(800, 1100), sf::Vector2f(33.3, 33.3));
		Moeda* m2 = new Moeda(sf::Vector2f(1000, 1100), sf::Vector2f(33.3, 33.3));
		Moeda* m3 = new Moeda(sf::Vector2f(2400, 500), sf::Vector2f(33.3, 33.3));
		Moeda* m4 = new Moeda(sf::Vector2f(3400, 400), sf::Vector2f(33.3, 33.3));
		Moeda* m5 = new Moeda(sf::Vector2f(3500, 500), sf::Vector2f(33.3, 33.3));
		Moeda* m6 = new Moeda(sf::Vector2f(6800, 600), sf::Vector2f(33.3, 33.3));
		Moeda* m7 = new Moeda(sf::Vector2f(7600, 600), sf::Vector2f(33.3, 33.3));
		Moeda* m8 = new Moeda(sf::Vector2f(7700, 700), sf::Vector2f(33.3, 33.3));
		Moeda* m9 = new Moeda(sf::Vector2f(8200, 900), sf::Vector2f(33.3, 33.3));
		Moeda* m10 = new Moeda(sf::Vector2f(10300, 700), sf::Vector2f(33.3, 33.3));
		
		entidades.adicionar(m1);
		entidades.adicionar(m2);
		entidades.adicionar(m3);
		entidades.adicionar(m4);
		entidades.adicionar(m5);
		entidades.adicionar(m6);
		entidades.adicionar(m7);
		entidades.adicionar(m8);
		entidades.adicionar(m9);
		entidades.adicionar(m10);

		pGC->incluirConsumivel(m1);
		pGC->incluirConsumivel(m2);
		pGC->incluirConsumivel(m3);
		pGC->incluirConsumivel(m4);
		pGC->incluirConsumivel(m5);
		pGC->incluirConsumivel(m6);
		pGC->incluirConsumivel(m7);
		pGC->incluirConsumivel(m8);
		pGC->incluirConsumivel(m9);
		pGC->incluirConsumivel(m10);
	}
	void Floresta::criarCura() {
		Cura* c1 = new Cura(sf::Vector2f(4500, 1200), sf::Vector2f(50.0, 50.0));
		Cura* c2 = new Cura(sf::Vector2f(8400, 1100), sf::Vector2f(50.0, 50.0));

		entidades.adicionar(c1);
		entidades.adicionar(c2);

		pGC->incluirConsumivel(c1);
		pGC->incluirConsumivel(c2);
	}
}