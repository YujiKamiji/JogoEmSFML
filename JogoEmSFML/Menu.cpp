#include  "Menu.h"
#include "GerenciadorDeEstados.h"

Menu::Menu(idEstado ID_ESTADO)
{
	Estados::Estado::id_estado = ID_ESTADO;
}

Menu::~Menu()
{
}

void Menu::executar(sf::Time deltaTime)
{
}

void Menu::desenhar()
{
}
