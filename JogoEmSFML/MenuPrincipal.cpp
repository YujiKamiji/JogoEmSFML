#include  "MenuPrincipal.h"
#include "GerenciadorDeEstados.h"

namespace Menus
{
	MenuPrincipal::MenuPrincipal(idEstado ID_ESTADO) :
		Menu(ID_ESTADO), botoes()
	{
		
	}

	MenuPrincipal::~MenuPrincipal() 
	{
		for (auto it = botoes.begin(); it != botoes.end(); it++)
		{
			delete* it;
		}
		botoes.clear();
	}

	void MenuPrincipal::irParaFlorestaSingle()
	{
		ativo = false;
		
		pGE->removerEstado(FLORESTA_SINGLE);	
		
	}
	void MenuPrincipal::irParaFlorestaMulti()
	{
		ativo = false;
		pGE->removerEstado(FLORESTA_MULTI);
	}

	void MenuPrincipal::irParaCasteloSingle()
	{
		ativo = false;
		pGE->removerEstado(CASTELO_SINGLE);
	}

	void MenuPrincipal::irParaCasteloMulti()
	{
		ativo = false;
		pGE->removerEstado(CASTELO_MULTI);
	}


	void MenuPrincipal::executarEstado()
	{
		inicializarElementos();	
		ativo = true;
		cout << "MenuPrincipal::executarEstado()" << endl;
		sf::RenderWindow* janela = pGG->getJanela();

		if (!janela) {
			std::cerr << "Erro: Janela nao foi inicializada corretamente." << std::endl;
			return;
		}
		while (pGG->janela_aberta() && ativo)
		{
			
			sf::Event evento;
			while (janela->pollEvent(evento))
			{
				if (evento.type == sf::Event::Closed)
				{
					janela->close();
				}
			}
			//iterar na lista de botoes e verificar se algum foi clicado
			for (int i = 0; i < botoes.size(); i++)
			{
				if(botoes[i])
					botoes[i]->tratarEvento(evento);
				
			}	
			janela->clear();
			desenhar();
			pGG->mostrar();

		}

	}

	void MenuPrincipal::inicializarElementos()
	{
		cout << "MenuPrincipal::inicializarElementos()" << endl;
		adicionarBotao(new Botao("Fase 1: Floresta", sf::Vector2f(640, 260), sf::Vector2f(300, 100), std::bind(&MenuPrincipal::irParaFlorestaSingle, this)));
		adicionarBotao(new Botao("Fase 2: Castelo", sf::Vector2f(640, 380), sf::Vector2f(300, 100), std::bind(&MenuPrincipal::irParaCasteloSingle, this))); 
		adicionarBotao(new Botao("Fase 1: Floresta - Multiplayer", sf::Vector2f(640, 500), sf::Vector2f(500, 100), std::bind(&MenuPrincipal::irParaFlorestaMulti, this)));
		adicionarBotao(new Botao("Fase 2: Castelo - Multiplayer", sf::Vector2f(640, 620), sf::Vector2f(500, 100), std::bind(&MenuPrincipal::irParaCasteloMulti, this)));
		
		pGG->reiniciarJanela();
	}

	

	void MenuPrincipal::adicionarBotao(Botao* botao)
	{
		botoes.push_back(botao);
	}

	void MenuPrincipal::desenhar() 
	{
		pGG->desenhar(&textoPrincipal); 
		for (int i = 0; i < botoes.size(); i++)
		{
			if (botoes[i])
				botoes[i]->desenhar();

		}
	}

	void MenuPrincipal::executar(sf::Time deltaTime)
	{
		cout << "MenuPrincipal::executar()" << endl;
	}

}