#include  "MenuPrincipal.h"
#include "GerenciadorDeEstados.h"

namespace Menus
{
	MenuPrincipal::MenuPrincipal(idEstado ID_ESTADO) :
		Menu(ID_ESTADO)
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
		pGE->removerEstado();
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
		while (pGG->janela_aberta() && pGE->getEstadoAtual() == this)
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
			for (auto it = botoes.begin(); it != botoes.end(); it++)
			{
				(*it)->tratarEvento(evento);
			}	 
			janela->clear();
			desenhar();
			pGG->mostrar();

		}

	}

	void MenuPrincipal::inicializarElementos()
	{
		cout << "MenuPrincipal::inicializarElementos()" << endl;
		adicionarBotao(new Botao("Fase 1: Floresta", sf::Vector2f(640, 360), sf::Vector2f(300, 100), std::bind(&MenuPrincipal::irParaFlorestaSingle, this)));

	}

	

	void MenuPrincipal::adicionarBotao(Botao* botao)
	{
		botoes.push_back(botao);
	}

	void MenuPrincipal::desenhar()
	{
		pGG->desenhar(&textoPrincipal);
		for (auto it = botoes.begin(); it != botoes.end(); it++)
		{
			(*it)->desenhar();
		}
	}

	void MenuPrincipal::executar(sf::Time deltaTime)
	{
		cout << "MenuPrincipal::executar()" << endl;
	}

}