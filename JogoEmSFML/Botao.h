#pragma once
#include "stdafx.h"
#include "Ente.h"

namespace Menus
{

	class Botao : public Ente
	{
	private:
		sf::Text texto;
		sf::RectangleShape corpo;
		sf::Color corNormal;
		sf::Color corSelecionado;
		sf::Color corAtual;
		bool selecionado;
		bool clicado;
		std::function<void()> clicou;

	public:
		Botao(std::string s, sf::Vector2f pos, sf::Vector2f tam, std::function<void()> f);
		~Botao();
		void desenhar();
		void executar(sf::Time deltaTime);
		bool mouseEmCima();
		void tratarEvento(sf::Event& evento);
		
	};
}
