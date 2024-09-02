#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Estado.h"
#include "Botao.h"

namespace Menus 
{
	class Menu : public Ente, public Estados::Estado {
	protected:
		sf::Text textoPrincipal;
		bool ativo;
	public:
		Menu(idEstado ID_ESTADO, string s);
		~Menu();
		void executar(sf::Time deltaTime);
		virtual void executarEstado() = 0;
		void desenhar();

		void setString(std::string s);
		void setPosicaoTexto(sf::Vector2f pos);
		void setCorTexto(sf::Color cor);
		void setTamanhoTexto(int tam);

		void setAtivo(bool b);

	};
}

