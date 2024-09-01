#include "GerenciadorDeEstados.h"
#include "Estado.h"

namespace Gerenciadores
{
    GerenciadorDeEstados* GerenciadorDeEstados::instancia = nullptr;
    GerenciadorDeEstados* GerenciadorDeEstados::getInstancia()
    {
        if (instancia == nullptr)
        {
            instancia = new GerenciadorDeEstados();
			cout << "Instancia criada" << endl;
        }
            
        return instancia;
    }

    GerenciadorDeEstados::GerenciadorDeEstados():
		pilhaDeEstados()
    {       
    }

    GerenciadorDeEstados::~GerenciadorDeEstados()
    {
        // Liberar todos os estados na pilha
        while (!pilhaDeEstados.empty())
        {
			if (pilhaDeEstados.top() != nullptr)
                delete pilhaDeEstados.top();
            pilhaDeEstados.pop();
        }
    }

    void GerenciadorDeEstados::executar() 
    {
        if (!pilhaDeEstados.empty()) 
        {
            pilhaDeEstados.top()->executarEstado(); // Executa o estado do topo da pilha
        }
        else
        {
            std::cout << "Pilha de estados vazia" << std::endl;
        }
    }

    void GerenciadorDeEstados::adicionarEstado(idEstado id)
    {      
		cout << "Adicionei estado: " << id << endl;
		pilhaDeEstados.push(geradorDeEstados.criarEstado(id)); // Adiciona um estado na pilha
    }

    void GerenciadorDeEstados::removerEstado()
    {
        std::cout << "Removi estado" << std::endl;
        if (pilhaDeEstados.top() != nullptr)
        {
			//delete pilhaDeEstados.top(); // Libera a memória do estado no topo da pilha
            pilhaDeEstados.top() = nullptr;
            pilhaDeEstados.pop(); // Remove o estado do topo da pilha 
        }

        if (pilhaDeEstados.empty()) // Todos os estados foram fechados
        {
			std::cout << "Todos os estados foram fechados" << std::endl;
        }
    }

    Estados::Estado* GerenciadorDeEstados::getEstadoAtual()
    {
        if (pilhaDeEstados.top())
        {
            return pilhaDeEstados.top();
        }
        else
        {
            std::cout << "Top da pilha vazio" << std::endl;
            return nullptr;
        }
    }
}
