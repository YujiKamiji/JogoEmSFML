#include "Botao.h"



Menus::Botao::Botao(std::string s, sf::Vector2f pos, sf::Vector2f tam, std::function<void()> callback):
	corpo(tam), selecionado(false), clicado(false), clicou(callback), corNormal(sf::Color::Black), corAtual(corNormal)
{
	corSelecionado = sf::Color(44, 26, 66, 255);
	

	texto.setString(s);
	texto.setFont(*(pGG->carregarFonte()));
	texto.setCharacterSize(20);
	texto.setFillColor(sf::Color::Red);

	sf::FloatRect textBounds = texto.getLocalBounds(); 
	texto.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f); 
	texto.setPosition(pos);

	corpo.setOrigin(tam.x / 2, tam.y / 2);
	corpo.setPosition(pos);
	corpo.setFillColor(corNormal);
}

Menus::Botao::~Botao()
{
}

void Menus::Botao::desenhar()
{
	pGG->desenhar(&corpo);
	pGG->desenhar(&texto);
}

void Menus::Botao::executar(sf::Time deltaTime)
{
	return;
}

bool Menus::Botao::mouseEmCima()
{
	if (pGG->getJanela())
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*pGG->getJanela());
		sf::Vector2f mousePosMundo = pGG->getJanela()->mapPixelToCoords(mousePos);

		return corpo.getGlobalBounds().contains(mousePosMundo);
	}
	
	return false;
}

void Menus::Botao::tratarEvento(sf::Event& evento)
{
	if (mouseEmCima())
	{
		if (!selecionado)
		{
			corpo.setFillColor(corSelecionado);
			selecionado = true;
		}
			
		if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left && !clicado)
		{
			clicado = true;
			clicou();
		}
		else if (evento.type == sf::Event::MouseButtonReleased && evento.mouseButton.button == sf::Mouse::Left) 
		{ 
			clicado = false;
		}
	}
	else
	{
		if (selecionado)
		{
			corpo.setFillColor(corNormal);
			selecionado = false;
		}
			
	}

}
