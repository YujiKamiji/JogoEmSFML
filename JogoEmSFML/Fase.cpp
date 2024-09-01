#include "Fase.h"
#include "GerenciadorDeEstados.h"

namespace Fases {
	Fase::Fase(bool m, idEstado ID_ESTADO) :
		entidades(), p1(nullptr), p2(nullptr), multijogador(m), corpo(),
		pGC(pGC->getInstancia()), Estado(ID_ESTADO){}

	Fase::~Fase() {}

	void Fase::setMultijogador(bool m)
	{
		multijogador = m;  
	}

	void Fase::executar(sf::Time deltaTime) {}

	bool Fase::verificarVivos() {
		if (multijogador) {
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
				pGE->removerEstado();
				return false;
			}
		}
		else {
			if (p1->getVivo())
				pGG->camera_segue(p1->getPosicao());
			else
			{
				pGE->removerEstado();
				return false;
			}
				
		}
		pGC->verificarVivos();
		return true;
	}

	void Fase::executarEstado(){}

	void Fase::desenhar() {
		pGG->desenhar(&corpo);
	}

	void Fase::carregarMapa(std::string mapaJson) {
		try {
			std::ifstream arquivo(mapaJson);

			if (!arquivo.is_open()) {
				throw std::runtime_error("Erro ao abrir o mapa (caminho mapa)");
			}

			arquivo >> mapa;
			arquivo.close();
		}
		catch (const std::exception& excecao) {
			std::cerr << "Erro durante o carregamento do mapa: " << excecao.what() << std::endl;
		}
	}

	void Fase::criarChao() {
		int tamanhoBloco = mapa["tilewidth"];
		int largura = mapa["width"];
		int altura = mapa["height"];

		int indice = 0;

		for (int y = 0; y < altura; y++) {
			for (int x = 0; x < largura; x++) {
				int tileId = mapa["layers"][0]["data"][indice++];
				if (tileId != 0) {
					sf::Vector2f posicao = sf::Vector2f(x * tamanhoBloco, y * tamanhoBloco);
					sf::Vector2f tamanho = sf::Vector2f(tamanhoBloco, tamanhoBloco);
					Chao* chao = new Chao(posicao, tamanho);
					pGC->incluirObstaculo(chao);
					entidades.adicionar(chao);
				}
			}
		}
	}

	void Fase::criarJogadores() {
		p1 = new Jogador(sf::Vector2f(100, 1400), sf::Vector2f(50.0, 100.0));
		entidades.adicionar(p1);
		entidades.adicionar(p1->getAtaque());
		pGC->incluirPersonagem(p1);
		pGC->incluirProjetil(p1->getAtaque());

		p2 = p1;

		if (multijogador) {
			p2 = new Jogador(sf::Vector2f(200, 1400), sf::Vector2f(50.0, 100.0));
			entidades.adicionar(p2);
			entidades.adicionar(p2->getAtaque());
			pGC->incluirPersonagem(p2);
			pGC->incluirProjetil(p2->getAtaque());
		}

	}
}