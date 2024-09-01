#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "Botao.h"

namespace Menus
{
	class MenuPrincipal : public Menu
	{
	private:
		std::list<Botao*> botoes; //lista de botoes 

		
	public:
		MenuPrincipal(idEstado ID_ESTADO);
		~MenuPrincipal();

		void irParaFlorestaSingle();

		void executarEstado();
		void inicializarElementos();
		
		void adicionarBotao(Botao* botao);
		void desenhar();
		void executar(sf::Time deltaTime);

	};
}