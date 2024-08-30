#include "Fase.h"

namespace Fases {
	Fase::Fase() :
		entidades(), personagens(), obstaculos(), projeteis(),
		pGG(pGG->getInstancia()), pGC(), corpo() {}

	Fase::~Fase() {}

	void Fase::executar(sf::Time deltaTime) {}

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
					obstaculos.inserir(chao);
					entidades.adicionar(chao);
				}
			}
		}
	}
}