#include "GerenciadorDeEstados.h"
#include "Estado.h"

namespace Gerenciadores
{
    GerenciadorDeEstados* GerenciadorDeEstados::instancia = nullptr;

    GerenciadorDeEstados* GerenciadorDeEstados::getInstancia()
    {
        if (instancia == nullptr)
            instancia = new GerenciadorDeEstados();
        return instancia;
    }

    GerenciadorDeEstados::GerenciadorDeEstados():
		pilhaDeEstados(), estados()
    {
		//criar o vetor de estados aqui
    }

    GerenciadorDeEstados::~GerenciadorDeEstados()
    {
        while (!pilhaDeEstados.empty())
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
            pilhaDeEstados.top()->executar(); // Executa o estado do topo da pilha
        }
        else
        {
            std::cout << "Pilha de estados vazia" << std::endl;
        }
    }

    void GerenciadorDeEstados::adicionarEstado(idEstado id)
    {
        // Aqui você deve criar uma instância de uma subclasse de Estado, não de Estado diretamente
        // Estado* estado = new Estado(id); // Isso está incorreto
        // Exemplo de criação de um estado específico:
        // Estado* estado = new EstadoMenu(id, this); // Supondo que EstadoMenu seja uma subclasse de Estado

        // Para fins de exemplo, vamos apenas usar um ponteiro nulo
        Estados::Estado* estado = nullptr;

        if (estado != nullptr)
            pilhaDeEstados.push(estado); // Adiciona o estado na pilha
        else
            std::cout << "Ponteiro nulo" << std::endl;

        std::cout << "Adicionei estado" << std::endl;
    }

    void GerenciadorDeEstados::removerEstado()
    {
        std::cout << "Removi estado" << std::endl;
        if (pilhaDeEstados.top() != nullptr)
        {
            delete (pilhaDeEstados.top()); // Deleta o estado do topo da pilha
            pilhaDeEstados.top() = nullptr;
            pilhaDeEstados.pop(); // Remove o estado do topo da pilha 
        }

        if (pilhaDeEstados.empty()) // Todos os estados foram fechados
        {
            // Gerenciador_Grafico* pGG = pGG->getInstancia();
            // pGG->fechar_janela();
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
