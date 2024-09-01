/*Inspirado em video tutorial de montagem de um jogo em SFML*/
/*Link do referido video: https://www.youtube.com/watch?v=v8UgcL97Q-A&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=14*/
#pragma once
#include "stdafx.h"
#include "GeradorDeEstados.h"
#include "Floresta.h"
#include "Castelo.h"
#include "Menu.h"
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

		GeradorDeEstados geradorDeEstados;

    public:
        ~GerenciadorDeEstados();
        static GerenciadorDeEstados* getInstancia();

        void executar(); // Executa o estado no topo da pilha
        void adicionarEstado(idEstado id); // Adiciona um estado na pilha
        void removerEstado(); // Remove o estado do topo da pilha
        Estados::Estado* getEstadoAtual(); // Retorna o estado no topo da pilha
    };
}

