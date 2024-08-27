#include "Floresta.h"

namespace Fases {
	Floresta::Floresta():
		Fase()
	{
		inicializar();
	}
	Floresta::~Floresta() { delete pGC; }

	void Floresta::inicializar() {
		p1 = new Jogador(sf::Vector2f(100, 100), sf::Vector2f(50.0, 100.0));
		p2 = new Jogador(sf::Vector2f(200, 100), sf::Vector2f(50.0, 100.0));
		Chao* chao = new Chao(sf::Vector2f(1280 / 2, 500), sf::Vector2f(1200, 30));

		personagens.inserir(p1);
		personagens.inserir(p2);
		obstaculos.inserir(chao);

		entidades.adicionar(p1);
		entidades.adicionar(p1->getAtaque());
		entidades.adicionar(p2);
		entidades.adicionar(p2->getAtaque());
		entidades.adicionar(chao);

		pGC = new GerenciadorDeColisoes(&obstaculos, &personagens);
	}

	void Floresta::executar() {
		sf::Clock relogio;
		sf::Time dt;
		sf::RenderWindow* janela = pGG->getJanela();

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
			pGG->camera_segue(p1->getPosicao(), p2->getPosicao());

			entidades.desenhar();
			pGG->mostrar();
		}
	}
	void Floresta::desenhar() {}
	void Floresta::salvar() {}
}