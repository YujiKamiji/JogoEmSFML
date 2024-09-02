#include  "Menu.h"
#include "GerenciadorDeEstados.h"

namespace Menus
{
	Menu::Menu(idEstado ID_ESTADO, string s) :
		Estado(ID_ESTADO),
		Ente(),
		textoPrincipal(),
		ativo(true)
	{
		textoPrincipal.setFont(*(pGG->carregarFonte()));
		textoPrincipal.setString(s);
		textoPrincipal.setCharacterSize(50);
		textoPrincipal.setFillColor(sf::Color::Red);
		textoPrincipal.setOrigin(textoPrincipal.getLocalBounds().width / 2, textoPrincipal.getLocalBounds().height / 2); 
		textoPrincipal.setPosition(100, 100);
	}

	Menu::~Menu() {}

	void Menu::executar(sf::Time deltaTime)
	{
		cout << "Menu::executar()" << endl;
	}
	void Menu::desenhar()
	{
		cout << "Menu::desenhar()" << endl;
		pGG->desenhar(&textoPrincipal);
	}
	void Menu::setString(std::string s)
	{
		textoPrincipal.setString(s);
	}
	void Menu::setPosicaoTexto(sf::Vector2f pos)
	{
		textoPrincipal.setPosition(pos);
	}
	void Menu::setCorTexto(sf::Color cor)
	{
		textoPrincipal.setFillColor(cor);
	}
	void Menu::setTamanhoTexto(int tam)
	{
		textoPrincipal.setCharacterSize(tam);
	}
	void Menu::setAtivo(bool b)
	{
		ativo = b;
	}
}
