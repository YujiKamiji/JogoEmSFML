#pragma once
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Gerenciador_Grafico.h"
#include "GerenciadorDeColisoes.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Gerenciadores;
using namespace Listas;

class Jogo {
private:
	Jogador p1;
	Jogador p2;
	Gerenciador_Grafico* pGG;
	GerenciadorDeColisoes* pGC;
	Lista<Entidades::Personagens::Personagem> personagens;
	Lista<Entidades::Obstaculos::Obstaculo> obstaculos;

public:
	Jogo();
	~Jogo();

	void inicializar();
	void executar();
	void desenhar();
	void salvar();

};
