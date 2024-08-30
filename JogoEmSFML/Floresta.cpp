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

	//void criarNinjaGarras() {}
	//void criarNinjaShuriken() {}
	//void criarPlataforma() {}
}