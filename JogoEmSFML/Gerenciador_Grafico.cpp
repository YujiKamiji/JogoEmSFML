#include "Gerenciador_Grafico.h"

namespace Gerenciadores {
	Gerenciador_Grafico::Gerenciador_Grafico() :
		janela(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "O Jogo")),
		camera(sf::Vector2f(LARGURA / 2, ALTURA / 2), sf::Vector2f(LARGURA, ALTURA)),
		texturas()
	{
		janela->setFramerateLimit(60);
	}

	Gerenciador_Grafico::~Gerenciador_Grafico() {
		std::map<const std::string, sf::Texture*>::iterator it;
		it = texturas.begin();
		while (it != texturas.end()) {
			delete it->second;
			it++;
		}
			
		texturas.clear();
		delete janela;
	}

	void Gerenciador_Grafico::mostrar() {
		if (janela_aberta())
			janela->display();
	}

	void Gerenciador_Grafico::limpar() {
		if (janela_aberta())
			janela->clear();
	}

	void Gerenciador_Grafico::fechar_janela() {
		janela->close();
	}
	bool Gerenciador_Grafico::janela_aberta() {
		return (janela->isOpen());
	}

	void Gerenciador_Grafico::camera_segue(sf::Vector2f posicao1) {

	}

	void Gerenciador_Grafico::camera_segue(sf::Vector2f posicao1, sf::Vector2f posicao2) {

	}
}