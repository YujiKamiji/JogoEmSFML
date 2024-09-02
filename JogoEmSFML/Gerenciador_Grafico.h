#pragma once
#include "stdafx.h"

#define LARGURA 1280
#define ALTURA 720

namespace Gerenciadores {
	class Gerenciador_Grafico
	{
	private:
		Gerenciador_Grafico();
		static Gerenciador_Grafico* instancia;

		sf::RenderWindow* janela;
		sf::View camera;

		std::map<const std::string, sf::Texture*> texturas;
		sf::Font* fonte;

	public:
		~Gerenciador_Grafico();

		void desenhar(sf::RectangleShape* corpo);
		void mostrar();
		void limpar();
		void fechar_janela();
		bool janela_aberta();

		sf::Texture* carregarTextura(std::string caminho);

		void camera_segue(sf::Vector2f posicao1);
		void camera_segue(sf::Vector2f posicao1, sf::Vector2f posicao);

		sf::RenderWindow* getJanela();
		static Gerenciador_Grafico* getInstancia();

		//para menu e afins:
		void desenhar(sf::Text* texto);
		void desenhar(sf::Sprite* sprite); 
		sf::Font* carregarFonte();
		void reiniciarJanela();
	};
}
