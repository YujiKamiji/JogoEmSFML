#pragma once
#include "stdafx.h"
#include <vector>
#include <stack>

namespace Estados {
    class Estado;
}

namespace Gerenciadores
{
    class GerenciadorDeEstados
    {
    private:
        GerenciadorDeEstados();
        static GerenciadorDeEstados* instancia;

        std::stack<Estados::Estado*> pilhaDeEstados; // Pilha de ponteiros para os estados
		std::vector<Estados::Estado> estados; // Vetor de ponteiros para guardar todos os estados

    public:
        ~GerenciadorDeEstados();
        static GerenciadorDeEstados* getInstancia();

        void executar(); // Executa o estado no topo da pilha
        void adicionarEstado(idEstado id); // Adiciona um estado na pilha
        void removerEstado(); // Remove o estado do topo da pilha
        Estados::Estado* getEstadoAtual(); // Retorna o estado no topo da pilha
    };
}
