#include "Castelo.h"

namespace Fases {
	Castelo::Castelo(bool m):
	Fase(m) 
	{
		inicializar();
		corpo.setSize(sf::Vector2f(8000.f, 4000.f));
		corpo.setOrigin(sf::Vector2f(50.f, 50.f));
		textura = pGG->carregarTextura("Sprites/Castelo.png");
		corpo.setTexture(textura);
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
			desenhar();
			pGG->mostrar();
		}
	}

	void Castelo::desenhar() {
		pGG->desenhar(&corpo);
	}
	void Castelo::salvar() {}

	void Castelo::criarNinjaGarras() {
		NinjaGarras* ng1 = new NinjaGarras(sf::Vector2f(100, 2200), sf::Vector2f(50.0, 100.0), p1, p2);		
		NinjaGarras* ng2 = new NinjaGarras(sf::Vector2f(1000, 2200), sf::Vector2f(50.0, 100.0), p1, p2);		
		NinjaGarras* ng3 = new NinjaGarras(sf::Vector2f(3100, 1000), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* ng4 = new NinjaGarras(sf::Vector2f(6300, 200), sf::Vector2f(50.0, 100.0), p1, p2);
		
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
			NinjaGarras* ng6 = new NinjaGarras(sf::Vector2f(6500, 200), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ng6);
			pGC->incluirPersonagem(ng6);
		}

		rng = rand() % 2;
		if(rng) {
			NinjaGarras* ng7 = new NinjaGarras(sf::Vector2f(7800, 1100), sf::Vector2f(50.0, 100.0), p1, p2);
			entidades.adicionar(ng7);
			pGC->incluirPersonagem(ng7);
		}
	}
	void Castelo::criarShogun() {
		Shogun* sho1 = new Shogun(sf::Vector2f(1800, 3400), sf::Vector2f(75.0, 125.0), p1, p2);
		Shogun* sho2 = new Shogun(sf::Vector2f(3000, 1300), sf::Vector2f(75.0, 125.0), p1, p2);
		Shogun* sho3 = new Shogun(sf::Vector2f(6800, 1100), sf::Vector2f(75.0, 125.0), p1, p2);
		Shogun* sho4 = new Shogun(sf::Vector2f(7300, 1100), sf::Vector2f(75.0, 125.0), p1, p2);

		entidades.adicionar(sho1);
		entidades.adicionar(sho1->getAtaque());
		entidades.adicionar(sho2);
		entidades.adicionar(sho2->getAtaque());
		entidades.adicionar(sho3);
		entidades.adicionar(sho3->getAtaque());
		entidades.adicionar(sho4);
		entidades.adicionar(sho4->getAtaque());

		pGC->incluirPersonagem(sho1);
		pGC->incluirPersonagem(sho2);
		pGC->incluirPersonagem(sho3);
		pGC->incluirPersonagem(sho4);

		pGC->incluirProjetil(sho1->getAtaque());
		pGC->incluirProjetil(sho2->getAtaque());
		pGC->incluirProjetil(sho3->getAtaque());
		pGC->incluirProjetil(sho4->getAtaque());
		
		int rng = rand() % 10;
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
		Plataforma* plat3 = new Plataforma(sf::Vector2f(3900, 1100), sf::Vector2f(300.0, 50.0));
		Plataforma* plat4 = new Plataforma(sf::Vector2f(4700, 1000), sf::Vector2f(300.0, 50.0));

		plat1->setMovel(true);
		plat2->setMovel(true);
		plat3->setMovel(true);
		plat4->setMovel(true);
		
		entidades.adicionar(plat1);
		entidades.adicionar(plat2);
		entidades.adicionar(plat3);
		entidades.adicionar(plat4);

		pGC->incluirObstaculo(plat1);
		pGC->incluirObstaculo(plat2);
		pGC->incluirObstaculo(plat3);
		pGC->incluirObstaculo(plat4);

		int rng = rand() % 4;
		if (rng == 0) {
			Plataforma* plat5 = new Plataforma(sf::Vector2f(3200, 2400), sf::Vector2f(300.0, 50.0));
			plat5->setMovel(true);
			entidades.adicionar(plat5);
			pGC->incluirObstaculo(plat5);
		}

		rng = rand() % 2;
		if (rng) {
			Plataforma* plat6 = new Plataforma(sf::Vector2f(2900, 1150), sf::Vector2f(700.0, 50.0));
			plat6->setMovel(false);
			entidades.adicionar(plat6);
			pGC->incluirObstaculo(plat6);
		}

		rng = rand() % 2;
		if (rng) {
			Plataforma* plat7 = new Plataforma(sf::Vector2f(4300, 700), sf::Vector2f(300.0, 50.0));
			plat7->setMovel(false);
			entidades.adicionar(plat7);
			pGC->incluirObstaculo(plat7);
		}
	}

	void Castelo::criarEspinho() {
		Espinhos* esp1 = new Espinhos(sf::Vector2f(600, 3400), sf::Vector2f(100.0, 50.0));
		Espinhos* esp2 = new Espinhos(sf::Vector2f(1200, 3400), sf::Vector2f(100.0, 50.0));
		Espinhos* esp3 = new Espinhos(sf::Vector2f(2150, 2200), sf::Vector2f(200.0, 50.0));
		Espinhos* esp4 = new Espinhos(sf::Vector2f(3500, 1100), sf::Vector2f(100.0, 50.0));

		entidades.adicionar(esp1);
		entidades.adicionar(esp2);
		entidades.adicionar(esp3);
		entidades.adicionar(esp4);

		pGC->incluirObstaculo(esp1);
		pGC->incluirObstaculo(esp2);
		pGC->incluirObstaculo(esp3);
		pGC->incluirObstaculo(esp4);

		int rng = rand() % 4;
		if (rng == 0) {
			Espinhos* esp5 = new Espinhos(sf::Vector2f(3300, 2600), sf::Vector2f(100.0, 50.0));
			entidades.adicionar(esp5);
			pGC->incluirObstaculo(esp5);
		}

		rng = rand() % 2;
		if (rng) {
			Espinhos* esp6 = new Espinhos(sf::Vector2f(1850, 1500), sf::Vector2f(100.0, 50.0));
			entidades.adicionar(esp6);
			pGC->incluirObstaculo(esp6);
		}
	}

	void Castelo::criarMoeda() {
		Moeda* m1 = new Moeda(sf::Vector2f(600, 1600), sf::Vector2f(33.3, 33.3));
		Moeda* m2 = new Moeda(sf::Vector2f(700, 1700), sf::Vector2f(33.3, 33.3));
		Moeda* m3 = new Moeda(sf::Vector2f(300, 2000), sf::Vector2f(33.3, 33.3));
		Moeda* m4 = new Moeda(sf::Vector2f(200, 2100), sf::Vector2f(33.3, 33.3));
		Moeda* m5 = new Moeda(sf::Vector2f(600, 2700), sf::Vector2f(33.3, 33.3));
		Moeda* m6 = new Moeda(sf::Vector2f(2400, 2900), sf::Vector2f(33.3, 33.3));
		Moeda* m7 = new Moeda(sf::Vector2f(1200, 2100), sf::Vector2f(33.3, 33.3));
		Moeda* m8 = new Moeda(sf::Vector2f(3900, 500), sf::Vector2f(33.3, 33.3));
		Moeda* m9 = new Moeda(sf::Vector2f(5100, 500), sf::Vector2f(33.3, 33.3));
		Moeda* m10 = new Moeda(sf::Vector2f(5700, 900), sf::Vector2f(33.3, 33.3));
		Moeda* m11 = new Moeda(sf::Vector2f(5800, 1000), sf::Vector2f(33.3, 33.3));
		Moeda* m12 = new Moeda(sf::Vector2f(5900, 900), sf::Vector2f(33.3, 33.3));

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
		entidades.adicionar(m11);
		entidades.adicionar(m12);

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
		pGC->incluirConsumivel(m11);
		pGC->incluirConsumivel(m12);
	}
	void Castelo::criarCura() {
		Cura* c1 = new Cura(sf::Vector2f(3300, 2500), sf::Vector2f(50.0, 50.0));
		Cura* c2 = new Cura(sf::Vector2f(5600, 1100), sf::Vector2f(50.0, 50.0));
		Cura* c3 = new Cura(sf::Vector2f(6000, 1100), sf::Vector2f(50.0, 50.0));

		entidades.adicionar(c1);
		entidades.adicionar(c2);
		entidades.adicionar(c3);

		pGC->incluirConsumivel(c1);
		pGC->incluirConsumivel(c2);
		pGC->incluirConsumivel(c3);
	}
}