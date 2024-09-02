#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "Botao.h"

namespace Menus
{
	class MenuRanking : public Menu
	{
	
	private:
		Botao* botaoVoltar;

		sf::RectangleShape fundo;

		sf::Text textoFloresta;
		sf::Text textoCastelo;

		sf::Text textoRecordeP1_Floresta;
		sf::Text textoRecordeP1_Castelo;
		sf::Text textoRecordeP2_Floresta;
		sf::Text textoRecordeP2_Castelo;

		static int RecordeP1_Floresta;
		static int RecordeP1_Castelo;
		static int RecordeP2_Floresta;
		static int RecordeP2_Castelo;

	public:
		MenuRanking(idEstado ID_ESTADO);
		~MenuRanking();

		void executarEstado();

		void voltarParaMenuPrincipal();
		
		void desenhar();
		void executar(sf::Time deltaTime);

		void lerArquivo(); //vai ler o arquivo e considerar se o recorde atual é maior que o recorde anterior
		void escreverArquivo(int recorde1, int record2, int record3, int record4); //vai escrever o recorde atual no arquivo
	};
}