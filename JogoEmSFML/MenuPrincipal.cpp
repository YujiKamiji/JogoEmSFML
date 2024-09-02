/*Imagem de fundo retirada de um site de hospedagem de wallpapers*/
/*Link do site: https://4kwallpapers.com/graphics-cgi/samurai-pixel-art-15196.html */


#include  "MenuPrincipal.h"
#include "GerenciadorDeEstados.h"

namespace Menus
{
	MenuPrincipal::MenuPrincipal(idEstado ID_ESTADO) :
		Menu(ID_ESTADO, "Ninja+Invasion"), botoes()
	{
		textura = pGG->carregarTextura("Assets/Sprites/Fundo1.jpg");
		setPosicaoTexto(sf::operator*(sf::Vector2f(640, 100), 1.f));
		fundo.setOrigin(sf::operator*(sf::Vector2f(1280, 720), 0.5f));
		fundo.setTexture(textura);
		fundo.setSize(sf::Vector2f(1280, 720));
		fundo.setPosition(sf::operator*(sf::Vector2f(1280, 720), 0.5f));
	}

	MenuPrincipal::~MenuPrincipal() 
	{
		for (auto it = botoes.begin(); it != botoes.end(); it++)
		{
			delete* it;
		}
		botoes.clear();
	}


	void MenuPrincipal::irParaMenuRanking()
	{
		ativo = false;
		pGE->removerEstado(MENU_RANKING);
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

	void MenuPrincipal::sair()
	{
		pGG->fechar_janela();
	}


	void MenuPrincipal::executarEstado()
	{
		inicializarElementos();	
		ativo = true;
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

		adicionarBotao(new Botao("Fase 1: Floresta", sf::Vector2f(640, 260), sf::Vector2f(300, 100), std::bind(&MenuPrincipal::irParaFlorestaSingle, this)));
		adicionarBotao(new Botao("Fase 2: Castelo", sf::Vector2f(640, 380), sf::Vector2f(300, 100), std::bind(&MenuPrincipal::irParaCasteloSingle, this))); 
		adicionarBotao(new Botao("Fase 1: Floresta - Multiplayer", sf::Vector2f(640, 500), sf::Vector2f(550, 100), std::bind(&MenuPrincipal::irParaFlorestaMulti, this)));
		adicionarBotao(new Botao("Fase 2: Castelo - Multiplayer", sf::Vector2f(640, 620), sf::Vector2f(545, 100), std::bind(&MenuPrincipal::irParaCasteloMulti, this)));
		adicionarBotao(new Botao("X", sf::Vector2f(50, 50), sf::Vector2f(50, 50), std::bind(&MenuPrincipal::sair, this)));
		adicionarBotao(new Botao("Ranking", sf::Vector2f(100, 650), sf::Vector2f(130, 50), std::bind(&MenuPrincipal::irParaMenuRanking, this)));

		pGG->reiniciarJanela();
	}

	

	void MenuPrincipal::adicionarBotao(Botao* botao)
	{
		botoes.push_back(botao);
	}

	void MenuPrincipal::desenhar() 
	{
		pGG->desenhar(&fundo);
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