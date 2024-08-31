#include "Castelo.h"

namespace Fases {
	Castelo::Castelo(bool m):
	Fase(m) 
	{
		inicializar();
	}
	Castelo::~Castelo() { delete pGC; }

	void Castelo::inicializar() {
		carregarMapa("Castelo.tmj");
		criarChao();
		criarJogadores();
		criarNinjaGarras();
		criarShogun();
		criarPlataforma();
		criarEspinho();
		criarMoeda();
		criarCura();
	}

	void Castelo::executar() {
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

	void Castelo::desenhar() {}
	void Castelo::salvar() {}

	void Castelo::criarNinjaGarras() {
		NinjaGarras* ng1 = new NinjaGarras(sf::Vector2f(100, 2200), sf::Vector2f(50.0, 100.0), p1, p2);		
		NinjaGarras* ng2 = new NinjaGarras(sf::Vector2f(1000, 2200), sf::Vector2f(50.0, 100.0), p1, p2);		
		NinjaGarras* ng3 = new NinjaGarras(sf::Vector2f(3500, 1200), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng4 = new NinjaGarras(sf::Vector2f(6300, 600), sf::Vector2f(50.0, 100.0), p1, p2);
		
		entidades.adicionar(ng1);		
		entidades.adicionar(ng2);
		entidades.adicionar(ng3);
		entidades.adicionar(ng4);		
		
		pGC->incluirPersonagem(ng1);		
		pGC->incluirPersonagem(ng2);
		pGC->incluirPersonagem(ng3);
		pGC->incluirPersonagem(ng4);
		
		int rng = rand() % 4;
		if (rng == 0) {
			NinjaGarras* ng5 = new NinjaGarras(sf::Vector2f(800, 2900), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ng5);
			pGC->incluirPersonagem(ng5);
		}

		rng = rand() % 3;
		if(rng == 0) {
			NinjaGarras* ng6 = new NinjaGarras(sf::Vector2f(1000, 1800), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ng6);
			pGC->incluirPersonagem(ng6);
		}

		rng = rand() % 2;
		if(rng) {
			NinjaGarras* ng7 = new NinjaGarras(sf::Vector2f(6200, 1100), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ng7);
			pGC->incluirPersonagem(ng7);
		}
	}
	void Castelo::criarShogun() {
		Shogun* sho1 = new Shogun(sf::Vector2f(1800, 3400), sf::Vector2f(75.0, 125.0), p1, p2);
		Shogun* sho2 = new Shogun(sf::Vector2f(3000, 1300), sf::Vector2f(75.0, 125.0), p1, p2);
		Shogun* sho3 = new Shogun(sf::Vector2f(6700, 1100), sf::Vector2f(75.0, 125.0), p1, p2);

		entidades.adicionar(sho1);
		entidades.adicionar(sho1->getAtaque());
		entidades.adicionar(sho2);
		entidades.adicionar(sho2->getAtaque());
		entidades.adicionar(sho3);
		entidades.adicionar(sho3->getAtaque());

		pGC->incluirPersonagem(sho1);
		pGC->incluirPersonagem(sho2);
		pGC->incluirPersonagem(sho3);

		pGC->incluirProjetil(sho1->getAtaque());
		pGC->incluirProjetil(sho2->getAtaque());
		pGC->incluirProjetil(sho3->getAtaque());

		int rng = rand() % 2;
		if (rng) {
			Shogun* sho4 = new Shogun(sf::Vector2f(7400, 1100), sf::Vector2f(75.0, 125.0), p1, p2);
			entidades.adicionar(sho4);
			entidades.adicionar(sho4->getAtaque());
			pGC->incluirPersonagem(sho4);
			pGC->incluirProjetil(sho4->getAtaque());
		}
		
		rng = rand() % 10;
		if (rng == 0) {
			Shogun* sho5 = new Shogun(sf::Vector2f(4800, 1900), sf::Vector2f(75.0, 125.0), p1, p2);
			entidades.adicionar(sho5);
			entidades.adicionar(sho5->getAtaque());
			pGC->incluirPersonagem(sho5);
			pGC->incluirProjetil(sho5->getAtaque());
		}

		rng = rand() % 10;
		if (rng == 0) {
			Shogun* sho6 = new Shogun(sf::Vector2f(4200, 1900), sf::Vector2f(75.0, 125.0), p1, p2);
			entidades.adicionar(sho6);
			entidades.adicionar(sho6->getAtaque());
			pGC->incluirPersonagem(sho6);
			pGC->incluirProjetil(sho6->getAtaque());
		}
	}

	void Castelo::criarPlataforma() {
		Plataforma* plat1 = new Plataforma(sf::Vector2f(2400, 3400), sf::Vector2f(300.0, 50.0));
		Plataforma* plat2 = new Plataforma(sf::Vector2f(2900, 3000), sf::Vector2f(300.0, 50.0));
		Plataforma* plat3 = new Plataforma(sf::Vector2f(3900, 1400), sf::Vector2f(300.0, 50.0));
		Plataforma* plat4 = new Plataforma(sf::Vector2f(4200, 1000), sf::Vector2f(300.0, 50.0));
		Plataforma* plat5 = new Plataforma(sf::Vector2f(4700, 1500), sf::Vector2f(300.0, 50.0));
		Plataforma* plat6 = new Plataforma(sf::Vector2f(5200, 1300), sf::Vector2f(300.0, 50.0));

		plat1->setMovel(true);
		plat2->setMovel(true);
		plat3->setMovel(true);
		plat4->setMovel(false);
		plat5->setMovel(true);
		plat6->setMovel(false);
		

		entidades.adicionar(plat1);
		entidades.adicionar(plat2);
		entidades.adicionar(plat3);
		entidades.adicionar(plat4);
		entidades.adicionar(plat5);
		entidades.adicionar(plat6);

		pGC->incluirObstaculo(plat1);
		pGC->incluirObstaculo(plat2);
		pGC->incluirObstaculo(plat3);
		pGC->incluirObstaculo(plat4);
		pGC->incluirObstaculo(plat5);
		pGC->incluirObstaculo(plat6);
	}

	void Castelo::criarEspinho() {
		Espinhos* esp1 = new Espinhos(sf::Vector2f(400, 3400), sf::Vector2f(100.0, 50.0));
		Espinhos* esp2 = new Espinhos(sf::Vector2f(2100, 2200), sf::Vector2f(100.0, 50.0));
		Espinhos* esp3 = new Espinhos(sf::Vector2f(2200, 2200), sf::Vector2f(100.0, 50.0));

		entidades.adicionar(esp1);
		entidades.adicionar(esp2);
		entidades.adicionar(esp3);

		pGC->incluirObstaculo(esp1);
		pGC->incluirObstaculo(esp2);
		pGC->incluirObstaculo(esp3);
	}
	void Castelo::criarMoeda() {}
	void Castelo::criarCura() {}
}