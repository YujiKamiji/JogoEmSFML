#include "GerenciadorDeEstados.h"

using namespace Estados;

namespace Gerenciadores
{
	GerenciadorDeEstados* GerenciadorDeEstados::instancia = nullptr;
	GerenciadorDeEstados* GerenciadorDeEstados::getInstancia()
	{
		if (instancia == nullptr)
			instancia = new GerenciadorDeEstados();
		return instancia;
	}

	GerenciadorDeEstados::GerenciadorDeEstados()
	{
	}

	GerenciadorDeEstados::~GerenciadorDeEstados()
	{
		while (pilhaDeEstados.empty() == false)
		{
			if (pilhaDeEstados.top() != nullptr)
				delete (pilhaDeEstados.top());
			pilhaDeEstados.top() = nullptr;
			pilhaDeEstados.pop();
		}
	}

	

	void GerenciadorDeEstados::executar()
	{


		if (!pilhaDeEstados.empty())
		{
			pilhaDeEstados.top()->executar(); //executa o estado do topo da pilha
		}
		else
		{
			cout << "pilha de estados vazia" << endl;
		}

	}

	void GerenciadorDeEstados::adicionarEstado(idEstado id)
	{
		Estado* estado = new Estado(id); //cria um novo estado de acordo com o id passado
		estado->criarEstado();

		if (estado != nullptr)
			pilhaDeEstados.push(estado); //adiciona o estado na pilha
		else
			cout << "ponteiro nulo" << endl;

		cout << "adicionei estado AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl; 
	}

	void GerenciadorDeEstados::removerEstado()
	{

		cout << "removi estado AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
		if (pilhaDeEstados.top() != nullptr)
		{
			delete (pilhaDeEstados.top()); //deleta o estado do topo da pilha
			pilhaDeEstados.top() = nullptr;
			pilhaDeEstados.pop(); //remove o estado do topo da pilha 
		}

		if (pilhaDeEstados.empty()) //todos os estados foram fechados
		{
			Gerenciador_Grafico* pGG = pGG->getInstancia();
			pGG->fechar_janela();
		}
		
			
	}

	Estado* GerenciadorDeEstados::getEstadoAtual()
	{
		if (pilhaDeEstados.top())
		{
			return pilhaDeEstados.top();
		}
		else
		{
			cout << "top da pilha vazio" << endl;
			return nullptr;
		}
	}

}