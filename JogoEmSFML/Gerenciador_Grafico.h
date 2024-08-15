#pragma once
#include "stdafx.h"

#define LARGURA 1280
#define ALTURA 720

namespace Gerenciadores {
	class Gerenciador_Grafico
	{
	private:
		sf::RenderWindow* janela;
		sf::View camera;

		std::map<const std::string, sf::Texture*> texturas;
	public:
		Gerenciador_Grafico();
		~Gerenciador_Grafico();

		void mostrar();
		void limpar();
		void fechar_janela();
		bool janela_aberta();

		void camera_segue(sf::Vector2f posicao1);
		void camera_segue(sf::Vector2f posicao1, sf::Vector2f posicao);
	};
}
