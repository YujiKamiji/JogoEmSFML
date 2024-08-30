/*Ideia inspirada em um video tutorial de montagem de um gerenciador de estados*/
/*Link do video em questao: https://www.youtube.com/watch?v=v8UgcL97Q-A&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=11 */

#pragma once
#include "stdafx.h"
#include "Estados.h"
#include "Gerenciador_Grafico.h"
#include <stack>


using namespace Estados;
namespace Gerenciadores
{
	class GerenciadorDeEstados
	{
	private:
		GerenciadorDeEstados();
		static GerenciadorDeEstados* instancia;

		std::stack<Estados::Estado*> pilhaDeEstados; //pilha de ponteiros para os estados

	public:
		~GerenciadorDeEstados();
		static GerenciadorDeEstados* getInstancia();

		void executar(); //executa o estado no topo da pilha
		
		void adicionarEstado(idEstado id); //adiciona um estado na pilha
		void removerEstado(); //remove o estado do topo da pilha

		Estado* getEstadoAtual(); //retorna o estado no topo da pilha
	};
}
