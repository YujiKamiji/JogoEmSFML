#include "Floresta.h"

namespace Fases {
	Floresta::Floresta():
		Fase()
	{
		inicializar();
	}
	Floresta::~Floresta() { delete pGC; }

	void Floresta::inicializar() {
		p1 = new Jogador(sf::Vector2f(100, 375), sf::Vector2f(50.0, 100.0));
		p2 = new Jogador(sf::Vector2f(200, 300), sf::Vector2f(50.0, 100.0));
		Chao* chao1 = new Chao(sf::Vector2f(1800, 500), sf::Vector2f(3600, 60));
		Chao* chao2 = new Chao(sf::Vector2f(1400, 380), sf::Vector2f(1200, 180));

		Chao* chao3 = new Chao(sf::Vector2f(4400, 470), sf::Vector2f(1800, 120));
		NinjaGarras* n1 = new NinjaGarras(sf::Vector2f(1500, 100), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaGarras* n2 = new NinjaGarras(sf::Vector2f(4000, 300), sf::Vector2f(50.0, 100.0), p1, p2);
		NinjaShuriken* ns1 = new NinjaShuriken(sf::Vector2f(400, 300), sf::Vector2f(50.0, 100.0), p1, p2);
		Plataforma* plat1 = new Plataforma(sf::Vector2f(1000, 200), sf::Vector2f(200, 20)); 
		Caixote* caixa1 = new Caixote(sf::Vector2f(1500, 200), sf::Vector2f(70.0, 130.0));
		Espinhos* espinhos1 = new Espinhos(sf::Vector2f(1300, 100), sf::Vector2f(100, 50));
		Shogun* shogun1 = new Shogun(sf::Vector2f(2000, 100), sf::Vector2f(70.0, 130.0), p1, p2);

		Cura* c1 = new Cura(sf::Vector2f(300, 400), sf::Vector2f(50, 50));
		Moeda* m1 = new Moeda(sf::Vector2f(370, 400), sf::Vector2f(50, 50));

		plat1->setMovel(true);

		personagens.inserir(p1);
		personagens.inserir(p2);
		personagens.inserir(n1);
		personagens.inserir(n2);
		personagens.inserir(ns1);
		personagens.inserir(shogun1);
		obstaculos.inserir(chao1);
		obstaculos.inserir(chao2);
		obstaculos.inserir(chao3);
		obstaculos.inserir(plat1);
		obstaculos.inserir(caixa1);
		obstaculos.inserir(espinhos1);
		projeteis.inserir(p1->getAtaque());
		projeteis.inserir(p2->getAtaque()); 
		projeteis.inserir(ns1->getAtaque());
		projeteis.inserir(shogun1->getAtaque());

		consumiveis.inserir(c1);
		consumiveis.inserir(m1);

		entidades.adicionar(p1);
		entidades.adicionar(p1->getAtaque());
		entidades.adicionar(p2); 
		entidades.adicionar(p2->getAtaque()); 
		entidades.adicionar(n1);
		entidades.adicionar(n2);
		entidades.adicionar(ns1);
		entidades.adicionar(ns1->getAtaque());
		entidades.adicionar(chao1);
		entidades.adicionar(chao2);
		entidades.adicionar(chao3);
		entidades.adicionar(plat1);
		entidades.adicionar(caixa1);
		entidades.adicionar(espinhos1);
		entidades.adicionar(shogun1);
		entidades.adicionar(shogun1->getAtaque());
		entidades.adicionar(c1);
		entidades.adicionar(m1);

		pGC = new GerenciadorDeColisoes(&obstaculos, &personagens, &projeteis, &consumiveis);
	}


	void Floresta::verificarVivos()
	{
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
}