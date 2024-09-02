#include "MenuRanking.h"
#include "GerenciadorDeEstados.h"

namespace Menus
{
	int MenuRanking::RecordeP1_Castelo = 0;
	int MenuRanking::RecordeP1_Floresta = 0;
	int MenuRanking::RecordeP2_Castelo = 0;
	int MenuRanking::RecordeP2_Floresta = 0;

	MenuRanking::MenuRanking(idEstado ID_ESTADO) :
		Menu(ID_ESTADO, "Ranking&$"),
		botaoVoltar(new Botao("X", sf::Vector2f(50, 50), sf::Vector2f(50, 50), std::bind(&MenuRanking::voltarParaMenuPrincipal, this))),
		fundo()
	{
		textura = pGG->carregarTextura("Assets/Sprites/Fundo1.jpg");
		setPosicaoTexto(sf::operator*(sf::Vector2f(640, 100), 1.f));
		fundo.setOrigin(sf::operator*(sf::Vector2f(1280, 720), 0.5f));
		fundo.setTexture(textura);
		fundo.setSize(sf::Vector2f(1280, 720));
		fundo.setPosition(sf::operator*(sf::Vector2f(1280, 720), 0.5f));

		textoFloresta.setFont(*(pGG->carregarFonte()));
		textoFloresta.setCharacterSize(20); 
		textoFloresta.setString("Recorde Floresta:"); 
		textoFloresta.setPosition(100, 200); // Defina a posição desejada 

		textoCastelo.setFont(*(pGG->carregarFonte())); 
		textoCastelo.setCharacterSize(20); 
		textoCastelo.setString("Recorde Castelo:"); 
		textoCastelo.setPosition(700, 200); // Defina a posição desejada 

		textoRecordeP1_Floresta.setFont(*(pGG->carregarFonte())); 
		textoRecordeP1_Floresta.setCharacterSize(20); 
	 	textoRecordeP1_Floresta.setPosition(100, 300); // Defina a posição desejada

 		textoRecordeP1_Castelo.setFont(*(pGG->carregarFonte()));
 		textoRecordeP1_Castelo.setCharacterSize(20);
 		textoRecordeP1_Castelo.setPosition(700, 300); // Defina a posição desejada

 		textoRecordeP2_Floresta.setFont(*(pGG->carregarFonte()));
 		textoRecordeP2_Floresta.setCharacterSize(20);
 		textoRecordeP2_Floresta.setPosition(100, 400); // Defina a posição desejada

		textoRecordeP2_Castelo.setFont(*(pGG->carregarFonte()));
		textoRecordeP2_Castelo.setCharacterSize(20);
		textoRecordeP2_Castelo.setPosition(700, 400); // Defina a posição desejada
	}

	MenuRanking::~MenuRanking()
	{
		delete botaoVoltar;
	}
	void MenuRanking::executarEstado()
	{
		ativo = true;
		sf::RenderWindow* janela = pGG->getJanela();
		lerArquivo();

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

			botaoVoltar->tratarEvento(evento);

			janela->clear();
			desenhar();
			pGG->mostrar();
		}
	}

	void MenuRanking::voltarParaMenuPrincipal()
	{
		ativo = false;
		pGE->removerEstado(MENU);
	}
	void MenuRanking::desenhar()
	{
		if (RecordeP1_Floresta >= RecordeP2_Floresta) {
			textoRecordeP1_Floresta.setPosition(100, 300);
			textoRecordeP2_Floresta.setPosition(100, 400);
		}
		else
		{
			textoRecordeP1_Floresta.setPosition(100, 400);
			textoRecordeP2_Floresta.setPosition(100, 300);
		}

		if (RecordeP1_Castelo >= RecordeP2_Castelo)
		{
			textoRecordeP1_Castelo.setPosition(700, 300);
			textoRecordeP2_Castelo.setPosition(700, 400);
		}
		else
		{
			textoRecordeP1_Castelo.setPosition(700, 400); 
			textoRecordeP2_Castelo.setPosition(700, 300); 
		}

		pGG->desenhar(&fundo);
		pGG->desenhar(&textoPrincipal);
		pGG->desenhar(&textoFloresta);
		pGG->desenhar(&textoCastelo);
		pGG->desenhar(&textoRecordeP1_Floresta);
		pGG->desenhar(&textoRecordeP1_Castelo);
		pGG->desenhar(&textoRecordeP2_Floresta);
		pGG->desenhar(&textoRecordeP2_Castelo);

		botaoVoltar->desenhar();
	}
	void MenuRanking::executar(sf::Time deltaTime)
	{
		cout << "MenuRanking::executar()" << endl;
	}

	void MenuRanking::lerArquivo()
	{
		int contador = 0;
		int recorde1 = 0;
		int recorde2 = 0;
		int recorde3 = 0;
		int recorde4 = 0;

		std::ifstream arquivo;
		arquivo.open("ranking.txt", std::ios::in);
		if (!arquivo.is_open())
		{
			cout << "Erro ao abrir o arquivo" << endl;
			return;
		}

		std::string linha;

		while (std::getline(arquivo, linha))
		{
			try {
				int valor = std::stoi(linha);
				switch (contador)
				{
				case 0:
					recorde1 = valor;
					break;
				case 1:
					recorde2 = valor;
					break;
				case 2:
					recorde3 = valor;
					break;
				case 3:
					recorde4 = valor;
					break;
				case 4:
					(valor < recorde1) ? RecordeP1_Floresta = recorde1 : RecordeP1_Floresta = valor;
					break;
				case 5:
					(valor < recorde2) ? RecordeP1_Castelo = recorde2 : RecordeP1_Castelo = valor;
					break;
				case 6:
					(valor < recorde3) ? RecordeP2_Floresta = recorde3 : RecordeP2_Floresta = valor;
					break;
				case 7:
					(valor < recorde4) ? RecordeP2_Castelo = recorde4 : RecordeP2_Castelo = valor;
					break;
				}
				
			}
			catch (const std::exception& excecao)
			{
				std::cerr << "Erro durante a leitura do arquivo: " << excecao.what() << std::endl;
			}
			contador++;
		}

		textoRecordeP1_Floresta.setString("Jogador 1: " + std::to_string(RecordeP1_Floresta));
		textoRecordeP1_Castelo.setString("Jogador 1: " + std::to_string(RecordeP1_Castelo));
		textoRecordeP2_Floresta.setString("Jogador 2: " + std::to_string(RecordeP2_Floresta));
		textoRecordeP2_Castelo.setString("Jogador 2: " + std::to_string(RecordeP2_Castelo));
		escreverArquivo(recorde1, recorde2, recorde3, recorde4);
	}
	void MenuRanking::escreverArquivo(int recorde1, int record2, int record3, int record4)
	{
		std::ofstream arquivo;
		arquivo.open("ranking.txt", std::ios::out);
		if (!arquivo.is_open())
		{
			cout << "Erro ao abrir o arquivo" << endl;
			return;
		}

		arquivo << recorde1 << std::endl;
		arquivo << record2 << std::endl;
		arquivo << record3 << std::endl;
		arquivo << record4 << std::endl;
		arquivo << RecordeP1_Floresta << std::endl;
		arquivo << RecordeP1_Castelo << std::endl;
		arquivo << RecordeP2_Floresta << std::endl;
		arquivo << RecordeP2_Castelo << std::endl;

		arquivo.close();
	}
}
