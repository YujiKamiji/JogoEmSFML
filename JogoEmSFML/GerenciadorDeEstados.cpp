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
        pilhaDeEstados.push(geradorDeEstados.criarEstado(id)); // Adiciona um estado na pilha
    }

    void GerenciadorDeEstados::removerEstado(idEstado ID_SUB)
    {  
        
        if (!pilhaDeEstados.empty() && pilhaDeEstados.top() != nullptr)
        {

			delete pilhaDeEstados.top(); // Libera a memória do estado no topo da pilha
            pilhaDeEstados.top() = nullptr;
            pilhaDeEstados.pop(); // Remove o estado do topo da pilha 
        }
        

        adicionarEstado(ID_SUB); // Adiciona um estado na pilha (substitui o estado removido)
        
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
            return nullptr;
        }
    }
}
