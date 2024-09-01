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

		cout << "topo da pilha: " << pilhaDeEstados.top()->getIdEstado() << endl; 
        std::cout << "Conteúdo da pilha de estados:" << std::endl;
        std::stack<Estados::Estado*> tempStack = pilhaDeEstados;

        while (!tempStack.empty())
        {
            Estados::Estado* estado = tempStack.top();
            std::cout << estado->getIdEstado() << std::endl;
            tempStack.pop();
        }
    }

    void GerenciadorDeEstados::removerEstado()
    {
        cout << "topo da pilha ANTES DE REMOVER: " << pilhaDeEstados.top()->getIdEstado() << endl;
        std::cout << "Conteúdo da pilha de estados ANTES DE REMOVER:" << std::endl;
        std::stack<Estados::Estado*> tempStack = pilhaDeEstados;

        while (!tempStack.empty())
        {
            Estados::Estado* estado = tempStack.top();
            std::cout << estado->getIdEstado() << std::endl;
            tempStack.pop();
        }


        std::cout << "Removi estado" << std::endl;
        if (!pilhaDeEstados.empty() && pilhaDeEstados.top() != nullptr)
        {

            Estados::Estado* aux = pilhaDeEstados.top();
            pilhaDeEstados.top() = nullptr;
            pilhaDeEstados.pop(); // Remove o estado do topo da pilha 
            delete aux; // Libera a memória do estado no topo da pilha
        }

        if (pilhaDeEstados.empty()) // Todos os estados foram fechados
        {
            std::cout << "Todos os estados foram fechados" << std::endl;
        }

		 

        cout << "topo da pilha DEPOIS DE REMOVER: " << pilhaDeEstados.top()->getIdEstado() << endl;
        std::cout << "Conteúdo da pilha de estados DEPOIS DE REMOVER:" << std::endl;
        tempStack = pilhaDeEstados;

        while (!tempStack.empty())
        {
            Estados::Estado* estado = tempStack.top();
            std::cout << estado->getIdEstado() << std::endl;
            tempStack.pop();
        }

        pilhaDeEstados.top()->executarEstado();
    }

    Estados::Estado* GerenciadorDeEstados::getEstadoAtual()
    {
        if (pilhaDeEstados.top())
        {
            //cout << "topo da pilha: " << pilhaDeEstados.top() << endl;
            return pilhaDeEstados.top();
        }
        else
        {
            std::cout << "Top da pilha vazio" << std::endl;
            return nullptr;
        }
    }
}
